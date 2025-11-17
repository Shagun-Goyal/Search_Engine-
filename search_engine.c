#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "documents.h"
#include "bst.h"

BSTNode *index_root = NULL;
double idf[TOTAL_DOCS][10000];  // precompute later if needed

void normalizeWord(char *word) {
    int i = 0, j = 0;
    while (word[i]) {
        if (isalpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
        i++;
    }
    word[j] = '\0';
}

void buildIndex(BSTNode **root) {
    for (int d = 0; d < TOTAL_DOCS; d++) {
        char *content = strdup(doc_contents[d]);
        char *token = strtok(content, " ");
        while (token) {
            normalizeWord(token);
            if (strlen(token) > 1) {  // ignore very small words
                *root = insert(*root, token, d);
            }
            token = strtok(NULL, " ");
        }
        free(content);
    }
    printf("\nIndex built successfully with %d documents!\n", TOTAL_DOCS);
}

double calculateTFIDF(int tf, int df) {
    if (df == 0) return 0;
    double idf_val = log10((double)TOTAL_DOCS / df);
    return tf * idf_val;
}

void searchPhrase(BSTNode *root, const char *phrase) {
    char query[500];
    strcpy(query, phrase);
    char *words[50];
    int word_count = 0;
    
    char *token = strtok(query, " ");
    while (token) {
        normalizeWord(token);
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }
    
    if (word_count == 0) return;
    
    clock_t start = clock();
    
    double scores[TOTAL_DOCS] = {0};
    int found_in[TOTAL_DOCS] = {0};
    
    // For phrase search: all words must appear in order
    for (int d = 0; d < TOTAL_DOCS; d++) {
        int positions[50] = {0};
        int all_found = 1;
        
        for (int w = 0; w < word_count; w++) {
            BSTNode *node = searchWord(root, words[w]);
            if (!node) { all_found = 0; break; }
            
            int word_found = 0;
            DocNode *doc = node->doc_list;
            while (doc) {
                if (doc->doc_id == d) {
                    positions[w] = doc->frequency;
                    word_found = 1;
                    break;
                }
                doc = doc->next;
            }
            if (!word_found) { all_found = 0; break; }
        }
        
        if (all_found) {
            found_in[d] = 1;
            for (int w = 0; w < word_count; w++) {
                BSTNode *node = searchWord(root, words[w]);
                DocNode *doc = node->doc_list;
                while (doc && doc->doc_id != d) doc = doc->next;
                if (doc) {
                    scores[d] += calculateTFIDF(doc->frequency, node->df);
                }
            }
        }
    }
    
    // Sort results by score
    typedef struct { int id; double score; } Result;
    Result results[TOTAL_DOCS];
    int count = 0;
    
    for (int i = 0; i < TOTAL_DOCS; i++) {
        if (found_in[i]) {
            results[count].id = i;
            results[count].score = scores[i];
            count++;
        }
    }
    
    // Simple bubble sort (for small N)
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-i-1; j++) {
            if (results[j].score < results[j+1].score) {
                Result temp = results[j];
                results[j] = results[j+1];
                results[j+1] = temp;
            }
        }
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) * 1000000 / CLOCKS_PER_SEC;
    
    printf("\nFound %d results in %.2f microseconds\n", count, time_taken);
    printf("════════════════════════════════════════════════\n");
    
    int show = count < 10 ? count : 10;
    for (int i = 0; i < show; i++) {
        int id = results[i].id;
        printf("Rank %d [Score: %.4f] → %s\n", i+1, results[i].score, doc_titles[id]);
    }
    
    if (count == 0) printf("No results found!\n");
    printf("════════════════════════════════════════════════\n");
}
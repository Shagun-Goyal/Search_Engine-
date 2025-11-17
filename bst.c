#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bst.h"

BSTNode* createNode(const char *word) {
    BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));
    strcpy(newNode->word, word);
    newNode->df = 0;
    newNode->doc_list = NULL;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* insert(BSTNode *root, const char *word, int doc_id) {
    if (root == NULL) {
        root = createNode(word);
        root->df = 1;
        
        DocNode *doc = (DocNode*)malloc(sizeof(DocNode));
        doc->doc_id = doc_id;
        doc->frequency = 1;
        doc->next = NULL;
        root->doc_list = doc;
        return root;
    }

    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        root->df++;
        DocNode *temp = root->doc_list;
        DocNode *prev = NULL;
        while (temp) {
            if (temp->doc_id == doc_id) {
                temp->frequency++;
                root->df--;  // because we counted extra
                return root;
            }
            prev = temp;
            temp = temp->next;
        }
        DocNode *doc = (DocNode*)malloc(sizeof(DocNode));
        doc->doc_id = doc_id;
        doc->frequency = 1;
        doc->next = NULL;
        if (prev) prev->next = doc;
        else root->doc_list = doc;
    }
    else if (cmp < 0)
        root->left = insert(root->left, word, doc_id);
    else
        root->right = insert(root->right, word, doc_id);
    return root;
}

BSTNode* searchWord(BSTNode *root, const char *word) {
    if (root == NULL) return NULL;
    int cmp = strcmp(word, root->word);
    if (cmp == 0) return root;
    if (cmp < 0) return searchWord(root->left, word);
    return searchWord(root->right, word);
}

void freeBST(BSTNode *root) {
    if (root == NULL) return;
    freeBST(root->left);
    freeBST(root->right);
    DocNode *temp = root->doc_list;
    while (temp) {
        DocNode *next = temp->next;
        free(temp);
        temp = next;
    }
    free(root);
}
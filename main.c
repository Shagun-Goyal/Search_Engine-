#include <stdio.h>
#include <string.h>
#include "bst.h"
#include "search_engine.h"

BSTNode *root = NULL;

void printHeader() {
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║           MiniSearch - DSA Project           ║\n");
    printf("║       TF-IDF + Phrase Search + BST Index     ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
}

int main() {
    printHeader();
    printf("Building index for 20 documents...\n");
    buildIndex(&root);
    
    char query[500];
    while (1) {
        printf("\nSearch: ");
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = 0;
        
        if (strcmp(query, "exit") == 0 || strcmp(query, "quit") == 0) break;
        if (strlen(query) == 0) continue;
        
        searchPhrase(root, query);
    }
    
    freeBST(root);
    printf("\nThank you! Project by You ❤️\n");
    return 0;
}
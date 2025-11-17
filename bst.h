#ifndef BST_H
#define BST_H

typedef struct DocNode {
    int doc_id;
    int frequency;
    struct DocNode *next;
} DocNode;

typedef struct BSTNode {
    char word[50];
    int df;                  // document frequency
    DocNode *doc_list;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode* createNode(const char *word);
BSTNode* insert(BSTNode *root, const char *word, int doc_id);
BSTNode* searchWord(BSTNode *root, const char *word);
void freeBST(BSTNode *root);

#endif
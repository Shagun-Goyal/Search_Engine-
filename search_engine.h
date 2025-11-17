#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include "bst.h"

void buildIndex(BSTNode **root);
void searchPhrase(BSTNode *root, const char *phrase);
void normalizeWord(char *word);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interviu3.h"

StockList* createStockNode(const char *n) {
    StockList* newNode = malloc(sizeof(StockList));
    if(newNode) { 
        strncpy(newNode->symbol, n, MAX_SYM); 
        newNode->next = NULL; 
    }
    return newNode;
}

TreeNode* createTreeNode(int day) {
    TreeNode* newNode = malloc(sizeof(TreeNode));
    if(newNode) { 
        newNode->stocks = NULL; 
        newNode->left = newNode->right = NULL; 
        newNode->depth = day; 
    }
    return newNode;
}

void addStockToNode(TreeNode *node, const char *n) {
    StockList* newNode = createStockNode(n);
    if (!node->stocks) {
        node->stocks = newNode;
    } else { 
        StockList* current = node->stocks; 
        while(current->next) current = current->next; 
        current->next = newNode; 
    }
}

void insertStockInTree(TreeNode *root, const char *n, const double pret[], int day) {
    TreeNode* currNode = root;
    for (int i = 0; i < day - 1; i++) {
        if (pret[i+1] >= pret[i]) {
            if (!currNode->right) currNode->right = createTreeNode(i + 1);
            currNode = currNode->right;
        } else {
            if (!currNode->left) currNode->left = createTreeNode(i + 1);
            currNode = currNode->left;
        }
    }
    addStockToNode(currNode, n);
}

TreeNode* findOppositeTrendNode(TreeNode *root, const double pret[], int day) {
    TreeNode* currNode = root;
    for (int i = 0; i < day - 1; i++) {
        if (pret[i+1] >= pret[i]) {
            if (!currNode->left) return NULL;
            currNode = currNode->left;
        } else {
            if (!currNode->right) return NULL;
            currNode = currNode->right;
        }
    }
    return currNode;
}

void freeTree(TreeNode *root) {
    if (!root) return;
    freeTree(root->left); 
    freeTree(root->right);
    StockList* currentStock = root->stocks;
    while (currentStock) { 
        StockList* temp = currentStock; 
        currentStock = currentStock->next; 
        free(temp); 
    }
    free(root);
}
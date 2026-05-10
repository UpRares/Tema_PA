#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interviu3.h"

int main(int argc, char** argv) {
    if (argc < 3){
         return 1;
        }
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");
    
    if (!f1 || !f2){
         return 1;
        }
    char n[NUM][MAX_SYM], buffer[2048];
    double pret[NUM][100];
    int day = 0, index_stock_curr, flag = 1;

    if (fgets(buffer, sizeof(buffer), f1)) {
        const char* t = strtok(buffer, ", \t\r\n");
        index_stock_curr = 0;
        while (t && index_stock_curr < NUM) { 
            strncpy(n[index_stock_curr++], t, MAX_SYM); 
            t = strtok(NULL, ", \t\r\n"); 
        }
    }

    while (fgets(buffer, sizeof(buffer), f1)) {
        const char* t = strtok(buffer, ", \t\r\n");
        int index_coloana = 0;
        while (t && index_coloana < NUM) { 
            pret[index_coloana++][day] = atof(t); 
            t = strtok(NULL, ", \t\r\n"); 
        }
        day++;
    }

    TreeNode* root = createTreeNode(0);
    for (index_stock_curr = 0; index_stock_curr < NUM; index_stock_curr++) {
        insertStockInTree(root, n[index_stock_curr], pret[index_stock_curr], day);
    }

    for (index_stock_curr = 0; index_stock_curr < NUM; index_stock_curr++) {
        TreeNode* mirrorNode = findOppositeTrendNode(root, pret[index_stock_curr], day);
        if (mirrorNode && mirrorNode->stocks) {
            StockList* list_ptr = mirrorNode->stocks;
            while (list_ptr) {
                int index_oglinda = -1;
                for(int i = 0; i < NUM; i++) {
                    if(!strcmp(n[i], list_ptr->symbol)) { 
                        index_oglinda = i; 
                        break; 
                    }
                }
                
                if (index_oglinda > index_stock_curr) {
                    if (!flag) fprintf(f2, "\n");
                    fprintf(f2, "%s-%s", n[index_stock_curr], list_ptr->symbol);
                    flag = 0;
                }
                list_ptr = list_ptr->next;
            }
        }
    }

    freeTree(root); 
    fclose(f1); 
    fclose(f2);
    return 0;
}
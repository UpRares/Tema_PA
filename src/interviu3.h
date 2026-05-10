#define MAX_SYM 10
#define NUM 10

typedef struct StockList {
    char symbol[MAX_SYM];
    struct StockList *next;
} StockList;

typedef struct TreeNode {
    StockList *stocks;
    struct TreeNode *left;
    struct TreeNode *right;
    int depth;
} TreeNode;

StockList* createStockNode(const char *n);
TreeNode* createTreeNode(int day);
void addStockToNode(TreeNode *node, const char *n);
void insertStockInTree(TreeNode *root, const char *n, const double pret[], int day);
TreeNode* findOppositeTrendNode(TreeNode *root, const double pret[], int day);
void freeTree(TreeNode *root);

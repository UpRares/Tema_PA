#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef double Data;

struct Elem {
    Data val;
    struct Elem * next;
};
typedef struct Elem Node;

int isEmpty(const Node *top);
void push(Node **top, Data v);
Data pop(Node **top);
Data top(Node **top);
void deleteStack(Node **top);


typedef struct QueueNode {
    int ziua;
    double diferenta_absoluta;
    char nume_piata[50];
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;


Queue* initQueue();
int isQueueEmpty(const Queue* q);
void enqueue(Queue* q, int ziua, double diferenta, const char* nume);
QueueNode* dequeue(Queue* q);

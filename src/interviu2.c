#include "interviu2.h"
#include <stdio.h>
#include <stdlib.h>

void push(Node **top, Data v)
{
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}
Data pop(Node ** top)
{
	if (isEmpty(*top))
      return 0;
	Node *temp=(*top);
	double aux=temp->val;
	*top=(*top)->next;
	free(temp);
	return aux;
}

int isEmpty ( const Node *top ){
return top == NULL ;
}

void deleteStack ( Node ** top ){
    while ((* top )!= NULL ){
    Node * temp ;
    temp =* top;
    *top =(* top) -> next ;
    free ( temp );
}
}

Queue* initQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

int isQueueEmpty(const Queue* q) {
    return (q == NULL || q->front == NULL);
}

void enqueue(Queue* q, int ziua, double diferenta, const char* nume) {
    if (q == NULL) return;

      QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Eroare la alocarea memoriei pentru coada.\n");
        return;
    }

    
    newNode->ziua = ziua;
    newNode->diferenta_absoluta = diferenta;
    
    strncpy(newNode->nume_piata, nume, 49);
    newNode->nume_piata[49] = '\0';
    
    newNode->next = NULL;

    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

QueueNode* dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }

       QueueNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return temp;
}

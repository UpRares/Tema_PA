#include "interviu2.h"

int main(int argc, const char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    FILE *fisier_in = fopen(argv[1], "r");
    if (!fisier_in) {
        printf("Eroare la deschiderea fisierului de intrare.\n");
        return 1;
    }

    char nume1[50], nume2[50], nume3[50];
    Node *stiva1 = NULL;
    Node *stiva2 = NULL;
    Node *stiva3 = NULL;
    double pret;

    fscanf(fisier_in, "%49[^\n\r]", nume1);
    while (fscanf(fisier_in, "%lf", &pret) == 1) {
        push(&stiva1, pret); 
    }

    fscanf(fisier_in, "%49[^\n\r]", nume2);
    while (fscanf(fisier_in, "%lf", &pret) == 1) {
        push(&stiva2, pret);
    }

    fscanf(fisier_in, "%49[^\n\r]", nume3);
    while (fscanf(fisier_in, "%lf", &pret) == 1) {
        push(&stiva3, pret);
    }

    fclose(fisier_in);

    Queue* coada = initQueue();
    int zi = 1;

    while (!isEmpty(stiva1) && !isEmpty(stiva2) && !isEmpty(stiva3)) {
        double p1 = pop(&stiva1);
        double p2 = pop(&stiva2);
        double p3 = pop(&stiva3);

        if (p1 == p2 && p1 != p3) {
            enqueue(coada, zi, fabs(p1 - p3), nume3);
        } 
        else if (p1 == p3 && p1 != p2) {
            enqueue(coada, zi, fabs(p1 - p2), nume2);
        } 
        else if (p2 == p3 && p2 != p1) {
            enqueue(coada, zi, fabs(p2 - p1), nume1);
        }

        zi++; 
    }

    deleteStack(&stiva1);
    deleteStack(&stiva2);
    deleteStack(&stiva3);


    FILE *fisier_out = fopen(argv[2], "w");
    if (!fisier_out) {
        printf("Eroare la crearea fisierului de iesire.\n");
        free(coada);
        return 1;
    }

    while (!isQueueEmpty(coada)) {
        QueueNode* oportunitate = dequeue(coada);
   
        fprintf(fisier_out, "ziua %d - %.2f - %s\n", oportunitate->ziua, oportunitate->diferenta_absoluta, oportunitate->nume_piata);
        
        free(oportunitate);
    }

    fclose(fisier_out);
    free(coada);

    return 0;
}
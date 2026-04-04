#include "interviu1.h"

int is_empty(Node* head) {
    return head == NULL;
}

Node* adaugare_nod_final(Node* head, double val, double randament){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Nu s-a putut aloca memorie");
        exit(1);
    }
    new_node->val = val;
    new_node->randament = randament;
    new_node->next = NULL;

    if (is_empty(head)) {
        return new_node;
    }

    Node* curent = head;
    while (curent->next != NULL) {
        curent = curent->next;
    }

    curent->next = new_node;
    return head;
}

void free_list(Node* head) {
    Node* curent = head;
    Node* next_node;

    while (curent != NULL) {
        next_node = curent->next;
        free(curent);
        curent = next_node;
    }
}

Node* populare_din_fisier(const char* fisier1, int* N) {
    FILE* fisier = fopen(fisier1, "r");
    if (fisier == NULL) {
        printf("Fisierul %s nu s-a putut deschide\n", fisier1);
        return NULL;
    }

    Node* head = NULL;
    
    if (fscanf(fisier, "%d", N) != 1) {
        fclose(fisier);
        return NULL;
    } 

    double val_curenta;
    double val_precedenta = 0.0;
    double randament = 0.0;

    for (int i = 0; i < *N; i++) {
        fscanf(fisier, "%lf", &val_curenta);

        if (i == 0) {
            randament = 0.0; 
        } else {
            randament = (val_curenta - val_precedenta) / val_precedenta;
        }

        head = adaugare_nod_final(head, val_curenta, randament);

        val_precedenta = val_curenta;
    }

    fclose(fisier);
    return head;
}
void print_list(Node* head) {
    if (is_empty(head)) {
        printf("Lista nu are valori\n");
        return;
    }

    Node* curent = head;
    int zi = 1;

    while (curent != NULL) {
        printf("Ziua %d: Valoare = %.3f, Randament = %.3f\n", 
               zi, curent->val, curent->randament);
        curent = curent->next;
        zi++;
    }
    printf("\n");
}

double calc_randament_mediu(Node* head, int N) {
    if (head == NULL || N <= 0) {
        return 0.0;
    }
    double suma = 0.0;
    Node* curent = head;

    while (curent != NULL) {
        suma += curent->randament;
        curent = curent->next;
    }
    return suma / N; 
}

double calc_volatilitatea(Node* head, int N, double media) {
   if (head == NULL || N <= 0) {
        return 0.0;
    }
    double suma_patrate = 0.0;
    Node* curent = head; 

    while (curent != NULL) {
        suma_patrate += pow(curent->randament - media, 2);
        curent = curent->next;
    }
    return sqrt(suma_patrate / N); 
}
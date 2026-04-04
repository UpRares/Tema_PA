#include <stdio.h>
#include <stdlib.h>

struct Elem
{
    double val;
    double randament;
    struct Elem * next ;
};

typedef struct Elem Node ;

int is_empty(Node* head);
Node* adaugare_nod_final(Node* head, double val, double randament);
void free_list(Node* head);

Node* populare_din_fisier(const char* filename, int* N);
void print_list(Node* head);
double calc_randament_mediu(Node* head, int N);
double calc_volatilitatea(Node* head, int N, double media);
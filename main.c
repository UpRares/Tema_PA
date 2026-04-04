#include <stdio.h>
#include "interviu1.h"
#include <math.h>

int main() {
    int N = 0;
    
    Node* portofoliu = populare_din_fisier("date.in", &N);
    if (portofoliu == NULL){ 
    return 1;
    }

    double rand_mediu = calc_randament_mediu(portofoliu, N);
    double volatilitate = calc_volatilitatea(portofoliu, N, rand_mediu);
    
    double sharpe_ratio = 0.0;
    if (volatilitate != 0.0) {
        sharpe_ratio = rand_mediu / volatilitate;
    }

    double rand_mediu_trunchiat = trunc(rand_mediu * 1000.0) / 1000.0;
    double volatilitate_trunchiata = trunc(volatilitate * 1000.0) / 1000.0;
    double sharpe_ratio_trunchiat = trunc(sharpe_ratio * 1000.0) / 1000.0;

    FILE* fisier_iesire = fopen("date.out", "w");
    
    if (fisier_iesire == NULL) {
        printf("Eroare la crearea fisierului de iesire!\n");
        free_list(portofoliu);
        return 1;
    }

    fprintf(fisier_iesire, "%.3f\n", rand_mediu_trunchiat);
    fprintf(fisier_iesire, "%.3f\n", volatilitate_trunchiata);
    fprintf(fisier_iesire, "%.3f\n", sharpe_ratio_trunchiat);

    fclose(fisier_iesire);
    free_list(portofoliu);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Utilizare: %s <fisier_intrare> <fisier_iesire>\n", argv[0]);
        return 1;
    }
    const char *fisier_in = argv[1];
    printf("in: %s, out: %s\n", argv[1], argv[2]);
    const char *fisier_out = argv[2];

    FILE *fin = fopen(fisier_in, "r");
    if (fin == NULL) {
        perror("Eroare la deschiderea fișierului de intrare");
        return 1;
    }

    FILE *fout = fopen(fisier_out, "w");
    if (fout == NULL) {
        perror("Eroare la deschiderea fișierului de ieșire");
        fclose(fin); 
        return 1;
    }

    fprintf(fout , "this is a demo ref file");

    printf("Datele au fost copiate cu succes din %s în %s!\n", fisier_in, fisier_out);

   
    fclose(fin);
    fclose(fout);

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
//  Arbore Binare de Căutare (BST),  
// acest arbore oferă o ordonare crescătoare la parcurgerea SRD.( stanga radacina dreapta ) 

/*
struct Ferma {
    char* denumire;
    int nrAnimale;
};

struct nod {
    struct Ferma info;
    struct nod* st;
    struct nod* dr;
};

struct Ferma initFerma(const char* denumire, const float nrAnimale) {
    struct Ferma f;
    f.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
    strcpy(f.denumire, denumire);
    f.nrAnimale = nrAnimale;
    return f;
}


void afisareFerma(struct Ferma f) {
    printf("Fermaul '%s' are nrAnimale %d \n", f.denumire, f.nrAnimale);
}


struct Ferma citireOFermaDinFisier(FILE* fisier)
{
    struct Ferma f;
    char buffer[256];


    fgets(buffer, 100, fisier);
    char* aux;

    aux = strtok(buffer, ",\n");
    f.denumire = malloc(strlen(aux) + 1);
    strcpy(f.denumire, aux);

    aux = strtok(NULL, ",\n");
    f.nrAnimale = atoi(aux);

    return f;
}

struct nod* inserareInArbore(struct nod* root, struct Ferma f) {
    if (root) {
        if (f.nrAnimale < root->info.nrAnimale) {
            root->st = inserareInArbore(root->st, f);
        }
        else if (f.nrAnimale > root->info.nrAnimale) {
            root->dr = inserareInArbore(root->dr, f);
        }
        return root;
    }
    else {
        struct nod* nou = (struct nod*)malloc(sizeof(struct nod));

        nou->info = f;
        nou->st = NULL;
        nou->dr = NULL;
        return nou;
    }
}

void citireFermeDinFisierSiInserareInArbore(const char* numeFisier, struct nod** root) {
    FILE* fisier = fopen(numeFisier, "r");

    while (!feof(fisier)) {
        struct Ferma f = citireOFermaDinFisier(fisier);

        *root = inserareInArbore(*root, f);


    }

    fclose(fisier);
}


void afisareSRD(struct nod* root) {
    if (root) {
        afisareSRD(root->st);
        afisareFerma(root->info);
        afisareSRD(root->dr);
    }
}

struct Ferma cautareFermaDupaPret(struct nod* root, float nrAnimale) {
    if (root) {
        if (root->info.nrAnimale > nrAnimale) {
            return cautareFermaDupaPret(root->st, nrAnimale);
        }
        else if (root->info.nrAnimale < nrAnimale) {
            return cautareFermaDupaPret(root->dr, nrAnimale);
        }
        else {
            return initFerma(root->info.denumire, root->info.nrAnimale);
        }
    }
    return initFerma("", -1);
}

void stergereArbore(struct nod** root) {
    if (*root) {
        stergereArbore(&(*root)->st);
        stergereArbore(&(*root)->dr);
        free((*root)->info.denumire);
        free(*root);
        *root = NULL;
    }
}

int inaltimeArbore(struct nod* root) {
    if (root) {
        return 1 + (inaltimeArbore(root->st) > inaltimeArbore(root->dr) ? inaltimeArbore(root->st) : inaltimeArbore(root->dr));
    }
    return 0;
}




int main() {
    struct nod* root = NULL;
   // root = inserareInArbore(root, initFerma("Avatar", 35));
  //  root = inserareInArbore(root, initFerma("Titanic", 30));
   // root = inserareInArbore(root, initFerma("Inception", 40));
  //  root = inserareInArbore(root, initFerma("Interstellar", 45));
   // root = inserareInArbore(root, initFerma("Joker", 25));
    
    citireFermeDinFisierSiInserareInArbore("Ferme.txt", &root);

    printf("Arborele de Fermae in ordine SRD:\n");
    afisareSRD(root);


    printf("Inaltimea arborelui: %d\n", inaltimeArbore(root));
    struct Ferma f = cautareFermaDupaPret(root, 40);

    printf("\nFerma cautata:\n");
    afisareFerma(f);

    stergereArbore(&root);
    return 0;
}



*/
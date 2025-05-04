#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//citire din fisier si incarcare in lista simpla inlantuita 
// si apoi selectare elemente din list acu nrAnimale > 13
struct Ferma {
    char* denumire;
    int nrAnimale;
};

/*
struct nod {
    struct Ferma info;
    struct nod* next;
};

void afisareFerma(struct Ferma f) {
    printf("Denumire ferma: %s\n", f.denumire);
    printf("Numar de animale: %d\n", f.nrAnimale);
}

struct nod* initNod(struct Ferma info, struct nod* next) {
    struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
    nou->info = info;
    nou->next = next;
    return nou;
}

struct nod* inserareNodNouLaSfarsitulListei(struct nod* cap, struct Ferma f) {
    struct nod* nou = initNod(f, NULL);
    if (cap) {
        struct nod* temp = cap;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = nou;
    }
    else {
        cap = nou;
    }
    return cap;
}

struct Ferma citireOFermaDinFisier(FILE* fisier) {
    struct Ferma f;
    char buffer[256];
    f.denumire = NULL;
    f.nrAnimale = 0;

    if (fgets(buffer, sizeof(buffer), fisier)) {
        char* aux = strtok(buffer, ",\n");
        if (aux) {
            f.denumire = (char*)malloc(strlen(aux) + 1);
            strcpy(f.denumire, aux);
        }

        aux = strtok(NULL, ",\n");
        if (aux) {
            f.nrAnimale = atoi(aux);
        }
    }

    return f;
}

void citireFermeDinFisierSiInserareInLista(const char* numeFisier, struct nod** cap, int dimensiune) {
    FILE* fisier = fopen(numeFisier, "r");
    int contor = 0;
    while (contor < dimensiune && !feof(fisier)) {
        struct Ferma f = citireOFermaDinFisier(fisier);
        
            *cap = inserareNodNouLaSfarsitulListei(*cap, f);
            contor++;
        
    }

    fclose(fisier);
}

void afisareListaFerme(struct nod* cap) {
    while (cap) {
        afisareFerma(cap->info);
        cap = cap->next;
    }
}

struct nod* stergereLista(struct nod* cap) {
    while (cap) {
        struct nod* aux = cap;
        cap = cap->next;
        free(aux->info.denumire);
        free(aux);
    }
    return NULL;
}

void afisareFermeCuPutineAnimale(struct nod* cap, int prag) {
    printf("\nFerme cu număr de animale mai mic decât %d:\n", prag);
    while (cap) {
        if (cap->info.nrAnimale < prag) {
            afisareFerma(cap->info);
        }
        cap = cap->next;
    }
}

int main() {
    struct nod* cap = NULL;
    citireFermeDinFisierSiInserareInLista("Ferme.txt", &cap, 5);

    printf("Afisare lista:\n");
    afisareListaFerme(cap);
    
    printf("Afiseaza doar elementele din lista cu nrAnimale <13:\n ");
    afisareFermeCuPutineAnimale(cap, 13);

    cap = stergereLista(cap); // Eliberăm memoria
    return 0;
}
*/
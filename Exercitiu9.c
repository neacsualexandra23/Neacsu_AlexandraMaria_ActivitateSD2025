#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//citire din fisier si incarcare in lista dubla inlantuita 

// Structura de bază
struct Ferma {
    char* denumire;
    int nrAnimale;
};

// Funcții de lucru cu o singură fermă
/*
void afisareFerma(struct Ferma f) {
    printf("Ferma: %s\n", f.denumire);
    printf("Numarul de animale este: %d\n", f.nrAnimale);
}

void eliberareFerma(struct Ferma f) {
    free(f.denumire);
}

// Nod pentru lista dublu înlănțuită
struct nod {
    struct Ferma info;
    struct nod* next;
    struct nod* prev;
};

// Lista dublă
struct listaDubla {
    struct nod* first;
    struct nod* last;
    int nrNoduri;
};

// Citirea unei ferme din fișier
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

// Inserare în lista dublă la final
void inserareOFermaInListaDublaLaSfarsit(struct listaDubla* lista, struct Ferma f) {
    struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
    nou->info = f;
    nou->next = NULL;
    nou->prev = lista->last;

    if (lista->last) {
        lista->last->next = nou;
    }
    else {
        lista->first = nou;
    }

    lista->last = nou;
    lista->nrNoduri++;
}

// Afișare lista dubla de la început spre sfarsit
void afisareListaFermeDeLaInceput(struct listaDubla lista) {
    struct nod* p = lista.first;
    while (p) {
        afisareFerma(p->info);
        p = p->next;
    }
}

// Afișare lista de la sfârșit
void afisareListaFermeDeLaSfarsit(struct listaDubla lista) {
    struct nod* p = lista.last;
    while (p) {
        afisareFerma(p->info);
        p = p->prev;
    }
}

// Citire ferme din fișier și construire listă
struct listaDubla citireFermeDinFisierSiInserareInLista(char* numeFisier) {
    FILE* fisier = fopen(numeFisier, "r");
    struct listaDubla lista = { NULL, NULL, 0 };

     while (!feof(fisier)) {
        struct Ferma f = citireOFermaDinFisier(fisier);
        inserareOFermaInListaDublaLaSfarsit(&lista, f);
       
    }

    fclose(fisier);
    return lista;
}

// Eliberare memorie
void eliberareLista(struct listaDubla* lista) {
    struct nod* p = lista->first;
    while (p) {
        struct nod* temp = p;
        p = p->next;
        eliberareFerma(temp->info);
        free(temp);
    }
    lista->first = NULL;
    lista->last = NULL;
    lista->nrNoduri = 0;
}

// Funcția principală
int main() {
  

    printf("\nCitire lista din fisier:\n");
    struct listaDubla lista = citireFermeDinFisierSiInserareInLista("ferme.txt");

    printf("\nAfisare lista de la inceput:\n");
    afisareListaFermeDeLaInceput(lista);

    printf("\nAfisare lista de la sfarsit:\n");
    afisareListaFermeDeLaSfarsit(lista);

    eliberareLista(&lista);

    return 0;
}
*/
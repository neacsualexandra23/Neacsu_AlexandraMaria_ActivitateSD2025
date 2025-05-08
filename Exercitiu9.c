#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//citire din fisier si incarcare in lista dubla inlantuita 

/*
struct Ferma {
    char* denumire;
    int nrAnimale;
};



void afisareFerma(struct Ferma f) {
    printf("Ferma: %s\n", f.denumire);
    printf("Numarul de animale este: %d\n", f.nrAnimale);
}

void eliberareFerma(struct Ferma f) {
    free(f.denumire);
}


struct nod {
    struct Ferma info;
    struct nod* next;
    struct nod* prev;
};


struct listaDubla {
    struct nod* first;
    struct nod* last;
    int nrNoduri;
};

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


void afisareListaFermeDeLaInceput(struct listaDubla lista) {
    struct nod* p = lista.first;
    while (p) {
        afisareFerma(p->info);
        p = p->next;
    }
}


void afisareListaFermeDeLaSfarsit(struct listaDubla lista) {
    struct nod* p = lista.last;
    while (p) {
        afisareFerma(p->info);
        p = p->prev;
    }
}


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

struct Ferma {
    char* denumire;
    int nrAnimale;
};



void afisareFerma(struct Ferma f) {
    printf("Ferma: %s\n", f.denumire);
    printf("Numarul de animale este: %d\n", f.nrAnimale);
}

void eliberareFerma(struct Ferma f) {
    free(f.denumire);
}


struct nod {
    struct Ferma info;
    struct nod* next;
    struct nod* prev;
};


struct listaDubla {
    struct nod* first;
    struct nod* last;
    int nrNoduri;
};
struct Ferma initFerma(char* denumire, int nrAnimale) {
    struct Ferma f;
    f.denumire = (char*)malloc((strlen(denumire) + 1));
    strcpy(f.denumire, denumire);
    f.nrAnimale = nrAnimale;
    return f;
}

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


void afisareListaFermeDeLaInceput(struct listaDubla lista) {
    struct nod* p = lista.first;
    while (p) {
        afisareFerma(p->info);
        p = p->next;
    }
}

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

int main() {


    printf("\nCreare in main de lista dubla din 3 ferme:\n");
    struct listaDubla lista = { NULL, NULL, 0 };

    struct Ferma f1, f2, f3;
    f1 = initFerma("ferma1", 112);
    f2 = initFerma("ferma2", 233);
    f3 = initFerma("ferme3", 136);

    inserareOFermaInListaDublaLaSfarsit(&lista, f1);
    inserareOFermaInListaDublaLaSfarsit(&lista, f2);
    inserareOFermaInListaDublaLaSfarsit(&lista, f3);

    printf("\nAfisare lista de la inceput:\n");
    afisareListaFermeDeLaInceput(lista);

 
    eliberareLista(&lista);

    return 0;
}
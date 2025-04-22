// Liste dublu inlantuite 
// 
#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Tara {
    char* nume;
    int nrLocuitori;
    float suprafata;
};

struct nod {
    struct Tara informatie;
    struct nod* urmator;
    struct nod* precedent;
};

struct Tara initializareTara(const char* nume, int nrLocuitori, float suprafata) {
    struct Tara t;
    t.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
    strcpy(t.nume, nume);
    t.nrLocuitori = nrLocuitori;
    t.suprafata = suprafata;
    return t;
}

struct nod* initializareNod(struct Tara info, struct nod* next, struct nod* prev) {
    struct nod* nodNou = (struct nod*)malloc(sizeof(struct nod));
    nodNou->informatie = info;
    nodNou->urmator = next;
    nodNou->precedent = prev;

    return nodNou;
}

struct ListaDubluInlantuita {
    struct nod* primNod;
    struct nod* ultimNod;
};

struct ListaDubluInlantuita inserareInceput(struct ListaDubluInlantuita lista, struct Tara tara) {
    struct nod* nodNou = initializareNod(tara, NULL, NULL);
    if (lista.primNod == NULL) {
        lista.primNod = nodNou;
        lista.ultimNod = nodNou;
    }
    else {
        nodNou->urmator = lista.primNod;
        lista.primNod->precedent = nodNou;
        lista.primNod = nodNou;
    }
    return lista;
}
struct ListaDubluInlantuita inserareSfarsit(struct ListaDubluInlantuita lista, struct Tara tara) {
    struct nod* nodNou = initializareNod(tara, NULL, NULL);
    if (lista.ultimNod == NULL) {
        lista.primNod = nodNou;
        lista.ultimNod = nodNou;
    }
    else {
        nodNou->precedent = lista.ultimNod;
        lista.ultimNod->urmator = nodNou;
        lista.ultimNod = nodNou;
    }
    return lista;
}

struct ListaDubluInlantuita stergereListaDubla(struct ListaDubluInlantuita lista) {

    while (lista.primNod) {
        struct nod* nodTemporar = lista.primNod;
        free(lista.primNod->informatie.nume);

        lista.primNod = lista.primNod->urmator;
        free(nodTemporar);
    }
    lista.primNod = NULL;
    lista.ultimNod = NULL;
    return lista;
}

void afisareTara(struct Tara t) {
    printf("Tara %s are %d locuitori si o suprafata de %5.2f.\n", t.nume, t.nrLocuitori, t.suprafata);
}

void afisareLista(struct ListaDubluInlantuita lista) {
    while (lista.primNod) {
        afisareTara(lista.primNod->informatie);
        lista.primNod = lista.primNod->urmator;
    }
}

struct Tara extragereDinListaDupaNume(struct ListaDubluInlantuita lista, const char* nume) {
    while (lista.primNod && strcmp(lista.primNod->informatie.nume, nume) != 0) {
        lista.primNod = lista.primNod->urmator;
    }
    if (lista.primNod) {
        struct Tara t = lista.primNod->informatie;
        if (lista.primNod->precedent) {
            lista.primNod->precedent->urmator = lista.primNod->urmator;
            lista.primNod->urmator->precedent = lista.primNod->precedent;
            free(lista.primNod);
        }
        else {
            struct nod* temp = lista.primNod;
            lista.primNod = lista.primNod->urmator;
            free(temp);
        }
        return t;
    }
    else {
        return initializareTara("", 0, 0);
    }
}
void main() {
    struct ListaDubluInlantuita lista;
    lista.primNod = lista.ultimNod = NULL;
    lista = inserareSfarsit(lista, initializareTara("Ungaria", 5000, 300));
    lista = inserareSfarsit(lista, initializareTara("Bulgaria", 3000, 200));
    lista = inserareSfarsit(lista, initializareTara("Serbia", 2000, 100));

    afisareLista(lista);

    afisareTara(extragereDinListaDupaNume(lista, "Ungaria"));
    printf("\n");
    afisareLista(lista);
    lista = stergereListaDubla(lista);
}
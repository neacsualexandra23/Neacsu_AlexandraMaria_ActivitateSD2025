#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
/*
struct Ferma {
	char* denumire;
	int nrAnimale;
};
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

void EliberareMemorie(struct Ferma f) {
	free(f.denumire);
}

void afisareFerma(struct Ferma f) {

	printf("Denumirea este: %d \n", f.denumire);
	printf("Numarul de animale este: %d \n", f.nrAnimale);
}

struct Ferma citireOFermaDinFisier(FILE* fisier) {
	struct Ferma f;
	char buffer[256];
	fgets(buffer, 100, fisier);
	char* aux;
	aux = strtok(buffer, ",\n");
	f.denumire = (char*)malloc(strlen(aux) + 1);
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

void afisareListaDublaDeLaInceput(struct listaDubla lista) {
	struct nod* p = lista.first;
	while (p) {
		afisareFerme(p->info);
		p = p->next;

	}
}
void afisareListaDublaDeLaSfarsit(struct listaDubla lista) {
	struct nod* p = lista.last;
	while (p) {
		afisareFerma(p->info);
		p = p->prev;
	}
}

struct listaDubla citireFermeDinFisierSiInserareInLista(char* numeFisier) {
	FILE* fisier = fopen(numeFisier, "r");
	struct listaDubla lista = { NULL,NULL,0 };
	while (!feof(fisier)) {
		struct Ferma f = citireOFermaDinFisier(fisier);
		inserareOFermaInListaDublaLaSfarsit(&lista, f);
	}
	fclose(fisier);
	return lista;
}

void EliberareMemorie(struct listaDubla* lista) {

}

*/
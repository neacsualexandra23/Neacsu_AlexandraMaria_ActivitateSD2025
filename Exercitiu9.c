#define _CRT_SECUR_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
// citire Ferme din fisier si incarcarea lor in lista dublu inlantuita 
// si apoi afisare lista de la cap la coada si invers

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

void afisareFerma(struct Ferma f) {
	printf("Ferma: %s \n", f.denumire);
	printf("Numarul de animale este: %d \n", f.nrAnimale);
}
void EliberareMemorieFerma(struct Ferma f) {
	free(f.denumire);
}

struct Ferma citireOFermaDinFisier(FILE* fisier) {
	struct Ferma f;
	char* buffer[256];
	fgets(buffer, 100, fisier);

	char* aux;
	aux = strtok(buffer, ",\n");
	f.denumire = malloc(strlen(aux) + 1);
	strcpy(f.denumire, aux);

	aux = strtok(NULL, ",\n");
	f.nrAnimale = atoi(aux);
	return f;
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
		afisareMasina(p->info);
		p = p->prev;
	}
}
void inserareOFermaInListaDublaLaSfarsit(struct listaDubla* lista, struct Ferma f) {
	struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
	nou->info = f;
	nou->next = NULL;
	nou->prev = NULL;
	nou->prev = lista->last;

	if (lista->last != NULL) {
		lista->last->next = nou;
	}
	else {
		lista->first = nou;
	}
	lista->last = nou;
	lista->nrNoduri++;
}
struct listaDubla citireFermeDinFisierSiInserareInLista( char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	FILE* fisier = fopen(numeFisier, "r");
	struct listaDubla lista;
	lista.first = NULL;
	lista.last = NULL;
	lista.nrNoduri = 0;
	while (!feof(fisier)) {
		struct Ferma f = citireOFermaDinFisier(fisier);
		inserareOFermaInListaDublaLaSfarsit(&lista,f);
	}
	fclose(fisier);
	return lista;
}
void eliberareLista(struct listaDubla* lista) {
	struct nod* p = lista->first;
	while (p) {
		struct nod* temp = p;
		p = p->next;
		EliberareMemorieFerma(temp->info);
		free(temp);
	}
	lista->first = NULL;
	lista->last = NULL;
	lista->nrNoduri = 0;
}

int main() {
	struct listaDubla lista;
	lista = citireFermeDinFisierSiInserareInLista("ferme.txt");

	printf("Lista ferme de la inceput:\n");
	afisareListaFermeDeLaInceput(lista);
	printf("Lista ferme de la sfarsit:\n");
	afisareListaFermeDeLaSfarsit(lista);
	eliberareLista(&lista);
	return 0;
}
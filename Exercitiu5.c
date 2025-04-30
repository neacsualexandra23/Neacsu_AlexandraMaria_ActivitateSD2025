#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
/* Citire structuri din fisier si incarcarea lor intr-o ista*/
/*
struct Ferma {
	char* denumire;
	int nrAnimale;

};

struct nod {
	struct Ferma info;
	struct nod* next;
};

struct Ferma initFerma(char* denumire, int nrAnimale) {
	struct Ferma f;
	f.denumire = malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(f.denumire, denumire);
	f.nrAnimale = nrAnimale;
	return f;
}
void afisareFerma(struct Ferma f)
{
	printf("Denumirea animal: %s \n", f.denumire);
	printf("Numar de animale: %d \n", f.nrAnimale);
}
void eliberareMemorrie(struct Ferma f) {
	free(f.denumire);

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

struct nod* stergereLista(struct nod* cap) {
	while (cap) {
		struct nod* aux = cap;
		cap = cap->next;
		free(aux->info.denumire);
		free(aux);
	}
	return cap;
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

void citireFermeDinFisierSiInserareInLista(char* numeFisier, struct nod* cap, int dimensiune) {
	
	FILE* fisier = fopen(numeFisier, "r");
	int contor = 0;
	while (contor < dimensiune && !feof(fisier)) {
		struct Ferma f = citireOFermaDinFisier(fisier);

		//inserareOFermaInVector(f, vector, contor);
		inserareNodNouLaSfarsitulListei(cap, f);
		contor++;
	}
	fclose(fisier);
}
void afisareListaFerme(struct nod* cap) {
	while (cap) {
		afisareFerma(cap->info);
		cap = cap->next;
	}

	//for (; cap != NULL; cap = cap->next) {
	//	afisareFerma(cap->info);
	//}
}
struct nod* stergereLista(struct nod* cap) {
	while (cap) {
		struct nod* aux = cap;
		cap = cap->next;
		free(aux->info.denumire);
		free(aux);
	}
	return cap;
}

int main()
{
	
	struct Ferma f1;
	f1 = initFerma("Ferma1", 10);
	struct nod* cap = initNod(f1, NULL);
	citireFermeDinFisierSiInserareInLista("ferme.txt",cap, 5);
	
	afisareListaFerme(cap);

	stergereLista(cap);
}

*/
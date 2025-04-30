#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
/* Citire structuri din fisier si incarcarea lor intr-o lista*/
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

struct nod* initNod(struct Ferma info, struct nod* next){
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



int main() {
	struct Ferma f1 = initFerma("Ferma1", 10);
	afisareFerma(f1);
	eliberareMemorrie(f1);



	return 0;
}
*/
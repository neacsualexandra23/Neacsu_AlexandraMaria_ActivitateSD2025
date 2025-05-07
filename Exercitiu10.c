#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct Ferma{
	char* denumire;
	int nrAnimale;
};
/*
	struct nod {
		struct Ferma info;
		struct nod* next;
	};


	struct Ferma initFerma(char* denumire , int nrAnimale) {
		struct Ferma f;
		f.denumire = (char*)malloc(strlen(denumire) + 1);
		strcpy(f.denumire, denumire);
		f.nrAnimale = nrAnimale;

		return f;
	}

	

	void afisareFerma(struct Ferma f) {
		printf("Denumirea este: %s \n", f.denumire);
		printf("Numarul animalelor este: %d \n", f.nrAnimale);
	}

	struct nod* initNod(struct Ferma info, struct nod* next) {
		struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
		nou->info = info;
		nou->next = next;

		return nou;
	}

	struct nod* inserareFermaLaSfarsitulListei(struct nod* cap, struct Ferma f){
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

	void afisareLista(struct nod* cap){
		while (cap) {
			afisareFerma(cap->info);
				cap = cap->next;
		}
	}

	void eliberareMemorie(struct Ferma f) {
		free(f.denumire);
	}
	int main() {
		struct nod* cap = NULL;
		struct Ferma f,f2;
		f = initFerma("ferma1", 6);
		f2 = initFerma("ferma3",8);
		//afisareFerma(f);
		cap =inserareFermaLaSfarsitulListei(cap, f);
		cap= inserareFermaLaSfarsitulListei(cap, f2);

		afisareLista(cap);
		eliberareMemorie(f);
		eliberareMemorie(f2);
	}
	*/
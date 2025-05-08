#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

struct Ferma  {
	char* denumire;
	int nrAnimale;
};
/*
struct nod {
	struct Ferma info ;
	struct nod* next;
};

void afisareFerma(struct Ferma f){
	printf("denumirea: %s \n", f.denumire);
	printf("numarul animalelor este: %d \n", f.nrAnimale);
}

struct nod* initNod(struct Ferma info, struct nod* next) {
	struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
	nou->info = info;
	nou->next = next;
	return nou;
}
void EliberareMemorie(struct Ferma f) {
	free(f.denumire);
}

struct Ferma CitireOFermaDinFisier(FILE* fisier) {
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

struct nod* InserareNodNouLaSfarsitulListei(struct nod* cap, struct Ferma f) {
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

void CitireToateElementeleDinListasiInserareInFisier(char* numeFisier, struct nod** cap, int dimensiune) {
	FILE* fisier = fopen(numeFisier, "r");
	int contor = 0;
	while (contor < dimensiune && !feof(fisier) ){
		struct Ferma f = CitireOFermaDinFisier(fisier);
			*cap = InserareNodNouLaSfarsitulListei(*cap, f);
			contor++;
	}
	fclose(fisier);
}

void afisareLista(struct nod* cap) {
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
	printf("\n Fermele cu numar mic de animale: %d \n", prag);
	while (cap) {
		if (cap->info.nrAnimale < prag) {
			afisareFerma(cap->info);
		}
		cap = cap->next;
	}
}

int main() {
	struct nod* cap = NULL;
	CitireToateElementeleDinListasiInserareInFisier("Ferme.txt", &cap, 5);
	afisareLista(cap);
}

*/
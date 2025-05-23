#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Ferma {
	char* denumire;
	int nrAnimale;
};

struct nod {
	struct Ferma info;
	struct nod* st;
	struct nod* dr;
};

void afisareFerma(struct Ferma f) {
	printf("Denumirea este: %s \n", f.denumire);
	printf("Numarul animalelor este: %d \n", f.nrAnimale);
}

struct Ferma initFerma(char* denumire, int nrAnimale) {
	struct Ferma f;
	f.denumire = (char*)malloc(strlen(denumire) + 1);
	f.nrAnimale = nrAnimale;
	return f;
}

struct Ferma citireOFermaDinFisier(FILE* fisier) {
	struct Ferma f;
	char buffer[256];
	fgets(buffer, 100, fisier);
	char* aux;
	aux = strtok(buffer, ",\n");
	f.denumire = (char*)malloc(strlen(aux) + 1);
	strcpy(f.denumire, aux);
	aux=strtok(NULL, ",\n");
	f.nrAnimale = atoi(aux);
	return f;
}

struct nod* inserareInArbore(struct nod* root, struct Ferma f) {
	if (root) {
		if (f.nrAnimale < root->info.nrAnimale) 
			root->st = inserareInArbore(root->st, f);
		
		else if (f.nrAnimale > root->info.nrAnimale)
	
			root->dr = inserareInArbore(root->dr, f);
		
		return root;
	}
		else {
			struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
			nou->info = f;
			nou->st = NULL;
			nou->dr = NULL;
			return nou;
		}
	}

void citireToateFermeleDinFisierSiInserareInArbore(char* numeFisier, struct nod** root) {
	FILE* fisier = fopen(numeFisier, "r");
	while (!feof(fisier)) {
		struct Ferma f = citireOFermaDinFisier(fisier);
		*root = inserareInArbore(*root, f);
	}
	fclose(fisier);

}

struct nod* afisareSRD(struct nod* root) {
	if (root) {
		afisareSRD(root->st);
		afisareFerma(root->info);
		afisareSRD(root->dr);
	}
}

int main() {
	struct nod* root = NULL;
	citireToateFermeleDinFisierSiInserareInArbore("Ferme.txt", &root);
	afisareSRD(root);
}
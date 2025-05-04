#define _CRT_SECUR_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct Ferma {
	char* denumire;
	int nrAnimale;
	
};
/*
struct Ferma afisareFerma(struct Ferma f) {
	printf("Ferma: %s \n", f.denumire);
	printf("Numarul de animale este: %d \n", f.nrAnimale);
}

void EliberareMemorieFerma(struct Ferma f) {
	free(f.denumire);
}

//Citire ferme din fisier si incarcarea lor intr-un vector

struct Ferma CitireOFermaDinFisier(FILE* fisier ) {
	struct Ferma f;
	char* buffer[256];
	fgets(buffer, 100, fisier);
	
	char* aux;
	aux = strtok(buffer,",\n");
	f.denumire = malloc(strlen(aux) + 1);
	strcpy(f.denumire, aux);

	aux = strtok(NULL, ",\n");
	f.nrAnimale = atoi(aux);

	
	return f;
}

void inserareOFermaInVector(struct Ferma** vector, struct Ferma f, int index) {
	(*vector)[index] = f;
}

void CitireToateFermeleDinFisier(char* numeFisier, struct Ferma** vector, int dimensiune) {
	*vector = (struct Ferma*)malloc(sizeof(struct Ferma*) * dimensiune);
	FILE* fisier = fopen(numeFisier, "r");
	int contor = 0;
		while (contor < dimensiune && !feof(fisier)) {
			struct Ferma f = CitireOFermaDinFisier(fisier);
			inserareOFermaInVector(vector, f, contor);
			contor++;
		}
	fclose(fisier);
}

void afisareElementeVector(struct Ferma* vector, int dimensiune) {
	for (int i = 0;i < dimensiune;i++) {
		afisareFerma(vector[i]);
	}
}

int main() {
	struct Ferma* vector;
	CitireToateFermeleDinFisier("Ferme.txt", &vector, 5);
	afisareElementeVector(vector,5);
}

*/
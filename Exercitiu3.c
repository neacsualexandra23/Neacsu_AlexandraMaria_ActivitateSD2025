/*  #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
Citire structuri din fisier si incarcarea lor intr-un vector

struct Ferma {
	char* denumire;
	int nrAnimale;

};

void afisareFerma(struct Ferma f)
{
	printf("Denumirea animal: %s \n", f.denumire);
	printf("Numar de animale: %d \n", f.nrAnimale);
}

struct Ferma initFerma(char* denumire, int nrAnimale) {
	struct Ferma f;
	f.denumire = malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(f.denumire, denumire);
	f.nrAnimale = nrAnimale;

	return f;

}

void EliberareMemorie(struct Ferma f) {
	free(f.denumire);
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
void inserareOFermaInVector(struct Ferma f, struct Ferma** vector, int index) {
	(*vector)[index] = f;
}

void citireFermeDinFisierSiInserareInVector(char* numeFisier, struct Ferma** vector, int dimensiune) {
	*vector = (struct Ferma*)malloc(sizeof(struct Ferma) * dimensiune);
	FILE* fisier = fopen(numeFisier, "r");
	int contor = 0;
	while (contor < dimensiune && !feof(fisier)) {
		struct Ferma f = citireOFermaDinFisier(fisier);

		inserareOFermaInVector(f, vector, contor);
		contor++;
	}
	fclose(fisier);
}

void AfisareElementeVector(struct Ferma* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++)
	{
		afisareFerma(vector[i]);
	}
}


int main()
{


	struct Ferma* vectorFerme;
	//vectorFerme = malloc(sizeof(struct Ferma) * 5);
	citireFermeDinFisierSiInserareInVector("ferme.txt", &vectorFerme, 5);
	AfisareElementeVector(vectorFerme, 5);


}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


struct Ferma {
	char* denumire;
	int nrAnimale;
};

struct Ferma initFerma(char* denumire, int nrAnimale) {
	struct Ferma f;
	f.denumire = (char*)malloc((strlen(denumire) + 1));
	strcpy(f.denumire, denumire);
	f.nrAnimale = nrAnimale;
	return f;
}

void afisareFerma(struct Ferma f) {
	printf("Denumirea fermei: %s \n", f.denumire);
	printf("Numar de animale: %d \n", f.nrAnimale);
}

void EliberareMemorie(struct Ferma f) {
	free(f.denumire);
}

void inserareOFermaInVector(struct Ferma f, struct Ferma** vector, int index) {
	(*vector)[index] = f;
}

void AfisareElementeVector(struct Ferma* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		afisareFerma(vector[i]);
	}
}

void EliberareVector(struct Ferma* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		EliberareMemorie(vector[i]);
	}
	free(vector);
}

int main() {
	
	struct Ferma* vectorFerme;
	vectorFerme = (struct Ferma*)malloc(sizeof(struct Ferma)*3);

	struct Ferma f1, f2, f3;
	f1 = initFerma("ferma1", 10);
	f2 = initFerma("ferma2", 20);
	f3 = initFerma("ferme3", 16);

	inserareOFermaInVector(f1, &vectorFerme, 0);
	inserareOFermaInVector(f2, &vectorFerme, 1);
	inserareOFermaInVector(f3, &vectorFerme, 2); 

	AfisareElementeVector(vectorFerme, 3);

	// Eliberare memorie
	EliberareVector(vectorFerme, 3);

	return 0;
}




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


struct Ferma {
	char* denumire;
	int nrAnimale;
};

struct Ferma initFerma(char* denumire, int nrAnimale) {
	struct Ferma f;
	f.denumire = (char*)malloc((strlen(denumire) + 1));
	strcpy(f.denumire, denumire);
	f.nrAnimale = nrAnimale;
	return f;
}

void afisareFerma(struct Ferma f) {
	printf("Denumirea fermei: %s \n", f.denumire);
	printf("Numar de animale: %d \n", f.nrAnimale);
}

void EliberareMemorie(struct Ferma f) {
	free(f.denumire);
}

void inserareOFermaInVector(struct Ferma f, struct Ferma** vector, int index) {
	(*vector)[index] = f;
}

void AfisareElementeVector(struct Ferma* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		afisareFerma(vector[i]);
	}
}

void EliberareVector(struct Ferma* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		EliberareMemorie(vector[i]);
	}
	free(vector);
}

int main() {

	struct Ferma* vectorFerme;
	vectorFerme = (struct Ferma*)malloc(sizeof(struct Ferma) * 3);

	struct Ferma f1, f2, f3;
	f1 = initFerma("ferma1", 10);
	f2 = initFerma("ferma2", 20);
	f3 = initFerma("ferme3", 16);

	inserareOFermaInVector(f1, &vectorFerme, 0);
	inserareOFermaInVector(f2, &vectorFerme, 1);
	inserareOFermaInVector(f3, &vectorFerme, 2);

	AfisareElementeVector(vectorFerme, 3);

	//Eliberare memorie
	EliberareVector(vectorFerme, 3);

	return 0;
}
*/
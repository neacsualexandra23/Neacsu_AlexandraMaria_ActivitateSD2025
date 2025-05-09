#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

struct Avion {
	char* denumire;
	int nrLocuri;
	int cod;
};

void afisareAvion(struct Avion f) {
	printf("denumirea este: %s \n", f.denumire);
	printf("numarul locurilor este: %d \n", f.nrLocuri);
	printf("codul este: %d \n", f.cod);
}

void eliberareMemorieAvion(struct Avion f) {
	free(f.denumire);
}
void inserareOAvionVector(struct Avion f, struct Avion** vector, int index) {
	(*vector)[index] = f;
}

struct Avion citesteOAvionDinFisier(FILE* fisier) {
	struct Avion f;
	char buffer[256];
	fgets(buffer, 100, fisier);
	char* aux;
	aux = strtok(buffer, ",\n");
	f.denumire = (char*)malloc(strlen(aux) + 1);
	strcpy(f.denumire, aux);

	aux = strtok(NULL, ",\n");
	f.nrLocuri = atoi(aux);

	aux = strtok(NULL, ",\n");
	f.cod = atoi(aux);
	return f;
}
void citesteToateAvioaneleDinFisierSiInserareInVector(char* numeFisier, struct Avion** vector, int dimensiune) {
	FILE* fisier = fopen(numeFisier, "r");
	(*vector) = (struct Ferma*)malloc(sizeof(struct Ferma*)*dimensiune);
	int contor = 0;
	while (contor < dimensiune && !feof(fisier)) {
		struct Avion f = citesteOAvionDinFisier(fisier);
		inserareOAvionVector(f, vector, contor);
		contor++;
	}
	fclose(fisier);
}
void afisareVectorAvioane(struct Avion* vector, int dimensiune) {
	for (int i = 0;i < dimensiune;i++)
		afisareAvion(vector[i]);
}

int main() {
	struct Avion* vectorAvioane;
	citesteToateAvioaneleDinFisierSiInserareInVector("Avioane.txt", &vectorAvioane, 5);
	afisareVectorAvioane(vectorAvioane, 5);
}
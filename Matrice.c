#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#include<stdbool.h>

struct Cinema {
	char* denumire;
	int nrSali;
	int NrIncasari;
	float* Incasari;
};
struct Cinema initCinema(const char* denumire, int nrSali, int NrIncasari, const float* Incasari) {
	struct Cinema c;
	int i;

	c.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy_s(c.denumire, strlen(denumire) + 1, denumire);


	c.nrSali = nrSali;
	c.NrIncasari = NrIncasari;
	c.Incasari = (float*)malloc(sizeof(Incasari) * sizeof(float));
	for (i = 0; i < NrIncasari; i++) {
		c.Incasari[i] = Incasari[i];
	}

	return c;
}
void afisareCinema(struct Cinema c) {


	printf("Denumire: %s\n", c.denumire);
	printf("Numar sali: %d\n", c.nrSali);
	printf("Numar incasari: %d\n", c.NrIncasari);

	printf("Incasari pe cinema:\n");
	for (int i = 0; i < c.NrIncasari; i++) {
		printf("  Incasare %d: %.2f \n", i + 1, c.Incasari[i]);
	}
}

struct Cinema citireCinemaDinFisier(FILE* file) {
	char buffer[256];
	struct Cinema c1;

	fgets(buffer, 100, file);
	char* aux;

	aux = strtok(buffer, ",\n");
	c1.denumire = malloc(strlen(aux) + 1);
	strcpy_s(c1.denumire, strlen(aux) + 1, aux);
	//printf("Denumire: %s\n", c1.denumire);

	aux = strtok(NULL, ",\n");
	c1.nrSali = atoi(aux);
	//printf("Numar sali: %d\n", c1.nrSali);

	aux = strtok(NULL, ",\n");
	c1.NrIncasari = atoi(aux);
	//printf("Numar incasari: %d\n", c1.NrIncasari);

	int i;

	c1.Incasari = malloc(c1.NrIncasari * sizeof(float));
	for (i = 0; i < c1.NrIncasari; i++) {
		aux = strtok(NULL, ",\n");
		c1.Incasari[i] = atof(aux);
		//printf("Incasare %d: %.2f\n", i + 1, c1.Incasari[i]);


	}

	return c1;
}
void inserareCinemaInVector(struct Cinema c, struct Cinema** vector, int index) {



	(*vector)[index].denumire = malloc(strlen(c.denumire) + 1);
	strcpy_s((*vector)[index].denumire, strlen(c.denumire) + 1, c.denumire);
	//printf("Denumire: %s\n", (*vector)[index].denumire);

	(*vector)[index].nrSali = c.nrSali;
	//printf("Numar sali: %d\n", (*vector)[index].nrSali);
	(*vector)[index].NrIncasari = c.NrIncasari;
	//printf("Numar incasari: %d\n", (*vector)[index].NrIncasari);

	(*vector)[index].Incasari = malloc(c.NrIncasari * sizeof(float));
	for (int i = 0; i < c.NrIncasari; i++) {
		(*vector)[index].Incasari[i] = c.Incasari[i];

	}

}
int main() {
	struct Cinema* vector = NULL;
	int nrElemente = 10; // presupunem 10 cinematografe în fișier
	//vector = (struct Cinema*)malloc(nrElemente * sizeof(struct Cinema));


	FILE* fisier = fopen("Cinematografe.txt", "r");
	if (!fisier) {
		printf("Eroare la deschiderea fisierului!\n");
		free(vector);
		return 1;
	}


	printf("\nAfisare vector:\n");

	citesteCinemaDinFisier(&vector, "Cinematografe.txt", nrElemente);
	afisareVector(vector, nrElemente);


	// Cleanup
	fclose(fisier);
	//dezalocareCinema(&p);
	dezalocareVector(&vector, &nrElemente);

	return 0;
}

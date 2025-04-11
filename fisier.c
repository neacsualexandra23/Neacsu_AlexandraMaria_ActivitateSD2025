#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#include<stdbool.h>
/*

//1.1 Definiti o structura de date care sa contina informatii despre un cinematograf.
// Alexandra Maria Neacsu
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
void dezalocareCinema(struct Cinema* c) {
	free(c->denumire);
	free(c->Incasari);
	c->nrSali = 0;
	c->NrIncasari = 0;
}

void afisareVector(struct Cinema* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareCinema(vector[i]);
		printf("\n");
	}
}

struct Cinema* copiazaPrimeleNElemente(struct Cinema* vector, int nrElemente, int nrElementeCopiate) {
	struct Cinema* v = NULL;
	if (nrElementeCopiate <= nrElemente) {
		v = (struct Cinema*)malloc(sizeof(struct Cinema) * nrElementeCopiate);
		for (int i = 0; i < nrElementeCopiate; i++) {
			v[i] = vector[i];
			v[i].denumire = (char*)malloc(strlen(vector[i].denumire) + 1);
			strcpy_s(v[i].denumire, strlen(vector[i].denumire) + 1, vector[i].denumire);
		}
	}
	return v;
}


void inserareCinemaInVector(struct Cinema c,struct Cinema** vector, int index) {

	

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

//3.1 Definiti o functie care sa aloce un vector de structuri de tip Cinema, 
// sa citeasca datele dintr-un fisier text si sa le afiseze pe ecran.
void citesteCinemaDinFisier(struct Cinema** vector, const char* numeFisier, int dimensiune) {
	*vector = malloc(sizeof(struct Cinema) * dimensiune);
	FILE* fisier = fopen(numeFisier, "r");
	int contor = 0;
	while (contor < dimensiune && !feof(fisier)) {
		struct Cinema p = citireCinemaDinFisier(fisier);

		inserareCinemaInVector(p, vector, contor);
		contor++;
	}
	fclose(fisier);
}
//3.2 Definiti o functie care sa salveze un obiect de tip Cinema intr-un fisier text.
void salveazaCinemaInFisier(struct Cinema c, const char* numeFisier) {
	FILE* f = fopen(numeFisier, "w"); // "a" = adaugă la final
	if (!f) {
		printf("Eroare la deschiderea fisierului %s\n", numeFisier);
		return;
	}

	// Scriem: denumire,nrSali,NrIncasari,Incasare1,Incasare2,...
	fprintf(f, "%s,%d,%d", c.denumire, c.nrSali, c.NrIncasari);

	for (int i = 0; i < c.NrIncasari; i++) {
		fprintf(f, ",%.2f", c.Incasari[i]);
	}

	fprintf(f, "\n"); // newline la final de obiect
	fclose(f);
}

//3.3 Scrieti o functie care va salva un vector de obiecte intr - un fisier text.
void salveazaVectorCinemaInFisier(struct Cinema* vector, int nrElemente, const char* numeFisier) {
	FILE* f = fopen(numeFisier, "w"); // "w" = scriere nouă (șterge ce era înainte)
	if (!f) {
		printf("Eroare la deschiderea fisierului %s\n", numeFisier);
		return;
	}

	for (int i = 0; i < nrElemente; i++) {
		fprintf(f, "%s,%d,%d", vector[i].denumire, vector[i].nrSali, vector[i].NrIncasari);

		for (int j = 0; j < vector[i].NrIncasari; j++) {
			fprintf(f, ",%.2f", vector[i].Incasari[j]);
		}

		fprintf(f, "\n"); // Trecem la linia următoare pentru următorul obiect
	}
	
void dezalocareVector(struct Cinema** vector, int* nrElemente) {
	for (int i = 0; i < *nrElemente; i++) {
		dezalocareCinema(&(*vector)[i]);
	}
	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
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


	// 3.2 Scrieti o functie care va salva un obiect intr-un fisier text
	
	float incasariExemplu[] = { 1000.5f, 2000.0f, 1500.25f };
	struct Cinema cc = initCinema("CinemaLux", 5, 3, incasariExemplu);
	salveazaCinemaInFisier(cc, "Cinematografe_salvate.txt");
	free(cc.denumire);
	free(cc.Incasari);

	// 3.3 Scrieti o functie care va salva un vector de obiecte intr-un fisier text
	//salveazaVectorCinemaInFisier(vector, nrElemente, "Cinematografe_salvate.txt");

	// Cleanup
	fclose(fisier);
	//dezalocareCinema(&p);
	dezalocareVector(&vector, &nrElemente);

	return 0;
}
*/
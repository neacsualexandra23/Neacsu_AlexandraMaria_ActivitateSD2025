#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#include<stdbool.h>
// vezi si matrice citite de la taastatura in Laborato03.c


struct Cinema {
	char* denumire;
	int nrSali;
	int NrIncasari;
	float* Incasari;
};
/*
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
void afisareVector(struct Cinema* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareCinema(vector[i]);
		printf("\n");
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
	//printf("\n Denumire: %s\n", c1.denumire);

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
		


	}

	return c1;
}


void inserareCinemaInVector(struct Cinema c, struct Cinema** vector, int index) {

	//printf("*hey: %s\n");

	(*vector)[index].denumire = malloc(strlen(c.denumire) + 1);
	strcpy_s((*vector)[index].denumire, strlen(c.denumire) + 1, c.denumire);
	//printf("*Denumire: %s\n", (*vector)[index].denumire);

	(*vector)[index].nrSali = c.nrSali;
	//printf("*Numar sali: %d\n", (*vector)[index].nrSali);
	(*vector)[index].NrIncasari = c.NrIncasari;
	//printf("*Numar incasari: %d\n", (*vector)[index].NrIncasari);

	(*vector)[index].Incasari = malloc(c.NrIncasari * sizeof(float));
	for (int i = 0; i < c.NrIncasari; i++) {
		(*vector)[index].Incasari[i] = c.Incasari[i];

	}

}

//3.1 Definiti o functie care sa aloce un vector de structuri de tip Cinema, 
// sa citeasca datele dintr-un fisier text si sa le afiseze pe ecran.
void citesteCinematografeDinFisier(struct Cinema** vector, const char* numeFisier, int dimensiune) {
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
// 4.2 Functie care sa copieze (deep copy) elementele din vector intr-o matrice alocată dinamic. 
// Asezarea in matrice pe linii a obiectelor o faceti dupa un criteriu aplicat unui atribut.
// Astfel veti obține mai multe clustere reprezentate de liniile matricei.

int gasesteIndexCategorie(int* categorii, int nrCategorii, int valoare) {
	for (int i = 0; i < nrCategorii; i++) {
		if (categorii[i] == valoare)
			return i;
	}
	return -1;
}
// Deep copy Cinema
struct Cinema deepCopyCinema(struct Cinema c) {
	struct Cinema copie;
	copie.denumire = malloc(strlen(c.denumire) + 1);
	strcpy_s(copie.denumire, strlen(c.denumire) + 1, c.denumire);

	copie.nrSali = c.nrSali;
	copie.NrIncasari = c.NrIncasari;
	copie.Incasari = malloc(c.NrIncasari * sizeof(float));
	for (int i = 0; i < c.NrIncasari; i++) {
		copie.Incasari[i] = c.Incasari[i];
	}
	return copie;
}
// 4.2: Copiere in matrice (grupare pe nrSali)
void copiereInMatricePeCriteriu(struct Cinema* vector, int nrElemente,
	struct Cinema*** matrice, int** vectorCategorii, int* nrCategorii, int** dimPeLinie)
{
	int* categorii = malloc(nrElemente * sizeof(int));
	int* dim = calloc(nrElemente, sizeof(int)); // nr elemente pe linie
	int totalCategorii = 0;

	// 1. Identificăm valorile unice de nrSali
	for (int i = 0; i < nrElemente; i++) {
		int index = gasesteIndexCategorie(categorii, totalCategorii, vector[i].nrSali);
		if (index == -1) {
			categorii[totalCategorii++] = vector[i].nrSali;
		}
	}

	// 2. Cautam cate elemente vor fi pe fiecare linie (grupare)
	for (int i = 0; i < nrElemente; i++) {
		int index = gasesteIndexCategorie(categorii, totalCategorii, vector[i].nrSali);
		dim[index]++;
	}

	// 3. Alocam matricea
	struct Cinema** tempMatrice = malloc(totalCategorii * sizeof(struct Cinema*));
	for (int i = 0; i < totalCategorii; i++) {
		tempMatrice[i] = malloc(dim[i] * sizeof(struct Cinema));
		dim[i] = 0; // resetăm pentru inserare
	}

	// 4. Inseram cu deep copy in matrice
	for (int i = 0; i < nrElemente; i++) {
		int index = gasesteIndexCategorie(categorii, totalCategorii, vector[i].nrSali);
		tempMatrice[index][dim[index]++] = deepCopyCinema(vector[i]);
	}

	// 5. Returnam rezultatele
	*matrice = tempMatrice;
	*vectorCategorii = categorii;
	*nrCategorii = totalCategorii;
	*dimPeLinie = dim;
}
void afisareMatriceCinema(struct Cinema** matrice, int nrCategorii, int* categorii, int* dimPeLinie) {
	for (int i = 0; i < nrCategorii; i++) {
		printf("Cluster %d - Cinematografe cu nrSali = %d:\n", i + 1, categorii[i]);
		for (int j = 0; j < dimPeLinie[i]; j++) {
			printf("  [%d,%d] -> ", i, j);
			afisareCinema(matrice[i][j]);
			printf("\n");
		}
		printf("====================================\n");
	}
}

// 4.3.Functie pentru mutarea liniile din matrice, astfel incat acestea sa fie sortate 
// dupa numarul de elemente de pe linie
void sorteazaLiniileMatricei(struct Cinema*** matrice, int* nrCategorii, int** categorii, int** dimPeLinie) {
	for (int i = 0; i < *nrCategorii - 1; i++) {
		for (int j = i + 1; j < *nrCategorii; j++) {
			if ((*dimPeLinie)[i] > (*dimPeLinie)[j]) {
				// schimba dimensiuni
				int tempDim = (*dimPeLinie)[i];
				(*dimPeLinie)[i] = (*dimPeLinie)[j];
				(*dimPeLinie)[j] = tempDim;

				// schimba categorii
				int tempCat = (*categorii)[i];
				(*categorii)[i] = (*categorii)[j];
				(*categorii)[j] = tempCat;

				// schimba liniile din matrice
				struct Cinema* tempLinie = (*matrice)[i];
				(*matrice)[i] = (*matrice)[j];
				(*matrice)[j] = tempLinie;
			}
		}
	}
}
/*
int main() {
	struct Cinema* vector = NULL;
	int nrElemente = 10; // presupunem 10 cinematografe în fișier
	//vector = (struct Cinema*)malloc(nrElemente * sizeof(struct Cinema));


	FILE* fisier = fopen("Cinematografe.txt", "r");
	if (!fisier) {
		printf("Eroare la deschiderea fisierului!\n");
	
		return 1;
	}
	
	

	//4.1 Citirea obiectelor dintr-un fișier și salvarea într-un vector.
	citesteCinematografeDinFisier(&vector, "Cinematografe.txt", nrElemente);
	printf( "\n\n---Afisare vector dupa ce citim din fisierul Cinematografe.txt  ---\n");
	printf( "\n\n================================================================  \n");
	afisareVector(vector, nrElemente);

	//4.2 alegem nrSali ca atribut de grupare pentru a copia elementele vectorului anterior intr-o matrice 

	struct Cinema** matrice = NULL;
	int* categorii = NULL;
	int* dimPeLinie = NULL;
	int nrCategorii = 0;
	fprintf(stdout, "\n\n---Afisare matrice dupa ce le grupam dupa atribut nrSali  ---\n");
	printf("\n\n================================================================  ---\n");

	copiereInMatricePeCriteriu(vector, nrElemente, &matrice, &categorii, &nrCategorii, &dimPeLinie);

	afisareMatriceCinema(matrice, nrCategorii, categorii, dimPeLinie);

	// 4.3.Functie pentru mutarea liniile din matrice, astfel incat acestea sa fie sortate 
	// dupa numarul de elemente de pe linie
	
	sorteazaLiniileMatricei(&matrice, &nrCategorii, &categorii, &dimPeLinie);

	printf("\n---Afisare matrice dupa sortare ---\n");
	afisareMatriceCinema(matrice, nrCategorii, categorii, dimPeLinie);
	// 5. Eliberare memorie
	for (int i = 0; i < nrElemente; i++) {
		free(vector[i].denumire);
		free(vector[i].Incasari);
	}
	free(vector);
	for (int i = 0; i < nrCategorii; i++) {
		for (int j = 0; j < dimPeLinie[i]; j++) {
			free(matrice[i][j].denumire);
			free(matrice[i][j].Incasari);
		}
		free(matrice[i]);
	}
	return 0;
}
*/
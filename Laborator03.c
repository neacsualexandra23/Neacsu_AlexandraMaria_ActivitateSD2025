#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#include<stdbool.h>
// lucrul cu matrici de structuri 
// matrice de structuri citite de la tastatura
// afisare matrice de structuri
// dezalocare matrice

/*
struct Bilet {
	int cod;
	float pretBilet;
	char* destinatie;
};

struct Bilet initializare(int c, float p, const char* den) {
	struct Bilet b;
	b.cod = c;
	b.pretBilet = p;
	b.destinatie = (char*)malloc(sizeof(char) * (strlen(den) + 1));
	strcpy(b.destinatie, den);
	return b;
}

void afisare(struct Bilet b)
{
	printf(" Codul:%d \n", b.cod);
	printf("Pret:%f \n", b.pretBilet);
	printf("Destinatie:%s ", b.destinatie);

}
struct Bilet citire()
{
	struct Bilet b1;
	char nume[10];

	scanf("%d", &b1.cod);
	scanf("%f", &b1.pretBilet);
	scanf("%s", nume);
	b1.destinatie = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy(b1.destinatie, nume);
	return b1;
}

struct Bilet** citire_masiv(int* nr_lini, int** col) {
	printf("\nIntrodu nr lini: ");
	scanf("%d", nr_lini);

	struct Bilet** b;
	b = (struct Bilet**)malloc(*nr_lini * sizeof(struct Bilet*));

	*col = (int*)malloc(sizeof(int) * (*nr_lini));

	for (int i = 0; i < *nr_lini; i++)
	{
		printf("Lungimea liniei %d", i + 1);
		scanf("%d", &(*col)[i]);
		b[i] = (struct Bilet*)malloc((*col)[i] * sizeof(struct Bilet));
		for (int j = 0; j < (*col)[i]; j++)
		{
			printf("Introdu biletul[%d][%d]: ", i + 1, j + 1);
			b[i][j] = citire();
		}
	}
	return b;
}

void afisareMatrice(struct Bilet** b, int nrLinii, int* nrColoane) {
	for (int i = 0; i < nrLinii; i++) {
		printf("Biletele de pe linia %d\n", i);
		for (int j = 0; j < nrColoane[i]; j++) {
			afisare(b[i][j]);
		}
	}
}

void afisareVector(struct Bilet* vector, int dim) {
	for (int i = 0; i < dim; i++) {
		afisare(vector[i]);
	}
}


void main()
{
	struct Bilet b1 = initializare(1, 99.77, "Malibu");
	afisare(b1);
	//Bilet b2 = citire();
	//afisare(b2);

	struct Bilet** matrice;
	int* nrColoane = NULL;
	int nrLinii = 0;

	matrice = citire_masiv(&nrLinii, &nrColoane);
	afisareMatrice(matrice, nrLinii, nrColoane);
	
	afisareVector(matrice[0], nrColoane[0]);
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane[i]; j++) {
			free(matrice[i][j].destinatie);
		}
		free(matrice[i]);
	}
	
	free(matrice);
	free(nrColoane);
	free(b1.destinatie);
	//free(b2.destinatie);
	
	
}
*/
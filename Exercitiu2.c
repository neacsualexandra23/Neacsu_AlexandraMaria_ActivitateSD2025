#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
/*
struct Cinema
{
	char* denumire;
	int nrSali;
	
};



struct Cinema initCinema( char* denumire, int nrSali, int nrIncasari,  float* incasari) {
	struct Cinema c;
	int i;

	c.denumire = malloc(sizeof(char*) * (strlen(denumire) + 1));
	strcpy(c.denumire, denumire);


	c.nrSali = nrSali;
	c.nrIncasari = nrIncasari;
	c.incasari = (float*)malloc(sizeof(incasari) * sizeof(float));
	for (i = 0; i < nrIncasari; i++) {
		c.incasari[i] = incasari[i];
	}

	return c;
}






void afisare(struct Cinema c) {
	printf("Denumirea cinematografului este:%s \n Numar sali:%d \n Numar incasari este:%d \n", c.denumire, c.nrSali, c.nrIncasari);
	for (int i = 0;i < c.nrIncasari;i++)
		printf("%f ", c.incasari[i]);
	printf("\n");
}

EliberareMemorie(struct Cinema c) {
	free(c.denumire);
	free(c.incasari);

}

void AfisareElementeleVectorului(struct Cinema* vectorCinematografe, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		afisare(vectorCinematografe[i]);
	}
}


void inserareUnCinemaInVector(struct Cinema c, struct Cinema** vector, int index) {

	(*vector)[index].denumire = malloc(strlen(c.denumire) + 1);
	strcpy((*vector)[index].denumire,  c.denumire);
	

	(*vector)[index].nrSali = c.nrSali;
	
	(*vector)[index].nrIncasari = c.nrIncasari;
	

	(*vector)[index].incasari = malloc(c.nrIncasari * sizeof(float));
	for (int i = 0; i < c.nrIncasari; i++) {
		(*vector)[index].incasari[i] = c.incasari[i];

	}

}
struct Cinema citireUnCinemaDinFisier(FILE* file) {
	char buffer[256];
	struct Cinema c;

	fgets(buffer, 100, file);
	char* aux;

	aux = strtok(buffer, ",\n");
	c.denumire = malloc(strlen(aux) + 1);
	strcpy(c.denumire,  aux);
	//printf("Denumire: %s\n", c1.denumire);

	aux = strtok(NULL, ",\n");
	c.nrSali = atoi(aux);
	//printf("Numar sali: %d\n", c1.nrSali);

	aux = strtok(NULL, ",\n");
	c.nrIncasari = atoi(aux);
	//printf("Numar incasari: %d\n", c1.NrIncasari);

	int i;

	c.incasari = malloc(c.nrIncasari * sizeof(float));
	for (i = 0; i < c.nrIncasari; i++) {
		aux = strtok(NULL, ",\n");
		c.incasari[i] = atof(aux);
		//printf("Incasare %d: %.2f\n", i + 1, c1.Incasari[i]);


	}

	return c;
}
void citesteCinematografeDinFisier(const char* numeFisier,  struct Cinema** vector,  int dimensiune) {
	*vector = (struct Cinema*)malloc(sizeof(struct Cinema) * dimensiune);
	FILE* fisier = fopen(numeFisier, "r");
	int contor = 0;
	while (contor < dimensiune && !feof(fisier)) {
		struct Cinema p = citireUnCinemaDinFisier(fisier);

		inserareUnCinemaInVector(p, vector, contor);
		contor++;
	}
	fclose(fisier);
}


int main()
{
	
	//2.1.Crearea unui vector in functia main, alocat dinamic cu cel puțin 5 obiecte de tipul structurii definite

	struct Cinema c1, c2, c3, c4, c5;
	float expVectorIncasari1[] = { 11.00f, 33.55f, 55.66f };
	float expVectorIncasari2[] = { 10.44f,11.45f,20.00f,50.56f };
	c1 = initCinema("CityCinema1", 5, 3, expVectorIncasari1);
	c2 = initCinema("CityCinema2", 20, 4, expVectorIncasari2);
	c3 = initCinema("CityCinema3", 100, 3, expVectorIncasari1);
	c4 = initCinema("CityCinema4", 50, 4, expVectorIncasari2);
	c5 = initCinema("CityCinema5", 50, 4, expVectorIncasari2);


	
	struct Cinema* vectorCinematografe;
	vectorCinematografe = (struct Cinema*)malloc(sizeof(struct Cinema*) * 5);
	
	vectorCinematografe[0] = c1;
	vectorCinematografe[1] = c2;
	vectorCinematografe[2] = c3;
	vectorCinematografe[3] = c4;
	vectorCinematografe[4] = c5;

	EliberareMemorie(c1);
	EliberareMemorie(c2);
	EliberareMemorie(c3);
	EliberareMemorie(c4);
	EliberareMemorie(c5);

	//AfisareElementeleVectorului(vectorCinematografe, 5);
	

	//3.1. Funcție pentru citirea obiectelor din fișier și salvarea într-un vector.
	struct Cinema* vectorCinematografe;
	vectorCinematografe = (struct Cinema*)malloc(sizeof(struct Cinema*) * 10);

	citesteCinematografeDinFisier("Cinematografe.txt" , &vectorCinematografe, 10);

	AfisareElementeleVectorului(vectorCinematografe, 10);




}
*/
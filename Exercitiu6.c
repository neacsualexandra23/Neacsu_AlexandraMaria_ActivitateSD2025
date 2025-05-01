#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct Cinema {
	char* denumire;
	int nrSali;
	int nrIncasari;
};

struct nod {
	struct Cinema info;
	struct nod* next;
};


struct Cinema  initCinema(char* denumire, int nrSali, int nrIncasari) {
	struct Cinema c;
	
	c.denumire = (char*)malloc(strlen(denumire) + 1);
	strcpy(c.denumire, denumire);

	c.nrSali = nrSali;
	c.nrIncasari = nrIncasari;
	

	return c;
}

struct nod* initNod(struct Cinema info, struct nod* next)
{
	struct nod* nodNou = malloc(sizeof(struct Cinema));
	nodNou->info = info;
	nodNou->next = next;
	return nodNou;
}

void afisarecinema(struct Cinema c) {
	printf("denumire cinema: %s \n", c.denumire);
	printf("nr sali este: %d \n", c.nrSali);
	printf("nr incasari este: %d \n", c.nrIncasari);
}

void afisareVector(struct Cinema* vector, int dimensiune) {
	for (int i = 0;i < dimensiune;i++)
		afisarecinema(vector[i]);
}

void eliberareMemorieCinema(struct Cinema c) {
	free(c.denumire);
}

void eliberareMemorieVector(struct Cinema* vector, int dimensiune) {
	for (int i = 0;i < dimensiune;i++)
		eliberareMemorieCinema(vector[i]);
}

int main() {
	struct Cinema c1,c2,c3;
	c1 = initCinema("City1",6,10);
	c2 = initCinema("City2", 4, 20);
	c3 = initCinema("City3", 10, 7);
	struct Cinema* vector;
	vector = (struct Cinema*)malloc(sizeof(struct Cinema)*3);
	vector[0] = c2;
	vector[1] = c1;
	vector[2] = c3;
	afisareVector(vector, 3);

	eliberareMemorieVector(vector, 3);
}
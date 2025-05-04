#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct Cinema {
	char* denumire;
	int nrSali;
	int nrIncasri;
};

/*
struct nod {
	struct Cinema info;
	struct nod* next;
	
};


struct Cinema initCinema(char* denumire, int nrSali, int nrIncasari) {
	struct Cinema c;
	c.denumire = (char*)malloc(strlen(denumire) + 1);
	strcpy(c.denumire, denumire);
	c.nrSali = nrSali;
	c.nrIncasri = nrIncasari;
	return c;
}

struct nod* initNod(struct Cinema info, struct nod* next) {
	struct nod* nou= (struct nod*)malloc(sizeof(struct nod));
	nou->info = info;
	nou->next = next;

	return nou;
}

void afisareCinema(struct Cinema c) {
	printf("Denumirea: %s \n", c.denumire);
	printf("Numar sali: %d \n", c.nrSali);
	printf("Numar incasari: %d \n", c.nrIncasri);
}

void afisareListaSimpla(struct nod* cap) {
	while (cap) {
		afisareCinema(cap->info);
		cap = cap->next;
	};
}

void eliberareCinema(struct Cinema c) {
	free(c.denumire);
}

struct nod* inserareInceput(struct nod* cap, struct Cinema c) {
	struct nod* nou = initNod(c, cap);
	return nou;
}

struct nod* inserareSfarsit(struct nod* cap, struct Cinema c) {
	struct nod* nou = initNod(c, NULL);
	if (cap) {
		struct nod* temp = cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;

	}
	else {
		cap = nou;
	}
	return cap;

}
void stergePozitie(struct nod** cap, int pozitie) {
	
	struct nod* temp = *cap;

	// Daca  stergem primul nod
	if (pozitie == 0) {
		*cap = temp->next;
		eliberareCinema(temp->info);
		free(temp);
		return;
	}

	int index = 0;
	struct nod* anterior = NULL;

	while (temp != NULL && index < pozitie) {
		anterior = temp;
		temp = temp->next;
		index++;
	}

	// temp este nodul de sters
	anterior->next = temp->next;
	eliberareCinema(temp->info);
	free(temp);
}

int main()
{
		struct Cinema c1, c2, c3;
		c1 = initCinema("city1", 5, 6);
		c2 = initCinema("city2", 4, 3);
		c3 = initCinema("city3", 7, 9);
		//afisareCinema(c1);
		//afisareCinema(c2);
		//afisareCinema(c3);


		
		struct nod* cap = NULL;
	
		//cap = inserareSfarsit(cap, c1);
		//cap = inserareSfarsit(cap, c2);
		//cap = inserareSfarsit(cap, c3);

		cap = inserareInceput(cap, c1);
		cap = inserareInceput(cap, c2);
		cap = inserareInceput(cap, c3);
		
		printf("Afisare lista: \n");
		afisareListaSimpla(cap);

		stergePozitie(&cap, 1);

		printf("======================  \n");

		printf("Afisare lista dupa stergere: \n");
		afisareListaSimpla(cap);
		




}
*/
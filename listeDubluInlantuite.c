#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Liste simplu inlantuite Tema 5

struct Cinema {
	char* denumire;
	int nrSali;
	int NrIncasari;
	float* Incasari;
};
/*
/struct nod {
	struct Cinema info;
	struct nod* next;
};

struct ListaDubluInlantuita {
	struct nod* primNod;
	struct nod* ultimNod;
};


struct Cinema initCinema(const char* denumire, int nrSali, int NrIncasari, const float* Incasari) {
	struct Cinema c;
	int i;

	c.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(c.denumire, denumire);


	c.nrSali = nrSali;
	c.NrIncasari = NrIncasari;
	c.Incasari = (float*)malloc(sizeof(Incasari) * sizeof(float));
	for (i = 0; i < NrIncasari; i++) {
		c.Incasari[i] = Incasari[i];
	}

	return c;
}
void dezalocare(struct Cinema* c) {
	free(c->denumire);
	(*c).denumire = NULL;
	free(c->Incasari);
	(*c).Incasari = NULL;
}
void afisareCinema(struct Cinema c) {
	int i;
	printf("Denumire: %s\n", c.denumire);
	printf("Numar Sali: %d\n", c.nrSali);
	printf("Numar Incasari: %d\n", c.NrIncasari);
	for (i = 0; i < c.NrIncasari; i++) {
		printf("Incasare[%d]: %.2f\n", i, c.Incasari[i]);
	}
}

struct nod* initNod(struct Tara info, struct nod* next, struct nod* prev) {
	struct nod* nodNou = (struct nod*)malloc(sizeof(struct nod));
	nodNou->informatie = info;
	nodNou->urmator = next;
	nodNou->precedent = prev;

	return nodNou;
}

void afisareListaCinematografe(struct nod* cap) {
	while (cap) {
		afisareCinema(cap->info);
		cap = cap->next;
	}

}
//6.1 Functie pentru ștergerea unui nod de pe o poziție dată.
void stergePozitie(struct nod** cap, int pozitie) {
	struct nod* temp = *cap;

	// Dacă ștergem primul nod
	if (pozitie == 0) {
		*cap = temp->next;
		freeCinema(temp->info);
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

	// temp este nodul de șters
	anterior->next = temp->next;
	freeCinema(temp->info);
	free(temp);
}

struct nod* inserareNodNouLaSfarsitulListei(struct nod* cap, struct Cinema c) {
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
//5.2 Functie pentru inserarea elementelor în ordine crescătoare după un atribut. exp Numar de sali
struct nod* inserareNodNouInOrdine(struct nod* cap, struct Cinema c) {
	struct nod* nou = initNod(c, NULL);
	if (cap == NULL || cap->info.nrSali >= c.nrSali) {
		nou->next = cap;
		return nou;
	}
	else {
		struct nod* temp = cap;
		while (temp->next != NULL && temp->next->info.nrSali < c.nrSali) {
			temp = temp->next;
		}
		nou->next = temp->next;
		temp->next = nou;
	}
	return cap;
}
//5.3 Functie pentru salvarea într - un vector a elementelor care îndeplinesc o condiție(deep copy). Nr sali > 5
struct Cinema* salvareInVector(struct nod* cap, int* dimensiune) {
	struct Cinema* vector = (struct Cinema*)malloc(sizeof(struct Cinema) * (*dimensiune));
	*dimensiune = 0;
	while (cap) {
		if (cap->info.nrSali > 5) {

			vector[*dimensiune] = cap->info;
			(*dimensiune)++;
		}
		cap = cap->next;
	}
	return vector;
}

void stergereLista(struct nod* cap) {
	struct nod* temp;
	while (cap) {
		temp = cap;
		cap = cap->next;
		free(temp->info.denumire);
		free(temp->info.Incasari);
		free(temp);
	}
}

// 5.4 Functie pentru interschimbarea a două elemente în listă pe baza pozițiilor.
struct nod* interschimbareNoduri(struct nod* cap, int poz1, int poz2) {
	struct nod* temp1 = cap;
	struct nod* temp2 = cap;
	struct Cinema aux;

	for (int i = 0; i < poz1 && temp1 != NULL; i++) {
		temp1 = temp1->next;
	}
	for (int i = 0; i < poz2 && temp2 != NULL; i++) {
		temp2 = temp2->next;
	}
	if (temp1 != NULL && temp2 != NULL) {
		aux = temp1->info;
		temp1->info = temp2->info;
		temp2->info = aux;
	}
	return cap;
}

void AfisareElementeVector(struct Cinema* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++)
	{
		afisareCinema(vector[i]);
	}
}

void dezalocareVector(struct Cinema* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		free(vector[i].denumire);
		free(vector[i].Incasari);
	}
	free(vector);
}
int main()
{

	struct Cinema c1, c2, c3;
	float vectorIncasari[] = { 10.30f, 20.34f,30.00f };
	c1 = initCinema("Cinema1", 10, 3, vectorIncasari);
	c2 = initCinema("Cinema2", 5, 3, vectorIncasari);
	c3 = initCinema("Cinema3", 7, 3, vectorIncasari);
	//afisareCinema(c1);
	struct nod* cap = initNod(c1, NULL);
	cap = inserareNodNouLaSfarsitulListei(cap, c2);
	cap = inserareNodNouLaSfarsitulListei(cap, c3);

	afisareListaCinematografe(cap);

	stergereNod(cap, 2);

	printf("\nLista dupa stergere:\n");
	afisareListaCinematografe(cap);


	//5.2 Funcție pentru inserarea elementelor în ordine crescătoare după un atribut. nr sali
	stergereLista(cap);
	cap = NULL;

	struct Cinema c4 = initCinema("Cinema4", 11, 3, vectorIncasari);
	struct Cinema c5 = initCinema("Cinema5", 8, 3, vectorIncasari);
	cap = inserareNodNouInOrdine(cap, c1);
	cap = inserareNodNouInOrdine(cap, c2);
	cap = inserareNodNouInOrdine(cap, c3);
	cap = inserareNodNouInOrdine(cap, c4);
	cap = inserareNodNouInOrdine(cap, c5);

	printf("\nAfisare Lista dupa inserare in lista in ordine dupa nr sali:\n");
	afisareListaCinematografe(cap);


	//5.3 Funcție pentru salvarea într - un vector a elementelor care îndeplinesc o condiție(deep copy). Nr sali > 5

	printf("\Afisae Vector  dupa inserare in  vector in ordine dupa nr sali:\n");
	struct Cinema* vector = NULL;
	int dimensiune = 0;
	vector = salvareInVector(cap, &dimensiune);
	//printf("\nDimensiune vector: %d\n", dimensiune);
	AfisareElementeVector(vector, dimensiune);

	//5.4 Functie pentru interschimbarea a două elemente în listă pe baza pozițiilor
	cap = interschimbareNoduri(cap, 0, 2);
	printf("\nAfisare Lista dupa intersicimbare elementelor din lista de pe 2 pozitii:\n");
	afisareListaCinematografe(cap);

	stergereLista(cap);
	dezalocareVector(vector, 5);

}
*/
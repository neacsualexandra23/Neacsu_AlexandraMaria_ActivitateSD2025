#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date
/* 
struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

//creare structura pentru Heap
//un vector de elemente, lungimea vectorului si numarul de elemente din vector
struct Heap {
	Masina* vector;
	int lungime;
	int nrMasini;
};
typedef struct Heap Heap;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

Heap initializareHeap(int lungime) {
	Heap heap;
	heap.lungime = lungime;
	heap.nrMasini = 0;
	heap.vector = (Masina*)malloc(sizeof(Masina) * lungime);

	return heap;
}

void filtreazaHeap(Heap heap, int pozitieNod) {
	//filtreaza heap-ul pentru nodul a carei pozitie o primeste ca parametru
	int pozFiuS = 2 * pozitieNod + 1;
	int pozFiuD = 2 * pozitieNod + 2;
	int pozMax = pozitieNod;
	if (pozFiuS < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuS].id) {
		pozMax = pozFiuS;
	}
	if (pozFiuD < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuD].id) {
		pozMax = pozFiuD;
	}
	if (pozMax != pozitieNod) {
		Masina aux = heap.vector[pozMax];
		heap.vector[pozMax] = heap.vector[pozitieNod];
		heap.vector[pozitieNod] = aux;
		//2*pozMax+1 <heap.nrMasini
		if (pozMax < (heap.nrMasini - 1) / 2) {
			filtreazaHeap(heap, pozMax);
		}
	}
}

Heap citireHeapDeMasiniDinFisier(const char* numeFisier, int lungime) {
	Heap heap = initializareHeap(lungime);
	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		heap.vector[heap.nrMasini] = m;
		heap.nrMasini++;
	}
	fclose(f);
	//heap.nrMasini-1 = 2*i+1
	for (int i = (heap.nrMasini - 2) / 2; i >= 0; i--) {
		filtreazaHeap(heap, i);
	}

	return heap;
}

void afisareHeap(Heap heap) {
	for (int i = 0; i < heap.nrMasini; i++) {
		afisareMasina(heap.vector[i]);
	}
}

void afiseazaHeapAscuns(Heap heap) {
	for (int i = heap.nrMasini; i < heap.lungime; i++) {
		afisareMasina(heap.vector[i]);
	}
}

Masina extrageMasina(Heap* heap) {
	Masina aux = heap->vector[0];
	heap->vector[0] = heap->vector[heap->nrMasini - 1];
	heap->vector[heap->nrMasini - 1] = aux;
	heap->nrMasini--;

	for (int i = (heap->nrMasini - 2) / 2; i >= 0; i--) {
		filtreazaHeap(*heap, i);
	}
	aux.model = (char*)malloc(strlen(heap->vector[heap->nrMasini].model) + 1);
	strcpy_s(aux.model, strlen(heap->vector[heap->nrMasini].model) + 1, heap->vector[heap->nrMasini].model);

	aux.numeSofer = (char*)malloc(strlen(heap->vector[heap->nrMasini].numeSofer) + 1);
	strcpy_s(aux.numeSofer, strlen(heap->vector[heap->nrMasini].numeSofer) + 1, heap->vector[heap->nrMasini].numeSofer);

	return aux;
}


void dezalocareHeap(Heap* heap) {
	for (int i = 0; i < heap->lungime; i++) {
		free(heap->vector[i].model);
		free(heap->vector[i].numeSofer);
	}
	free(heap->vector);
	heap->vector = NULL;
	heap->nrMasini = 0;
	heap->lungime = 0;
}

int main() {
	Heap heap = citireHeapDeMasiniDinFisier("masini.txt", 10);
	afisareHeap(heap);

	printf("Extrage masina\n");
	Masina m = extrageMasina(&heap);
	afisareMasina(m);
	free(m.model);
	free(m.numeSofer);

	m = extrageMasina(&heap);
	afisareMasina(m);
	free(m.model);
	free(m.numeSofer);

	dezalocareHeap(&heap);
	return 0;


}*/
//liste simplu inlantuite 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>


struct Ferma {
	char* nume;
	int nrAnimale;
};

struct nod {
	struct Ferma info;
	struct nod* next;
};
/*
 struct Ferma createFerma(const char* nume, int nrAnimale) {
	struct Ferma f;
	f.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(f.nume, nume);
	f.nrAnimale = nrAnimale;
	return f;
}

struct nod* createNod(struct Ferma f, struct nod* next) {
	struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
	nou->info = f;
	nou->next = next;
	return nou;
}

struct nod* inserareSfarsit(struct nod* cap, struct Ferma f) {
	struct nod* nou = createNod(f, NULL);
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


void afisareFerma(struct Ferma f) {
	printf("Ferma %s are %d animale.\n", f.nume, f.nrAnimale);
}

void afisareListaFerme(struct nod* cap) {
	while (cap) {
		afisareFerma(cap->info);
		cap = cap->next;
	}

	//for (; cap != NULL; cap = cap->next) {
	//	afisareFerma(cap->info);
	//}
}

struct nod* inserareInceput(struct nod* cap, struct Ferma f) {
	struct nod* nou = createNod(f, cap);
	return nou;
}

float medieAnimale(struct nod* cap) {
	if (cap) {
		int nr = 0, s = 0;
		while (cap) {
			nr++;
			s += cap->info.nrAnimale;
			cap = cap->next;
		}
		return s / nr;
	}
	else {
		return 0;
	}
}

struct nod* stergereLista(struct nod* cap) {
	while (cap) {
		struct nod* aux = cap;
		cap = cap->next;
		free(aux->info.nume);
		free(aux);
	}
	return cap;
}

void stergereListaRecursiv(struct nod** cap) {
	if (*cap) {
		stergereListaRecursiv(&(*cap)->next);
		free((*cap)->info.nume);
		free(*cap);
		*cap = NULL;
	}
}

struct nod* inserareInainteDeUnNodCuValoareaData(struct nod* cap, const char* nume, struct Ferma f) {
	struct nod* nou = createNod(f, NULL);
	if (cap) {
		struct nod* p = cap;
		struct nod* adresaMax = NULL;
		while (p) {
			if (p->next && strcmp(p->next->info.nume, nume) == 0) {
				if (!adresaMax) {
					adresaMax = p;
				}
				if (p->next->info.nrAnimale > adresaMax->next->info.nrAnimale) {
					adresaMax = p;
				}
			}
			p = p->next;
		}
		if (adresaMax == NULL) {
			if (strcmp(cap->info.nume, nume) == 0) {
				cap = inserareInceput(cap, f);
			}
			else {
				cap = inserareSfarsit(cap, f);
			}
		}
		else {
			if (strcmp(cap->info.nume, nume) == 0) {
				if (cap->info.nrAnimale > adresaMax->info.nrAnimale) {
					cap = inserareInceput(cap, f);
					return cap;
				}
			}
			nou->next = adresaMax->next;
			adresaMax->next = nou;
		}
	}
	else {
		cap = nou;
	}
	return cap;
}

void main() {
	struct Ferma f = createFerma("faraAnimale", 1);
	struct nod* node = createNod(f, NULL);
	struct nod* cap = NULL;
	cap = inserareSfarsit(cap, createFerma("Cocosul vesel", 200));
	cap = inserareSfarsit(cap, createFerma("Ferma", 100));
	cap = inserareSfarsit(cap, createFerma("Avicola", 400));
	cap = inserareSfarsit(cap, createFerma("Crevedia", 1200));

	afisareListaFerme(cap);

	cap = inserareInceput(cap, createFerma("Avicola", 1200));

	afisareListaFerme(cap);
	printf("%5.2f", medieAnimale(cap));

	//stergereListaRecursiv(&cap);

	//cap = inserareInceput(cap, createFerma("Ferma", 400));

	afisareListaFerme(cap);
	printf("\n\n");

	cap = inserareInainteDeUnNodCuValoareaData(cap, "Avicola", createFerma("NOUA", 90));

	afisareListaFerme(cap);

}
*/

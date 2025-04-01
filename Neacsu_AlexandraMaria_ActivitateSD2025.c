#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//1.2. Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul 
// construit de voi.Funcția returnează obiectul citit. 
//

struct Cinema citireCinema() {
	struct Cinema c;
	int i;
	char buffer[20];
	printf("Denumire: ");
	scanf("%s", buffer);
	c.denumire = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
	strcpy(c.denumire, buffer);
	printf("Nr sali: ");
	scanf("%d", &c.nrSali);
	printf("Nr incasari: ");
	scanf("%d", &c.NrIncasari);
	c.Incasari = (float*)malloc(sizeof(float) * c.NrIncasari);
	for (i = 0; i < c.NrIncasari-1; i++) {
		printf("Incasare[%d]: ", i);
		scanf("%f", &c.Incasari[i]);
	}
	return c;
}
//1.3.  o functie care calculeaza media incasarilor pe cinematograf
//float calculareMedieIncasari(struct Cinema c);
float calculareMedieIncasari(struct Cinema c) {
	if (c.NrIncasari == 0) {
		printf("Cinematograful nu are incasari.\n");
		return 0;
	}

	float suma = 0;
	for (int i = 0; i < c.NrIncasari-1; i++) {
		suma += c.Incasari[i];
	}

	return suma / c.NrIncasari;
};
//1.4. Realizati o functie care modifica pentru un obiect primit ca parametru, 
// un anumit camp. noua valoare este primita ca parametru. 
//void modificareNrSali(struct Cinema* c, int nrSaliNou)
void modificareNrSali(struct Cinema* c, int nrSaliNou) {
	c->nrSali = nrSaliNou;
}

// 1.5.Realizați o funcție care afișează un obiect de tipul creat.
// Afișarea se face la console, și sunt afișate toate informațiile.
void afisare(struct Cinema c) {
	int i;
	printf("\nDenumire: %s\nNr sali: %d\nNr incasari: %d\nIncasari: ", c.denumire, c.nrSali, c.NrIncasari);
	for (i = 0; i < c.NrIncasari-1; i++) {
		printf("%.2f ", c.Incasari[i]);
	}
}

//1.6. Realizati un program care dezaloca memoria alocata pentru un obiect de tipul creat.
//void dezalocare(struct Cinema* c);
void dezalocare(struct Cinema* c) {
	free(c->denumire);
	(*c).denumire = NULL;
	free(c->Incasari);
	(*c).Incasari = NULL;
}
//2.2.Funcție pentru copierea obiectelor care îndeplinesc o condiție într - un nou vector.
//struct Cinema* copiereCinematografe(struct Cinema* vectorCinematografe, int nrSali);
void copiereCinemaCunrElementeMaiMreDecat(struct Cinema* vector, int nrElemente, float prag, struct Cinema** vectorNou, int* dimensiune) {

	*dimensiune = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (prag < vector[i].nrSali)
		{
			(*dimensiune)++;

		}
	}
	if (*dimensiune > 0)
	{
		int j = 0;
		*vectorNou = (struct Cinema*)malloc((*dimensiune) * sizeof(struct Cinema));
		for (int i = 0; i < nrElemente; i++)
		{
			if (prag < vector[i].nrSali)
			{
				(*vectorNou)[j] = vector[i];
				(*vectorNou)[j].denumire = malloc((strlen(vector[i].denumire) + 1) * sizeof(char));
				strcpy_s((*vectorNou)[j].denumire, strlen(vector[i].denumire) + 1, vector[i].denumire);

				(*vectorNou)[j].Incasari = (float*)malloc(sizeof(vector[i].Incasari) * sizeof(float));
				for (int k = 0; k < vector[i].NrIncasari; k++) {
					(*vectorNou)[j].Incasari[k] = vector[i].Incasari[k];

				}
				j++;
			}
		}
	}


}

//2.5. Funcție pentru afișarea unui vector de obiecte.
void afisareVector(struct Cinema* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisare(vector[i]);
		printf("\n");
	}
}

int main()
{ 
	float incasariExemplu[] = { 1000.5f, 2000.0f, 1500.25f };
	struct Cinema c1 = initCinema("CinemaCity", 5, 3, incasariExemplu);
	afisare(c1);

	//citire cinema de la tastatura
	struct Cinema c2 = citireCinema();
	afisare(c2);

	float m;
	m = calculareMedieIncasari(c2);
	printf("Media incasarilor pe cinematograf este: %.2f\n", m);


	modificareNrSali(&c2, 10);
	afisare(c2);
	printf("\n=========   Partea 2 vectori de structuri  =======\n");

	dezalocare(&c1);
	dezalocare(&c2);

	//2.1 Vectori de structuri
	//Creati in functia main un vector alocat dinamic cu cel putin 5 obiecte de tipul structurii voastre.

	struct Cinema* vectorCinematografe;
	vectorCinematografe = (struct Cinema*)malloc(sizeof(struct Cinema) * 5);

	float incasariExemplu2[] = { 1700.5f, 20870.0f, 1500.25f };
	vectorCinematografe[0] = initCinema("CinemaCity", 6, 3, incasariExemplu2);
	vectorCinematografe[1] = initCinema("CinemaCity2", 8, 3, incasariExemplu2);
	vectorCinematografe[2] = initCinema("CinemaCity3", 7, 3, incasariExemplu);
	vectorCinematografe[3] = initCinema("CinemaCity4", 5, 3, incasariExemplu);
	vectorCinematografe[4] = initCinema("CinemaCity5", 5, 3, incasariExemplu2);

	//2.3. Realizati o functie care sa copieze in alt vector obiectele care indeplinesc o anumita conditie.
	struct Cinema* vectorCinematografeCopiate = NULL;
	int nrElemCop = 0;
	copiereCinemaCunrElementeMaiMreDecat(vectorCinematografe, 5, 5, &vectorCinematografeCopiate, &nrElemCop);


	afisareVector(vectorCinematografeCopiate, nrElemCop);

	
	return 0;

}
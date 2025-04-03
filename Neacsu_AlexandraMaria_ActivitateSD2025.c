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
	for (i = 0; i < c.NrIncasari; i++) {
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
	for (int i = 0; i < c.NrIncasari; i++) {
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
	for (i = 0; i < c.NrIncasari; i++) {
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
void copiereCinemaCuSaliMaiMareDecat(struct Cinema* vector, int nrElemente, float prag, struct Cinema** vectorNou, int* dimensiune) {

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
//2.3. Funcție pentru mutarea obiectelor care îndeplinesc o altă condiție într-un nou vector
//NrIncasari sa fie mai mare decat 10
void mutaCinemaCuNrIncasariMare(struct Cinema** vector, int* nrElemente, int NrIncasariPrag,
	struct Cinema** vectorIncasariMari, int* dimensiune) {

	*dimensiune = 0;
	for (int i = 0; i < *nrElemente; i++) {
		if ((*vector)[i].NrIncasari > NrIncasariPrag) {
			(*dimensiune)++;
		}
	}
	*vectorIncasariMari = (struct Cinema*)malloc(sizeof(struct Cinema) * (*dimensiune));
	int k = 0;
	for (int i = 0; i < *nrElemente;) {
		if ((*vector)[i].NrIncasari > NrIncasariPrag) {
			(*vectorIncasariMari)[k] = (*vector)[i];

			(*vectorIncasariMari)[k].denumire = (char*)malloc(strlen((*vector)[i].denumire) + 1);
			strcpy_s((*vectorIncasariMari)[k].denumire, strlen((*vector)[i].denumire) + 1, (*vector)[i].denumire);

			(*vectorIncasariMari)[k].Incasari = (float*)malloc((*vector)[i].NrIncasari * sizeof(float));
			for (int j = 0; j < (*vector)[i].NrIncasari; j++) {
				(*vectorIncasariMari)[k].Incasari[j] = (*vector)[i].Incasari[j];
			}
			free((*vector)[i].denumire);
			free((*vector)[i].Incasari);

			for (int j = i; j < *nrElemente - 1; j++) {
				(*vector)[j] = (*vector)[j + 1];
			}

			(*nrElemente)--;
			k++;
		}
		else {
			i++;
		}
	}

}
//2.4. Funcție pentru concatenarea a doi vectori
void concatenareVectori(struct Cinema** vectorRezultat, int* dimensiune,
	 struct Cinema* vector1, int* dimensiuneV1,
	 struct Cinema* vector2, int* dimensiuneV2) {
	*dimensiune = (*dimensiuneV1) + (*dimensiuneV2);
	*vectorRezultat = (struct Cinema*)malloc(sizeof(struct Cinema) * (*dimensiune));

	for (int i = 0; i < *dimensiuneV1; i++) {
		(*vectorRezultat)[i] = vector1[i];
		(*vectorRezultat)[i].denumire = (char*)malloc(strlen(vector1[i].denumire) + 1);
		strcpy_s((*vectorRezultat)[i].denumire, strlen(vector1[i].denumire) + 1, vector1[i].denumire);

		(*vectorRezultat)[i].Incasari = (float*)malloc((*vectorRezultat)[i].NrIncasari * sizeof(float));
		for (int k = 0; k < vector1[i].NrIncasari; k++) {
			(*vectorRezultat)[i].Incasari[k] = vector1[i].Incasari[k];
		}
	}

	for (int j = 0; j < *dimensiuneV2; j++) {
		(*vectorRezultat)[j + (*dimensiuneV1)] = vector2[j];
		(*vectorRezultat)[j + (*dimensiuneV1)].denumire = (char*)malloc(strlen(vector2[j].denumire) + 1);
		strcpy_s((*vectorRezultat)[j + (*dimensiuneV1)].denumire, strlen(vector2[j].denumire) + 1, vector2[j].denumire);

		(*vectorRezultat)[j + (*dimensiuneV1)].Incasari = (float*)malloc(
			(*vectorRezultat)[j + (*dimensiuneV1)].NrIncasari * sizeof(float));
		for (int l = 0; l < vector2[j].NrIncasari; l++) {
			(*vectorRezultat)[j + (*dimensiuneV1)].Incasari[l] = vector2[j].Incasari[l];
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

	float incasariExemplu2[] = { 129.5f, 20870.0f, 1500.25f };
	float incasariExemplu3[] = { 129.5f, 20870.0f, 1500.25f, 345.7f, 45.5 };
	vectorCinematografe[0] = initCinema("CinemaCity", 6, 3, incasariExemplu2);
	vectorCinematografe[1] = initCinema("CinemaCity2", 8, 3, incasariExemplu2);
	vectorCinematografe[2] = initCinema("CinemaCity3", 7, 5, incasariExemplu3);
	vectorCinematografe[3] = initCinema("CinemaCity4", 5, 3, incasariExemplu);
	vectorCinematografe[4] = initCinema("CinemaCity5", 5, 5, incasariExemplu3);

	//2.3. Realizati o functie care sa copieze in alt vector obiectele care indeplinesc o anumita conditie.
	//copiereCinemaCuSaliMaiMareDecat
	struct Cinema* vectorCinematografeCopiate = NULL;
	int nrElemCop = 0;
	copiereCinemaCuSaliMaiMareDecat(vectorCinematografe, 5, 4, &vectorCinematografeCopiate, &nrElemCop);

	printf("\n2.3 Cinematgrafele cu numar de sali mai mare decat 5 :\n");
	afisareVector(vectorCinematografeCopiate, nrElemCop);

	//2.4. Realizati o functie care sa mute in alt vector obiectele care indeplinesc o anumita conditie.

	struct Cinema* vectorCinematografeIncasariMari = NULL;
	int nrElemIncasariMari = 0;
	int nrElemente = 5;
	int prag = 4;
	//mutaCinemaCuNrIncasariMare(&vectorCinematografe, &nrElemente, prag, &vectorCinematografeIncasariMari, &nrElemIncasariMari);

	
	printf("\n 2.4 Muta Cinematografele cu NrIncasari mai mari decat 4:\n");
	afisareVector(vectorCinematografeIncasariMari, nrElemIncasariMari);

	struct Cinema* vectorCinematografe1;
	vectorCinematografe1 = (struct Cinema*)malloc(sizeof(struct Cinema) * 5);

	float incasariExemplu4[] = { 129.5f, 20870.0f, 1500.25f };
	float incasariExemplu5[] = { 129.5f, 20870.0f, 1500.25f, 345.7f, 45.5 };
	vectorCinematografe1[0] = initCinema("CinemaCity", 6, 3, incasariExemplu4);
	vectorCinematografe1[1] = initCinema("CinemaCity2", 8, 3, incasariExemplu5);
	vectorCinematografe1[2] = initCinema("CinemaCity3", 7, 5, incasariExemplu4);
	vectorCinematografe1[3] = initCinema("CinemaCity4", 5, 3, incasariExemplu4);
	vectorCinematografe1[4] = initCinema("CinemaCity5", 5, 5, incasariExemplu5);
	

	struct Cinema* vectorCinematografe2;
	vectorCinematografe2 = (struct Cinema*)malloc(sizeof(struct Cinema) * 4 );

	float incasariExemplu6[] = { 129.5f, 20870.0f, 1500.25f };
	float incasariExemplu7[] = { 129.5f, 20870.0f, 1500.25f, 345.7f, 45.5 };
	vectorCinematografe2[0] = initCinema("CinemaCity", 6, 3, incasariExemplu6);
	vectorCinematografe2[1] = initCinema("CinemaCity2", 8, 3, incasariExemplu7);
	vectorCinematografe2[2] = initCinema("CinemaCity3", 7, 5, incasariExemplu6);
	vectorCinematografe2[3] = initCinema("CinemaCity4", 5, 3, incasariExemplu6);
	

	// 2.5 concatenam 2 vectori de cinematografe vectorCinematografe1 si vectorCinematografe2 in vectorul vectorConcatenat
	struct Cinema* vectorConcatenat = NULL;
	int dimVectorConcatenat = 0;
	int dimVector1 = 5;
	int dimVector2 = 4;
	concatenareVectori(&vectorConcatenat, &dimVectorConcatenat,
		vectorCinematografe2, &dimVector2,
		vectorCinematografe1, &dimVector1);
	printf("\n2.5 Vectorul rezultat concatenat este:\n"); 
	afisareVector(vectorConcatenat, dimVectorConcatenat);
	
	printf("\n=========   Partea 3. Fișiere  =======\n");
	// in fisierul fisier.c
	return 0;


}

*/
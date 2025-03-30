#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

//Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul 
// construit de voi.Funcția returnează obiectul citit.

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
//3.  o functie care calculeaza media incasarilor pe cinematograf
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

void afisare(struct Cinema c) {
	int i;
	printf("\nDenumire: %s\nNr sali: %d\nNr incasari: %d\nIncasari: ", c.denumire, c.nrSali, c.NrIncasari);
	for (i = 0; i < c.NrIncasari; i++) {
		printf("%.2f ", c.Incasari[i]);
	}
}
int main()
{ 
	float incasariExemplu[] = { 1000.5f, 2000.0f, 1500.25f };
	struct Cinema c1 = initCinema("CinemaCity", 5, 3, incasariExemplu);
	afisare(c1);

	struct Cinema c2 = citireCinema();
	afisare(c2);

	float m;
	m = calculareMedieIncasari(c2);
	printf("Media incasarilor pe cinematograf este: %.2f\n", m);
	printf("Hello World!");

	
	return 0;

}
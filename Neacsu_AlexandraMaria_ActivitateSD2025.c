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
	strcpy(c.denumire, denumire);
	
	    
    c.nrSali = nrSali;
	c.NrIncasari = NrIncasari;
    c.Incasari = (float*)malloc(sizeof(Incasari) * sizeof(float));
    for (i = 0; i < NrIncasari; i++) {
        c.Incasari[i] = Incasari[i];
    }

    return c;
}



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
	struct Cinema c1 = initCinema("Cinema City", 5, 3, incasariExemplu);
	afisare(c1);
	printf("Hello World!");
	
	return 0;

}
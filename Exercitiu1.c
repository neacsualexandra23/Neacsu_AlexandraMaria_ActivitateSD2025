#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Cinema
{
	char* denumire;
	int nrSali;
	int nrIncasari;
	int* incasari;
};

/*
struct Cinema CitireDeLaTastatura() {
	struct Cinema c;
	char buffer[20];
	printf("Introduceti denumirea cinematografului: ");
	scanf("%s", buffer);
	c.denumire = (char*)malloc((strlen(buffer) +1) );

	strcpy(c.denumire, buffer);


	printf("Introduceti numarul de sali: ");
	scanf("%d", &c.nrSali);

	printf("Introduceti numarul de incasari: ");
	scanf("%d", &c.nrIncasari);

	printf("Introduceti incasarile: ");
	c.incasari = (int*)malloc(c.nrIncasari * sizeof(int));
	for (int i = 0; i < c.nrIncasari;i++)
	{
		scanf("%d", &c.incasari[i]);
	}
	return c;
}

void afisare(struct Cinema c) {

	printf("Denumirea cinematografului este:%s \n", c.denumire);
	printf("Numarul de sali este:%d \n", c.nrSali);
	printf("Numarul de incasari este:%d \n", c.nrIncasari);

	// printf("Denumirea cinematografului este:%s \n Numar sali:%d \n Numar incasari este:%d \n", c.denumire, c.nrSali, c.nrIncasari);
	for (int i = 0;i < c.nrIncasari;i++)
		printf("%d ", c.incasari[i]);
}

void EliberareMemorie(struct Cinema c) {
	free(c.denumire);
	free(c.incasari);

}
//1.3.Funcție care calculează o valoare(ex: medie, sumă, maxim, minim).
int SumaIncasari(struct Cinema c) {
	int suma = 0;
	for (int i = 0;i < c.nrIncasari;i++)
		suma = suma + c.incasari[i];
	return suma;
}
//1.4. Funcție care modifică un atribut al articolului.

void modificareNrSali(struct Cinema* c, int nrSaliNou) {
	c->nrSali = nrSaliNou;
}


struct Cinema initCinema(const char* denumire, int nrSali, int nrIncasari, const int* incasari) {
	struct Cinema c;
	int i;

	c.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(c.denumire, denumire);


	c.nrSali = nrSali;
	c.nrIncasari = nrIncasari;
	c.incasari = (float*)malloc(sizeof(incasari) * sizeof(float));
	for (i = 0; i < nrIncasari; i++) {
		c.incasari[i] = incasari[i];
	}

	return c;
}




int main()
{
	struct Cinema  c2;
	int varnou = 90;





	c1 = CitireDeLaTastatura();
	afisare(c1);
	printf("\nSuma incasarilor este:%d  \n",SumaIncasari(c1));


	modificareNrSali(&c1, varnou);
	afisare(c1);

	EliberareMemorie(c1);

	printf("==============Structura c2 initializat in interiorul functiei main cu niste valori default \n");

	int  incasariExemplu[] = {129,2087,1500};
	c2 = initCinema("CinemaCity", 6, 3, incasariExemplu);
	afisare(c2);
	EliberareMemorie(c2);


}
*/
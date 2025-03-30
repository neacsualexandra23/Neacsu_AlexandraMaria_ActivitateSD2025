1. Structura și funcții   👍
1.1. Se consideră prima literă din numele vostru și prima literă din prenumele vostru. Se va construi un articol care să conțină aceste două litere.

Articolul trebuie să aibă logică.
Articolul trebuie să fie un substantiv.
Trebuie să aibă cel puțin trei atribute, dintre care unul alocat dinamic.
Exemplu:
Alin Zamfiroiu → A și Z.
Structura:

struct Magazin {
    int cod;
    char* denumire;
    int nrProduse;
    float *preturi;
};


struct Cinema {
	char* denumire;
	int nrSali;
	int NrIncasari;
	float* Incasari;
};

Funcții necesare:
1.2. Funcție pentru citirea unui articol de la tastatură.  👍
        struct Cinema initCinema(const char* denumire, int nrSali, int NrIncasari, const float* Incasari) {
1.3. Funcție care calculează o valoare (ex: medie, sumă, maxim, minim).  👍
        float calculareMedieIncasari(struct Cinema c) 
1.4. Funcție care modifică un atribut al articolului.  👍
         void modificareNrSali(struct Cinema* c, int nrSaliNou)
1.5. Funcție pentru afișarea unui articol.  👍
         void afisare(struct Cinema c)

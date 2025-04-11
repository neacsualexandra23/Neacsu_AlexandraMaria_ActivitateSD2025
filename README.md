1. Structura și funcții    
========================

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
};👍    


Funcții necesare:

1.2. Funcție pentru citirea unui articol de la tastatură.  👍
        struct Cinema initCinema(const char* denumire, int nrSali, int NrIncasari, const float* Incasari) 
	
1.3. Funcție care calculează o valoare (ex: medie, sumă, maxim, minim).  👍
        float calculareMedieIncasari(struct Cinema c) 

1.4. Funcție care modifică un atribut al articolului.  👍
         void modificareNrSali(struct Cinema* c, int nrSaliNou)
	 
1.5. Funcție pentru afișarea unui articol.  👍
         void afisare(struct Cinema c)
	 
2. Vectori
   
============

	2.1. Crearea unui vector alocat dinamic cu cel puțin 5 obiecte de tipul structurii definite.👍
	2.2. Funcție pentru copierea obiectelor care îndeplinesc o condiție într-un nou vector.👍
	2.3. Funcție pentru mutarea obiectelor care îndeplinesc o altă condiție într-un nou vector.👍
	2.4. Funcție pentru concatenarea a doi vectori.👍
	2.5. Funcție pentru afișarea unui vector de obiecte.👍
	Apelarea tuturor funcțiilor în main().👍

3. Fișiere
   
===========

	Crearea unui fișier cu cel puțin 10 obiecte.👍
	3.1. Funcție pentru citirea obiectelor din fișier și salvarea într-un vector.👍
	3.2. Funcție pentru salvarea unui obiect într-un fișier text.👍
	3.3. Funcție pentru salvarea unui vector de obiecte într-un fișier text.👍

 4. Matrice
    
 ===========

	4.0. Citirea obiectelor dintr-un fișier și salvarea într-un vector.
	4.1. Functie care sa copieze (deep copy) elementele din vector intr-o matrice alocată dinamic. Asezarea in matrice pe linii a 		obiectelor o faceti dupa un criteriu aplicat unui atribut. Astfel veti obține mai multe clustere reprezentate de liniile matricei.
	4.2. Functie pentru mutarea liniile din matrice, astfel incat acestea sa fie sortate dupa numarul de elemente de pe linie
	4.3. Funcție pentru afișarea elementelor din matrice.

	 
	 

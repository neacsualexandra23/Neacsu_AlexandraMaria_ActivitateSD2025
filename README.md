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
   
=============

	2.1. Crearea unui vector alocat dinamic cu cel puțin 5 obiecte de tipul structurii definite.👍
	2.2. Funcție pentru copierea obiectelor care îndeplinesc o condiție într-un nou vector.👍
	2.3. Funcție pentru mutarea obiectelor care îndeplinesc o altă condiție într-un nou vector.👍
	2.4. Funcție pentru concatenarea a doi vectori.👍
	2.5. Funcție pentru afișarea unui vector de obiecte.👍
	Apelarea tuturor funcțiilor în main().👍

3. Fișiere
   
============

	Crearea unui fișier cu cel puțin 10 obiecte.👍
	3.1. Funcție pentru citirea obiectelor din fișier și salvarea într-un vector.👍
	3.2. Funcție pentru salvarea unui obiect într-un fișier text.👍
	3.3. Funcție pentru salvarea unui vector de obiecte într-un fișier text.👍

 4. Matrice
    
 ===========

	4.0. Citirea obiectelor dintr-un fișier și salvarea într-un vector. 👍
	4.1. Functie care sa copieze (deep copy) elementele din vector intr-o matrice alocată dinamic. 
             Asezarea in matrice pe linii a obiectelor o faceti dupa un criteriu aplicat unui atribut. 
	     Astfel veti obține mai multe clustere reprezentate de liniile matricei.👍
 
	4.2. Functie pentru mutarea liniile din matrice, astfel incat acestea sa fie sortate 
             dupa numarul de elemente de pe linie👍
	4.3. Funcție pentru afișarea elementelor din matrice.👍


 5. Liste simplu înlănțuite
    
 =========================
    
	5.1 Funcție pentru ștergerea unui nod de pe o poziție dată.👍
	5.2 Funcție pentru inserarea elementelor în ordine crescătoare după un atribut.👍
	5.3 Funcție pentru salvarea într-un vector a elementelor care îndeplinesc o condiție (deep copy).👍
	5.4 Funcție pentru interschimbarea a două elemente în listă pe baza pozițiilor.👍
    
6. Liste dublu înlănțuite
   
==========================

	6.1 Funcție pentru ștergerea unui nod de pe o poziție dată.
	6.2 Funcție pentru inserarea elementelor în ordine crescătoare după un atribut.
	6.3 Funcții pentru parcurgerea listei în ordine crescătoare și descrescătoare.
	6.4 Funcție pentru salvarea elementelor într-o listă simplu înlănțuită (deep copy).
	6.5 Funcție pentru interschimbarea a două elemente din listă pe baza pozițiilor.

 7. HashTable
 ==================
7.1 Crearea unei tabele de dispersie pentru stocarea clădirilor din București (clustere pe baza anului construirii).
7.2 Funcție pentru afișarea clădirilor dintr-un anumit an.
7.3 Funcție pentru ștergerea unei clădiri pe baza ID-ului și anului construirii.
7.4 Funcție pentru ștergerea unei clădiri doar pe baza ID-ului.
Observarea diferenței dintre cele două funcții de ștergere.
7.5 Funcție pentru salvarea într-un vector a clădirilor dintr-un anumit an (deep copy).
7.6 Funcție pentru modificarea anului de construire a unei clădiri (cu actualizarea clusterizării).

8. Heap
==========
8.1 Implementarea unui sistem pentru gestiunea pacienților la Unitatea de Primiri Urgențe (UPU).
8.2 Structura Pacient include un grad de urgență.
8.3 Utilizarea unui Max-Heap pentru gestionarea pacienților astfel încât cei mai urgenti să fie preluați cu prioritate.
   
9. Arbori binari de căutare (BST)
=================================
9.1 Funcție pentru ștergerea unui nod pe baza unui ID, menținând proprietățile arborelui BST.
9.2 Funcție pentru returnarea subarborelui cu înălțimea mai mare.
9.3 Funcție pentru numărarea nodurilor subordonate unui nod.
9.4 Funcție pentru returnarea subarborelui cu mai multe noduri în subordine.

10. Arbori AVL
================
10.1 Implementarea unui arbore binar de căutare echilibrat (AVL).
10.2 Verificarea și aplicarea rotațiilor pentru menținerea echilibrului.
10.3 Funcție de căutare a unui nod în arbore pe baza unui ID.
10.4 Funcție pentru salvarea nodurilor într-un vector folosind preordine, inordine, postordine.
10.5 Funcție pentru salvarea nodurilor într-o listă simplu înlănțuită (preordine, inordine, postordine).
10.6 Funcție pentru salvarea nodurilor într-o listă dublu înlănțuită (preordine, inordine, postordine).

12. Stive și cozi
===================
Stivă (LIFO):

Pe un vector.
Pe o listă simplu înlănțuită.
Pe o listă dublu înlănțuită.
Coada (FIFO):

Pe un vector.
Pe o listă simplu înlănțuită.
Pe o listă dublu înlănțuită.


	 
	 

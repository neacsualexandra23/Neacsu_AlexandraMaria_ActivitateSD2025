#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura pentru un cinematograf (fără typedef, se folosește struct Cinema)
struct Cinema {
    int id;
    char* denumire;
    int nrSali;
};

// Structura Nod pentru implementarea cozii (lista înlănțuită)
struct Nod {
    struct Cinema info;
    struct Nod* next;
};

// Funcție de inițializare a unui cinematograf (alocă memorie pentru denumire și setează câmpurile)
struct Cinema initializareCinema(const char* denumire, int id, int nrSali) {
    struct Cinema c;
    c.id = id;
    c.nrSali = nrSali;
    // Alocăm memorie pentru denumire și copiem șirul de caractere
    c.denumire = (char*)malloc((strlen(denumire) + 1) * sizeof(char));
    if (c.denumire != NULL) {
        strcpy(c.denumire, denumire);
    }
    return c;
}

// Funcție de adăugare a unui element de tip Cinema în stivă (LIFO) 
void pushCinema(struct Cinema* stiva, int* varf, struct Cinema c) {
    (*varf)++;                  // creștem indicele de vârf al stivei
    stiva[*varf] = c;           // adăugăm elementul la vârful stivei
}

// Funcție de extragere (ștergere) a elementului de tip Cinema din vârful stivei (LIFO)
struct Cinema popCinema(struct Cinema* stiva, int* varf) {
    struct Cinema rezultat = stiva[*varf];  // copiem elementul din vârf
    (*varf)--;                             // scădem indicele de vârf
    return rezultat;
}

// Funcție de inserare a unui element de tip Cinema în coadă (FIFO)
void inserareCoadaCinema(struct Nod** prim, struct Nod** ultim, struct Cinema c) {
    // Alocăm un nod nou și setăm informațiile acestuia
    struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));
    if (nou == NULL) {
        fprintf(stderr, "Eroare la alocarea nodului pentru coadă!\n");
        exit(1);
    }
    nou->info = c;    // copiem structura Cinema în nodul nou
    nou->next = NULL;
    // Dacă coada este goală, noul nod devine atât primul, cât și ultimul
    if (*prim == NULL) {
        *prim = nou;
        *ultim = nou;
    }
    else {
        // altfel, adăugăm nodul la sfârșitul cozii
        (*ultim)->next = nou;
        *ultim = nou;
    }
}

// Funcție de extragere a primului element de tip Cinema din coadă (FIFO)
struct Cinema extragereCoadaCinema(struct Nod** prim, struct Nod** ultim) {
    if (*prim == NULL) {
        fprintf(stderr, "Coada este goală - nu există elemente de extras!\n");
        // Returnăm un element "gol" în caz de eroare
        struct Cinema c_eroare;
        c_eroare.id = -1;
        c_eroare.denumire = NULL;
        c_eroare.nrSali = 0;
        return c_eroare;
    }
    // Preluăm elementul de la începutul cozii
    struct Nod* temp = *prim;
    struct Cinema rezultat = temp->info;
    // Mutăm începutul cozii la următorul element
    *prim = (*prim)->next;
    if (*prim == NULL) {
        // Dacă am extras ultimul element, pointerul 'ultim' devine NULL
        *ultim = NULL;
    }
    free(temp); // eliberăm memoria nodului extras
    return rezultat;
}

int main() {
    // Inițializăm un vector de cinematografe (de exemplu, 3 cinematografe)
    int nrCinematografe = 3;
    struct Cinema* vector = (struct Cinema*)malloc(nrCinematografe * sizeof(struct Cinema));
    if (vector == NULL) {
        fprintf(stderr, "Eroare la alocarea vectorului de cinematografe!\n");
        return 1;
    }
    // Populăm vectorul cu date despre cinematografe
    vector[0] = initializareCinema("Cinema City", 101, 10);
    vector[1] = initializareCinema("Movieplex", 102, 5);
    vector[2] = initializareCinema("Hollywood Multiplex", 103, 8);

    // Operăm cu stiva
    struct Cinema* stiva = (struct Cinema*)malloc(nrCinematografe * sizeof(struct Cinema));
    if (stiva == NULL) {
        fprintf(stderr, "Eroare la alocarea stivei!\n");
        return 1;
    }
    int varf = -1; // inițial, stiva este goală (vârf = -1)

    // Adăugăm toate cinematografele din vector în stivă
    for (int i = 0; i < nrCinematografe; i++) {
        pushCinema(stiva, &varf, vector[i]);
    }

    // Extragem elementele din stivă și le afișăm (ordinea LIFO)
    printf("Elementele extrase din stivă (LIFO):\n");
    while (varf != -1) {
        struct Cinema c = popCinema(stiva, &varf);
        printf("Cinema %d: %s, %d săli\n", c.id, c.denumire, c.nrSali);
    }

    // Operăm cu coada
    struct Nod* prim = NULL;
    struct Nod* ultim = NULL;

    // Inserăm toate cinematografele din vector în coadă
    for (int i = 0; i < nrCinematografe; i++) {
        inserareCoadaCinema(&prim, &ultim, vector[i]);
    }

    // Extragem elementele din coadă și le afișăm (ordinea FIFO)
    printf("\nElementele extrase din coadă (FIFO):\n");
    while (prim != NULL) {
        struct Cinema c = extragereCoadaCinema(&prim, &ultim);
        printf("Cinema %d: %s, %d săli\n", c.id, c.denumire, c.nrSali);
    }

    // Eliberăm memoria alocată
    free(stiva);
    for (int i = 0; i < nrCinematografe; i++) {
        free(vector[i].denumire);  // eliberăm memoria alocată pentru denumirea fiecărui cinematograf
    }
    free(vector);

    return 0;
}

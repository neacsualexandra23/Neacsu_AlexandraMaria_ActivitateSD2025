#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cinema {
    char* titlu;
    float pretBilet;
};

struct nod {
    struct Cinema info;
    struct nod* st;
    struct nod* dr;
};

struct Cinema creareCinema(const char* titlu, const float pretBilet) {
    struct Cinema f;
    f.titlu = (char*)malloc(sizeof(char) * (strlen(titlu) + 1));
    if (f.titlu == NULL) {
        printf("Eroare la alocarea memoriei pentru titlu!\n");
        exit(1);
    }
    strcpy(f.titlu, titlu);
    f.pretBilet = pretBilet;
    return f;
}

void afisareCinema(struct Cinema f) {
    printf("Cinemaul '%s' are pretul biletului %5.2f lei\n", f.titlu, f.pretBilet);
}

struct nod* inserareInArbore(struct nod* root, struct Cinema f) {
    if (root) {
        if (f.pretBilet < root->info.pretBilet) {
            root->st = inserareInArbore(root->st, f);
        }
        else if (f.pretBilet > root->info.pretBilet) {
            root->dr = inserareInArbore(root->dr, f);
        }
        return root;
    }
    else {
        struct nod* nou = (struct nod*)malloc(sizeof(struct nod));
        if (nou == NULL) {
            printf("Eroare la alocarea nodului!\n");
            exit(1);
        }
        nou->info = f;
        nou->st = nou->dr = NULL;
        return nou;
    }
}

void afisareSRD(struct nod* root) {
    if (root) {
        afisareSRD(root->st);
        afisareCinema(root->info);
        afisareSRD(root->dr);
    }
}

struct Cinema cautareCinemaDupaPret(struct nod* root, float pretBilet) {
    if (root) {
        if (root->info.pretBilet > pretBilet) {
            return cautareCinemaDupaPret(root->st, pretBilet);
        }
        else if (root->info.pretBilet < pretBilet) {
            return cautareCinemaDupaPret(root->dr, pretBilet);
        }
        else {
            return creareCinema(root->info.titlu, root->info.pretBilet);
        }
    }
    return creareCinema("", -1);
}

void stergereArbore(struct nod** root) {
    if (*root) {
        stergereArbore(&(*root)->st);
        stergereArbore(&(*root)->dr);
        free((*root)->info.titlu);
        free(*root);
        *root = NULL;
    }
}

int inaltimeArbore(struct nod* root) {
    if (root) {
        return 1 + (inaltimeArbore(root->st) > inaltimeArbore(root->dr) ? inaltimeArbore(root->st) : inaltimeArbore(root->dr));
    }
    return 0;
}

int main() {
    struct nod* root = NULL;
    root = inserareInArbore(root, creareCinema("Avatar", 35));
    root = inserareInArbore(root, creareCinema("Titanic", 30));
    root = inserareInArbore(root, creareCinema("Inception", 40));
    root = inserareInArbore(root, creareCinema("Interstellar", 45));
    root = inserareInArbore(root, creareCinema("Joker", 25));

    printf("Arborele de cinemae in ordine SRD:\n");
    afisareSRD(root);
    printf("Inaltimea arborelui: %d\n", inaltimeArbore(root));

    struct Cinema f = cautareCinemaDupaPret(root, 40);
    printf("\nCinemaul cautat:\n");
    afisareCinema(f);

    stergereArbore(&root);
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Client {
    int id;
    int varsta;
    char* nume;
    float buget;
    char initialaTata;
};
/*
struct Client citireClientFisier(FILE* f) {
    struct Client c;
    char buffer[100];
    char sep[] = ",\n";

    // Initialize all struct fields to avoid undefined behavior
    c.id = 0;
    c.varsta = 0;
    c.nume = NULL;
    c.buget = 0.0;
    c.initialaTata = '\0';

    if (fgets(buffer, sizeof(buffer), f) == NULL) {
        printf("Error reading line from file.\n");
        exit(1); // Exit program if reading fails
    }

    // Tokenization using strtok with NULL checks
    char* token = strtok(buffer, sep);
    if (token) c.id = atoi(token); else { printf("Error: Missing id\n"); exit(1); }

    token = strtok(NULL, sep);
    if (token) c.varsta = atoi(token); else { printf("Error: Missing varsta\n"); exit(1); }

    token = strtok(NULL, sep);
    if (token) {
        c.nume = (char*)malloc(strlen(token) + 1);
        if (c.nume != NULL) {
            strcpy(c.nume, token);
        }
        else {
            printf("Error: Memory allocation failed for nume\n");
            exit(1);
        }
    }
    else {
        printf("Error: Missing nume\n");
        exit(1);
    }

    token = strtok(NULL, sep);
    if (token) c.buget = atof(token); else { printf("Error: Missing buget\n"); exit(1); }

    token = strtok(NULL, sep);
    if (token) c.initialaTata = token[0]; else { printf("Error: Missing initialaTata\n"); exit(1); }

    return c;
}

int main() {
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    struct Client client = citireClientFisier(file);
    fclose(file);

    printf("ID: %d\n", client.id);
    printf("Varsta: %d\n", client.varsta);
    printf("Nume: %s\n", client.nume);
    printf("Buget: %.2f\n", client.buget);
    printf("Initiala Tata: %c\n", client.initialaTata);

    free(client.nume);  // Free allocated memory
    return 0;
}

*/
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;


int gracz[10][10] = {0}, gracz1[10][10] = {0}, komputer[10][10] = {0};
int g = 0, k = 0, i, t, a, b;

/* Are coordinates in range of the map */
bool coordsInMap(int x, int y) {

    /* compare numbers to the map size */
    if (x>-1 && x < 10 && y>-1 && y < 10) {

        /* Coords in range, hooray */
        return true;
    }

    /* Out of range, sad face */
    return false;
}

/* Return content of the field */
int getFieldValue(int map[10][10], int x, int y) {

    /* Are coordinates in range of the map 
     * Checking it here saves us a lot of work (border checks)
     */
    if (coordsInMap(x, y)) {

        /* Return the field's value 
         * 0 - ?
         * 1 - ?
         * 2 - ?
         * 3 - ?
         */
        return map[x][y];
    }

    /* Field not in a map, return an error */
    return -1;
}

/* Set field value */
void setFieldValue(int map[10][10], int x, int y, int value) {

}

/* Prepares important stuff, prints game info, etc. */
void beginGame() {
    srand(time(NULL));
    printf("Gra w statki.\nKazdy z graczy posiada plansze 10x10 na ktorej znajduje sie 8 jednomasztowcow.\n");
    printf("Celem graczy jest zatopienie statkow przeciwnika.\nWygrywa ten, ktory jako pierwszy zatopi statki przeciwnika.\n");
    printf("Kazdy gracz ma jeden strzal na ture.\nTrafienie w statek przeciwnika upowaznia do oddania dodatowego strzalu.\n");
    printf("Statki nie moga sie stykac krawedziani i rogami.\n");
    system("pause");
    system("cls");
}

/* Build player map */
void buildPlayerMap() {
    printf("Ustaw swoje statki!\n");
    system("pause");
    do {
        system("cls");
        printf("Twoje statki:\n");
        wypisz(gracz);
        dodaj(1, gracz);
        g++;
    } while (g < 8);
    system("cls");
    printf("Ukonczono ustawianie statkow!\nTwoje statki:\n");
    wypisz(gracz);
    system("pause");
}

/* Build cpu map */
void buildCpuMap() {
    printf("Komputer ustawia swoje statki...\n");
    do {
        dodaj(0, komputer);
        k++;
    } while (k < 8);
    printf("Skończone.\n");
}

/* Prints a single field of the map
 * It could be changed to return the value translated to the "image" 
 * The returned value could be used in printf
 */
void printField(int value) {

    switch (value) {
        case 1: printf("X");
            break;
        case 2: printf("#");
            break;
        case 3: printf("O");
            break;
        default: printf(" ");
    }
}

/* print map */
void printMap(int map[10][10]) {

}

/* Perform player's turn */
void playerTurn() {
    a = 1;
    do {
        if (k > 0 && g > 0) {
            system("cls");
            printf("Twoje statki:\n");
            wypisz(gracz);
            printf("Twoje strzaly:\n");
            wypisz(gracz1);
            t = strzal(komputer, gracz1);
            if (t == 1) {
                k--;
            } else {
                a = 0;
            };
            system("pause");
        };
        if (k == 0) {
            a = 0;
        };
    } while (a == 1);
}

/* Perform cpu turn */
void cpuTurn() {
    b = 1;
    do {
        if (k > 0 && g > 0) {
            t = strzalk(gracz);
            if (t == 1) {
                g--;
            } else {
                b = 0;
            };
        };
        if (g == 0) {
            b = 0;
        };
    } while (a == 1 && b == 1);
}

/* Ends the game, prints status, etc */
void endGame() {
    system("cls");
    if (k == 0) {
        printf("Gratulacje! Wygrana!\n");
    }
    if (g == 0) {
        printf("Niestety, komputer wygrywa.\n");
    }
    printf("Twoje statki:\n");
    wypisz(gracz);
    printf("Statki przeciwnika:\n");
    wypisz(komputer);
    system("pause");
}

int main(int argc, char** argv) {
    beginGame();
    buildPlayerMap();
    buildCpuMap();
    do {
    } while (g > 0 && k > 0);
    return 0;
}


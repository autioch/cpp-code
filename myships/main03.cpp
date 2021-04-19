/* Przebudowane funkcje, dalsze zmiany w nazwach oraz zasiegu zmiennych. */

/* To nie jest idealny kod (przede wszystkim te globalne zmienne...), ale 
 * myślę, że poziom czytelności znacząco się zwiększył, oraz pojawiły
 * się dalsze opcje rozbudowy. */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int playerMap[10][10] = {0}, playerHits[10][10] = {0}, cpuMap[10][10] = {0};
int playerShips = 8, cpuShips = 8;

/* Map functions */

void mapPrint(int map[10][10]) {
    int i, j;
    printf("\n  |");
    for (i = 0; i < 10; i++) {
        printf("%d|", i + 1);
    };
    for (i = 0; i < 10; i++) {
        if (i > 8) {
            printf("\n%d|", i + 1);
        } else {
            printf("\n %d|", i + 1);
        };
        for (j = 0; j < 10; j++) {
            if (j > 8) {
                printf(" ");
            };
            switch (map[i][j]) {
                case 1: printf("X|");
                    break;
                case 2: printf("#|");
                    break;
                case 3: printf("O|");
                    break;
                default: printf(" |");
            }
        }
    }
    printf("\n");
}

int coordsInMap(int x, int y) {
    if (x>-1 && x < 10 && y>-1 && y < 10) {
        return 1;
    }
    return 0;
}

void mapMarkShip(int map[10][10], int x, int y) {
    int i, j;
    for (i = x - 1; i < x + 2; i++) {
        for (j = y - 1; j < y + 2; j++) {
            if (coordsInMap(i, j) == 1) {
                map[i][j] = 3;
            }
        }
    }
    map[x][y] = 2;
}

void mapAddShip(int map[10][10], int player) {
    int shipAdded = 0, shipFound = 0, x = 11, y = 11, i, j;
    do {
        if (player == 1) {
            printf("Podaj wspolrzedne Twojego statku.\n");
            scanf("%d %d", &x, &y);
            x--;
            y--;
            if (coordsInMap(x, y) == 0) {
                do {
                    printf("Przekroczono zakres.\n");
                    printf("Podaj wspolrzedne Twojego statku.\n");
                    scanf("%d %d", &x, &y);
                    x--;
                    y--;
                } while (coordsInMap(x, y) == 0);
            };
        } else {
            x = rand() % 10;
            y = rand() % 10;
        };
        if (map[x][y] == 1) {
            if (player == 1) {
                printf("W tym polu jest juz statek!\n");
            };
        } else {
            shipFound = 0;
            for (i = x - 1; i < x + 1; i++) {
                for (j = y - 1; j < y + 1; j++) {
                    if ((coordsInMap(i, j) == 1) && (map[i][j] == 1)) {
                        if (player == 1) {
                            printf("W sasiedztwie juz znajduje sie statek!\n");
                        };
                        shipFound = 1;
                        break;
                    }
                }
            }
            if (shipFound == 0) {
                map[x][y] = 1;
                shipAdded = 1;
            }
        };
    } while (shipAdded == 0);
}

/* Player functions */

void playerPlaceShips() {
    int shipsPlaced = 0;
    printf("Ustaw swoje statki!\n");
    system("pause");
    do {
        system("cls");
        printf("Twoje statki:\n");
        mapPrint(playerMap);
        mapAddShip(playerMap, 1);
        shipsPlaced++;
    } while (shipsPlaced < playerShips);
    system("cls");
    printf("Ukonczono ustawianie statkow!\nTwoje statki:\n");
    mapPrint(playerMap);
    system("pause");
}

int playerAction() {
    int hit, x, y;
    printf("Twoja kolej!\n");
    printf("Podaj wspolrzedne.\n");
    scanf("%d %d", &x, &y);
    x--;
    y--;
    if (coordsInMap(x, y) == 0) {
        do {
            printf("Przekroczono zakres.\n");
            printf("Podaj wspolrzedne.\n");
            scanf("%d %d", &x, &y);
            x--;
            y--;
        } while (coordsInMap(x, y) == 0);
    };
    switch (cpuMap[x][y]) {
        case 0:
            printf("Pudlo!\n");
            playerHits[x][y] = 3;
            cpuMap[x][y] = 3;
            hit = 0;
            break;
        case 1:
            mapMarkShip(cpuMap, x, y);
            mapMarkShip(playerHits, x, y);
            hit = 1;
            break;
        case 2:
            printf("Juz padl strzal w to pole!\n");
            hit = 0;
            break;
        case 3:
            printf("Juz padl strzal w to pole!\n");
            hit = 0;
            break;
        default:
            hit = 0;
    }
    return hit;
}

void playerTurn() {
    int a = 1;
    do {
        if (cpuShips > 0 && playerShips > 0) {
            system("cls");
            printf("Twoje statki:\n");
            mapPrint(playerMap);
            printf("Twoje strzaly:\n");
            mapPrint(playerHits);
            if (playerAction() == 1) {
                cpuShips--;
            } else {
                a = 0;
            };
            system("pause");
        };
        if (cpuShips == 0) {
            a = 0;
        };
    } while (a == 1);
}

/* CPU functions */

void cpuPlaceShips() {
    int shipsPlaced = 0;
    printf("Komputer ustawia swoje statki...\n");
    do {
        mapAddShip(cpuMap, 0);
        shipsPlaced++;
    } while (shipsPlaced < cpuShips);
    printf("Skończone.\n");
}

int cpuAction() {
    int hit, x, y;
    do {
        x = rand() % 10;
        y = rand() % 10;
    } while (playerMap[x][y] == 2 || playerMap[x][y] == 3);
    if (playerMap[x][y] == 1) {
        mapMarkShip(playerMap, x, y);
        hit = 1;
    } else {
        hit = 0;
        playerMap[x][y] = 3;
    };
    return hit;
}

void cpuTurn() {
    printf("Komputer strzela...\n");
    int hit = 1;
    do {
        if (cpuShips > 0 && playerShips > 0) {
            if (cpuAction() == 1) {
                playerShips--;
            } else {
                hit = 0;
            };
        };
        if (playerShips == 0) {
            hit = 0;
        };
    } while (playerShips > 0 && hit == 1);
}

/* Misc functions */

void gameBegin() {
    srand(time(NULL));
    printf("Gra w statki.\nKazdy z graczy posiada plansze 10x10 na ktorej znajduje sie %d jednomasztowcow.\n", playerShips);
    printf("Celem graczy jest zatopienie statkow przeciwnika.\nWygrywa ten, ktory jako pierwszy zatopi statki przeciwnika.\n");
    printf("Kazdy gracz ma jeden strzal na ture.\nTrafienie w statek przeciwnika upowaznia do oddania dodatowego strzalu.\n");
    printf("Statki nie moga sie stykac krawedziani i rogami.\n");
    system("pause");
    system("cls");
}

void gameEnd() {
    system("cls");
    if (cpuShips == 0) {
        printf("Gratulacje! Wygrana!\n");
    }
    if (playerShips == 0) {
        printf("Niestety, komputer wygrywa.\n");
    }
    printf("Twoje statki:\n");
    mapPrint(playerMap);
    printf("Statki przeciwnika:\n");
    mapPrint(cpuMap);
    system("pause");
}

int main(int argc, char** argv) {
    gameBegin();
    playerPlaceShips();
    cpuPlaceShips();
    do {
        playerTurn();
        cpuTurn();
    } while (playerShips > 0 && cpuShips > 0);
    gameEnd();
    return 0;
}

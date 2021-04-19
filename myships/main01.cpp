/* W tej wersji kod został podzielony na funkcje. */
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int gracz[10][10] = {0}, gracz1[10][10] = {0}, komputer[10][10] = {0};
int g = 0, k = 0, i, t, a, b;

int wypisz(int x[10][10]) {
    int i, j;
    printf("  ");
    for (i = 0; i < 10; i++) {
        printf("|%d", i + 1);
    };
    printf("|\n");
    for (i = 0; i < 10; i++) {
        if (i == 9) {
            printf("%d", i + 1);
        } else {
            printf("%d ", i + 1);
        };
        for (j = 0; j < 10; j++) {
            if (x[i][j] == 0) {
                printf("| ");
            } else {
                if (x[i][j] == 1) {
                    printf("|X");
                } else {
                    if (x[i][j] == 2) {
                        printf("|#");
                    } else {
                        if (x[i][j] == 3) {
                            printf("|O");
                        };
                    };
                };
            };
        };
        printf(" |\n");
    }
    printf("\n");
    return 0;
}

int dodaj(int p, int x[10][10]) {
    int a = 0, e = 11, f = 11;
    do {
        if (p == 1) {
            printf("Podaj wspolrzedne Twojego statku.\n");
            scanf("%d %d", &e, &f);
            e--;
            f--;
            if (e > 9 || e < 0 || f > 9 || f < 0) {
                do {
                    printf("Przekroczono zakres.\n");
                    printf("Podaj wspolrzedne Twojego statku.\n");
                    scanf("%d %d", &e, &f);
                    e--;
                    f--;
                } while (e > 9 || e < 0 || f > 9 || f < 0);
            };
        } else {
            e = rand() % 10;
            f = rand() % 10;
        };
        if (x[e][f] == 1) {
            if (p == 1) {
                printf("W tym polu jest juz statek!\n");
            };
        } else {
            if (e == 0 && f == 0) {
                if (x[e + 1][f] == 1 || x[e + 1][f + 1] == 1 || x[e][f + 1] == 1) {
                    if (p == 1) {
                        printf("W sasiedztwie juz znajduje sie statek!\n");
                    };
                } else {
                    x[e][f] = 1;
                    a = 1;
                };
            } else {
                if (e == 9 && f == 9) {
                    if (x[e - 1][f] == 1 || x[e - 1][f - 1] == 1 || x[e][f - 1] == 1) {
                        if (p == 1) {
                            printf("W sasiedztwie juz znajduje sie statek!\n");
                        };
                    } else {
                        x[e][f] = 1;
                        a = 1;
                    };
                } else {
                    if (e == 0 && f == 9) {
                        if (x[e][f - 1] == 1 || x[e + 1][f - 1] == 1 || x[e + 1][f] == 1) {
                            if (p == 1) {
                                printf("W sasiedztwie juz znajduje sie statek!\n");
                            };
                        } else {
                            x[e][f] = 1;
                            a = 1;
                        };
                    } else {
                        if (e == 9 && f == 0) {
                            if (x[e - 1][f] == 1 || x[e - 1][f + 1] == 1 || x[e][f + 1] == 1) {
                                printf("W sasiedztwie juz znajduje sie statek!\n");
                            } else {
                                x[e][f] = 1;
                                a = 1;
                            };
                        } else {
                            if (f == 0) {
                                if (x[e - 1][f] == 1 || x[e - 1][f + 1] == 1 || x[e][f + 1] == 1 || x[e + 1][f + 1] == 1 || x[e + 1][f] == 1) {
                                    if (p == 1) {
                                        printf("W sasiedztwie juz znajduje sie statek!\n");
                                    };
                                } else {
                                    x[e][f] = 1;
                                    a = 1;
                                };
                            } else {
                                if (f == 9) {
                                    if (x[e - 1][f] == 1 || x[e - 1][f - 1] == 1 || x[e][f - 1] == 1 || x[e + 1][f - 1] == 1 || x[e + 1][f] == 1) {
                                        if (p == 1) {
                                            printf("W sasiedztwie juz znajduje sie statek!\n");
                                        };
                                    } else {
                                        x[e][f] = 1;
                                        a = 1;
                                    };
                                } else {
                                    if (e == 0) {
                                        if (x[e][f - 1] == 1 || x[e][f + 1] == 1 || x[e + 1][f - 1] == 1 || x[e + 1][f] == 1 || x[e + 1][f + 1] == 1) {
                                            if (p == 1) {
                                                printf("W sasiedztwie juz znajduje sie statek!\n");
                                            };
                                        } else {
                                            x[e][f] = 1;
                                            a = 1;
                                        };
                                    } else {
                                        if (e == 9) {
                                            if (x[e][f - 1] == 1 || x[e][f + 1] == 1 || x[e - 1][f - 1] == 1 || x[e - 1][f] == 1 || x[e - 1][f + 1] == 1) {
                                                if (p == 1) {
                                                    printf("W sasiedztwie juz znajduje sie statek!\n");
                                                };
                                            } else {
                                                x[e][f] = 1;
                                                a = 1;
                                            };
                                        } else {
                                            if (x[e - 1][f - 1] == 1 || x[e - 1][f] == 1 || x[e - 1][f + 1] == 1 || x[e][f - 1] == 1 || x[e][f + 1] == 1 || x[e + 1][f - 1] == 1 || x[e + 1][f] == 1 || x[e + 1][f + 1] == 1) {
                                                if (p == 1) {
                                                    printf("W sasiedztwie juz znajduje sie statek!\n");
                                                };
                                            } else {
                                                x[e][f] = 1;
                                                a = 1;
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    } while (a == 0);
    return 0;
}

int trafiony(int x[10][10], int i, int j) {
    x[i][j] = 2;
    if (i == 0 && j == 0) {
        x[i + 1][j] = 3;
        x[i + 1][j + 1] = 3;
        x[i][j + 1] = 3;
    } else {
        if (i == 9 && j == 9) {
            x[i - 1][j] = 3;
            x[i - 1][j - 1] = 3;
            x[i][j - 1] = 3;
        } else {
            if (i == 0 && j == 9) {
                x[i][j - 1] = 3;
                x[i + 1][j - 1] = 3;
                x[i + 1][j] == 3;
            } else {
                if (i == 9 && j == 0) {
                    x[i - 1][j] = 3;
                    x[i - 1][j + 1] = 3;
                    x[i][j + 1] = 3;
                } else {
                    if (j == 0) {
                        x[i - 1][j] = 3;
                        x[i - 1][j + 1] = 3;
                        x[i][j + 1] = 3;
                        x[i + 1][j + 1] = 3;
                        x[i + 1][j] = 3;
                    } else {
                        if (j == 9) {
                            x[i - 1][j] = 3;
                            x[i - 1][j - 1] = 3;
                            x[i][j - 1] = 3;
                            x[i + 1][j - 1] = 3;
                            x[i + 1][j] = 3;
                        } else {
                            if (i == 0) {
                                x[i][j - 1] = 3;
                                x[i][j + 1] = 3;
                                x[i + 1][j - 1] = 3;
                                x[i + 1][j] = 3;
                                x[i + 1][j + 1] = 3;
                            } else {
                                if (i == 9) {
                                    x[i][j - 1] = 3;
                                    x[i][j + 1] = 3;
                                    x[i - 1][j - 1] = 3;
                                    x[i - 1][j] = 3;
                                    x[i - 1][j + 1] = 3;
                                } else {
                                    x[i - 1][j - 1] = 3;
                                    x[i - 1][j] = 3;
                                    x[i - 1][j + 1] = 3;
                                    x[i][j - 1] = 3;
                                    x[i][j + 1] = 3;
                                    x[i + 1][j - 1] = 3;
                                    x[i + 1][j] = 3;
                                    x[i + 1][j + 1] = 3;
                                };
                            };
                        };
                    };
                };
            };
        };
    };
}

int strzal(int k[10][10], int g1[10][10]) {
    int t, i, j;
    printf("Twoja kolej!\n");
    printf("Podaj wspolrzedne.\n");
    scanf("%d %d", &i, &j);
    i--;
    j--;
    if (i < 0 || i > 9 || j < 0 || j > 9) {
        do {
            printf("Przekroczono zakres.\n");
            printf("Podaj wspolrzedne.\n");
            scanf("%d %d", &i, &j);
            i--;
            j--;
        } while (i > 9 || i < 0 || j > 9 || j < 0);
    };
    if (k[i][j] == 0) {
        printf("Pudlo!\n");
        g1[i][j] = 3;
        k[i][j] = 3;
        t = 0;
    } else {
        if (k[i][j] == 3 || k[i][j] == 2) {
            printf("Juz padl strzal w to pole!\n");
            t = 0;
        };
    };
    if (k[i][j] == 1) {
        trafiony(k, i, j);
        trafiony(g1, i, j);
        t = 1;
    }
    return t;
}

int strzalk(int g[10][10]) {
    int t, i, j, licznik = 0;
    i = rand() % 10;
    j = rand() % 10;
    do {
        i = rand() % 10;
        j = rand() % 10;
        licznik++;
    } while (g[i][j] == 2 || g[i][j] == 3);
    if (g[i][j] == 1) {
        trafiony(g, i, j);
        t = 1;
    } else {
        t = 0;
        g[i][j] = 3;
    };
    return t;
}

void beginGame() {
    srand(time(NULL));
    printf("Gra w statki.\nKazdy z graczy posiada plansze 10x10 na ktorej znajduje sie 8 jednomasztowcow.\n");
    printf("Celem graczy jest zatopienie statkow przeciwnika.\nWygrywa ten, ktory jako pierwszy zatopi statki przeciwnika.\n");
    printf("Kazdy gracz ma jeden strzal na ture.\nTrafienie w statek przeciwnika upowaznia do oddania dodatowego strzalu.\n");
    printf("Statki nie moga sie stykac krawedziani i rogami.\n");
    system("pause");
    system("cls");
}

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

void buildCpuMap() {
    printf("Komputer ustawia swoje statki...\n");
    do {
        dodaj(0, komputer);
        k++;
    } while (k < 8);
    printf("Skończone.\n");
}

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
        playerTurn();
        cpuTurn();
    } while (g > 0 && k > 0);
    endGame();
    return 0;
}


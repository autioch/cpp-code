#include <iostream>
#include <sstream>
#include "plansza.h"

using namespace std;

/* Deklaracje */

int plansza[4][4][4];
int plansza_rozmiar = 3;

#define PUSTE -1
#define KOLKO 0
#define KRZYZ 1

string w_wiersz(int x, int y, bool top);
string w_pole(int x, int y, int z, bool top);

/* Funkcje zewnetrzne */

void plansza_nowa() {
    for (int i = 0; i < plansza_rozmiar; i++) {
        for (int j = 0; j < plansza_rozmiar; j++) {
            for (int k = 0; k < plansza_rozmiar; k++) {
                plansza[i][j][k] = PUSTE;
            }
        }
    }
};

void plansza_rozmiar_ustaw(int rozmiar) {
    if ((rozmiar == 3) || (rozmiar == 4)) {
        plansza_rozmiar = rozmiar;
    }
}

int plansza_rozmiar_podaj() {
    return plansza_rozmiar;
};

bool plansza_pole_ustaw(int x, int y, int z, int w) {
    if ((x > -1) && (x < plansza_rozmiar) && (y > -1) && (y < plansza_rozmiar) && (z > -1) && (z < plansza_rozmiar)) {
        if (plansza[x][y][z] == PUSTE) {
            plansza[x][y][z] = w;
            return true;
        }
    }
    return false;
};

string plansza_wyswietl() {
    string pole;
    if (plansza_rozmiar == 4) {
        for (int i = 0; i < 3; i = i + 2) {
            for (int j = 0; j < 4; j++) {
                if (j > 0) {
                    pole += "\n ----+----+----+----  ----+----+----+----";
                }
                pole = pole + "\n  " + w_wiersz(i, j, 1) + "    " + w_wiersz(i + 1, j, 1);
                pole = pole + "\n  " + w_wiersz(i, j, 0) + "    " + w_wiersz(i + 1, j, 0);
            }
            pole = pole + "\n";
        }
    } else {
        for (int j = 0; j < 3; j++) {
            if (j > 0) {
                pole += "\n ----+----+----  ----+----+----  ----+----+----";
            }
            pole = pole + "\n  " + w_wiersz(0, j, 1) + "    " + w_wiersz(1, j, 1) + "    " + w_wiersz(2, j, 1);
            pole = pole + "\n  " + w_wiersz(0, j, 0) + "    " + w_wiersz(1, j, 0) + "    " + w_wiersz(2, j, 0);
        }
    }
    return pole;
};

int plansza_sprawdz() {
    //TODO
    int suma;
    for (int i = 0; i < plansza_rozmiar; i++) {
        for (int j = 0; j < plansza_rozmiar; j++) {
            for (int k = 0; k < plansza_rozmiar; k++) {
                if (plansza[i][j][k] != PUSTE) {
                    suma++;
                    if (suma > 4) {
                        return 1;
                    }
                }
            }
        }
    }
    return -1;
}

/* Funkcje wewnetrzne */

string w_pole(int x, int y, int z, bool top) {
    string tmp1 = "/\\";
    string tmp2 = "\\/";
    ostringstream ss;
    ss << x << y;
    string pustegora = ss.str();
    ss.str("");
    ss << z << " ";
    string pustedol = ss.str();
    switch (plansza[x][y][z]) {
        case PUSTE: return (top ? pustegora:pustedol);
            break;
        case KOLKO: return (top ? tmp1:tmp2);
            break;
        case KRZYZ: return (top ? tmp2:tmp1);
            break;
        default: return "";
            break;
    };
}

string w_wiersz(int x, int y, bool top) {
    string wiersz;
    wiersz = w_pole(x, y, 0, top);
    for (int i = 1; i < plansza_rozmiar; i++) {
        wiersz += " | ";
        wiersz += w_pole(x, y, i, top);
    }
    return wiersz;
}

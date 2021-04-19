#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "gracz.h"

using namespace std;

/* Deklaracje wewnetrznych zmiennych i funkcji*/

int gracz_lista_ilosc;
gracz * gracz_lista;

/* Funkcje zewnetrzne */

bool gracz_wczytaj(string plik_nazwa) {
    ifstream plik(plik_nazwa.c_str());
    if (plik.is_open()) {
        string linia;
        while (plik.good()) {
            getline(plik, linia);
            if (strlen(linia.c_str()) > 0) {
                gracz_lista_ilosc++;
            }
        }
        /* plik.seekg(0, ios::beg) nie chce dzialac,
         * nawet jesli uzyjemy plik.clear(),
         * dlatego ponownie otwieramy ten sam plik
         */
        plik.close();
        plik.clear();
        plik.open(plik_nazwa.c_str());
        gracz_lista = new gracz[gracz_lista_ilosc];
        int liczba = 0;
        int pos;
        gracz g;
        while (plik.good()) {
            getline(plik, linia);
            if (strlen(linia.c_str()) > 0) {

                pos = linia.find(" ");
                g.imie = linia.substr(0, pos);
                linia = linia.substr(pos + 1);
                pos = linia.find(" ");
                stringstream tmp0(linia.substr(0, pos));
                tmp0 >> g.wygrane;
                linia = linia.substr(pos + 1);
                pos = linia.find(" ");
                stringstream tmp1(linia.substr(0, pos));
                tmp1 >> g.przegrane;
                gracz_lista[liczba] = g;
                liczba++;
            }
        }
        plik.close();
        return true;
    } else {
        gracz_lista_ilosc = 0;
        gracz_lista = new gracz[gracz_lista_ilosc];
        return false;
    }
};

string gracz_pokaz() {
    string lista = " Imie\t\tZagranych\tWygranych\tPrzegranych";
    stringstream tmp;
    for (int i = 0; i < gracz_lista_ilosc; i++) {
        if (strlen(gracz_lista[i].imie.c_str()) > 0) {
            tmp << "\n " << gracz_lista[i].imie;
            tmp << "\t\t" << (gracz_lista[i].wygrane + gracz_lista[i].przegrane);
            tmp << "\t\t" << gracz_lista[i].wygrane;
            tmp << "\t\t" << gracz_lista[i].przegrane;
            lista = lista + tmp.str();
            tmp.str("");
        }
    }
    return lista;
};

gracz gracz_pokaz(string imie) {
    return gracz_lista[gracz_pozycja(imie)];
};

bool gracz_dodaj(string imie) {
    if (gracz_pozycja(imie)>-1) {
        return false;
    }
    gracz * tmp = new gracz[(gracz_lista_ilosc + 1)];
    for (int i = 0; i < gracz_lista_ilosc; i++) {
        tmp[i] = gracz_lista[i];
    }
    //memcpy(tmp, gracz_lista, gracz_lista_ilosc * sizeof (gracz)); <-z jakiegos powodu nie dziala
    delete [] gracz_lista;
    gracz_lista = tmp;
    gracz nowy;
    nowy.imie = imie;
    nowy.wygrane = 0;
    nowy.przegrane = 0;
    gracz_lista[gracz_lista_ilosc++] = nowy;
    return true;
}

bool gracz_usun(string imie) {
    int pos = gracz_pozycja(imie);
    if (pos>-1) {
        gracz_lista[pos].imie = "";
        return true;
    }
    return false;
}

int gracz_pozycja(string imie) {
    for (int i = 0; i < gracz_ilosc(); i++) {
        if (strcmp(gracz_lista[i].imie.c_str(), imie.c_str()) == 0) {
            return i;
        }
    }
    return -1;
};

bool gracz_wynik_dodaj(string imie, bool wygrana) {
    int pos = gracz_pozycja(imie);
    if (pos>-1) {
        if (wygrana) {
            gracz_lista[pos].wygrane++;
        } else {
            gracz_lista[pos].przegrane++;
        }
        return true;
    }
    return false;
};

bool gracz_zapisz(string plik_nazwa) {
    ofstream plik(plik_nazwa.c_str());
    if (plik.is_open()) {
        for (int i = 0; i < gracz_ilosc(); i++) {
            if (strlen(gracz_lista[i].imie.c_str()) > 0) {
                plik << gracz_lista[i].imie;
                plik << " " << gracz_lista[i].wygrane;
                plik << " " << gracz_lista[i].przegrane;
                plik << endl;
            }
        }
        plik.close();
        return true;
    }
    return false;
};

void gracz_uwolnij() {
    delete [] gracz_lista;
}

int gracz_ilosc() {
    return gracz_lista_ilosc;
}

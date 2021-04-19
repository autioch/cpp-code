/* 
 * File:   Plansza.cpp
 * Author: Oskar
 * 
 * Created on 27 maj 2012, 12:39
 */

#include "Plansza.h"
#include "Gracz.h"
#include "Potwor.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <windows.h>
using namespace std;

Plansza::Plansza() {
}

Plansza::Plansza(const Plansza& orig) {
}

Plansza::~Plansza() {
}

void Plansza::wstawPlansza1() { // wygenerowanie planszy 1 z pliku 
    fstream plik("plansza1.txt", std::ios::in); //zakładamy, że plik istnieje
    char dane[ 1024 ];
    int pom = 0;
    cout << "\t\t\t\tPierwsze starcie\n";
    while (!plik.eof()) {
        plik.read(dane, 76); //wczytuje dane do końca linijki z pliku
        for (int i = pom; i <= pom; i++) {
            for (int j = 0; j < 75; j++) {
                plansza[i][j] = dane[j];
                //UstalPozycjeGracza(i, j);
            }
        }
        pom++;
        if (pom == 21) break;
    }
    plik.close();
}

void Plansza::wstawPlansza2() { // wygenerowanie planszy 2 z pliku 
    fstream plik("plansza2.txt", std::ios::in); //zakładamy, że plik istnieje
    char dane[ 1024 ];
    int pom = 0;
    cout << "\t\t\t\tNieznany tekst\n";
    while (!plik.eof()) {
        plik.read(dane, 76); //wczytuje dane do końca linijki z pliku
        for (int i = pom; i <= pom; i++) {
            for (int j = 0; j < 75; j++) {
                plansza[i][j] = dane[j];
            }
        }
        pom++;
    }
    plik.close();
}

void Plansza::wyswietlPlansze() { // wyświetlanie planszy
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 75; j++) {
            if (plansza[i][j] == 'o') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << plansza[i][j];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                if (plansza[i][j] == 'A') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << plansza[i][j];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                } else cout << plansza[i][j];
            }

        }
        cout << endl;
    }
}

void Plansza::ustalPozycjeGracza(int &a, int &b) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 75; j++) {
            if ((plansza[i][j] == 'o') || (plansza[i][j] == 'O')) {
                a = i;
                b = j;
            }
        }
    }
}

void Plansza::ustawieniePozycjiPotworow(int& a, int& b, int tablica[20]) {
    int n = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 75; j++) {
            if (plansza[i][j] == 'P') {
                a = i;
                b = j;
                tablica[n++] = a;
                tablica[n++] = b;
            }
        }
    }
    //for (int i=0; i<20; i++)
    //  cout << tablica[i] << " ";
}

/*
void Plansza::ustawieniePozycjiCelu(int& a, int& b) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 75; j++) {
            if (plansza[i][j] == 'A') {
                a = i;
                b = j;
            }
        }
    }
}*/

int Plansza::koniecGry() {
    int a, b;
    ustalPozycjeGracza(a, b);
    int koniec = 0;
    if (plansza[a][b] == 'O')
        koniec = 1;
    else koniec = 0;
    return koniec;
}

void Plansza::granie(Plansza &p) {
    Potwor pot;
    pot.pozycjapom(p);
    Gracz g;
    g.zycie(p);
    //g.pozycjaNaPlanszy(p);
    g.ustawienieTablicyDlaGracza(p);
    
    int licznik = 1;
    int wejscie = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 75; j++) {
            if (plansza[i][j] == 'P') {
                plansza[i][j] = ' ';
                int a = pot.tab[licznik++]->ruch(p);
                if (plansza[a][j] == 'o') {
                    plansza[2][2] = 'o';
                    plansza[a][j] = 'q';
                } else
                    plansza[a][j] = 'q';

                //cout << i << j;
            }

            if ((plansza[i][j] == 'o') && (wejscie == 1)) {
                plansza[i][j] = ' ';
                //plansza[g.ruchDoGory()][j] = 'o';
                int a = g.tab[0]->ruch(p);
                wykoanieRuchu(i, j, a);
                //if (a == 0) plansza[i][j] = 'o';
                //if (a == 1) plansza[i - 1][j] = 'o';
                //if (a == 2) plansza[i + 1][j] = 'o';
                //if (a == 3) plansza[i][j - 1] = 'o';
                //if (a == 4) plansza[i][j + 1] = 'o';
                wejscie = 0;
            }

        }
    }
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 75; j++) {
            if (plansza[i][j] == 'q')
                plansza[i][j] = 'P';
        }
    //cout << pot.tab[licznik++]->ruch();
    cout << pot.zwrocLiczbePotworow();
}

int Plansza::sprawdzenieRuchu(int& a, int& b) {
    if (plansza[a][b] == 'X')
        return 1;
    else
        return 0;

}

void Plansza::wykoanieRuchu(int& i, int& j, int &a) {
    if (a == 0) {
        if ((plansza[i][j] == 'P') || (plansza[i][j] == 'q'))
            plansza[2][2] = 'o';
        else
            plansza[i][j] = 'o';
    }

    if (a == 1) {
        if (plansza[i - 1][j] != 'A') {
            if ((plansza[i - 1][j] == 'P') || (plansza[i - 1][j] == 'q')){
                plansza[2][2] = 'o';
            }
            else
                plansza[i - 1][j] = 'o';
        } else plansza[i - 1][j] = 'O';
    }

    //if (a == 2) {
    //  if (plansza[i + 1][j]!='A')
    //          plansza[i + 1][j] = 'o';
    //  else plansza[i + 1][j] = 'O';
    //}

    if (a == 2) {
        if (plansza[i + 1][j] != 'A') {
            if ((plansza[i + 1][j] == 'P') || (plansza[i + 1][j] == 'q'))
                plansza[2][2] = 'o';
            else
                plansza[i + 1][j] = 'o';
        } else plansza[i + 1][j] = 'O';
    }

    if (a == 3) {
        if (plansza[i][j - 1] != 'A') {
            if ((plansza[i][j - 1] == 'P') || (plansza[i][j - 1] == 'q')) {
                plansza[2][2] = 'o';
            } else
                plansza[i][j - 1] = 'o';
        } else plansza[i][j - 1] = 'O';
    }

    if (a == 4) {
        if (plansza[i][j + 1] != 'A') {
            if ((plansza[i][j + 1] == 'P') || (plansza[i][j + 1] == 'q'))
                plansza[2][2] = 'o';
            else
                plansza[i][j + 1] = 'o';
        } else plansza[i][j + 1] = 'O';
    }
}

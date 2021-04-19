#include <string>

using namespace std;

#ifndef GRACZ_H
#define	GRACZ_H

struct gracz{
        string imie;
        int wygrane;    
        int przegrane;    
};

bool gracz_wczytaj(string plik_nazwa);
gracz gracz_pokaz(string imie);
string gracz_pokaz();
bool gracz_dodaj(string imie);
bool gracz_usun(string imie);
int gracz_pozycja(string imie);
bool gracz_wynik_dodaj(string imie, bool wygrana);
bool gracz_zapisz(string plik_nazwa);
void gracz_uwolnij();
int gracz_ilosc();

#endif	/* GRACZ_H */

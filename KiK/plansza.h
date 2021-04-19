#include <string>

using namespace std;

#ifndef PLANSZA_H
#define	PLANSZA_H

void plansza_nowa();
void plansza_rozmiar_ustaw(int rozmiar);
int plansza_rozmiar_podaj();
bool plansza_pole_ustaw(int x, int y, int z,int w);
string plansza_wyswietl();
int plansza_sprawdz();

#endif	/* PLANSZA_H */

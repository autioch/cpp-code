/* 
 * File:   Potwor.h
 * Author: Oskar
 *
 * Created on 27 maj 2012, 14:41
 */
#include "Obiekt.h"
#include "Plansza.h"
#include <ctime>
#include <iostream>
using namespace std;
#ifndef POTWOR_H
#define	POTWOR_H

class Potwor : public Obiekt {
public:
    Potwor();

    Potwor(int a, int b) {
        x = a;
        y = b;        
    }

    Potwor(const Potwor& orig);
    virtual ~Potwor();

    void pozycjaNaPlanszy(Plansza &p) {
        cout << x << y;
    }

    //int zwrocPozycjeX() {
      //  return x;
    //}

    //int zwrocPozycjeY() {
      //  return y;
    //}

    int zwrocLiczbePotworow() {
        return liczbaPotworow;
    }

    void pozycjapom(Plansza &p) { // wyszukanie i zapisanie pozycji 
        int licznik = 1; // potworow do tablica obiektow
        int tablica[20];
        for (int i = 0; i < 20; i++)
            tablica[i] = 0;
        p.ustawieniePozycjiPotworow(x, y, tablica);

        //for (int i = 0; i < 20; i++)
        //cout << tablica[i] << " ";
        for (int i = 0; i < 20; i++) {
            if (tablica[i] == 0)
                break;

            if (i % 2 == 0)
                tab[licznik++] = new Potwor(tablica[i], tablica[i + 1]);
        }
        liczbaPotworow = licznik-1;
        //for (int i=0; i<licznik; i++)
        //  tab[i]->pozycjaNaPlanszy(p);
    }

    void zycie(Plansza &p) {
    }

    int ruch(Plansza &p) {
        srand( time( NULL ) );
        int wylosowana_liczba =( rand() % 2 );
        //cout << p.sprawdzenieRuchu(x,y);
        if (wylosowana_liczba == 1){
            x++;
            if (p.sprawdzenieRuchu(x,y)==1)
                x--;      
        }
        else{
            x--;
            if (p.sprawdzenieRuchu(x,y)==1)
                x++;
        }
        return x;
    }



private:
    int x;
    int y;
    int liczbaPotworow;

};

#endif	/* POTWOR_H */


/* 
 * File:   Gracz.h
 * Author: Oskar
 *
 * Created on 27 maj 2012, 12:45
 */
#include "Plansza.h"
#include "Obiekt.h"
#include <iostream>
#include <conio.h>
using namespace std;
#ifndef GRACZ_H
#define	GRACZ_H

class Gracz : public Obiekt {
public:
    Gracz();

    Gracz(int x, int y) {
        a = x;
        b = y;
        liczba_zyc = 2;
    }

    Gracz(const Gracz& orig);
    virtual ~Gracz();

    int ruch(Plansza &p) {
        char znak = getch();
        switch (znak) {
            case 119://w gore                
                a = a - 1;
                if (p.sprawdzenieRuchu(a, b) == 1) {
                    a = a + 1;
                    return 0;
                }
                return 1;
                break;
            case 115:// w dol                
                a = a + 1;
                if (p.sprawdzenieRuchu(a, b) == 1) {
                    a = a - 1;
                    return 0;
                }
                return 2;
                break;
            case 97://w lewo                
                b = b - 1;
                if (p.sprawdzenieRuchu(a, b) == 1) {
                    b = b + 1;
                    return 0;
                }
                return 3;
                break;
            case 100://w prawo                
                b = b + 1;
                if (p.sprawdzenieRuchu(a, b) == 1) {
                    b = b - 1;
                    return 0;
                }
                return 4;
                break;
        }

    }

    void pozycjaNaPlanszy(Plansza &p) { // ustawienie pozycji gracza na planszy
        p.ustalPozycjeGracza(a, b);
        //cout << a << " " << b;
    }

    int zwrocPozycjeGraczaX() {
        return a;
    }

    int zwrocPozycjeGraczaY() {
        return b;
    }

    void zycie(Plansza &p) {
        //cout << liczba_zyc;
    }
    
    int zmniejszLiczbeZyc(){
        liczba_zyc--;
        return liczba_zyc;
    }
    
    int zwiekszLiczbeZyc(){
        liczba_zyc++;
        return liczba_zyc;
    }

    



    //int ruchDoGory() {//(int &x, int &y) {
    //  //x = x - 1;
    //  a--;
    //  return a;
    //}

    //int ruchNaDol() {
    //  a++;
    //  return a;
    //}

    //int ruchNaPrawo() {
    //  b++;
    //  return b;
    //}

    //int ruchNaLewo() {
    //  b--;
    //  return b;
    //}

    void ustawienieTablicyDlaGracza(Plansza &p) {
        p.ustalPozycjeGracza(a, b);
        tab[0] = new Gracz(a, b);
        
    }

private:
    int a;
    int b;
    int liczba_zyc;
};

#endif	/* GRACZ_H */


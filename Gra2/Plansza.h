/* 
 * File:   Plansza.h
 * Author: Oskar
 *
 * Created on 27 maj 2012, 12:39
 */
//#include "Obiekt.h"
#ifndef PLANSZA_H
#define	PLANSZA_H

class Plansza {
public:
    Plansza();
    Plansza(const Plansza& orig);
    virtual ~Plansza();
    
    void wstawPlansza1();
    void wstawPlansza2();
    void wyswietlPlansze();
    void ustalPozycjeGracza(int &a, int &b);
    void ustawieniePozycjiPotworow(int &a, int &b, int tablica[20]);
    int koniecGry();
    void granie(Plansza &p);
    int sprawdzenieRuchu(int &a, int &b);
    //void ustawieniePozycjiCelu(int &a, int &b);
    void wykoanieRuchu(int &i, int &j, int &a);
    
    
private:
    char plansza[20][75];
    //Obiekt* tablica[20];
};

#endif	/* PLANSZA_H */


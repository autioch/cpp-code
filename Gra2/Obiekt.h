/* 
 * File:   Obiekt.h
 * Author: Oskar
 *
 * Created on 27 maj 2012, 12:35
 */
#include "Plansza.h"
#ifndef OBIEKT_H
#define	OBIEKT_H

class Obiekt {
public:
    Obiekt();
    Obiekt(const Obiekt& orig);
    virtual ~Obiekt();
    
    virtual int ruch(Plansza &p) = 0;
    virtual void pozycjaNaPlanszy(Plansza &p) = 0;
    virtual void zycie(Plansza &p) = 0;
    Obiekt* tab[20];
    
    
private:
    
};

#endif	/* OBIEKT_H */


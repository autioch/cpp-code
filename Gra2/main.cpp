
#include <cstdlib>
#include <iostream>
#include "Plansza.h"
#include "Gracz.h"
#include "Obiekt.h"
#include "Potwor.h"

using namespace std;

int main(int argc, char** argv) {
    Plansza p;
    p.wstawPlansza1();
    p.wyswietlPlansze();
    //Gracz g;
    //g.pozycjaNaPlanszy(p);
    //pot.pozycjapom(p);
    
    //pot.tab[0]->pozycjaNaPlanszy(p);
    //pot.tab[1]->pozycjaNaPlanszy(p);
    
    while(p.koniecGry()!=1)
    {
        p.granie(p);
        p.wyswietlPlansze();
    }
    
    //for (int i = 0; i < 40; i++) {
        //cin.ignore();
        
      //  p.granie(p);
      //  p.wyswietlPlansze();
    //}



    cin.ignore();
    return 0;
}


#include <cstdlib>
#include <iostream>
#include <string>
#include "kontrola.h"

using namespace std;

int main(int argc, char** argv) {
    kontrola_start();
    char decyzja;
    do {
        kontrola_menu();
        decyzja = kontrola_wybor();
        switch (decyzja) {
            case 'q': break;            
            case 'g': kontrola_graj();
                break;
            case 'l': kontrola_plansza();
                break;
            case 'r': kontrola_gracz();
                break;
            case 'p': kontrola_pomoc();
                break;
            default: break;
        }
    } while (decyzja != 'q');
    kontrola_koniec();
    return 0;
}

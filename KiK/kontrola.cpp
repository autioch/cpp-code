#include <iostream>
#include "kontrola.h"
#include "gracz.h"
#include "plansza.h"

using namespace std;

/* Deklaracje */

int gracz = 0;
int wynik = -1;
int rozmiar = 4;
string gracz1 = "gosc";
string gracz2 = "gosc";
#define LISTA_GRACZY "lista_graczy.txt"

struct pozycja {
    int x;
    int y;
    int z;
};

void kontrola_czekaj();
void kontrola_graj_nowa();
void kontrola_graj_ruch();
void kontrola_gracz_dodaj();
void kontrola_gracz_usun();
void kontrola_gracz_wybierz();
void kontrola_gracz_wygrana();
void kontrola_gracz_stan_gry();

/* Funkcje zewnetrzne */

void kontrola_start() {
    system("cls");
    if (!gracz_wczytaj(LISTA_GRACZY)) {
        printf("\n Blad przy probie odczytu danych graczy z %s.", LISTA_GRACZY);
        printf("\n Upewnij sie co do istnienia pliku i praw odczytu/zapisu.");
        printf("\n Jesli plik nie istnieje, program sprobuje stworzyc plik,");
        printf("\n aby umozliwic zapis wynikow po zakonczeniu gry.\n");
        kontrola_czekaj();
    }
    plansza_nowa();
};

void kontrola_koniec() {
    system("cls");
    if (!gracz_zapisz(LISTA_GRACZY)) {
        printf("\n Blad przy probie zapisu danych graczy do %s.", LISTA_GRACZY);
        printf("\n Upewnij sie co do istnienia pliku i praw odczytu/zapisu.");
        printf("\n Jesli plik nie istnieje, program sprobuje stworzyc plik,");
        printf("\n aby umozliwic zapis wynikow po zakonczeniu gry.\n");
    }
    gracz_uwolnij();
    cout << "\n Dzieki za gre. Milego dnia!\n ";
    //getchar();    
};

void kontrola_menu() {
    system("cls");
    printf(" G Graj    L Plansza    R Gracze    P Pomoc    Q Koniec\n");
    printf("\n Plansza:\t\t%dx%dx%d", plansza_rozmiar_podaj(), plansza_rozmiar_podaj(), plansza_rozmiar_podaj());
    printf("\n Gracze: \t\t%s vs %s", gracz1.c_str(), gracz2.c_str());
    printf("\n Graczy ogolem: \t%d", gracz_ilosc());
};

char kontrola_wybor() {
    printf("\n\n Wcisnij litere z menu i zatwierdz [enter]: ");
    fflush(stdin);
    return getchar();
    fflush(stdin);
};

void kontrola_graj() {
    char decyzja;
    do {
        system("cls");
        printf(" N Nowa plansza    R Wykonaj ruch    Q Glowne menu");
        printf("\n");
        printf(plansza_wyswietl().c_str());
        decyzja = kontrola_wybor();
        switch (decyzja) {
            case 'q': break;
            case 'n': kontrola_graj_nowa();
                break;
            case 'r': kontrola_graj_ruch();
                break;
            default: break;
        }
    } while (decyzja != 'q');
};

void kontrola_plansza() {
    char decyzja;
    system("cls");
    printf(" Wybierz rozmiar planszy: 3 lub 4.");
    printf("\n Aktualna gra zostanie utracona.");
    printf("\n Dowolny inny przycisk anuluje reset gry i zmiane rozmiaru.");
    decyzja = kontrola_wybor();
    switch (decyzja) {
        case 'q': break;
        case '3': plansza_rozmiar_ustaw(3);
            plansza_nowa();
            break;
        case '4':
            plansza_rozmiar_ustaw(4);
            plansza_nowa();
            break;
        default: break;
    }
};

void kontrola_gracz() {
    char decyzja;
    do {
        system("cls");
        printf(" N Nowy gracz    U Usun gracza    W Wybierz    Q Glowne menu");
        printf("\n\n Gracz 1: %s Gracz 2: %s\n\n", gracz1.c_str(), gracz2.c_str());
        printf(gracz_pokaz().c_str());
        decyzja = kontrola_wybor();
        switch (decyzja) {
            case 'q': break;
            case 'n': kontrola_gracz_dodaj();
                break;
            case 'u': kontrola_gracz_usun();
                break;
            case 'w': kontrola_gracz_wybierz();
                break;
            default: break;
        }
    } while (decyzja != 'q');
};

void kontrola_pomoc() {
    cout << "\nKolko i krzyzyk 3d.";
    cout << "\nPlansza do gry to szescian o boku 3x3 lub 4x4.";
    cout << "\nPuste pola maja wypisane swoje wspolrzedne.";
    cout << "\nObsluga graczy nie jest aktualnie dostepna.";
    cout << "\n";
    kontrola_czekaj();
};

/* Funkcje wewnetrzne */

void kontrola_czekaj() {
    fflush(stdin);
    cout << "\n\n Nacisnij dowolny przycisk, aby kontynuowac...";
    getchar();
}

void kontrola_graj_nowa() {
    char decyzja;
    system("cls");
    if (wynik == -1) {
        printf(" Czy na pewno chcesz zresetowac gre? ");
        printf("\n Wybierz t, aby potwierdzic.");
        printf("\n Dowolny inny przycisk anuluje reset gry.");
        decyzja = kontrola_wybor();
        if (decyzja != 't') {
            return;
        }
    }
    plansza_nowa();
    wynik = -1;
};

void kontrola_graj_ruch() {
    kontrola_gracz_stan_gry();    
    if (wynik>-1) {
        return;
    }
    pozycja p;
    char ruch[4];
    cout << "\nPodaj pozycje do wykonania ruchu (trzy cyfry bez spacji): ";
    fflush(stdin);
    cin >> ruch;
    if ((isdigit(ruch[0])) && (isdigit(ruch[1])) && (isdigit(ruch[2]))) {
        p.x = (int) ruch[0] - 48;
        p.y = (int) ruch[1] - 48;
        p.z = (int) ruch[2] - 48;
        if (!plansza_pole_ustaw(p.x, p.y, p.z, gracz)) {
            cout << "\nNie mozesz wykonac ruchu w tym miejscu.";
            kontrola_czekaj();
        } else {
            wynik = plansza_sprawdz();
            if (wynik > -1) {
                kontrola_gracz_wygrana();
            } else {
                gracz = (gracz + 1) % 2;
            }
        }
    } else {
        cout << "\nBlednie podane wspolrzedne ruchu.";
    };
};

void kontrola_gracz_dodaj() {
    string imie;
    cout << "\nWprowadz imie nowego gracza: ";
    cin >> imie;
    if (gracz_dodaj(imie)) {
        cout << "\nDodano nowego gracza.";
    } else {
        cout << "\nNie mozna dodac gracza o imieniu " << imie << ".";
    };
    kontrola_czekaj();
}

void kontrola_gracz_usun() {
    string imie;
    gracz_pokaz();
    cout << "\nWprowadz imie gracza do usuniecia: ";
    cin >> imie;
    if (gracz_usun(imie)) {
        cout << "\nUsunieto gracza.";
    } else {
        cout << "\nNie usunieto gracza o imieniu " << imie << ".";
    };
    kontrola_czekaj();
};

void kontrola_gracz_wybierz() {
    string imie;
    gracz_pokaz();
    cout << "\nWprowadz imie pierwszego gracza: ";
    cin >> imie;
    if (gracz_pozycja(imie)>-1) {
        gracz1 = imie;
        cout << "\nWprowadz imie drugiego gracza: ";
        cin >> imie;
        if (gracz_pozycja(imie)>-1) {
            gracz2 = imie;
        } else {
            cout << "\nNie znaleziono gracza o imieniu " << imie << ".";
        };

    } else {
        cout << "\nNie znaleziono gracza o imieniu " << imie << ".";
    };
};

void kontrola_gracz_wygrana() {
    if (wynik == 0) {
        if (gracz_pozycja(gracz1)>-1) {
            gracz_wynik_dodaj(gracz1, true);
        }
        if (gracz_pozycja(gracz2)>-1) {
            gracz_wynik_dodaj(gracz2, false);
        }
    } else {
        if (wynik == 1) {
            if (gracz_pozycja(gracz1)>-1) {
                gracz_wynik_dodaj(gracz1, false);
            }
            if (gracz_pozycja(gracz2)>-1) {
                gracz_wynik_dodaj(gracz2, true);
            }

        }
    }
    kontrola_czekaj();
}

void kontrola_gracz_stan_gry() {
    if (wynik == 0) {
        cout << "\n Wygral kolko: " << gracz1;
        return;
    } else {
        cout << "\n Wygral krzyzyk: " << gracz2;
        return;
    }
    cout << "Ruch: " << ((gracz > 0) ? "krzyzyk" : "kolko");
}
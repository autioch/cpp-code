#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <math.h>
 
using namespace std;
 
int main()
{
    srand(time(NULL));
 
    ofstream plik_do_pisania("info.dat");
 
    float prec = 1000000; 
 
    int A, B;
    int liczby[] = {10, 100, 1000, 10000, 100000, 1000000};
 
    float czasytworzenia[6];
    float czasyzapisu[6];
    float czasyodczytu[6];
 
    fstream pliki[6];
    pliki[0].open ("plik1.txt", std::fstream::in | std::fstream::out);
    pliki[1].open ("plik2.txt", std::fstream::in | std::fstream::out);
    pliki[2].open ("plik3.txt", std::fstream::in | std::fstream::out);
    pliki[3].open ("plik4.txt", std::fstream::in | std::fstream::out);
    pliki[4].open ("plik5.txt", std::fstream::in | std::fstream::out);
    pliki[5].open ("plik6.txt", std::fstream::in | std::fstream::out);
 
    cout << "Podaj poczatek i koniec przedzialu: " << endl;
 
    cin >> A >> B;
 
    plik_do_pisania << A << endl << B;
 
    // TWORZENIE DANYCH
    for(int p=0;p<6;p++)
    {
        clock_t czas;
        czas = clock();
 
        for(int i=0;i<liczby[p];i++)
        {
            int pocz = A*prec;
            int koniec = B*prec;
 
            float t = rand() % koniec + pocz;
            t/=prec;
        }
 
        czas = clock() - czas;
        czasytworzenia[p] = czas;
        czasytworzenia[p]=float(czasytworzenia[p])/1000;
    }
 
    // ZAPIS DO PLIKU
 
    for(int p=0;p<6;p++)
    {
        clock_t czas;
        czas = clock();
 
        for(int i=0;i<liczby[p];i++)
        {
            int pocz = A*prec;
            int koniec = B*prec;
 
            float t = rand() % koniec + pocz;
            t/=prec;
            pliki[p] << t << " ";
        }
 
        czas = clock() - czas;
        czasyzapisu[p] = czas - czasytworzenia[p];
        czasyzapisu[p]=float(czasyzapisu[p])/1000;
    }
 
    // ODCZYT Z PLIKU
 
    for(int p=0;p<6;p++)
    {
        clock_t czas;
        czas = clock();
 
        for(int i=0;i<liczby[p];i++)
        {
            float k;
            pliki[p] >> k;
        }
 
        czas = clock() - czas;
        czasyodczytu[p] = czas;
        czasyodczytu[p]=float(czasyodczytu[p])/1000;
    }
 
    cout << "|----------------------------------------------------------------------|" << endl;
    cout << "|rozmiar_danych | czas_tworzenia_danych | czas_pisania | czas_czytania |" << endl;
    cout << "|----------------------------------------------------------------------|" << endl;
    for(int i=0;i<6;i++)
    {
        cout << "|";
        cout.width(11);
        cout.setf(ios::right);
        cout << liczby[i];
        cout.unsetf(ios::right);
        cout << "    |    ";
        
        cout.precision(10);
        cout.setf( std::ios::fixed, std:: ios::floatfield );
        cout << czasytworzenia[i] << "       | " << czasyzapisu[i] << " | " << czasyodczytu[i] << "  |";
        cout << endl;
    }
 
    return 0;
}

/* 
 * File:   main.cpp
 * Author: Jakub
 *
 * Created on 2 grudzień 2011, 19:29
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (){
string keyboard;
char * read;
FILE * testfile;

/*
 * Tutaj jeszcze udało się wczytywać całą linię naraz.
 * Jesli nie uzyje sie "getline", przykladowe "testowe zdanie numer jeden"
 * miałoby każde slowo zapisane w nowej linii (specyfika scanf). Jesli
 * jest uzyte, cos, czego nie znasz -> google it.
 */
printf("Wpisuj linie do zapisania do pliku. (\"0\" aby zakonczyc):\n");
testfile = fopen("fopen.txt","w");
if (testfile!=NULL){
    getline(cin,keyboard);
    while(strcmp(keyboard.c_str(),"0")!=0){
        fprintf(testfile,keyboard.c_str());
        fprintf(testfile,"\n");
        getline(cin,keyboard);
    }
    fclose(testfile);
}
/*
 * Nie znalazlem zadnego sposobu na zachowanie ciagu linii w fscanf, jesli 
 * nie znamy skladu linii - w przypadku linii o roznej ilosci wyrazow
 * fscanf jest po prostu bezuzyteczny, jesli chcemy zachowac strukture.
 * Polecam fgetc() (znak po znaku) lub gets() (cala linia). Wiecej na google.
 * No dobra, mozna poczytac tutaj: http://mrx.net/c/readfunctions.html.
 */
printf("Odczytywanie danych zapisanych w pliku:\n");
testfile = fopen("fopen.txt","r");
if (testfile!=NULL){
    while(fscanf(testfile,"%s",read)){
        printf("%s ",read);        
        if (feof(testfile)){
            break;
        }        
    }
    fclose(testfile);
}

}

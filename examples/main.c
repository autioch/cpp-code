#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int nazwa_funkcji(int argument, int arg2){
	return 0;
}


int main(int argc, char *argv[]) {
	/*int a,b,c;
	printf("Witaj w kalkulatorze!\nWprowadz 1 liczbe: ");
	scanf("%d",&a);
	printf("\nWprowadz 2 liczbe: ");
	scanf("%d",&b);*/
	/*
	int a,b;
	printf("Witaj w programie nr 2!\nWprowadz 1 liczbe: ");
	scanf("%d",&a);
	printf("\nWprowadz 2 liczbe: ");
	scanf("%d",&b);
	int i; // i od iterator
	for (i=a;i<b;i++){
		printf("\n%d",i);
	}*/

	/*
	int a,b,c;
	printf("Witaj w programie nr 3!\nWprowadz 1 liczbe: ");
	scanf("%d",&a);
	printf("\nWprowadz 2 liczbe: ");
	scanf("%d",&b);
	printf("\nWpisz 0 jesli chcesz dodawac, 1 jesli chcesz odejmowac, 2 jesli chcesz mnozyc, 3 jesli chcesz dzielic: ");
	scanf("%d",&c);
	if (c == 0){
		printf("Wynik dodawania %d i %d to: %d",a,b,a+b);
	} else {
		if ( c==1){
		printf("Wynik odejmowania %d i %d to: %d",a,b,a-b);
		} else {
			if (c==2){
			printf("Wynik mnozenia %d i %d to: %d",a,b,a*b);
			} else {
				printf("Wynik dzielenia %d i %d to: %d, reszta %d",a,b,a/b,a%b);
			}
		}
	}
	*/
	
	int a,b;
	char o;
	printf("\nWprowadz 1 liczbe: ");
	scanf("%d",&a);
	printf("\nWprowadz 2 liczbe: ");
	scanf("%d",&b);
	printf("\nWpisz + jesli chcesz dodawac, - jesli chcesz odejmowac, * jesli chcesz mnozyc, / jesli chcesz dzielic: ");
	fflush(stdin);
	//o = getchar();
	scanf("%c",&o);
	
	//printf("\nWybrales operacje %c.",o);
	
	/*if (o == '+'){
		printf("Wynik dodawania %d i %d to: %d",a,b,a+b);
	} else {
		if ( o=='-'){
		printf("Wynik odejmowania %d i %d to: %d",a,b,a-b);
		} else {
			if (o=='*'){
			printf("Wynik mnozenia %d i %d to: %d",a,b,a*b);
			} else {
				printf("Wynik dzielenia %d i %d to: %d, reszta %d",a,b,a/b,a%b);
			}
		}
	}	*/
	
	switch(o){
		case '+': printf("Wynik dodawania %d i %d to: %d",a,b,a+b); 
		case '-': printf("Wynik odejmowania %d i %d to: %d",a,b,a-b); 
		case '*': printf("Wynik mno¿enia %d i %d to: %d",a,b,a*b); 
		case '/': printf("Wynik dzielenia %d i %d to: %d, reszta %d",a,b,a/b,a%b); 
		default: printf("Wybrales/as nieprawidlowa opcje kalkulatora.");	
	}
	printf("\nKoniec programu.\n");
	
	system("pause");		
	return 0;
}

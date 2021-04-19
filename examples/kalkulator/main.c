#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("Witaj w kalkulatorze.");
	int a,b;
	printf("\nWprowadz liczbe a: ");
	scanf("%d",&a);
	printf("\nWprowadz liczbe b: ");
	scanf("%d",&b);
	printf("\nWpisz +,-,*,/ jako wybor operacji:");
	char o;
	fflush(stdin);
	scanf("%c",&o);
	switch (o){
		case '+': printf("%d + %d = %d",a,b,a+b); break;
		case '-': printf("%d - %d = %d",a,b,a-b); break;
		case '*': printf("%d * %d = %d",a,b,a*b); break;
		case '/': printf("%d / %d = %d reszta %d",a,b,a/b,a%b); break;
		default: printf("Nie wprowadzono prawidlowego znaku.");
	}
	return 0;
}

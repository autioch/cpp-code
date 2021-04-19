#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int suma,a;
	suma = 0;
	printf("Dodajemy liczby dopoki nie dostaniemy zera.");
	printf("\nWprowadz liczbe: ");
	scanf("%d",&a);
	while( a != 0){
		suma = suma + a; //jak zapisac to krocej?
		printf("Wprowadz liczbe: ");
		scanf("%d",&a);
	};
	printf("Suma wynosi %d",suma);
	
	return 0;
}

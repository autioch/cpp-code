#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int liczby[10];
	int i,suma;
	suma = 0;
	for (i=0;i<10;i++){
	scanf("%d",&liczby[i]);
	suma = suma + liczby[i];
	};
	for (i=0;i<10;i++){
		printf("%d ",liczby[i]);
	}
	printf("Suma: %d",suma);
	printf("\nSrednia: %f",suma/10);
	return 0;
}

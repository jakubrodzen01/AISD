#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorytmy.h"

#pragma warning(disable: 4996)

int main()
{
	int *tab, n;
	printf("Podaj wielkosc tablicy: ");
	scanf("%d", &n);
	tab =(unsigned int *) malloc(n * sizeof(int));

	FILE* fp = NULL;
	if (!(fp = fopen("dane", "r")))
	{
		printf("Blad otwarcia pliku dane");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf(fp, "%d", &tab[i]);
	printf("\n insertsort: ");
	insertsort(tab, n);
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	
	if (!(fp = fopen("dane", "r")))
	{
		printf("Blad otwarcia pliku dane");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf(fp, "%d", &tab[i]);
	printf("\n selectionsort: ");
	selectionsort(tab, n);
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	
	if (!(fp = fopen("dane", "r")))
	{
		printf("Blad otwarcia pliku dane");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf(fp, "%d", &tab[i]);
	printf("\n bubblesort:");
	bubblesort(tab, n);
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	
	
	if (!(fp = fopen("dane", "r")))
	{
		printf("Blad otwarcia pliku dane");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf(fp, "%d", &tab[i]);
	printf("\n quicksort:");
	quicksort(tab, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	
	if (!(fp = fopen("dane", "r")))
	{
		printf("Blad otwarcia pliku dane");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf(fp, "%d", &tab[i]);
	printf("\n shellsort:");
	shellsort(tab, n);
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	if (!(fp = fopen("dane", "r")))
	{
		printf("Blad otwarcia pliku dane");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf(fp, "%d", &tab[i]);
	printf("\n heapsort:");
	heapsort(tab, n);
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	
	return 0;
}
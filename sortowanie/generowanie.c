#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable: 4996)

void generowanie(int n)
{
	FILE *fp;
	fp = fopen("dane.txt", "w");
	srand( time(NULL) );
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", rand() % 201 - 100);
	}
	fclose(fp);
}
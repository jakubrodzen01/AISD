#include <stdio.h>

void insertsort(int* tab, int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = tab[i];
		j = i - 1;
		while (tab[j] > x && j >= 0)
		{
			tab[j + 1] = tab[j]; j--;
		}
		tab[j + 1] = x;
	}
}



void bubblesort(int* tab, int n)
{
	int tmp;
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = n - 2; i >= j; i--)
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
	}
}

void selectionsort(int* tab, int n)
{
	int min_index, tmp;
	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
			if (tab[j] < tab[min_index])
				min_index = j;
		tmp = tab[i];
		tab[i] = tab[min_index];
		tab[min_index] = tmp;
	}
}

void quicksort(int* tab, int p, int k)
{
	int i = p, j = k, s, tmp;
	s = tab[(i + j) / 2];
	do
	{
		while (tab[i] < s)
			i++;
		while (tab[j] > s) j--;		
			if(i <= j)				
			{
				tmp = tab[i]; 
				tab[i] = tab[j]; 
				tab[j] = tmp; 
				i++; 
				j--;
			};
	} while(i <= j);				
	if(j > p)						
		quicksort(tab, p, j);
	if(i < k)						
		quicksort(tab, i, k);
}

void shellsort(int* tab, int n) {
	int p = n / 2;
	while (p >= 1) 
	{
		for (int i = p; i < n; i += 1) 
		{
			int tmp = tab[i];
			int j;
			for (j = i; j >= p && tab[j - p] > tmp; j -= p)	
				tab[j] = tab[j - p];
			tab[j] = tmp;
		}
		p /= 2;
	}
}

		//kopcowanie//

void heapify(int* tab, int n, int korzen)
{
	int max = korzen;
	int left = 2 * korzen + 1;
	int right = 2 * korzen + 2;
	if (left < n && tab[left] > tab[max]) max = left;
	if (right < n && tab[right] > tab[max]) max = right;
	if (max != korzen)
	{
		int swap = tab[korzen];
		tab[korzen] = tab[max];
		tab[max] = swap;
		heapify(tab, n, max);
	}
}

void heapsort(int* tab, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(tab, n, i);

	for (i = n - 1; i > 0; i--)
	{
		int temp = tab[0];
		tab[0] = tab[i];
		tab[i] = temp;
		heapify(tab, i, 0);
	}
}
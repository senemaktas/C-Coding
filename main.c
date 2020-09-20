#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define dizi 100000

void InsertionSort(int sayilar[]);

int main(int argc, char *argv[]) 
{
	time_t t;
	srand((unsigned) time(&t));
	
	int i;
	int sayilar[dizi];
	
	//clock_t start_t, end_t, total_t;
	//start_t = clock();
	for( i = 0; i < dizi; i++)
	{
		sayilar[i] = rand();
	}
	//end_t = clock();
	//total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	
	/*for(i = 0; i < dizi; i++)
	{
		printf("%d: %d\n", i+1, sayilar[i]);
	}*/
	
	InsertionSort(sayilar);
	/*printf("Siranalmi hali********************\n");
	for(i = 0; i < dizi; i++)
	{
		printf("%d: %d\n", i+1, sayilar[i]);
	}*/
	
	//printf("Toplam geçen süre:: %f saniyedir.\n", total_t);
	
	return 0;
}

void InsertionSort(int sayilar[])
{
	int i, j, key;
	for(j = 1; j < dizi; j++)
	{
		key = sayilar[j];
		i = j - 1;
		while( i >= 0 && sayilar[i] > key)
		{
			sayilar[i+1] = sayilar[i];
			i = i - 1;
		}
		sayilar[i+1] = key;
	}
}

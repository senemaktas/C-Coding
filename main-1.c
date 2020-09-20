#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

#define ARRAYSIZE 100000

long int mySize = 100000;

void InsertionSort(int A[]);
void MergeSort(int A[], int p, int r);
void Merge(int A[], int p, int q, int r);

int main()
{
	int numbers1[ARRAYSIZE];
	int numbers2[ARRAYSIZE];
	int i,j;
	
	int num;
	time_t t;
	srand((unsigned) time(&t));
	for(i = 0; i < ARRAYSIZE; i++)
	{
		num = rand();
		numbers1[i] = num;
		numbers2[i] = num;
	}
	/*for(i = 0; i < ARRAYSIZE; i++)
		printf("%d:\t%d\n",i+1,numbers1[i]);*/
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	InsertionSort(numbers1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by Insertion Sort: %f sec\n", cpu_time_used);
     
    //for(i = 0; i < ARRAYSIZE; i++)
	//	printf("%d:\t%d\n",i+1,numbers2[i]);
	start = clock();
	MergeSort(numbers2,0,ARRAYSIZE-1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by Merge Sort: %f sec\n", cpu_time_used);
	//for(i = 0; i < ARRAYSIZE; i++)
	//	printf("%d:\t%d\n",i+1,numbers2[i]);
	return 0;
}

void InsertionSort(int A[])
{
	printf("Insertion Sort starts!\n");
	int i,j;
	int key;
	for(j = 1; j < ARRAYSIZE; j++)
	{
		key = A[j];
		i = j-1;
		while(i >= 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
}

void MergeSort(int A[], int p, int r)
{
	int q;
	if(p < r)
	{
		q = floor((p+r)/2);
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

/*void Merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j, k;
	
	int *L = (int *) malloc((n1+1)* sizeof(int));
	int *R = (int *) malloc((n2+1)* sizeof(int));
	for(i = 0; i < n1; i++)
	{
		L[i] = A[p + i];
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = A[q + j + 1];
	}
	
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	for(k = p; k < r + 1; k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
	}
}*/









void Merge(int A[], int p, int q, int r)
{
	int i,j,k;
	int n1 = q - p + 1;
	int n2 = r - q;

	int *L = (int *)malloc((n1+1) * sizeof(int));
	int *R = (int *)malloc((n2+1) * sizeof(int));
	for(i = 0; i < n1; i++)
	{
		L[i] = A[p+i];
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = A[q+j+1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	i = 0;
	j = 0;
	for(k = p; k < r+1; k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}


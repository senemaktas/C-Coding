#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

#define ARRAYSIZE 100

struct subArray FIND_MAX_CROSSIN_SUBARRAY();
struct subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high);

struct subArray
{
	int maxLeft;
	int maxRight;
	int maxSum;
};

int main()
{
	printf("Hello World!\n");
	//int myArray[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	//struct subArray res = FIND_MAXIMUM_SUBARRAY(myArray,0,15);
	int i;
	int myArray[ARRAYSIZE];
	int myArray2[ARRAYSIZE];
	time_t t;
	srand((unsigned) time(&t));
	for(i = 0; i < ARRAYSIZE; i++)
		myArray[i] = rand() % 100;
	for(i = 1; i <ARRAYSIZE; i++)
		myArray2[i] = myArray[i] - myArray[i-1];
	struct subArray res = FIND_MAXIMUM_SUBARRAY(myArray2,1,ARRAYSIZE-1);
	for(i = 1; i < ARRAYSIZE; i++)
	{
		printf("%d: %d\n", i, myArray2[i]);	
	}	
	printf("Start: %d.\n",res.maxLeft);
	printf("Finish: %d.\n", res.maxRight);
	printf("Sum: %d.\n", res.maxSum);
	return 0;
}

struct subArray FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high)
{
	struct subArray res;
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	int i,j;
	for(i = mid; i >= low; i--)
	{
		sum = sum + A[i];
		if(sum > left_sum)
		{
			left_sum = sum;
			res.maxLeft = i;
		}
	}
	sum = 0;
	for(j = mid + 1; j <= high; j++)
	{
		sum = sum + A[j];
		if(sum > right_sum)
		{
			right_sum = sum;
			res.maxRight = j;
		}
	}
	res.maxSum = left_sum + right_sum;
	return res;
}

struct subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high)
{
	struct subArray res;
	struct subArray left_res;
	struct subArray right_res;
	struct subArray cross_res;
	int mid;
	if(high == low)
	{
		res.maxLeft = low;
		res.maxRight = high;
		res.maxSum = A[low];
		return res;
	}
	else
	{
		mid = floor((low+high) / 2);
		left_res = FIND_MAXIMUM_SUBARRAY(A,low,mid);
		right_res = FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
		cross_res = FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);
		if(left_res.maxSum >= right_res.maxSum && left_res.maxSum >= cross_res.maxSum)
			return left_res;
		else if(right_res.maxSum >= left_res.maxSum && right_res.maxSum >= cross_res.maxSum)
			return right_res;
		else
			return cross_res;
	}
}

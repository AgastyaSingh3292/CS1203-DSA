//Insertion sort
#include <stdio.h>

void insertionSort(int a[], int len) //function to perform insertion sort
{
	int key, j;
	for (int i = 1; i < len; i++)
	{
		key = a[i];
		j = i-1;
		while (j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

int main()
{
	int a[] = {11,42,63,22,7,2,19,34,29,5,23,44,221,54};//intializing array
	int len = sizeof(a) / sizeof(a[0]);//storing length of array

	insertionSort(a, len);//calling function insertionSort()
	
	for(int k=0;k<len;k++)
	{
	    printf("%d ", a[k]);//printig the sorted array
	}

	return 0;
}

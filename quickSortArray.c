//Quicksort

#include <stdio.h>

int partition(int a[], int low, int high) //function to partition the array 
{

    int pivot = a[high];
    int ptr = low-1;
    int swap;

    for (int j=low;j<high;j++) 
    {
        if (a[j] <= pivot) 
        {
            ptr++;
            swap = a[ptr];
            a[ptr] = a[j];
            a[j] = swap;
        }
    }

    int temp = a[ptr+1];
    a[ptr+1] = a[high];
    a[high] = temp;
    
    return (ptr + 1);
}

void quickSort(int a[], int low, int high) //function to perform quicksort
{
    if (low < high) 
    {
        int x = partition(a,low,high);
        
        quickSort(a,low,x-1);
        
        quickSort(a,x+1,high);
    }
}

int main() 
{
    int a[] = {11,42,63,22,7,2,19,34,29,5,23,44,221,54};//intializing array
    int len = sizeof(a)/sizeof(a[0]);//storing length of array

    quickSort(a,0,len-1);//calling function quicksort()
  
    for(int k=0;k<len;k++)
        {
            printf("%d ", a[k]);//printing sorted array
        }
  
    return 0;
}
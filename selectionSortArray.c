//Selection sort using arrays
//Ascending order
#include <stdio.h>

int main()
{
    int a[] = {12,32,76,43,87,6,92,42}; //initializing array
    int len = sizeof(a)/sizeof(a[0]); //storing length of array
    int ind=0;
    int swap=0;
    
    for(int i=0;i<len;i++)
    {
        ind = i;
        for(int j=i+1;j<len;j++)
        {
            if(a[ind]>a[j]) //checking if element is smaller than 
            {
                ind = j;
            }
        }
        swap = a[i]; //swapping elements with minimum element
        a[i] = a[ind];
        a[ind] = swap;
        
    }
    
    for(int k=0;k<len;k++) //printing array
    {
        printf("%d ", a[k]);
    }
    
    return 0;
}
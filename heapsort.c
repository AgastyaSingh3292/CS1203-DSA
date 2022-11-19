//resources: https://www.programiz.com/dsa/heap-sort

 #include <stdio.h>

 void heapify(int a[],int n,int i) //function to convert array to heap
 {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp=0;
      
    if (left < n && a[left] > a[max])
    {
        max = left;
    }
    if (right < n && a[right] > a[max])
    {
        max = right;
    }
    if (max != i) 
    {
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        
        heapify(a,n,max);
    }
}
  
void heapSort(int a[], int n) //function to convert heap to max-heap
{
    int temp=0;
    
    for (int i = n/2-1;i >= 0;i--)
    {
      heapify(a,n,i);
    }
    
    for (int i = n - 1; i >= 0; i--) 
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        heapify(a,i,0);
    }
}

int main() 
{
    int a[] = {11,42,63,22,7,2,19,34,29,5,23,44,221,54};//intializing array
    int n = sizeof(a)/sizeof(a[0]);//storing length of array
  
    heapSort(a, n);//calling function heapsort()
  
    printf("Max Heap: ");
    
    for(int i=0;i<n;i++)
    {
        printf("%d ", a[i]);//printing max-heap
    }
    
    return 0;
}
#include <stdio.h>

int main()
{
    float a = 0.0000001;
    while(a!=1)
    {
        printf("%f \n",a*a);
    }
    
    for(double n = 0.0003244332442;n<2;n++)
    {
        printf("%d \n", n+n);
    }
    return 0;
}
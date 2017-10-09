#include <stdio.h>
#include <iostream>
using namespace std; 

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
int main()
{
    int x, y;
    int a ,b ;
    cout<<"value of a and b ? ";
    cin>>a>>b;
    int g = gcdExtended(a, b, &x, &y);
    printf("gcd(%d, %d) = %d, x = %d, y = %d\n",a, b, g, x, y);
    return 0;
}
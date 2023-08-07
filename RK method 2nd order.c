#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000

float f(float x, float y)
{
    return ((1+sin(1+x+y))/(1+exp(x*y)));
}

void main()
{
    int i,n = N;
    float x0,y0,x,y,h,k,k1,k2;
    printf("enter x0, y0, x,:\n");
    scanf("%f%f%f",&x0,&y0,&x);
    h = (x-x0)/n;
    x = x0;
    y = y0;
    for(i=0;i<=n-1;i++) {
        k1 = h*f(x,y);
        k2 = h*f(x+h,y+k);
        k = (k1+k2)/2;
        x = x + h;
        y = y + k;
    }
    printf("\n ans = %f",y);
}

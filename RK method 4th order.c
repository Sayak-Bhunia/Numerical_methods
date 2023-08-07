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
    float x0,y0,x,y,h,k,k1,k2,k3,k4;
    printf("enter x0, y0, x,:\n");
    scanf("%f%f%f",&x0,&y0,&x);
    h = (x-x0)/n;
    x = x0;
    y = y0;
    for(i=0;i<=n-1;i++) {
        k1 = h*f(x,y);
        k2 = h*f(x+(h/2),y+(k1/2));
        k3 = h*f(x+(h/2),y+(k2/2));
        k4 = h*f(x+h,y+k3);
        k = (k1+((k2+k3)*2)+k4)/6;
        x = x + h;
        y = y + k;
    }
    printf("\n ans = %f",y);
}

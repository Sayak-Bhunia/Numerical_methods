#include<stdio.h>
#include<conio.h>
#include<math.h>
# define N 100000

float f(float x)
{
    return (1/(1+x));
}

float Simpson(float h, float x0, float xn)
{
    float res = 0;
    do {
        res += (h/3)*(f(x0) + 4*f(x0 + h) + f(x0 + 2*h));
        x0 = x0 + 2*h;
    }while(x0 < xn);
    return res;
}

void main()
{
    int i;
    float x0,xn,x[20],y[20],h,odd,even,res = 0.0;
    printf("ENTER x0, xn: ");
    scanf("%f%f",&x0,&xn);
    h = (xn - x0) / N;
    printf("\nRESULT = %f",Simpson(h,x0,xn));
}

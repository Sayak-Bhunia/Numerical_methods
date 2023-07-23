#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

float f(float x)
{
    return(x*x*x-2);
}

float df(float x)
{
    return(3*x*x);
}

void newton_raphson(float sv, float tolerance)
{
    float x,h;
    x=sv;
    do{
        if(fabs(df(x))>0.00000001) {
            h = -f(x)/df(x);
            x = x + h;
        }
    }while(fabs(f(x))>=tolerance);
    printf("\n x = %.5f",x);
    printf("\n f(x) = %.5f",f(x));
}

void main()
{
    float sv,tolerance=0.0;
    printf("Enter the seed value: ");
    scanf("%f",&sv);
    printf("\nEnter tolerance: ");
    scanf("%f",&tolerance);
    newton_raphson(sv,tolerance);
}

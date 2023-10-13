#include<stdio.h>
#include<math.h>
#define N 100000

float f(float x)
{
    return (1.0/(1.0+x));
}

float Weddle(float a, float b)
{
    float h = (b - a)/6;
    float sum = 0;
    sum = sum + ((3*h/10)*(f(a) + 5*f(a+h) + f(a+2*h) + 6*f(a+3*h) + f(a+4*h) + 5*f(a+5*h) + f(a+6*h)));
    return sum;
}

int main()
{
    float a,b;
    printf("Enter the values of a & b: ");
    scanf("%f%f",&a,&b);
    printf("Result = %.4f",Weddle(a,b));
}

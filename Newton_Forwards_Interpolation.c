#include<stdio.h>
#include<stdlib.h>
#define N 3

float find_u(float u,int n)
{
    float z=u;
    for(int i=1;i<n;i++)
    {
        z = z*(u-i);
    }
    return z;
}

float factorial(int n)
{
    int f=1;
    for(int i=2;i<=n;i++) {
        f *= i;
    }
    return f;
}

int main()
{
    int n=4;
    float x[]={45,50,40,55};
    float y[n][n];
    y[0][0] = 0.7071;
    y[1][0] = 0.7660;
    y[2][0] = 0.8192;
    y[3][0] = 0.8660;

    for(int i=1;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            y[j][i] = y[j+1][i-1]-y[j][i-1];
        }
    }
    printf("Forward Difference:\n");
    for(int i=0;i<n;i++) {
        printf("%.4f\t",x[i]);
        for(int j=0;j<n-i;j++) {
            printf("%.4f\t",y[i][j]);
        }
        printf("\n");
    }
    float value = 45;
    float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    for(int i=1;i<n;i++) {
        sum = sum + (find_u(u, i) * y[0][i]) / factorial(i);
    }
    printf("Value at %.2f is %.4f\n", value, sum);
}

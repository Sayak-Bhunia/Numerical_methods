#include<stdio.h>
#include<stdlib.h>

void Print_Matrix(float **arr, int n, int m)
{
    int i,j;
    for(i=0;i<n;i++) {
        printf("\n");
        for(j=0;j<m;j++) {
            printf("%.3f ",arr[i][j]);
        }
    }
}

void Print_Sol(float **arr, int n)
{
    int i;
    for(i=0;i<n;i++) {
        printf("\n %.3f",arr[i][n]);
    }
}

void Sol_Eq(float **matrix, float *b, int order)
{
    int i,j,k;
    float temp;
    float *tp;

    printf("\n===Matrix===\n");
    Print_Matrix(matrix, order, order);

    for(i=0;i<order;i++) {
        matrix[i][order] = b[i];
    }

    for(i=order-1;i>0;i--) {
        if(matrix[i-1][0]<matrix[i][0]) {
            tp = matrix[i];
            matrix[i] = matrix[i-1];
            matrix[i-1] = tp;
        }
    }

    printf("\n===Augmented Matrix===\n");
    Print_Matrix(matrix, order, (order+1));

    for(i=0;i<order;i++) {
        for(j=0;j<order;j++) {
            if(j!=i) {
                temp = matrix[j][i]/matrix[i][i];
                for(k=0;k<=order;k++) {
                    matrix[j][k] -= matrix[i][k]*temp;
                }
            }
        }
    }

    for(i=0;i<order;i++) {
        temp = matrix[i][i];
        for(j=0;j<=order;j++) {
            matrix[i][j] = matrix[i][j]/temp;
        }
    }

    printf("\n===Solution===\n");
    Print_Sol(matrix, order);
}

int main()
{
    int i,j, order;

    order = 3;
    float **matrix;
    float *b;
    matrix= (float**) malloc(sizeof(float*)*20);

    for(i=0;i<20;i++) {
        matrix[i] = (float*)malloc(sizeof(float)*20);
    }

    b=(float*) malloc(sizeof(float)*20);

     for(i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            matrix[i][j] = 0.0;
        }
    }

    for(i=0;i<20;i++) {
        b[i] = 0.0;
    }


    matrix[0][0] = 2;
    matrix[0][1] = -3;
    matrix[0][2] = 5;
    matrix[1][0] = 3;
    matrix[1][1] = 2;
    matrix[1][2] = -4;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = -2;
    b[0]=11;
    b[1]=-5;
    b[2]=-3;

    Sol_Eq(matrix, b, order);
}

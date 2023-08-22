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

void Print_Inverse(float **arr, int n, int m)
{
    int i,j;
    for(i=0;i<n;i++) {
        printf("\n");
        for(j=n;j<m;j++) {
            printf("%.3f ",arr[i][j]);
        }
    }
}

void Inverse_Matrix(float **matrix, int order)
{
    int i,j,k;
    float temp;
    float *tp;
    printf("\n===Matrix===\n");
    Print_Matrix(matrix, order, order);
    for(i=0;i<order;i++) {
        for(j=0;j<(2*order);j++) {
            if(j == (i+order)) matrix[i][j] = 1;
            if(j>=order && j!=(i+order)) matrix[i][j] = 0.0;
        }
    }

    for(i=order-1;i>0;i--) {
        if(matrix[i-1][0]<matrix[i][0]){
            tp = matrix[i];
            matrix[i] = matrix[i-1];
            matrix[i-1] = tp;
        }
    }

    printf("\n===Augmented Matrix===\n");
    Print_Matrix(matrix, order, (2*order));

    for(i=0;i<order;i++) {
        for(j=0;j<order;j++) {
            if(j!=i) {
                temp = matrix[j][i]/matrix[i][i];
                for(k=0;k<(2*order);k++) {
                    matrix[j][k] -= matrix[i][k]*temp;
                }
            }
        }
    }

    for(i=0;i<order;i++) {
        temp = matrix[i][i];
        for(j=0;j<(2*order);j++) {
            matrix[i][j] = matrix[i][j]/temp;
        }
    }

    printf("\n===Inverse Matrix===\n");
    Print_Inverse(matrix, order, (2*order));
}

int main()
{
    int i,j,order;
    order = 3;
    float** matrix;
    matrix = (float**)malloc(sizeof(float*)*20);
    for(i=0;i<20;i++) {
        matrix[i] = (float*)malloc(sizeof(float)*20);
    }
    for(i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            matrix[i][j] = 0.0;
        }
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

    Inverse_Matrix(matrix, order);
}



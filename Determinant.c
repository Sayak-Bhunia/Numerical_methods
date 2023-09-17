#include<stdio.h>
#include<conio.h>
#define N 3

void Swap_Rows(double matrix[N][N+1], int r1, int r2)
{
    for(int i=0;i<=N;i++) {
        double temp = matrix[r1][i];
        matrix[r1][i] = matrix[r2][i];
        matrix[r2][i] = temp;
    }
}

void Gauss_Jordan(double matrix[N][N])
{
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i!=j) {
                double ratio = matrix[j][i]/matrix[i][i];
                for(int k=0;k<=N;k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
}

int main()
{
    double matrix[N][N] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    // 1 0 0
    // 0 1 0
    // 0 0 1
    Gauss_Jordan(matrix);
    float det = 1.0;
    for(int i=0;i<N;i++) det *= matrix[i][i];
    printf("DETERMINANT = %.2f\n",det);
}

#include <stdio.h>
#define N 5
#define M 3
void print_2D(int row, int col, int a[][col]);
int matrix_change(int matrix[][M], int x, int y);
void matrix_tr(int des[][N], int src[][M]);

int main()
{
    int i, j;
    int matrix[N][M];
    printf("Initialize Matrix: \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            matrix[i][j]= i*M+ j + 1;
        }
    }

    print_2D(N, M, matrix);


    printf("New Matrix: Swap row 0 and 2\n");
    int rc = matrix_change(matrix, 0, 2);
    //int rc = matrix_change(matrix, 0, 8);
    if (rc != 0){
        printf("exchange row index out of bound\n");
        return rc;
    }
    print_2D(N, M, matrix);

    int matrix_T[M][N];
    matrix_tr(matrix_T, matrix);
    printf("New Matrix: Transpose\n");
    print_2D(M, N, matrix_T);
}
// Swap x-th row and y-th row
// Returns 0 if success, otherwise -1
int matrix_change(int matrix[N][M], int x, int y)
{
    if( x<0 || y<0 || x >= N || y >=N )
        return -1;

    int j, temp;

    for(j=0; j<M ; j++){
        temp = matrix[x][j];
        matrix[x][j] = matrix[y][j];
        matrix[y][j] = temp;
    }
    return 0;

}
// Transpose src matrix and store in des matrix
void matrix_tr(int des[M][N], int src[N][M])
{
    int i,j;

    for(i=0; i<M ; i++)
        for(j=0; j<N; j++)
            des[i][j] = src[j][i];
    

}
void print_2D(int row, int col, int a[][col])
{
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

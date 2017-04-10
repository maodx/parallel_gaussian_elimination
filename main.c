#include <stdio.h>

#define MAX_DEM 3

double a[MAX_DEM][MAX_DEM],b[MAX_DEM],y[MAX_DEM];

void matrix_generator(){
    int i,j;
    srand(time(NULL));
    for(i=0;i<MAX_DEM;++i){
        for(j=0;j<MAX_DEM;++j){
            a[i][j] = rand()/RAND_MAX*10+1;
        }
    }
    for(i=0;i<MAX_DEM;++i)
        b[i] = rand()/RAND_MAX*10+1;
}

void print_matrix(){
    for(i=0;i<MAX_DEM;++i){
        for(j=0;j<MAX_DEM;++j){
            printf("%g.6 ",a[i][j]);
        }
        printf("%g.6 \n",y[i]);
    }
}

int main() {

    int i,k,j;
    matrix_generator();
    for(k=0;k<MAX_DEM;++k){
        y[k]=b[k]/a[k][k];
        for (j= k + 1 ;j<MAX_DEM;++j){
            A[k, j] = A[k, j]/A[k, k]; /* Division step */
            for (i = k + 1 ;i<MAX_DEM;++i)
                A[i ][j] = A[i][j] - A[i][k] * A[k][ j]; /* Elimination step */
            b[j] = b[j]- A[j][ k]*y[k];  //存疑
            A[j][ k] = 0;
        }

        A[k][ k] = 1;
    }
    print_matrix();

    return 0;
}
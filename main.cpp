#include <stdio.h>
#include <cstdlib>
#include <time.h>

#define MAX_DEM 12

double a[MAX_DEM][MAX_DEM],b[MAX_DEM],y[MAX_DEM];

void matrix_generator(){
    int i,j;
    srand(time(NULL));
    for(i=0;i<MAX_DEM;++i){
        for(j=0;j<MAX_DEM;++j){
            a[i][j] = rand()/(double)RAND_MAX*10+1;
        }
    }
    for(i=0;i<MAX_DEM;++i)
        b[i] = rand()/(double)RAND_MAX*10+1;
}

void print_matrix(){
    int i,j;
    for(i=0;i<MAX_DEM;++i){
        for(j=0;j<MAX_DEM;++j){
            printf("%6.4f ",a[i][j]);
        }
        printf("%6.4f \n",y[i]);
    }
}

int main(int argc,char** argv) {
    int num_thread =4;
    if (argc < 2) {
        printf("create default number of threads\n");
        exit(0);
    }
    else{
        num_thread = atoi(argv[1]);
    }

    int i,k,j;
    matrix_generator();
    //print_matrix();
    for(k=0;k<MAX_DEM;++k){
        y[k]=b[k]/a[k][k];
        for (j= k + 1 ;j<MAX_DEM;++j){
            a[k][ j] = a[k][ j]/a[k][k]; /* Division step */
            for (i = k + 1 ;i<MAX_DEM;++i)
                a[i ][j] = a[i][j] - a[i][k] * a[k][ j]; /* Elimination step */
            b[j] = b[j]- a[j][ k]*y[k];  //存疑
            a[j][ k] = 0;
        }
        a[k][ k] = 1;
    }
    print_matrix();

    return 0;
}
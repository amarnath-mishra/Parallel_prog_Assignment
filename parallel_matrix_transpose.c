#include<stdio.h>
#include<stdlib.h>
#include <omp.h>

void display_trans_mat(double *transposed_mat,int num_cols,int num_rows)
{
printf("\n transposed matrix is : \n");
int i,j;

    for(i=0; i<num_cols; i++)
    {
        for(j=0; j<num_rows; j++)
            printf("%lf \t",transposed_mat[j+i*num_rows]);
        printf("\n");
    }

}

void display_original_mat(double *original_mat,int num_cols,int num_rows)
{

int i,j;
    printf("\n Original Matrix is: \n");
    for(i=0; i<num_rows; i++)
    {
        for(j=0; j<num_cols; j++)
            printf("%lf \t ",original_mat[j+i*num_cols]);
        printf("\n");
    }

}

main()
{

    omp_set_num_threads(2);

    int num_rows,num_cols;

    printf("\nEnter number of rows :\n");
    scanf("%d",&num_rows);
    printf("\nEnter number of columns :\n");
    scanf("%d",&num_cols);
    int dimension=num_rows*num_cols;


    double time;
    int i,j,k,n;
    //double *original_mat,*transposed_mat;

    double *original_mat= (double*) malloc((num_rows*num_cols)*sizeof(double));

    double *transposed_mat= (double*) malloc((num_rows*num_cols)*sizeof(double));


    for(i=0; i<num_rows*num_cols; i++)    //here we are filling orginal_matrix with random numbers as input.
          original_mat[i]=rand()%100;
          display_original_mat(original_mat,num_cols,num_rows);

    time = omp_get_wtime( );

#pragma omp parallel for private(n)
    for( n = 0; n<dimension; n++)
     {

        int i = n/num_cols;
         int j = n%num_cols;
        transposed_mat[j*num_rows+i] = original_mat[n];
    }

time = omp_get_wtime ( ) - time;

display_trans_mat(transposed_mat,num_cols,num_rows);

printf ( "Execution time =\t%lf\n\n", time);

        return 0;
}






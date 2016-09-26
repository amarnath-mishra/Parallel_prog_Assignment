#include<stdio.h>
#include<stdlib.h>
#include <omp.h>

void Input_Vector(int *vec1,int mat_col)
{	int i,j;
	for(i=0; i<mat_col; i++)
		vec1[i]=rand()%10;
	printf("input vector to be multiplied -> \n");

		for(j=0; j<mat_col; j++)
		    printf("%d\t",vec1[j]);
}


void Input_Matrix(int **arr1,int mat_rows,int mat_col)
{
int i,j;
for(i=0; i<mat_rows; i++)
        {
        arr1[i]=(int*)malloc(mat_col*sizeof(int));
        }

     for(i=0; i<mat_rows; i++)
        for(j=0; j<mat_col; j++)        //here giving random values in arr1
            arr1[i][j]=rand()%10;

 printf("\n Input mat is -> \n");
    for(i=0; i<mat_rows; i++)
    {
        for(j=0; j<mat_col; j++)
            printf("%d\t ",arr1[i][j]);
        printf("\n");
    }

}


main()
{
    omp_set_num_threads(2);

    int mat_rows,mat_col;
    double timeofday;

   int i,j,k,n,y;

    printf("\nEnter number of rows in matrix...\n");
    scanf("%d",&mat_rows);
    printf("\nEnter number of columns in matrix...\n");
    scanf("%d",&mat_col);

    int **arr1= (int**) malloc(mat_rows*sizeof(int*));  //arr1 in our input 2D matrix
	Input_Matrix(arr1,mat_rows,mat_col);
        

    int *vec1= (int*) malloc((mat_col)*sizeof(int));        //vec1 is the Vector array to be multiplied in our original array
    Input_Vector(vec1,mat_col);

    int *output=(int*)calloc((mat_rows),sizeof(int));   //output array is array in which multiplication result is stored.

 struct timeval begin, end2;
gettimeofday(&begin, NULL);

#pragma omp parallel shared(vec1, arr1)
{
    #pragma omp for schedule(static , 8)
    for(y = 0; y < mat_rows ; y++){
        int result = 0;
        for(i = 0; i < mat_col; i++){
                result += arr1[y][i]*vec1[i];
        }
        output[y] = result;
    }
}

gettimeofday(&end2, NULL);
double elapsed = (end2.tv_sec - begin.tv_sec) +
              ((end2.tv_usec - begin.tv_usec)/1000000.0);
              printf("\n get time gave took %f seconds to execute \n", elapsed);
printf("\n\nResult of  Multiplication -\n\n");

        for(j=0; j<mat_rows; j++)
            printf("%d\t",output[j]);


    printf("\n");


        return 0;
}







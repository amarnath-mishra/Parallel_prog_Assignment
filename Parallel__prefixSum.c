#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int main()
{
struct timeval begin, end2;    

    int n,h,i;
    printf("Enter n = 2*k\n");
    scanf("%d",&n);
    int *arr1 = (int *)malloc((n+1) * sizeof(int));
    int rows =(int)(log2(n));
    rows= rows+1;
    printf("\n%d",rows);
    int **arr2 = (int **)malloc(rows * sizeof(int *));
    int **arr3 = (int **)malloc(rows * sizeof(int *));
    for (i=0; i<rows; i++)
    {
       arr2[i] = (int *)malloc((n+1) * sizeof(int));
	arr3[i] = (int *)malloc((n+1) * sizeof(int));
    }
	omp_set_num_threads(4);

 
    //printf("%f",pow(2,3));
    printf("\n Enter n values for the matrix \n");
	int t1 =n+1;
  
	 for(i=1;i<t1;i++)
	    {
		//scanf("%d",&arr1[i]);
		arr1[i] = rand()%100;
	
	    }	
gettimeofday(&begin, NULL);
	
 	#pragma omp parallel
	{   
	#pragma omp for
	 for(i=1;i<t1;i++)
	    {
		arr2[0][i]=arr1[i];
	//int i1=omp_get_thread_num();
	//printf("hello(%d)-%d %d %d   ",i1,i,arr1[i],arr2[0][i]);
 
	    }
	}
  
    int j;
    for(h=1;h<=((int)(log2(n))+1);h++)
    {
        int t =n/(int)pow(2,h);
		#pragma omp parallel
		{   
		#pragma omp for
		for(j=1;j<=t;j++)
		{
	int i1=omp_get_thread_num();

	
		    arr2[h][j]=arr2[h-1][(2*j)-1] + arr2[h-1][(2*j)];
		//printf("hello(%d)-%d %d   ",i1,j,arr2[h][j]);
		    //printf("%d ",arr2[h][j]);
		}
		}
	
    }

     for(h=((int)log2(n)+1);h>=0;h--)
    {
        int t =n/(int)pow(2,h);
         // printf("\nh = %d,t = %d\n",h,t);
	#pragma omp parallel
	{   
	#pragma omp for
		for(j=1;j<=t;j++)
		{
		    if((j%2)==0)
		    {
		        arr3[h][j] = arr3[h+1][j/2];
		    }
		    else if(j==1)
		    {
		        arr3[h][1]= arr2[h][1];
		    }
		    else
		    {
		        arr3[h][j] = arr3[h+1][(j-1)/2] + arr2[h][j];
		    }
		}
	}	
    }


 gettimeofday(&end2, NULL);
double elapsed = (end2.tv_sec - begin.tv_sec) +
              ((end2.tv_usec - begin.tv_usec)/1000000.0);
              printf("\n get time gave took %f seconds to execute \n", elapsed);

printf("\n sum is \n");

	for(i=1;i<=n;i++)
	    {
		//printf("%d  ",arr3[0][i]);
	    }
	

    return 0;
}

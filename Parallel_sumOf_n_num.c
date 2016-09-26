#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<math.h>

void printArray(int *arr,int sizeOfArray)
{
int j;
    for(j=0;j<sizeOfArray;j++) {
    printf("%d ",arr[j]);
      }
}
void summation(int * arr,int *arrM,int sizeOfArray)
{
    int noOfThreads=2;
    int i,j;
    omp_set_num_threads(noOfThreads);
    struct timeval tv;
    double start_t,end_t;

  gettimeofday(&tv, 0);
  start_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
  #pragma omp parallel
  {
  int flag=sizeOfArray;
  while(flag/2>0){
 	 #pragma omp for
  	for(i=0;i<sizeOfArray;i++){
  	arrM[i]=arr[2*i]+arr[2*i+1];
 	}

 	#pragma omp for
 	for(i=0;i<sizeOfArray/2;i++){
 	arr[i]=arrM[i];
 	}
     flag=flag/2;
  }
   }
   gettimeofday(&tv, 0);
   end_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
   printf("Time taken to sum using manual reduction is %lf and sum is %d \n",end_t-start_t,arr[0]);


}
main(int argc , char **argv)
{
  int *arr,*arrM, serial_sum, sum;

  int sizeOfArray, i,j;
  printf("Enter size n=2*k\n");
  scanf("%d",&sizeOfArray);

  arr = (int *)malloc(sizeof(int)*sizeOfArray);
  arrM = (int *)malloc(sizeof(int)*sizeOfArray);

  for(i=0;i<sizeOfArray;i++) {
	arr[i] = rand()%100;
  }
    printArray(arr,sizeOfArray);
    summation(arr,arrM,sizeOfArray);
}

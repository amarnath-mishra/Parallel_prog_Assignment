
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>

void parallel_function(int *prev_parent,int *prev_Prev,int num_nodes)
{
omp_set_num_threads(4);

while(1){
	int n,i;
        printf("Which node's ROOT you want to find. (-1 to exit) ");
        scanf("%d",&n);
        if(n==-1)
            break;
	double start_t,end_t;
    	struct timeval tv;
        gettimeofday(&tv, 0);
        start_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;

        while(1)
        {

	    #pragma omp parallel for schedule(static,8)
            for(i=0;i<num_nodes;i++)
            {
		//int i1=omp_get_thread_num();
	//printf("hello(%d)",i1);
            prev_Prev[i]=prev_parent[prev_parent[i]];
            }

            if(prev_parent[n]==prev_Prev[n])
                break;
	    #pragma omp parallel for schedule(static,8)
            for(i=0;i<num_nodes;i++)
            {
                prev_parent[i]=prev_Prev[i];
            }

        }
        gettimeofday(&tv, 0);
        end_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
        end_t = end_t-start_t;
        printf("The root of this element is %d  ",prev_parent[n]);
        printf("  Exec Time taken: %f ",end_t);

    }
}


void main()
{
    
    int i,n,num_nodes,num_threads;
   
    printf("Give the number of nodes in the forest :");
    scanf("%d",&num_nodes);

    int * prev_parent = (int *)malloc(num_nodes*sizeof(int));
    int * prev_Prev = (int *)malloc(num_nodes*sizeof(int));



    printf("\n**************Enter nodes based on diff trees of forest***************** \n\n");
    for(i=0;i<num_nodes;i++)
    {
        printf("\nTo which parent u want to connect %d node : ",i);
        scanf("%d",&prev_parent[i]);
    }
	parallel_function(prev_parent,prev_Prev,num_nodes);

   
}



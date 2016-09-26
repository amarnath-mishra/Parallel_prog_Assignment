# Parallel_prog_Assignment
Amarnath Mishra
Roll no – 1301007
Assignment 1 – Statistics of Run.

************  SEE THE PDF FILE INSIDE FOR GRAPHS OF RUNTIME VS INPUT **********************

1.	Parallel Sum of n numbers
Following are the input of n (n= 2^k) and output in seconds.

64	0.000131
128	0.000224
256	0.000369
1024	0.000675
2048	0.000699
4096	0.000715
8192	0.00091


 

2.	Parallel Prefix Sum –
Following are the input of n (n= 2^k) and output in seconds.

						
8	0.00052
128	0.000775
512	0.000905
1024	0.00093
2048	0.00105
4096	0.001119
8192	0.001488

 

3.	Parallel Matrix Multiplication-
The input =n means n*n (for example 3 means matrix was 3*3 , so obviously vector will be 3*1)
3	0.000057
5	0.000076
12	0.000132
21	0.000143
35	0.00015
50	0.000242
70	0.000262
	
    

	
4.	Parallel Matrix transpose –   
Here, in x axis , any value n represents that  matrix was of dimension “ n*(n+1) “ dimension, and on Y-axis I have represented the time in transposing the original matrix.
3	0.000146
5	0.000173
11	0.000162
17	0.000293
25	0.00109
50	0.00342
90	0.0056
 




5.	Parallel_Root_Finding –

In that we will have time based on out input forest of trees and which node is connected to which tree and root, so I have not shown that into graph but I have tested that for several inputs and it is perfectly running 

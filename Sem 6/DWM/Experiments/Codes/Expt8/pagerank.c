//Vedant Sahai
//Batch C
//Roll No 8364

#include<stdio.h>
int main(){
	// Adjecancy Matrix
	int n;
	printf("Enter Number of vertices\n");
	scanf("%d", &n);
	int x[n+1];
	int i, j, adj[n+1][n+1],m;
	for(i=0;i<n+1;i++){
			for(j=0;j<n+1;j++){
				adj[i][j] = 0;
			}
		}
	for(i = 1;i < n+1; i++){
		int k;
		printf("Enter number of Neighbours of %d vertex\n", i);
		scanf("%d",&k);
		x[i] = k;
		for(j = 0; j<k; j++){
			int flag;
			printf("Enter vertex number\n");
			scanf("%d", &flag);
			
			adj[i][flag] = 1;
		}
		printf("\n");
		}
		for(i=1;i<n+1;i++){
			for(j=1;j<n+1;j++){
				printf("%d\t",adj[i][j]);
	
			}
			printf("\n");
		}
		
		//Stochastic_graph
		double an[n+1][n+1];
		
	for(i=0;i<n+1;i++){
			for(j=0;j<n+1;j++){
				an[i][j] = 0;
			}
		}
		for(i = 1;i < n+1; i++){
			for(j = 1; j < n+1; j++){
				an[i][j] = (double)adj[i][j]/x[i];
			}
		}
		for(i=1;i<n+1;i++){
			for(j=1;j<n+1;j++){
				printf("%lf\t",an[i][j]);
			}
			printf("\n");
		}
		// Zero Iteration / Initialisation
		
		double itr[n+1], prev[n+1];
		for(i = 1; i < n+1; i++){
			itr[i] = (double)1/n;
			prev[i] = (double)1/n;
		}
		for(i = 1; i < n+1; i++){
			printf("%lf \t", itr[i]);
		}
		printf("\n");
		
		/*
				Now we need to go for vector next number of iterations...
				
				To calculate PR of let's say A we PR(A) = (PR(Previous Iteration of which A is neighbour of)) / No of Outgoing Links (This we can find in x[] array)
		*/
		int num, a;
		printf("Enter number of Iterations required\n");
		scanf("%d",&num);
		for(i = 0 ; i < num ; i++){
			for(j = 1; j < n+1; j++){
				double sum = 0;
				for(m = 1; m < n+1;m++){
					if(m == j){
						continue;
					}
					else{
						if(adj[m][j] == 1){
							sum += (double)prev[m]/x[m];
						}
					}
				}
				itr[j] = sum;
				printf("\n");
			}
			
				printf("On Iteration %d :",i);
			for(a = 1; a < n+1 ; a++){
				prev[a] = itr[a];
				printf("%lf \t",itr[a]);
			}
			printf("\n");
		}
		for(i = 1; i < n+1 ; i++){

		}
		printf("\n");
		
		
	return 0;
}
/* 
[mayank@asonicmaster Desktop]$ cc c.c
[mayank@asonicmaster Desktop]$ ./a.out
Enter Number of vertices
4
Enter number of Neighbours of 1 vertex
2
Enter vertex number
2
Enter vertex number
3

Enter number of Neighbours of 2 vertex
1
Enter vertex number
4

Enter number of Neighbours of 3 vertex
3
Enter vertex number
1
Enter vertex number
2
Enter vertex number
4

Enter number of Neighbours of 4 vertex
1
Enter vertex number
3

0	1	1	0	
0	0	0	1	
1	1	0	1	
0	0	1	0	
0.000000	0.500000	0.500000	0.000000	
0.000000	0.000000	0.000000	1.000000	
0.333333	0.333333	0.000000	0.333333	
0.000000	0.000000	1.000000	0.000000	
0.250000 	0.250000 	0.250000 	0.250000 	
Enter number of Iterations required
3




On Iteration 0 :0.083333 	0.208333 	0.375000 	0.333333 	




On Iteration 1 :0.125000 	0.166667 	0.375000 	0.333333 	




On Iteration 2 :0.125000 	0.187500 	0.395833 	0.291667 
*/








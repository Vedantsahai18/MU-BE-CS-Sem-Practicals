/*
 Title   : Graph Colouring
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int adj[SIZE][SIZE] = {0};
int X[SIZE] = {0};

void create_graph(int n)
{

	int s, d, e, i, j, w;
	for(i=1; i<=n; i++)
	{
		printf("Enter number edges for %d\n", i);
		scanf("%d", &e);
		for(j=1; j<=e; j++)
		{
      printf("Enter destination\n");
			scanf("%d", &d);
			adj[i][d] = 1;
		}
	}
}

int isSafe(int node, int colour){
  int j;
  for(j = 1; j <= node - 1; j++){
    if(adj[node][j] == 1 && X[j] == colour){
      return 0;
    }
  }
  return 1;
}

void canColour(int node, int n, int m, int *count){
  int i,j,k;
  for(i = 1; i <= m; i++){
    if(isSafe(node, i)){
      X[node] = i;
      if(node == n){
        printf("The solution is\n");
        for(k = 1; k <= n; k++){
          printf("The colour for node %d is %d\n", k, X[k]);
        }
        *count = *count + 1;
        printf("\n");
      }
      else{
        canColour(node + 1, n, m, count);
      }
    }
  }
}


void main(){
  int n, m, count = 0;
  printf("Enter the number of colours: ");
  scanf("%d", &m);
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  create_graph(n);
  canColour(1, n, m, &count);
  printf("\nTotal solutions are %d\n", count);
}

/*
Enter the number of colours: 3
Enter the number of vertices: 4
Enter number edges for 1
2
Enter destination
2
Enter destination
4
Enter number edges for 2
2
Enter destination
1
Enter destination
3
Enter number edges for 3
2
Enter destination
2
Enter destination
4
Enter number edges for 4
2
Enter destination
1
Enter destination
3
The solution is
The colour for node 1 is 1
The colour for node 2 is 2
The colour for node 3 is 1
The colour for node 4 is 2

The solution is
The colour for node 1 is 1
The colour for node 2 is 2
The colour for node 3 is 1
The colour for node 4 is 3

The solution is
The colour for node 1 is 1
The colour for node 2 is 2
The colour for node 3 is 3
The colour for node 4 is 2

The solution is
The colour for node 1 is 1
The colour for node 2 is 3
The colour for node 3 is 1
The colour for node 4 is 2

The solution is
The colour for node 1 is 1
The colour for node 2 is 3
The colour for node 3 is 1
The colour for node 4 is 3

The solution is
The colour for node 1 is 1
The colour for node 2 is 3
The colour for node 3 is 2
The colour for node 4 is 3

The solution is
The colour for node 1 is 2
The colour for node 2 is 1
The colour for node 3 is 2
The colour for node 4 is 1

The solution is
The colour for node 1 is 2
The colour for node 2 is 1
The colour for node 3 is 2
The colour for node 4 is 3

The solution is
The colour for node 1 is 2
The colour for node 2 is 1
The colour for node 3 is 3
The colour for node 4 is 1

The solution is
The colour for node 1 is 2
The colour for node 2 is 3
The colour for node 3 is 1
The colour for node 4 is 3

The solution is
The colour for node 1 is 2
The colour for node 2 is 3
The colour for node 3 is 2
The colour for node 4 is 1

The solution is
The colour for node 1 is 2
The colour for node 2 is 3
The colour for node 3 is 2
The colour for node 4 is 3

The solution is
The colour for node 1 is 3
The colour for node 2 is 1
The colour for node 3 is 2
The colour for node 4 is 1

The solution is
The colour for node 1 is 3
The colour for node 2 is 1
The colour for node 3 is 3
The colour for node 4 is 1

The solution is
The colour for node 1 is 3
The colour for node 2 is 1
The colour for node 3 is 3
The colour for node 4 is 2

The solution is
The colour for node 1 is 3
The colour for node 2 is 2
The colour for node 3 is 1
The colour for node 4 is 2

The solution is
The colour for node 1 is 3
The colour for node 2 is 2
The colour for node 3 is 3
The colour for node 4 is 1

The solution is
The colour for node 1 is 3
The colour for node 2 is 2
The colour for node 3 is 3
The colour for node 4 is 2


Total solutions are 18
*/

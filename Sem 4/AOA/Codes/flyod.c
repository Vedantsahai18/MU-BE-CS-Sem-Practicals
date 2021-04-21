#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct queue
{
	int a[SIZE];
	int front;
	int rear;
}que;

int adj[SIZE][SIZE]={0};
int seq[SIZE][SIZE]={0};

void create_graph(int n)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      adj[i][j] = 1000;
    }
  }
	int s, d, e, i, j, w;
	for(i=0; i<n; i++)
	{
		printf("Enter number edges for %d\n", i);
		scanf("%d", &e);
		for(j=0; j<e; j++)
		{
      printf("Enter destination\n");
			scanf("%d", &d);
      printf("Enter weight\n");
      scanf("%d", &w);
			adj[i][d] = w;
			seq[i][d] = d;
		}
	}
}


void display_adjmat(int n)
{
    int i,j;
    printf("Adjacency matrix is\n");
           for(i = 1; i <= n; i++)
           {
               for(j = 1; j <= n; j++)
               {
                   printf(" %d ", adj[i][j]);
               }
               printf("\n");
           }
}

void display_seq(int n)
{
    int i,j;
    printf("Sequence matrix is\n");
           for(i = 1; i <= n; i++)
           {
               for(j = 1; j <= n; j++)
               {
                   printf(" %d ", seq[i][j]);
               }
               printf("\n");
           }
}

void display(int n){
  int i, j, k;
  for(i = 1; i < n; i++){
		for(j = 1; j <= n;j++){
			if((i != j) && (i < j)){
					printf("\nSource - %d\tDestination - %d\tDistance - %d\n", i, j, adj[i][j]);
					k = i;
					printf("%d ", j);
					while(seq[k][j] != j){
						k = seq[k][j];
						printf("<-%d ", k);
					}
					printf("<-%d \n", i);
			}
		}
	}
}

void flyod(int n){
  int i, j, k = 1;
  while(k <= n){
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++){
        if((i != k )&& (j != k) && (j != i)){
					if(adj[i][j] > adj[i][k] + adj[k][j]){
						adj[i][j] = adj[i][k] + adj[k][j];
						seq[i][j] = k;
					}
        }
      }
    }
		k = k + 1;
  }
	display(n);
}

void main(){
  int n;
  printf("Enter number of vertices\n");
  scanf("%d", &n);
  create_graph(n);
  flyod(n);
}

/*
Enter number of vertices
4

Source - 1	Destination - 2	Distance - 4
2 <-3 <-1

Source - 1	Destination - 3	Distance - 1
3 <-1

Source - 1	Destination - 4	Distance - 2
4 <-1

Source - 2	Destination - 3	Distance - 3
3 <-2

Source - 2	Destination - 4	Distance - 6
4 <-3 <-1 <-2

Source - 3	Destination - 4	Distance - 3
4 <-1 <-3
*/

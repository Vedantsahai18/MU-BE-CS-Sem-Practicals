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
			adj[i][d]=w;
		}
	}
}

void display_adjmat(int n)
{
    int i,j;
    printf("Adjacency matrix is\n");
           for(i=0; i<n; i++)
           {
               for(j=0; j<n; j++)
               {
                   printf(" %d ", adj[i][j]);
               }
               printf("\n");
           }
}


void disp_arr(int arr[], int n, int src){
  int i;
  for(i = 0; i < n; i++){
		if(i == src){
			printf("src ");
		}
		else{
			printf("%d ", arr[i]);
		}
  }
  printf("\n");
}

void display(int pred[], int dist[], int n, int src){
  int i, j;
  printf("\nDistance array is\n");
  disp_arr(dist, n, src);
  printf("Predecessor array is\n");
  disp_arr(pred, n, src);
  printf("\n");
  for(i = 0; i < n; i++){
    if(i == src){
      printf("%d is source node\n", i);
      continue;
    }
    printf("\nFor vertex %d\n", i);
    printf("%d ", i);
    j = i;
    while(pred[j] != src){
      j = pred[j];
      printf("<-%d ", j);
    }
    printf("<-%d ", src);
    printf("\n");
    printf("Total distance is %d\n", dist[i]);
  }
}

void dij(int n){
  int src, newsrc, n1, n2, min, check = 1, i;
  int dist[SIZE] = {1000};
  int pred[SIZE] = {0};
  int visited[SIZE] = {0};
  printf("Enter source node\n");
  scanf("%d", &src);
  visited[src] = 1;
  for(i = 0; i < n; i++){
    if(i != src){
      dist[i] = adj[src][i];
      pred[i] = src;
    }
  }
  while(check){
    min = 1000;
    for(i = 0; i < n; i++){
      if(visited[i] == 0 && min > dist[i]){
        min = dist[i];
        newsrc = i;
      }
    }
    visited[newsrc] = 1;

    for(i = 0; i < n; i++){

      if(adj[newsrc][i] != 1000 && i != src){
        n1 = dist[i];
        n2 = dist[newsrc] + adj[newsrc][i];

        if(n2 < n1){
          dist[i] = n2;
          pred[i] = newsrc;
        }
      }
    }
    for(i = 0; i < n; i++){
      if(visited[i] == 1){
        check = 0;
      }
      else{
        check = 1;
				break;
      }
    }
  }
  display(pred, dist, n, src);
}

void main(){
  int n;
  printf("Enter number of vertices\n");
  scanf("%d", &n);
  create_graph(n);
  dij(n);
}

/*
Enter number of vertices
6
Enter number edges for 0
2
Enter destination
1
Enter weight
20
Enter destination
2
Enter weight
15
Enter number edges for 1
3
Enter destination
0
Enter weight
2
Enter destination
5
Enter weight
30
Enter destination
4
Enter weight
10
Enter number edges for 2
2
Enter destination
5
Enter weight
10
Enter destination
3
Enter weight
4
Enter number edges for 3
0
Enter number edges for 4
1
Enter destination
3
Enter weight
15
Enter number edges for 5
2
Enter destination
3
Enter weight
4
Enter destination
4
Enter weight
10
Enter source node
0

Distance array is
src 20 15 19 30 25
Predecessor array is
src 0 0 2 1 2

0 is source node

For vertex 1
1 <-0
Total distance is 20

For vertex 2
2 <-0
Total distance is 15

For vertex 3
3 <-2 <-0
Total distance is 19

For vertex 4
4 <-1 <-0
Total distance is 30

For vertex 5
5 <-2 <-0
Total distance is 25
*/

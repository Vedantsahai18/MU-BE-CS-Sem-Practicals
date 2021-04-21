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
			if(w < adj[i][d]){
				adj[i][d]=w;
			}
			if(i == d){
				adj[i][d] = 0;
			}
		}
	}
}

void testgraph(int n)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      adj[i][j] = 1000;
    }
  }
	adj[0][1] = 3;
	adj[0][5] = 5;
	adj[0][4] = 6;
	adj[1][0] = 3;
	adj[5][0] = 5;
	adj[4][0] = 6;

	adj[1][2] = 1;
	adj[1][5] = 4;
	adj[2][1] = 1;
	adj[5][1] = 4;

	adj[2][3] = 6;
	adj[2][5] = 4;
	adj[3][2] = 6;
	adj[5][2] = 4;

	adj[3][5] = 5;
	adj[3][4] = 8;
	adj[5][3] = 5;
	adj[4][3] = 8;

	adj[4][5] = 2;
	adj[5][4] = 2;
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
  int i, j, sum = 0;
  printf("\nDistance array is\n");
  disp_arr(dist, n, src);
  printf("Predecessor array is\n");
  disp_arr(pred, n, src);
  printf("\n");
  for(i = 1; i < n; i++){
    sum = sum + dist[i];
  }
	printf("Total weight of the graph is %d\n", sum);
}

void prim(int n){
  int src, mindx, mjndx, min, check = 1, i, j,count = 0;
  int dist[SIZE] = {1000};
  int pred[SIZE] = {0};
  int visited[SIZE] = {0};
  printf("Enter source node: ");
  scanf("%d", &src);
  visited[src] = 1;
  while(count < n-1){
		min = 1000;
		mindx = 0;
		mjndx = 0;
		for(i = 0; i < n; i++){
			if(visited[i] == 1){
				for(j = 0; j < n; j++){
					if(visited[j] == 0 && adj[i][j] < min){
						min = adj[i][j];
						mindx = i;
						mjndx = j;
					}
				}
			}
		}
		pred[mjndx] = mindx;
		dist[mjndx] = min;
		visited[mjndx] = 1;
		printf("Edge %d -> %d added\n", mindx, mjndx);
		count = count + 1;
  }
  display(pred, dist, n, src);
}

void main(){
  int n;
  printf("Enter number of vertices\n");
  scanf("%d", &n);
  //create_graph(n);
	testgraph(n);
	prim(n);
}

/*
Enter number of vertices
6
Enter source node: 0
Edge 0 -> 1 added
Edge 1 -> 2 added
Edge 1 -> 5 added
Edge 5 -> 4 added
Edge 5 -> 3 added

Distance array is
src 3 1 5 2 4
Predecessor array is
src 0 1 5 5 1

Total weight of the graph is 15
*/

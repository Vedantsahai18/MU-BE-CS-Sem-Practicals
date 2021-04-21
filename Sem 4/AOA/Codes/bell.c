/*
 Title   : Flyod Warshall's Algorithm
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct edge
{
	int src;
	int dest;
	int weight;
}ed;

int adj[SIZE][SIZE]={0};
ed list[SIZE]={};

int create_graph(int n)
{
	int d, e, i, j, w, k = 0;
	for(i = 0; i < n; i++)
	{
		printf("Enter number edges for %d\n", i);
		scanf("%d", &e);
		for(j = 0; j < e; j++)
		{
			ed edge;
      printf("Enter destination\n");
			scanf("%d", &d);
      printf("Enter weight\n");
      scanf("%d", &w);
			edge.src = i;
			edge.dest = d;
			edge.weight = w;
			list[k] = edge;
			k = k + 1;
		}
	}
	return k;
}

void disp_arr(int arr[], int n, int src)
{
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


void display(int n, int pred[], int dist[], int src){
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

void bell(int k, int n){
	int i, src, check, j;
	int dist[SIZE] = {0};
	int pred[SIZE] = {0};
	int visited[SIZE] = {0};
	for(i = 0; i < n; i++){
    dist[i] = 1000;
  }
	printf("Enter source vertex\n");
	scanf("%d", &src);
	dist[src] = 0;
	for(i = 0; i < n; i++){
		printf("\n\nIteration %d\n", i+1);

		for(j = 0; j < k; j++){

			if(i == n-1){
				check = 0;
				if(dist[list[j].src] + list[j].weight < dist[list[j].dest]){
					check = 1;
					break;
				}
			}

			if(dist[list[j].src] + list[j].weight < dist[list[j].dest]){
				dist[list[j].dest] = dist[list[j].src] + list[j].weight;
				pred[list[j].dest] = list[j].src;
			}
		}
		printf("Distance array is\n");
		disp_arr(dist, n, src);
		printf("Predecessor array is\n");
		disp_arr(pred, n, src);
	}
	if(check){
		printf("\nBellman Ford fails\n");
	}
	else{
		display(n, pred, dist, src);
	}
}

void main(){
  int n, e;
  printf("Enter number of vertices\n");
  scanf("%d", &n);
  e = create_graph(n);
  bell(e, n);
}

/*
Enter number of vertices
4
Enter number edges for 0
2
Enter destination
1
Enter weight
5
Enter destination
2
Enter weight
4
Enter number edges for 1
1
Enter destination
3
Enter weight
3
Enter number edges for 2
1
Enter destination
1
Enter weight
-6
Enter number edges for 3
1
Enter destination
2
Enter weight
2
Enter source vertex
0


Iteration 1
Distance array is
src -2 4 8
Predecessor array is
src 2 0 1


Iteration 2
Distance array is
src -2 3 1
Predecessor array is
src 2 3 1


Iteration 3
Distance array is
src -3 3 1
Predecessor array is
src 2 3 1


Iteration 4
Distance array is
src -3 3 1
Predecessor array is
src 2 3 1

Bellman Ford fails

--------------------------x--------------------------
Enter number of vertices
4
Enter number edges for 0
2
Enter destination
1
Enter weight
5
Enter destination
2
Enter weight
4
Enter number edges for 1
1
Enter destination
3
Enter weight
3
Enter number edges for 2
1
Enter destination
1
Enter weight
-2
Enter number edges for 3
1
Enter destination
2
Enter weight
2
Enter source vertex
0


Iteration 1
Distance array is
src 2 4 8
Predecessor array is
src 2 0 1


Iteration 2
Distance array is
src 2 4 5
Predecessor array is
src 2 0 1


Iteration 3
Distance array is
src 2 4 5
Predecessor array is
src 2 0 1


Iteration 4
Distance array is
src 2 4 5
Predecessor array is
src 2 0 1

Distance array is
src 2 4 5
Predecessor array is
src 2 0 1

0 is source node

For vertex 1
1 <-2 <-0
Total distance is 2

For vertex 2
2 <-0
Total distance is 4
*/
For vertex 3
3 <-1 <-2 <-0
Total distance is 5
*/

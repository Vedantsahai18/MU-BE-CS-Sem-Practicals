#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define SIZE 30  
 int k1[SIZE];
 int parent[SIZE];
struct Edge
{
    // This structure is equal to an edge. Edge contains two end points. These edges are directed edges so they
    //contain source and destination and some weight. These 3 are elements in this structure
    int source, destination, weight;
};
 
// a structure to represent a connected, directed and weighted graph
struct Graph
{
    int V, E;
    // V is number of vertices and E is number of edges
 
    struct Edge* edge;
    // This structure contain another structure which we already created edge.
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
    //Allocating space to structure graph
 
    graph->V = V;   //assigning values to structure elements that taken form user.
 
    graph->E = E;   //assigning edge  value to structure elements that is taken from user.
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    //Creating "Edge" type structures inside "Graph" structure, the number of edge type structures are equal to number of edges
 
    return graph;
}

//function to get path from source to destination.
void path(int x, int source, int temp){
	if(x == source){
		return;
	}
	else{
		x = parent[x];
		path(x, source, temp);    //recursive function to backtrack its path.
		if(x == temp){  // useless
			printf("%d\n", x);
		}
		else{
			printf(" %d ----->", x);     //printing the path
			
		}
	}
		
}
 
void FinalSolution(int dist[], int n,int g,int E1, int source)
{
    int b[SIZE],sum=0,sum1=0,sum3,j;
	int dest;
    
    // This function prints the final solution
	
    int i, temp;
	
    printf("\nVertex\tDistance from Source Vertex\tPath To Be Followed\n");
    
    for (i = 1; i <= n; ++i)
    {
        printf("%d \t\t %d\t\t\t", i, dist[i]);
		temp = i;
		path(i, source, temp);
		printf(" %d\n", i);
    }
    for (j=0;j<g;j++)
    {
        for(i = 1; i <= n; ++i)
        {
            if(k1[j]==i)
            {
               sum1=sum1+dist[i];
               b[j]=(E1-dist[i]);
              
               continue;
            }
        }
       
    }
    sum3=E1-sum1;  
    
    for(j=0;j<g;j++)
    {
        sum=sum^b[j];
    }
   
    printf("The total number of roads to be destroyed is : %d \n",(sum^E1^sum3));
	
	
	exit(0);
    
}
 
 
void BellmanFord(struct Graph* graph, int source,int g,int E1)
{
    
    int V = graph->V;
 
    int E = graph->E;
 
    int StoreDistance[V];
 
    int i,j;
 
    // This is initial step that we know , we initialize all distance to infinity except source.
    // We assign source distance as 0(zero)
 
    for (i = 1; i <= V; i++)
        StoreDistance[i] = INT_MAX;
 
    StoreDistance[source] = 0;
 
    //The shortest path of graph that contain V vertices, never contain "V-1" edges. So we do here "V-1" relaxations
    for (i = 1; i <= V-1; i++)
    {
        for (j = 1; j <= E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
				parent[v] = u;
        }
    }
 
    // Actually upto now shortest path found. But BellmanFord checks for negative edge cycle. In this step we check for that
    // shortest distances if graph doesn't contain negative weight cycle.
 
    // If we get a shorter path, then there is a negative edge cycle.
    for (i = 1; i <= E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
 
        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("This graph contains negative edge cycle\n");
    }
 
   
   FinalSolution(StoreDistance, V,g,E1, source);
}
 
int main()
{
    int V,E1,S,g;  //V = no.of Vertices, E = no.of Edges, S is source vertex
 
    printf("Enter the total number of cities : \n");
    scanf("%d",&V);
    
    printf("The number of roads are :  \n");
    scanf("%d",&E1);
    
    printf("Enter your source vertex number : \n");
    scanf("%d",&S);
 
    struct Graph* graph = createGraph(V, E1);    //calling the function to allocate space to these many vertices and edges
 
    int i, j;
    for(i=1;i<=E1;i++)   //Reads the properties of the edges of the graph
    {
        printf("\nEnter edge %d properties Source, destination, weight respectively : \n",i);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
    printf("Enter the number of good cities : \n");
    scanf("%d",&g);

   
    printf("Enter the potential good cities : \n");
    for(j=0;j<g;j++)
    {
        scanf("%d",&k1[j]); 
    }
   
 
    BellmanFord(graph, S,g,E1);
    //passing created graph and source vertex to BellmanFord Algorithm function

    
    return 0;
}

/*
OUTPUT:
Enter the total number of cities :
7
The number of roads are :
6
Enter your source vertex number :
1
Enter edge 1 properties Source, destination, weight respectively :
1 2 1
Enter edge 2 properties Source, destination, weight respectively :
1 3 1
Enter edge 3 properties Source, destination, weight respectively :
1 4 1
Enter edge 4 properties Source, destination, weight respectively :
2 5 1
Enter edge 5 properties Source, destination, weight respectively :
3 6 1
Enter edge 6 properties Source, destination, weight respectively :
3 7 1
Enter the number of good cities : 
2 
Enter the potential good cities : 
2 7
Vertex	Distance from Source Vertex	    Path To Be Followed
1 		          0			            1
2 		          1			            1 -----> 2
3 		          1			            1 -----> 3
4 		          1			            1 -----> 4
5 		          2			            1 -----> 2 -----> 5
6 		          2			            1 -----> 3 -----> 6
7 		          2			            1 -----> 3 -----> 7
The total number of roads to be destroyed is : 4*/

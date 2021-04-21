#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int graph[SIZE][SIZE]={0};
int degree[SIZE]={0};
int stack[SIZE]={0};
int path[SIZE]={0};
int a[SIZE][SIZE]={0};
int top=-1;
int count=0;
int start;

struct stack
{
	int a[SIZE];
	int top;
};
struct stack s;

void emptyStack()
{
	while(top!=-1)	
		stack[top--];
}

void initstk(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s,int x)
{
	if(s->top==SIZE-1)
		printf("Stack overflow\n");
	else 
	{
		s->top=s->top+1;
		s->a[s->top]=x;
	}
}

int pop(struct stack *s)
{
	int x;
	if(s->top==-1)
		printf("Stack underflow\n");
	else
	{
		x=s->a[s->top];
		s->top=s->top-1;
		return x;
	}
}	

int isEmptystk(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

void indegree(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
        {
            if(graph[j][i]==1)
                degree[i]++;
        }
    }
}

void pathdisp(int n)
{
	int i;
	printf("\n");
	for(i=n-1;i>=0;i--)
		printf("%d-->",path[i]);
}

void dfs(int source,int n)
{	
	int j,x,i=0;
	for(j=1;j<=n;j++)
	{
		if(a[source][j]==1)
		{
			i=1;
			a[source][j]=0;
			a[j][source]=0;
			push(&s,source);
			dfs(j,n);
			break;
		}
	}
	if(i==1)
	{
		path[count++]=source;
		x=pop(&s);
		dfs(x,n);
	}
}	

void dfsset(int source,int n)
{
	int i,j;
	start=source;
	initstk(&s);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			a[i][j]=graph[i][j];
	}
	dfs(source,n);
	pathdisp(n);
}

void oddeven(int n)
{	indegree(n);
	int i,odd,even,v;
	odd=0;
	even=0;
	for(i=1;i<=n;i++)
	{
		if(degree[i]%2==0)
			even++;
		else
			odd++;
	}
	if(odd>2)
	{
		printf("\nNo Eulerian Path");
		exit(1);
	}
	else if(even==n)
	{	
		printf("\nAll nodes have even degree\nEnter starting node\t");
		scanf("%d",&v);
		dfsset(v,n);
		printf("%d",v);	
	}
	else 
	{
		if(odd==2)
		{	int c,vx[SIZE];
			c=0;
			printf("\nVestices: ");
			for(i=1;i<=n;i++)
			{
				if(degree[i]%2!=0)
				{	
					printf("%d ",i);
					vx[c++]=i;
				}
			}
			printf("\nEnter starting point among above vertices:");
			scanf("%d",&v);
			dfsset(v,n);
			if(v==vx[0])
				printf("%d",vx[1]);
			else
				printf("%d",vx[0]);		
			
		}
	}	
}	
void main()
{	
	int i,j,n;
	printf("\nEnter number of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter edge from %d to %d: ",i,j);
			scanf("%d",&graph[i][j]);
		}
	}
	oddeven(n);
}

Output:
Enter number of vertices: 5

Enter edge from 1 to 1:	0
Enter edge from 1 to 2:	1
Enter edge from 1 to 3:	0
Enter edge from 1 to 4:	0
Enter edge from 1 to 5:	1
Enter edge from 2 to 1:	1
Enter edge from 2 to 2:	0
Enter edge from 2 to 3:	1
Enter edge from 2 to 4:	1
Enter edge from 2 to 5:	0
Enter edge from 3 to 1:	0
Enter edge from 3 to 2:	1
Enter edge from 3 to 3:	0
Enter edge from 3 to 4:	1
Enter edge from 3 to 5:	0
Enter edge from 4 to 1:	0
Enter edge from 4 to 2:	1
Enter edge from 4 to 3:	1
Enter edge from 4 to 4:	0
Enter edge from 4 to 5:	0
Enter edge from 5 to 1:	1
Enter edge from 5 to 2:	0
Enter edge from 5 to 3:	0
Enter edge from 5 to 4:	0
Enter edge from 5 to 5:	0

Vertices: 2 5	
Enter starting point among above vertices: 2

Eulerian Path: 2-->3-->4-->2-->1-->5
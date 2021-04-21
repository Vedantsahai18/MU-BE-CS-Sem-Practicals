#include<stdio.h>
#include<conio.h>

int n,i, finalExit, levelExit;
int station_times[2][10], t[2][9], entry[2], e[2], f1[10], f2[10], l[2][10];
//station_times: node values as like cost of a place in monopoly
//t: transaction time between two satges of different levels. Stages on a same level do not have a transaction time between them.
//entry: entry values into the two stages
//e: exit values outgoing the two stages

void print_stations()
{
		int j,i=levelExit;
		printf("\nThe Optimal path is:\n");
		for(j=1;j<n;++j)
		{
				i = l[i-1][j];
				printf("line %d ", i);
				printf("station %d ", j);
				printf("\n");
		}
		i = levelExit;
		printf("line %d ", i);
		printf("station %d ", n);
		printf("\n");
}
void fastest_way()
{
		f1[0] = entry[0] + station_times[0][0];
    f2[0] = entry[1] + station_times[1][0];
    int j;
    for(j = 1; j<n; ++j)
    {
      	if( (f1[j-1]+station_times[0][j]) <= (f2[j-1]+t[1][j-1]+station_times[0][j]) )
				{
						f1[j] = f1[j-1] + station_times[0][j];
						l[0][j] = 1;
				}
				else
				{
						f1[j] = f2[j-1] + t[1][j-1] + station_times[0][j];
						l[0][j] = 2;
				}
				if( (f2[j-1]+station_times[1][j]) <= (f1[j-1]+t[0][j-1]+station_times[1][j]) )
				{
						f2[j] = f2[j-1] + station_times[1][j];
						l[1][j] = 2;
				}
				else
				{
						f2[j] = f1[j-1] + t[0][j-1] + station_times[1][j];
						l[1][j] = 1;
				}
		}
		if( (f1[n-1] + e[0]) <= (f2[n-1] + e[1]) )
		{
				finalExit = f1[n-1] + e[0];
				levelExit = 1;
		}
		else
		{
				finalExit = f2[n-1] + e[1];
				levelExit = 2;
		}
		print_stations();
}
int main()
{
		printf("\tAssembly Line Scheduling\n");
		printf("Enter the number of nodes: ");
		scanf("%d",&n);
		printf("Enter the entry values:\n");
		for(i=0;i<2;i++)	
				scanf("%d",&entry[i]);
		printf("Enter the exit values:\n");
		for(i=0;i<2;i++)
				scanf("%d",&e[i]);
		printf("\nEnter the station times of row/line S1:\n");
		for(i=0; i<n; ++i)
				scanf("%d", &station_times[0][i]);
		printf("\nEnter the station times of row/line S2:\n");
		for(i=0 ; i<n; ++i)
				scanf("%d", &station_times[1][i]);
		printf("\nEnter transaction times from row/line S1:\n");
		for(i=0; i<n-1; ++i)
				scanf("%d", &t[0][i]);
		printf("\nEnter transaction times from row/line S2:\n");
		for(i=0; i<n-1; ++i)
				scanf("%d", &t[1][i]);
		printf("\n");
		fastest_way();
		printf("\nOptimal path costs are:\n");
		i=1;
		printf("For Path[%d] ->\t",i);
		for(int j=0;j<n;j++)
				printf("S[%d][%d]=%d\t",i,j+1,f1[j]);
		printf("Total cost: %d",finalExit);
		printf("\n");
		i=2;
		printf("For Path[%d] ->\t",i);
		for(int j=0;j<n;j++)
				printf("S[%d][%d]=%d\t",i,j+1,f2[j]);
		finalExit = f2[n-1] + e[1];
		printf("Total cost: %d",finalExit);
		getch();
		return 0;
}
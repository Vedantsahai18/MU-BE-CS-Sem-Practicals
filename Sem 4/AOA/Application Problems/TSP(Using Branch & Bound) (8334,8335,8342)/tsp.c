//PROJECT TOPIC : TRAVELLING-SALESMAN USING BRANCH AND BOUND


#include<stdio.h>
#include<stdlib.h>
int a[10][10],visited[10],n,cost=0;
void get()
{
int i,j;
printf("\n\nEnter Number of Cities: ");
scanf("%d",&n);

printf("\nEnter Cost Matrix: \n");
for( i=0;i<n;i++)
     {
     printf("\n Enter Elements of Row # : %d\n",i+1);
     for( j=0;j<n;j++)
     scanf("%d",&a[i][j]);
     visited[i]=0;
     }

printf("\nThe Cost Matrix is:\n");

for( i=0;i<n;i++)
     {
     printf("\n");
     for( j=0;j<n;j++)
          printf("%d ",a[i][j]);

          }

}
int least(int c)
{
 int i,nc=999;
 int min=999,kmin;
 for(i=0;i<n;i++)
    {
     if((a[c][i]!=0)&&(visited[i]==0))
     if(a[c][i]<min)
     {
      min=a[i][0]+a[c][i];
      kmin=a[c][i];
      nc=i;
      }
     }

if(min!=999)
cost+=kmin;
return nc;
}


void mincost(int city)
{
int i,ncity;
visited[city]=1;
printf("%d -> ",city+1);
ncity=least(city);

if(ncity==999)
    {
     ncity=0;
     printf("%d",ncity+1);
     cost+=a[city][ncity];
     return;
     }

mincost(ncity);
}


void put()
{
 printf("\n\nMinimum cost:");
 printf("%d",cost);
}

int main()
{
get();
printf("\n\nThe Path is:\n\n");
mincost(0);
put();
}

/*

Enter Number of Cities: 4

Enter Cost Matrix:

 Enter Elements of Row # : 1
999
4
6
7

 Enter Elements of Row # : 2
4
999
6
3

 Enter Elements of Row # : 3
5
9
999
6

 Enter Elements of Row # : 4
2
1
5
999

The Cost Matrix is:

999 4 6 7
4 999 6 3
5 9 999 6
2 1 5 999

The Path is:

1 -> 4 -> 2 -> 3 -> 1

Minimum cost:19
*/

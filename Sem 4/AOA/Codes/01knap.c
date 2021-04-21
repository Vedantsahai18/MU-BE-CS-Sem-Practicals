#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int table[SIZE][SIZE] = {0};

typedef struct item{
	int profit, weight;
}itm;

int max(int n1, int n2){
  if(n1>n2){
    return n1;
  }
  else{
    return n2;
  }
}

void display(itm list[], int n){

	for(int i = 1; i <= n; i++){
		printf("Item no: %d | Profit: %d | weight: %d\n", i, list[i].profit, list[i].weight);
	}
}

void disp_table(int n, int cap)
{
    int i,w;
    printf("Table is\n");
           for(i=0; i<=n; i++)
           {
               for(w=0; w<=cap; w++)
               {
                   printf("%d\t", table[i][w]);
               }
               printf("\n");
           }
}

void run(itm list[], int cap, int n){
  int i, w;
  itm item;
  for(i = 1; i <= n; i++){
    item = list[i];
    for(w = 0; w <= cap; w++){
      if(item.weight <= w){
        table[i][w] = max(table[i-1][w], item.profit+table[i-1][w-item.weight]);
      }
      else{
        table[i][w] = table[i-1][w];
      }
    }
  }
  disp_table(n, cap);
  i = n;
  w = cap;
  printf("Items in sack are\n");
  while(i > 0){
    if(table[i][w] != table[i-1][w]){
      printf("Item %d ", i);
      w = w - list[i].weight;
    }
    i = i - 1;
  }
  printf("\n");
}

int main(){
  int i, n, cap;
	itm list[10];
	printf("Enter capacity of sack\n");
  scanf("%d", &cap);
	printf("Enter number of elements\n");
	scanf("%d", &n);
	for(i=1; i<n+1; i++)
	{
		printf("Enter details for Item %d\n", i);
    printf("Enter profit\n");
		scanf("%d", &list[i].profit);
		printf("Enter weight\n");
		scanf("%d", &list[i].weight);
	}
  run(list, cap, n);
}

/*
Enter capacity of sack
5
Enter number of elements
4
Enter details for Item 1
Enter profit
100
Enter weight
3
Enter details for Item 2
Enter profit
20
Enter weight
2
Enter details for Item 3
Enter profit
60
Enter weight
4
Enter details for Item 4
Enter profit
40
Enter weight
1
Table is
0	0	0	0	0	0
0	0	0	100	100	100
0	0	20	100	100	120
0	0	20	100	100	120
0	40	40	100	140	140
Items in sack are
Item 4 Item 1
*/

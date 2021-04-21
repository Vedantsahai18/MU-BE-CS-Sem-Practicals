#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int list[], int low, int high)
{
	int pivot, i=low, j=high;
	pivot=list[low];
	while(i<j)
	{
		while(list[i]<=pivot)
		{
			i++;
		}
		while(list[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			swap(&list[i], &list[j]);
		}
	}
	swap(&list[low], &list[j]);
	return j;
}

void quickSort(int list[], int low, int high)
{
	int pi;
	if(low<high)
	{
		pi=partition(list,low, high);
		quickSort(list, low, pi-1);
		quickSort(list, pi+1, high);
	}
}

void display(int list[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

void main()
{
	int list[SIZE], i, j, n, ele;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	printf("Enter elements\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &ele);
		list[i]=ele;
	}
	printf("Array before sorting is\n");
	display(list, n);
	quickSort(list, 0, n-1);
	printf("Array after sorting is\n");
	display(list, n);
}

/*
Enter number of elements
5
Enter elements
5
4
3
2
1
Array before sorting is
5 4 3 2 1 
Array after sorting is
1 2 3 4 5 
*/


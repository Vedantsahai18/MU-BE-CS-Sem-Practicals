#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void merge(int list[], int low, int mid, int high) //Function to merge arrays
{
    int i, j, k=0;
    i=low;
    j=mid+1;
    int c[SIZE];
    while(i<=mid && j<=high)
    {
        if(list[i]<list[j])
        {
            c[k]=list[i];
            i++;
        }
        else
        {
            c[k]=list[j];
            j++;
        }
        k++;
    }
    while(i<=mid) //For when j>high
    {
        c[k]=list[i];
        i++;
        k++;
    }
    while(j<=high)  //For when i>mid
    {
        c[k]=list[j];
        j++;
        k++;
    }
    for(i=low, k=0; i<=high; i++, k++) //To change elements of original array after copying into temp array
    {
        list[i]=c[k];
    }
}

void mergeSort(int list[], int low, int high) /*Recursive function that splits arrays and merges them after sorting*/
{
	int m;
	if(low<high)
	{
		m=(low+high)/2;
		mergeSort(list, low, m);
		mergeSort(list, m+1, high);
        merge(list,low, m, high);
	}
}

void display(int list[], int n) //Function to display elements in array
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
	mergeSort(list, 0, n-1);
	printf("Array after sorting is\n");
	display(list, n);
}


/*
 Enter number of elements
 8
 Enter elements
 39
 9
 81
 45
 90
 27
 72
 18
 Array before sorting is
 39 9 81 45 90 27 72 18
 Array after sorting is
 9 18 27 39 45 72 81 90
*/

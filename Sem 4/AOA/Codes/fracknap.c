#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	int id, profit, weight;
	float ratio, frac;
}itm;

void merge(itm list[], int low, int mid, int high) //Function to merge arrays
{
    int i, j, k=0;
    i=low;
    j=mid+1;
    itm c[10];
    while(i<=mid && j<=high)
    {
        if(list[i].ratio > list[j].ratio)
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

void mergeSort(itm list[], int low, int high) /*Recursive function that splits arrays and merges them after sorting*/
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

void display(itm list[], int n){

	for(int i = 0; i < n; i++){
		printf("Item no: %d | Profit: %d | weight: %d | ratio: %f | fraction: %f\n", list[i].id, list[i].profit, list[i].weight, list[i].ratio, list[i].frac);
	}
}

void main()
{
	int i, n, j, flag = 1, cap, remcap, cnt = 0;
	float totprofit = 0.0;
	itm ele, list[10], sack[10];
	printf("Enter capacity of sack\n");
	scanf("%d", &cap);
	remcap = cap;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	printf("Enter elements\n");
	for(i=0; i<n; i++)
	{
		printf("Enter details for Item %d\n", i+1);
		list[i].id = i+1;
		printf("Enter weight\n");
		scanf("%d", &list[i].weight);
		printf("Enter profit\n");
		scanf("%d", &list[i].profit);
		list[i].ratio = (float)list[i].profit/list[i].weight;
		list[i].frac = 0.0;
	}

	printf("List of items\n");
	display(list, n);

	mergeSort(list, 0, n-1);

	printf("\nAfter sorting\n");
	display(list, n);

	for(i = 0, j = 0; i < n; i++){
		if(remcap >= list[i].weight){
			list[i].frac = 1.0;
			sack[j] = list[i];
			cnt++;
			j++;
		}
		else if(remcap < list[i].weight && remcap > 0){
			list[i].frac = (float)remcap/list[i].weight;
			sack[j] = list[i];
			cnt++;
			j++;
		}
		remcap = remcap - list[i].weight*list[i].frac;
	}

	for(i = 0; i < cnt; i++){
		totprofit = totprofit + sack[i].profit*sack[i].frac;
	}

	printf("\nItems in sack\n");
	display(sack, cnt);
	printf("Total profit is %f\n", totprofit);
}

/*
Enter capacity of sack
20
Enter number of elements
3
Enter elements
Enter details for Item 1
Enter weight
18
Enter profit
25
Enter details for Item 2
Enter weight
15
Enter profit
24
Enter details for Item 3
Enter weight
10
Enter profit
15
List of items
Item no: 1 | Profit: 25 | weight: 18 | ratio: 1.388889 | fraction: 0.000000
Item no: 2 | Profit: 24 | weight: 15 | ratio: 1.600000 | fraction: 0.000000
Item no: 3 | Profit: 15 | weight: 10 | ratio: 1.500000 | fraction: 0.000000

After sorting
Item no: 2 | Profit: 24 | weight: 15 | ratio: 1.600000 | fraction: 0.000000
Item no: 3 | Profit: 15 | weight: 10 | ratio: 1.500000 | fraction: 0.000000
Item no: 1 | Profit: 25 | weight: 18 | ratio: 1.388889 | fraction: 0.000000

Items in sack
Item no: 2 | Profit: 24 | weight: 15 | ratio: 1.600000 | fraction: 1.000000
Item no: 3 | Profit: 15 | weight: 10 | ratio: 1.500000 | fraction: 0.500000
Total profit is 31.500000

------------------XXXX------------------

Enter capacity of sack
15
Enter number of elements
6
Enter elements
Enter details for Item 1
Enter weight
10
Enter profit
1
Enter details for Item 2
Enter weight
5
Enter profit
2
Enter details for Item 3
Enter weight
4
Enter profit
4
Enter details for Item 4
Enter weight
2
Enter profit
4
Enter details for Item 5
Enter weight
7
Enter profit
7
Enter details for Item 6
Enter weight
3
Enter profit
2
List of items
Item no: 1 | Profit: 1 | weight: 10 | ratio: 0.100000 | fraction: 0.000000
Item no: 2 | Profit: 2 | weight: 5 | ratio: 0.400000 | fraction: 0.000000
Item no: 3 | Profit: 4 | weight: 4 | ratio: 1.000000 | fraction: 0.000000
Item no: 4 | Profit: 4 | weight: 2 | ratio: 2.000000 | fraction: 0.000000
Item no: 5 | Profit: 7 | weight: 7 | ratio: 1.000000 | fraction: 0.000000
Item no: 6 | Profit: 2 | weight: 3 | ratio: 0.666667 | fraction: 0.000000

After sorting
Item no: 4 | Profit: 4 | weight: 2 | ratio: 2.000000 | fraction: 0.000000
Item no: 5 | Profit: 7 | weight: 7 | ratio: 1.000000 | fraction: 0.000000
Item no: 3 | Profit: 4 | weight: 4 | ratio: 1.000000 | fraction: 0.000000
Item no: 6 | Profit: 2 | weight: 3 | ratio: 0.666667 | fraction: 0.000000
Item no: 2 | Profit: 2 | weight: 5 | ratio: 0.400000 | fraction: 0.000000
Item no: 1 | Profit: 1 | weight: 10 | ratio: 0.100000 | fraction: 0.000000

Items in sack
Item no: 4 | Profit: 4 | weight: 2 | ratio: 2.000000 | fraction: 1.000000
Item no: 5 | Profit: 7 | weight: 7 | ratio: 1.000000 | fraction: 1.000000
Item no: 3 | Profit: 4 | weight: 4 | ratio: 1.000000 | fraction: 1.000000
Item no: 6 | Profit: 2 | weight: 3 | ratio: 0.666667 | fraction: 0.666667
Total profit is 16.333334
*/

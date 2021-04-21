#include<stdio.h>
#include<stdlib.h>

typedef struct MinMax{
	int max, min;
}MM;

MM calculate(int a[], int low, int high){
	
	MM LSA, RSA, res;
	int mid;
	
	if(low == high){
		res.max = a[low];
		res.min = a[low];
	}
	
	else if(low + 1 == high){
		
		if(a[high] > a[low]){
			res.min = a[low];
			res.max = a[high];
		}
		else{
			res.min = a[high];
			res.max = a[low];
		}
	}
	
	else{
		mid = (low+high)/2;
		
		LSA = calculate(a, low, mid);
		RSA = calculate(a, mid+1, high);
		
		if(LSA.min > RSA.min){
			res.min = RSA.min;
		}
		else{
			res.min = LSA.min;
		}
		
		if(LSA.max > RSA.max){
			res.max = LSA.max;
		}
		else{
			res.max = RSA.max;
		}
	}
	
	return res;
}


void main()
{
	int list[10], i, n, ele;
	MM res;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	printf("Enter elements\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &list[i]);
	}
	res = calculate(list, 0, n-1);
	printf("Maximum element is %d\nMinimum element is %d\n", res.max, res.min);
}

/*
Enter number of elements
8
Enter elements
12
325
673
34
5
7
235
4
Maximum element is 673
Minimum element is 4
*/

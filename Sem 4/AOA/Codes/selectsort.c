#include <stdio.h>
#include <stdlib.h>

void main(){
	int a[5], ele, i, j, flag = 1, n;
	printf("Enter the size of array\n");
	scanf("%d", &n); 
	printf("Enter %d elements\n", n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("Array before sorting\n");
	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i = 0; i < n-1; i++){
		flag = i;
		for(j = i+1; j<n; j++){
			if(a[j] < a[flag]){
				flag = j;
				ele = a[flag];
				a[flag] = a[i];
				a[i] = ele;
			}
		}
	}
	printf("Array after sorting\n");
	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

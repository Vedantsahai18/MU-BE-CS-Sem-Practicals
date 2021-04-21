/*
 Title   : Insertion Sort
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>

void main(){
	int a[10], ele, i, j, key, n;
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
	for(i = 1; i < n; i++){
		key = a[i];
    j = i - 1;
    while(j > 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
	}
	printf("Array after sorting\n");
	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*
Enter the size of array
5
Enter 5 elements
13
24
46
36
57
Array before sorting
13 24 46 36 57
Array after sorting
13 24 36 46 57
*/

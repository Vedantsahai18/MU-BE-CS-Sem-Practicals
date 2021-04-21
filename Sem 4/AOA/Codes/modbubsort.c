#include <stdio.h>
#include <stdlib.h>

void main(){
	int a[5], ele, i, j, flag = 1;
	printf("Enter 5 elements\n");
	for(i = 0; i < 5; i++){
		scanf("%d", &a[i]);
	}
	printf("Array before sorting\n");
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i = 0; (i < 5) && flag == 1; i++){
		flag = 0;
		for(j = 0; j < 5-i; j++){
			if(a[j] > a[j+1]){
				ele = a[j];
				a[j] = a[j+1];
				a[j+1] = ele;
				flag = 1;
			}
		}
	}
	printf("Array after sorting\n");
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

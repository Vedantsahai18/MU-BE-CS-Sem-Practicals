#include<stdio.h>
#define size 30

void coin_change(int amt, int n,int c[size]){
	int arr[size][size]={0},i,j;
	arr[0][j] = 1;
	for(j = 1;j <= amt;j++){
		arr[0][j] = 0;
	}
	
	for(i = 1; i <= n;i++){
		for(j = 0;j <= amt;j++){
			if(c[i]>j){
			    arr[i][j] = arr[i-1][j];
			}
			else{
			    arr[i][j] = arr[i-1][j] + arr[i][j-c[i]];
			}
		}
	}
	
	for(i = 0; i <= n;i++){
	    for(j = 0;j <= amt;j++)
	    {
	        printf("%d\t",arr[i][j]);
	    }
	    printf("\n");
	}
	
	printf("The number of possible ways to make change of %d is %d",amt,arr[n][amt]);
}

void main()
{
	int amt,n,c[size] = {0};
	printf("Enter the total amount: ");
	scanf("%d",&amt);
	printf("Enter the no of coins: "); //assume when no of coins are 4 the coins are 1,2,3,4
	scanf("%d",&n);
	printf("Enter the denominations: \n");
	for(int i = 1;i <= n;i++){
		scanf("%d",&c[i]);
	}
	
	printf("\n");
	coin_change(amt,n,c);
}





/*
Enter the total amount: 10                                                                                                             
Enter the no of coins: 4                                                                                                               
Enter the denominations:                                                                                                               
2                                                                                                                                      
3                                                                                                                                      
5                                                                                                                                      
6    


1       0       0       0       0       0       0       0       0       0      0
1       0       1       0       1       0       1       0       1       0      1
1       0       1       1       1       1       2       1       2       2      2
1       0       1       1       1       2       2       2       3       3      4
1       0       1       1       1       2       3       2       4       4      5
The number of possible ways to make change of 10 is 5                                                                                  
                                                  
*/
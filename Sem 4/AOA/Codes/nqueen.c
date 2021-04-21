/*
 Title   : N-Queen's Algorithm
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 10

int col[SIZE] = {0};

int isSafe(int q, int c){
  int k;
  for(k = 1; k <=  q - 1; k++){
    if(c == col[k] || abs(q-k) == abs(c-col[k])){
      return 0;
    }
  }
  return 1;
}

void nQueen(int q, int n, int *count){
  int c;
  for(c = 1; c <= n; c++){
    if(isSafe(q,c)){
      col[q] = c;
      if(q == n){
        for(c = 1; c <= n; c++){
          printf("Queen %d placed at column %d\n", c, col[c]);
        }
        printf("\n");
        *count = *count + 1;
      }
      else{
        nQueen(q+1, n, count);
      }
    }
  }
}

void main(){
  int n, count = 0;
  printf("Enter the number of Queens\n");
  scanf("%d", &n);
  nQueen(1, n, &count);
  printf("There are %d solutions possible\n", count);
}

/*
Enter the number of Queens
4
Queen 1 placed at column 2
Queen 2 placed at column 4
Queen 3 placed at column 1
Queen 4 placed at column 3

Queen 1 placed at column 3
Queen 2 placed at column 1
Queen 3 placed at column 4
Queen 4 placed at column 2

There are 2 solutions possible
*/

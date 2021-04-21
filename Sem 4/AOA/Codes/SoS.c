/*
 Title   : Sum of Subset Algorithm
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 #define SIZE 10

int sol[SIZE] = {0};

int isProm(int l, int wsf, int tpl, int w[], int s){
  if(wsf + tpl >= s && wsf + w[l + 1] <= s){
    return 1;
  }
  else{
    return 0;
  }
}

void SumofSub(int l, int wsf, int tpl, int w[], int s, int n){
  if(wsf == s){
    printf("The solution is\n");
    for(int i = 0; i < n; i++){
      if(sol[i] == 1){
        printf("%d ", w[i]);
      }
    }
    printf("\n");
  }
  else if(isProm(l, wsf, tpl, w, s)){
    sol[l+1] = 1;
    SumofSub(l+1, wsf + w[l+1], tpl - w[l+1], w, s, n);
    sol[l+1] = 0;
    SumofSub(l+1, wsf, tpl - w[l+1], w, s, n);
  }
}

void sort(int n, int a[]){
  int flag, ele, i, j;
  for(i = 0; (i < n) && flag == 1; i++){
    flag = 0;
    for(j = 0; j < n-i; j++){
      if(a[j] > a[j+1]){
        ele = a[j];
        a[j] = a[j+1];
        a[j+1] = ele;
        flag = 1;
      }
    }
  }
}

 void main(){
   int n, w[SIZE], sum = 0, usersum;
   printf("Enter number of weights\n");
   scanf("%d", &n);
   printf("Enter weights\n");
   for(int i = 0; i < n; i++){
     scanf("%d", &w[i]);
     sum = sum + w[i];
   }
   sort(n, w);
   printf("Enter required sum\n");
   scanf("%d", &usersum);
   SumofSub(-1, 0, sum, w, usersum, n);
 }

/*
Enter number of weights
4
Enter weights
6
5
3
4
Enter required sum
13
The solution is
6 3 4 

----------------x----------------

Enter number of weights
3
Enter weights
2
4
6
Enter required sum
6
The solution is
2 4
The solution is
6
*/

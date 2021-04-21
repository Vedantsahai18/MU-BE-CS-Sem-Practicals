#include<stdio.h>
#include<math.h>
#define m 20
void con(long int num, int arr[],int z){
    int j=1;
    long int k,i=num;
    printf("\ni=%ld",num);
    while(i!=0){
        k=i%10;
        i/=10;
        arr[j++]=k;
    }
}
void main(){
    int i,j,k,x,e,r=0,p,n,hc[m],par[6],temp[m];
    long int ham;
    printf("Enter the parity :\n1. even\n2. odd : ");
    scanf("%d",&p);
    printf("Enter the number of bits in the hamming code : ");
    scanf("%d",&n);
    printf("Enter the hc that is being sent : ");
    scanf("%ld",&ham);
    printf("\nham = %ld",ham);
    con(ham,hc,n);
    printf("\nThe string is : ");
    for(i=1;i<=n;i++)
        printf("%d",hc[i]);
    while(pow(2,r)<(n+1))//returns the array going from 1 to n for lsb to msb
        r++;
    for(i=0;i<r;i++){
        j=1;
        e=0;
        x = pow(2,i);
        printf("\n The bits selected for parity bit 2^%d = %d :",i,x);
        
        for(k=1;k<x;k++)
            j++;
        
        while(j<=n){
            for(k=1;k<=x;k++){
                if(j<=n){
                    printf("%d ",j);
                    temp[e++]=hc[j++];
                }
                else
                    break;
            }
        
            if(j>n)
                break;
        
            for(k=1;k<=x;k++)
                j++;
        }
        
        printf("\n The bits : ");
        for(j=0;j<e;j++)
            printf("%d",temp[j]);
        
        if(p==1){
            x=0;
            for(j=0;j<e;j++){
                if(temp[j]==1)
                    x++;
            }
            if(x%2==0)
                par[i]=0;
            else
                par[i]=1;
        }
        
        else if(p==2){
            x=0;
            for(j=0;j<e;j++){
                if(temp[j]==1)
                    x++;
            }
            if(x%2==1)
                par[0]=0;
            else
                par[1]=1;
        }
        
    }
    
    printf("\n The error bit is : ");
    for(i=0;i<r;i++){
        printf("%d",par[i]);
    }
    printf("\n");
}
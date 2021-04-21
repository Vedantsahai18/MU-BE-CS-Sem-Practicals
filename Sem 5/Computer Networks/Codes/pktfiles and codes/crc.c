#include<stdio.h>
#include<math.h>
#define n 10

void con(int num, int arr[n],int z){
    int k,i=num,j=0,a[n];
    while(i!=0){
        k=i%10;
        i/=10;
        a[j++]=k;
    }
    
    for(i=0,k=z-1;k>=0;i++,k--){
        arr[i]=a[k];
    }
    
}

void divide(int t[n], int d[n], int k[n], int x, int y){
    int i,j,r,q=0;
    
    for(i=0;i<x;i++){
        if(x-i-1>=y-1){
            if(d[i]==1){
                t[q++]=1;
                for(j=0,r=i;j<y;j++,r++){
                    if((d[r]==0 && k[j]==1)||(d[r]==1 && k[j]==0))
                        d[r]=1;
                    else if((d[r]==0 && k[j]==0)||(d[r]==1 && k[j]==1))
                        d[r]=0;    
                }   
            }
            else
                t[q++]=0;
        }
        else
            break;
    }
    
    printf("\nThe quotient : ");
    for(j=0;j<(x-y+1);j++)
        printf("%d",t[j]);
        
    printf("\nThe remainder : ");
    for(j=0;j<x;j++)
        printf("%d",d[j]);
}

void main(){
    int data,key,d[n],k[n],t[n],r[n],l,m,i,j;
    
    printf("Enter the no. of bits in data : ");
    scanf("%d",&l);
    printf("Enter the data that is being sent : ");
    scanf("%d",&data);
    printf("Enter the no. of bits in key : ");
    scanf("%d",&m);
    printf("Enter the key to check that data : ");
    scanf("%d",&key);
    //creating array
    data*=pow(10,m-1);
    con(data,d,l+m-1);
    con(key,k,m);
    //remainder
    for(i=0;i<l+m-1;i++)
        r[i]=d[i];
    
    //getting the remainder
    divide(t,r,k,l+m-1,m);
    
    //aading rem+data
    for(i=0;i<l+m-1;i++)
        d[i]+=r[i];
        
    //checking crc
    divide(t,d,k,l+m-1,m);
    i=1;
    for(j=0;j<l;j++){
        if(d[j]==1){
            i=0;
            break;
        }
    }
    if(i==1)
        printf("\nThe data sent  is correct");
    if(i==0)
        printf("\nThe data sent is corrupted");    
}

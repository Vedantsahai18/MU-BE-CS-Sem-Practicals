#include<stdio.h>
#include<math.h>
#define m 20
void con(long int num, int arr[], int z, int y){
    int j=1,fl,f;
    long int k=2,i=num;
    while(i!=0){
        f=fl=0;
        while(f!=y){
            if(j==pow(2,f)){
                arr[j++]=0;
                fl=1;
                break;
            }
            f++;
        }
        if(fl==0){
            k=i%10;
            i/=10;
            arr[j++]=k;
        }
    }
    
}
void main(){
    int i,j,k,x,e,r=0,p,n,y,hc[m],d[m],par[6],temp[m];
    long int ham,data;
    printf("Enter the parity :\n1. even\n2. odd : ");
    scanf("%d",&p);
    printf("Enter the number of bits in the data : ");
    scanf("%d",&n);
    printf("Enter the data string that is being sent : ");
    scanf("%ld",&data);
    printf("\ndata = %ld",data);
    while(pow(2,r)<(n+r+1))
        r++;
    con(data,d,n,r);//returns the array going from 1 to n for lsb to msb
    n+=r;
    for(i=1;i<=n;i++)
        hc[i]=d[i];
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
        y=pow(2,i);    
        if(p==1){
            x=0;
            for(j=0;j<e;j++){
                if(temp[j]==1)
                    x++;
            }
            if(x%2==1)
                hc[y]=1;
        }
        else if(p==2){
            x=0;
            for(j=0;j<e;j++){
                if(temp[j]==1)
                    x++;
            }
            if(x%2==0)
                hc[y]=1;
        }
    }
    printf("\n The hamming code : ");
    for(i=n;i>=1;i--)
        printf("%d",hc[i]);
    
    for(i=0;i<r;i++){
        j=1;
        e=0;
        x = pow(2,i);
        printf("\n The bits selected for parity bit 2^%d = %d :",i,x);
        //going 2^i-1 positions ahead
        for(k=1;k<x;k++)
            j++;
        //selecting 2^i elements
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
            //going 2^i positions ahead
            for(k=1;k<=x;k++)
                j++;
        }
        
        printf("\n The bits : ");
        for(j=0;j<e;j++)
            printf("%d",temp[j]);
        //even parity checking temp bits selected
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
        }//odd parity checking temp bits selected
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
    //checking the error bit    
    printf("\n The error bit is : ");
    for(i=0;i<r;i++){
        printf("%d",par[i]);
    }
    printf("\n");
}
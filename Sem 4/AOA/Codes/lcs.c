/*
Title:Longest Common Subsequence
Name:Mayank Mishra
roll no.:8348
Exp no.:17
*/
#include<stdio.h>
#include<string.h>
# define max 10
void main()
{
    char a[max],b[max],fl[max],fw[max],temp;
    int f[max+1][max+1],i,j,r=0,c=0,q,w;
    printf("Enter the string 1:");
    scanf("%s",a);
    printf("%s\n",a);
    printf("Enter the string 2:");
    scanf("%s",b);
    printf("%s",b);
    for(i=0;a[i]!='\0';i++)
        r++;
    for(i=0;b[i]!='\0';i++)
        c++;
    for(i=0;i<r+1;i++)
    {
        for(j=0;j<c+1;j++)
            f[i][j]=0;
    }
    for(i=1;i<r+1;i++)
    {
        for(j=1;j<c+1;j++)
        {
            if(a[i-1]==b[j-1])
                f[i][j]=1+f[i-1][j-1];
            else
            {
                if(f[i-1][j]>=f[i][j-1])
                    f[i][j]=f[i-1][j];
                else if(f[i-1][j]<f[i][j-1])
                    f[i][j]=f[i][j-1];
            }
        }
    }
    printf("\nThe mat\n");
    printf("    ");
    for(q=0;q<c;q++)
        printf("%c ",b[q]);
    for(q=0;q<r+1;q++)
    {
        printf("\n");
        if(q>0)
            printf("%c ",a[q-1]);
        else
            printf("  ");
        for(w=0;w<c+1;w++)
            printf("%d ",f[q][w]);
    }
    i=r;
    j=c;
    q=0;
    while(i!=0)
    {
        if(f[i-1][j]>f[i][j-1])
        {
            if(f[i-1][j]!=f[i][j])
            {
                fl[q++]=a[i-1];
                i--;
                j--;
            }
            else
                i--;
        }
        else if(f[i-1][j]<=f[i][j-1])
        {
            if(f[i][j-1]!=f[i][j])
            {
                fl[q++]=a[i-1];
                i--;
                j--;
            }
            else
                j--;
        }
    }
    fl[q]='\0';
    for(i=q-1,j=0;i>=0;i--,j++)
        fw[j]=fl[i];
    fw[j]='\0';
    printf("\nThe longest common subsequence : %s",fw);
}
/*OUTPUT:
Enter the string 1:abcdef
abcdef
Enter the string 2:acbedf
acbedf
The mat
    a c b e d f
  0 0 0 0 0 0 0
a 0 1 1 1 1 1 1
b 0 1 1 2 2 2 2
c 0 1 2 2 2 2 2
d 0 1 2 2 2 3 3
e 0 1 2 2 3 3 3
f 0 1 2 2 3 3 4
The longest common subsequence : acef
*/
#include<stdio.h>
#include<conio.h>
void main()
{
        unsigned int a,b,i,ari,log,shf,res,res1;
        clrscr();
        {
                printf("1:Arithmetic Ins\n 2:Logical Ins\n Enter option: ");
                scanf("%d",&i);
                switch(i)
                {
                        case 1:
                                printf("1.Addition\n 2. Subtraction\n 3.Multiplication\n 4.Division\n Enter : ");
                                scanf("%d",&ari);
                                switch(ari)
                                {
                                        case 1: printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        mov bx,b
                                                        add ax,bx
                                                        mov res,ax
                                                }
                                                printf("Addition=%d\n",res);
                                                break;

                                        case 2:printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        mov bx,b
                                                        sub ax,bx
                                                        mov res,ax
                                                }
                                                printf("subtraction=%d\n",res);
                                                break;

                                        case 3:printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        mov bx,b
                                                        mul bx
                                                        mov res,ax
                                                        mov res1,dx
                                                }
                                                printf("Multiplication=%d%d\n",res,res1);
                                                break;

                                        case 4:printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        mov bx,b
                                                        div bx
                                                        mov res,ax
                                                        mov res1,dx
                                                }
                                                printf("Division: Quotient=%d Remainder=%d",res,res1);
                                                break;

                                        default:
                                                printf("Invalid Input");
                                                break;

                                }
                                break;
                        case 2: printf("1:AND\n 2:OR\n 3:NOT\n 4:exOR\n Enter option: ");

                        switch(i)
                        {
                        case 1:
                                printf("1.Addition\n 2. Subtraction\n 3.Multiplication\n 4.Division\n Enter : ");
                                scanf("%d",&log);
                                switch(log)
                                {
                                        case 1: printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        mov bx,b
                                                        and ax,bx
                                                        mov res,ax
                                                }
                                                printf("and=%d\n",res);
                                                break;

                                        case 2:printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        mov bx,b
                                                        or ax,bx
                                                        mov res,ax
                                                }
                                                printf("or=%d\n",res);
                                                break;

                                        case 3:printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        not ax
                                                        mov res,ax
                                                }
                                                printf("not=%d%d\n",res,res1);
                                                break;

                                        case 4:printf("\nEnter two nos: ");
                                                scanf("%d%d",&a,&b);
                                                _asm{
                                                        mov ax,a
                                                        mov bx,b
                                                        xor ax,bx
                                                        mov res,ax
                                                }
                                                printf("XOR=%d\n",res);
                                                break;

                                        default:
                                                printf("Invalid Input");
                                                break;

                                }
                                break;
                                }}
                                getch();
                }}

	
	
	

#include<stdio.h>
#include<stdlib.h>
#define reset 0

int grid[9][9]= {{0, 0, 5, 3, 0, 0, 0, 0, 0},
        		 {8, 0, 0, 0, 0, 0, 0, 2, 0},
        		 {0, 7, 0, 0, 1, 0, 5, 0, 0},
        		 {4, 0, 0, 0, 0, 5, 3, 0, 0},
        		 {0, 1, 0, 0, 7, 0, 0, 0, 6},
        		 {0, 0, 3, 2, 0, 0, 0, 8, 0},
        		 {0, 6, 0, 5, 0, 0, 0, 0, 9},
        		 {0, 0, 4, 0, 0, 0, 0, 3, 0},
        		 {0, 0, 0, 0, 0, 9, 7, 0, 0}
        		};

int row,col;
int total_call=0;

int isempty()
{
 	int i,j;
 	for(i=row;i<=8;i++)
    for(j=0;j<=8;j++)
	{
  		if(grid[i][j]==0)
   		{
   			row=i;
			col=j;
   			return 1;
   		}
    }
   	return 0;
}

int valid(int Row, int Col, int num)
{
   	int i,j;
    int row_start=(Row/3)*3;
    int col_start=(Col/3)*3;
   	for(j=0;j<=8;j++)
	{
       	if(grid[Row][j]==num)
    		return 0;
       	if(grid[j][Col]==num)
    		return 0;
   	}
    for(i=row_start;i<=row_start+2;i++)
  	for(j=col_start;j<=col_start+2;j++)
      	if(grid[i][j]==num)
			return 0;
    	return 1;
}

int solvesudoku()
{
	int digit,prev_row,prev_col; 
    total_call++;
	if(!isempty())
 		return 1;
	for(digit=1;digit<=9;digit++)
	{
  		if(valid(row,col,digit))
		{
  			grid[row][col]=digit;
  			prev_row=row;
			prev_col=col;
  			if(solvesudoku())
   				return 1;
  			row=prev_row;
			col=prev_col;
  			grid[row][col]=reset;
  		}
	}
	return 0;
}

void display()
{
	int i,j;
 	printf("\t-------------------------\n");
 	for(i=0;i<9;i++)
	{
    	printf("\t");
    	for(j=0;j<9;j++)
		{
       		if(j==0)
    			printf("| ");
       		if(grid[i][j]==0)
    			printf(". ");
       		else
    			printf("%d ",grid[i][j]);
       		if((j+1)%3==0)
    			printf("| ");
   		}
   		if((i+1)%3==0)
       		printf("\n\t-------------------------");
   		printf("\n");
	}
}

int main()
{
	int i,j,choice;
	int result=0; 
    printf("The entered sudoku is:\n");
    display();
    printf("1. Solve\t2. Exit\n");
    scanf("%d",&choice);
    if(choice==2)
       exit(0);
    else if(choice==1)
	{
		result=solvesudoku();
    	if(result)
		{
 			printf("The solved sudoku is:\n");
 			display();
    	}
    	else
    	printf("No possible solution\n");
    }
    return 0;
}
/* OUTPUT:
Case1:
The entered sudoku is:
        -------------------------
        | . . 5 | 3 . . | . . . |
        | 8 . . | . . . | . 2 . |
        | . 7 . | . 1 . | 5 . . |
        -------------------------
        | 4 . . | . . 5 | 3 . . |
        | . 1 . | . 7 . | . . 6 |
        | . . 3 | 2 . . | . 8 . |
        -------------------------
        | . 6 . | 5 . . | . . 9 |
        | . . 4 | . . . | . 3 . |
        | . . . | . . 9 | 7 . . |
        -------------------------
1. Solve        2. Exit
1
The solved sudoku is:
        -------------------------
        | 1 4 5 | 3 2 7 | 6 9 8 |
        | 8 3 9 | 6 5 4 | 1 2 7 |
        | 6 7 2 | 9 1 8 | 5 4 3 |
        -------------------------
        | 4 9 6 | 1 8 5 | 3 7 2 |
        | 2 1 8 | 4 7 3 | 9 5 6 |
        | 7 5 3 | 2 9 6 | 4 8 1 |
        -------------------------
        | 3 6 7 | 5 4 2 | 8 1 9 |
        | 9 8 4 | 7 6 1 | 2 3 5 |
        | 5 2 1 | 8 3 9 | 7 6 4 |
        -------------------------

Case2: 
The entered sudoku is:
        -------------------------
        | . 2 5 | 3 . . | . . . |
        | 8 . . | . . . | . 2 . |
        | . 7 . | . 1 . | 5 . . |
        -------------------------
        | 4 . . | . . 5 | 3 . . |
        | . 1 . | . 7 . | . . 6 |
        | . . 3 | 2 . . | . 8 . |
        -------------------------
        | . 6 . | 5 . . | . . 9 |
        | . . 4 | . . . | . 3 . |
        | . . . | . . 9 | 7 . . |
        -------------------------
1. Solve        2. Exit
1
No possible solution

Case3:
The entered sudoku is:
        -------------------------
        | . . 5 | 3 . . | . . . |
        | 8 . . | . . . | . 2 . |
        | . 7 . | . 1 . | 5 . . |
        -------------------------
        | 4 . . | . . 5 | 3 . . |
        | . 1 . | . 7 . | . . 6 |
        | . . 3 | 2 . . | . 8 . |
        -------------------------
        | . 6 . | 5 . . | . . 9 |
        | . . 4 | . . . | . 3 . |
        | . . . | . . 9 | 7 . . |
        -------------------------
1. Solve        2. Exit
2                                                 */

#include<stdio.h> 
int N=8; 
int sol[8][8];
int solveKTUtil(int x, int y, int movei,int xMove[], int yMove[]); 
int isSafe(int x, int y) 
{ 
	if( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
		return 1;
	else
		return 0; 
} 
void printSolution() 
{ 
	for (int x = 0; x < N; x++) 
	{ 
		for (int y = 0; y < N; y++) 
			printf(" %d\t ", sol[x][y]); 
		printf("\n"); 
	}
	printf("\n"); 
} 
int solveKnight() 
{ 
	for (int x = 0; x < N; x++) 
	{
		for (int y = 0; y < N; y++) 
		{
			sol[x][y] = -1; 
		}	
	}
	sol[1][7]=0;
	printSolution();
		int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
	
	if (solveKTUtil(1, 4, 1, xMove, yMove) == 0) 
	{ 
		printf("Solution does not exist"); 
		return 0; 
	} 
	else{
		printf("The Solution is :\n\n");
		printSolution();
	}
		 

	return 1; 
} 
int solveKTUtil(int x, int y, int movei,int xMove[], int yMove[]) 
{ 
int k, next_x, next_y; 
if (movei == N*N) 
	return 1; 
for (k = 7; k > 0; k--) 
{ 
	next_x = x + xMove[k]; 
	next_y = y + yMove[k]; 
	if (isSafe(next_x, next_y)) 
	{ 
		sol[next_x][next_y] = movei; 
		if (solveKTUtil(next_x, next_y, movei+1,xMove, yMove)) 
			return 1; 
		else
			sol[next_x][next_y] = -1;
	} 
} 

return 0; 
} 
int main() 
{ 
	solveKnight(); 
	return 0; 
}

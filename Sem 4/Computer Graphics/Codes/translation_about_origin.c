#include<Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a[10][3];
void drawPoly(float a[][3], int n)
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0;i < n;i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();
	glFlush();
}

void mul(int n, float trans[3][3])
{
	int i, j, k;
	float result[10][3];
	// Multiply original coordinate matrix a [][] with transformation matrix trans[][] to get the resultant new coordinates
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < 3;j++)
		{
			result[i][j] = 0;
			for (k = 0;k < 3;k++)
			{
				result[i][j] = result[i][j] + (a[i][k] * trans[k][j]);
			}
		}
	}

	printf("\n Final coordinates are");
	for (i = 0;i < n;i++)
	{
		printf("\n");

		for (j = 0;j < 3;j++)
		{
			printf("%f  ", result[i][j]);
		}
	}
	drawPoly(result, n);

}

void translation(int n,float tx,float ty)
{
 int i,j;
 float f[3][3]={ {1.0,0.0,0.0} ,{0.0,1.0,0.0}, {0.0,0.0,1.0}};
 // Initialize translation matrix
 f[2][0] = tx;
 f[2][1] = ty;

 printf("\n Translation Matrix is:");
 for(i=0;i<3;i++)
 {
	  printf("\n");
	 for(j=0;j<3;j++)
	 {
	   printf("%f ",f[i][j]);
	 }

 }

  // call mul function
  mul(n,f);
  printf("\n");

}

void input()
{

	int n, i,j;
	float tx,ty;
	printf("\n Enter number of vertices: ");
	scanf("%d", &n);
	printf("\n Enter coordinates of vertices: ");
	for(i = 0; i<n ;i++)
	{
		  printf("\n Enter coordinates:");
		  scanf("%f %f",&a[i][0],&a[i][1]);
	}


	for(i=0;i<n;i++)// set the last column as 1 for homogeneous co-ordinates
		 a[i][2]=1.0;


	printf("\n Input vertex are: ");// print the input vertices in matrix form
	for(i=0;i<n;i++)
	 {
		printf ("\n");
		for(j=0;j<3;j++)
				printf("%f , ",a[i][j]);
	 }


	drawPoly(a,n);

	printf("\n Enter the tx and ty: ");
	scanf("%f%f",&tx,&ty);
	translation(n,tx,ty);// call rotation function
}

void disp()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	// call input function
	input();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Translation...");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(disp);
	glutMainLoop();

}
?? 2019 GitHub, Inc.

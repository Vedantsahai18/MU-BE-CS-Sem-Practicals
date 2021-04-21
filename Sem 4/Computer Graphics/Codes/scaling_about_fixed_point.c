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

void scaling(int n,float sx,float sy)
{
	int i,j,xf=0,yf=0;
	float f[3][3]={ {0.0,0.0,0.0} ,{0.0,0.0,0.0}, {0.0,0.0,1.0}};
	// Initialize scaling matrix
	for(i=0;i<n;i++)
		xf += a[i][0];
	xf=xf/n;
	for(i=0;i<n;i++)
		yf += a[i][1];
	yf=yf/n;
	printf("\n fixed point x = %d y = %d",xf,yf);
	f[2][0] = xf*(1-sx);
	f[2][1] = yf*(1-sy);
	f[0][0] = sx;
	f[1][1] = sy;
	printf("\n Scaling Matrix is:");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
			printf("%f ",f[i][j]);
	}
	// call mul function
	mul(n,f);
	printf("\n");
}

void input()
{

	int n, i,j;
	float sx,sy;
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

	printf("\n Enter the sx and sy: ");
	scanf("%f%f",&sx,&sy);
	scaling(n,sx,sy);// call rotation function
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
	glutCreateWindow("Rotation...");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(disp);
	glutMainLoop();

}

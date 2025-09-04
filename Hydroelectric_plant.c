#include <GL/glut.h> 
#include <stdlib.h>
float x1, x2, x3, x4, x5, x6, x7, y1, y2, y3, y4, y5, y6, y7;
int d1, d2, d3;
int w1, w2, w3;

void edgedetect(float x1, float y1, float x2, float y2, int* le, int* re)
{
	float mx, x, temp;
	int i;
	if ((y2 - y1) < 0)
	{
		temp = y1; y1 = y2; y2 = temp;
		temp = x1; x1 = x2; x2 = temp;
	}
	if ((y2 - y1) != 0)
		mx = (x2 - x1) / (y2 - y1);

	else	mx = x2 - x1;
	x = x1;
	for (i = y1; i <= y2; i++)
	{
		if (x < (float)le[i])
			le[i] = (int)x;
		if (x > (float)re[i])
			re[i] = (int)x;
		x += mx;
	}
}
void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	if (x % 20 == 0)
		glFlush();
}
void scanfill(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	int le[700], re[700]; int i, y;
	for (i = 0; i < 700; i++)
	{
		le[i] = 700;
		re[i] = 0;
	}
	edgedetect(x1, y1, x2, y2, le, re);
	edgedetect(x2, y2, x3, y3, le, re);
	edgedetect(x3, y3, x4, y4, le, re);
	edgedetect(x4, y4, x1, y1, le, re);
	for (y = 700; y > 0; y--)
	{
		if (le[y] <= re[y])
			for (i = (int)le[y]; i < (int)re[y]; i++)
				draw_pixel(i, y);
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1, 0.8, 1.0, 1.0);
	
	x1 = 0.0; y1 = 259.0; x2 = 699.99; y2 = 259.0; x3 = 699.99; y3 = 470.0; x4 = 0.0; y4 = 470.0;
	glColor3f(0.0, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 0.0; y1 = 100.0; x2 = 180.0; y2 = 100.0; x3 = 180.0; y3 = 329.0; x4 = 0.0; y4 = 329.0;
	glColor3f(0.5, 0.6, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	
	x1 = 519.99; y1 = 100.0; x2 = 699.0; y2 = 100.0; x3 = 699.0; y3 = 329.0; x4 = 519.99; y4 = 329.0;
	glColor3f(0.5, 0.6, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 180.0; y1 = 100.0; x2 = 519.99; y2 = 100.0; x3 = 519.99; y3 = 259.0; x4 = 180.0; y4 = 259.0;
	glColor3f(0.3, 0.3, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 285.0; y1 = 100.0; x2 = 295.0; y2 = 100.0; x3 = 295.0; y3 = 309.99; x4 = 285.0; y4 = 309.99;
	glColor3f(0.5, 0.6, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 395.0; y1 = 100.0; x2 = 405.0; y2 = 100.0; x3 = 405.0; y3 = 309.99; x4 = 395.0; y4 = 309.99;
	glColor3f(0.5, 0.6, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 0.0; y1 = 0.0; x2 = 90.0; y2 = 0.0; x3 = 180.0; y3 = 100.0; x4 = 0.0; y4 = 100.0;
	glColor3f(0.6, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 609.99; y1 = 0.0; x2 = 699.0; y2 = 0.0; x3 = 699.0; y3 = 100.0; x4 = 519.99; y4 = 100.0;
	glColor3f(0.6, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 90.0; y1 = 0.0; x2 = 609.99; y2 = 0.0; x3 = 519.99; y3 = 100.0; x4 = 180.0; y4 = 100.0;
	glColor3f(0.5, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 180.0; y1 = 309.99; x2 = 519.99; y2 = 309.99; x3 = 519.99; y3 = 329.0; x4 = 180.0; y4 = 329.0;
	glColor3f(0.5, 0.6, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 0.0; y1 = 389.0; x2 = 120.0; y2 = 400.0; x3 = 90.0; y3 = 559.0; x4 = 0.0; y4 = 649.0;
	glColor3f(0.3, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 0.0; y1 = 329.0; x2 = 160.0; y2 = 380.0; x3 = 120.0; y3 = 400.0; x4 = 0.0; y4 = 389.0;
	glColor3f(0.7, 0.5, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 489.99; y1 = 389.0; x2 = 699.99; y2 = 369.0; x3 = 699.99; y3 = 600; x4 = 559.99; y4 = 509.99;
	glColor3f(0.3, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 469.99; y1 = 349.0; x2 = 699.0; y2 = 340.0; x3 = 699.99; y3 = 369.0; x4 = 489.99; y4 = 389.0;
	glColor3f(0.7, 0.5, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 0.0; y1 = 40.0; x2 = 75.0; y2 = 40.0; x3 = 75.0; y3 = 170; x4 = 0; y4 = 170.0;
	glColor3f(0.4, 0.4, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 75.0; y1 = 40.0; x2 = 145.0; y2 = 100.0; x3 = 145.0; y3 = 230; x4 = 75.0; y4 = 170.0;
	glColor3f(0.3, 0.4, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 0.0; y1 = 170.0; x2 = 75.0; y2 = 170.0; x3 = 145.0; y3 = 230; x4 = 0.0; y4 = 230.0;
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 85.0; y1 = 90.0; x2 = 138.0; y2 = 135.0; x3 = 138.0; y3 = 175.0; x4 = 85.0; y4 = 130.0;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 193.0; y1 = 0.0; x2 = 204.0; y2 = 0.0; x3 = 294.0; y3 = 100.0; x4 = 284.0; y4 = 100.0;
	glColor3f(0.5, 0.6, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	x1 = 484.0; y1 = 0.0; x2 = 495.0; y2 = 0.0; x3 = 406.0; y3 = 100.0; x4 = 396.0; y4 = 100.0;
	glColor3f(0.5, 0.6, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	glFlush();	
	glutPostRedisplay();
}


void light()
{
	x1 = 85.0; y1 = 90.0; x2 = 138.0; y2 = 135.0; x3 = 138.0; y3 = 175.0; x4 = 85.0; y4 = 130.0;
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
}

void dark()
{
	x1 = 85.0; y1 = 90.0; x2 = 138.0; y2 = 135.0; x3 = 138.0; y3 = 175.0; x4 = 85.0; y4 = 130.0;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
}

void tailrace1() 
{
	x1 = 90.0; y1 = 0.0; x2 = 195.0; y2 = 0.0; x3 = 285.0; y3 = 100.0; x4 = 180.0; y4 = 100.0;
	glColor3f(0.3, 0.8, 0.7);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
}

void closetailrace1() 
{
	x1 = 90.0; y1 = 0.0; x2 = 195.0; y2 = 0.0; x3 = 285.0; y3 = 100.0; x4 = 180.0; y4 = 100.0;
	glColor3f(0.5, 0.2, 0);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	if (d2 == 0 && d3 == 0)glutDisplayFunc(dark);
}

void tailrace2() 
{
	x1 = 205.0; y1 = 0.0; x2 = 485.00; y2 = 0.0; x3 = 397.0; y3 = 100.0; x4 = 295.0; y4 = 100.0;
	glColor3f(0.3, 0.8, 0.7);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	
}

void closetailrace2() {

	x1 = 205.0; y1 = 0.0; x2 = 485.00; y2 = 0.0; x3 = 397.0; y3 = 100.0; x4 = 295.0; y4 = 100.0;
	glColor3f(0.5, 0.2, 0);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	if (d1 == 0 && d3 == 0)glutDisplayFunc(dark);
}


void tailrace3()
{
	x1 = 496.0; y1 = 0.0; x2 = 609.99; y2 = 0.0; x3 = 519.99; y3 = 100.0; x4 = 406.0; y4 = 100.0;
	glColor3f(0.3, 0.8, 0.7);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
}

void closetailrace3() 
{
	x1 = 495.0; y1 = 0.0; x2 = 609.99; y2 = 0.0; x3 = 519.99; y3 = 100.0; x4 = 406.0; y4 = 100.0;
	glColor3f(0.5, 0.2, 0);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	if (d2 == 0 && d1 == 0)glutDisplayFunc(dark);
}


void opengate1()
{
	light();
	x1 = 180.0; y1 = 100.0; x2 = 285.0; y2 = 100.0; x3 = 285.0; y3 = 259.0; x4 = 180.0; y4 = 259.0;
	glColor3f(0.3, 0.8, 0.7);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	light();
	glutDisplayFunc(tailrace1);
}

void closegate1()
{
	x1 = 180.0; y1 = 100.0; x2 = 285.0; y2 = 100.0; x3 = 285.0; y3 = 259.0; x4 = 180.0; y4 = 259.0;
	glColor3f(0.3, 0.3, 0.4);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	glutDisplayFunc(closetailrace1);
	d1 = 0;
}


void opengate2()
{
	light();
	x1 = 295.0; y1 = 100.0; x2 = 396.99; y2 = 100.0; x3 = 396.99; y3 = 259.0; x4 = 295.0; y4 = 259.0;
	glColor3f(0.3, 0.8, 0.7);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	glutDisplayFunc(tailrace2);
}

void closegate2()
{
	x1 = 295.0; y1 = 100.0; x2 = 396.99; y2 = 100.0; x3 = 396.99; y3 = 259.0; x4 = 295.0; y4 = 259.0;
	glColor3f(0.3, 0.3, 0.4);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	glutDisplayFunc(closetailrace2);
	d2 = 0;
}


void opengate3()
{
	light();
	x1 = 406.0; y1 = 100.0; x2 = 521.99; y2 = 100.0; x3 = 521.99; y3 = 259.0; x4 = 406.0; y4 = 259.0;
	glColor3f(0.3, 0.8, 0.7);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	glutDisplayFunc(tailrace3);
}

void closegate3()
{
	x1 = 406.0; y1 = 100.0; x2 = 521.99; y2 = 100.0; x3 = 521.99; y3 = 259.0; x4 = 406.0; y4 = 259.0;
	glColor3f(0.3, 0.3, 0.4);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
	glutPostRedisplay();
	glutDisplayFunc(closetailrace3);
	d3 = 0;
}


void myinit()
{
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 699.0, 0.0, 699.0);	
}
void select(int ch)
{
	switch (ch)
	{
	case 1: {
		glutDisplayFunc(opengate1);
		d1 = 1;
	}
		  break;

	case 2: {
		glutDisplayFunc(opengate2);
		d2 = 1;
	} break;

	case 3:
	{
		glutDisplayFunc(opengate3);
		d3 = 1;
	}
	break;

	case 4:
	{
		glutDisplayFunc(closegate1);
		d1 = 0;
	}
	break;

	case 5:
	{		
		glutDisplayFunc(closegate2);
		d2 = 0;
	}
	break;

	case 6:
	{		
		glutDisplayFunc(closegate3);
		d3 = 0;
	}
	break;
	}
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Hydroelectric power plant");
	myinit();
	glutDisplayFunc(display);
	glutCreateMenu(select);
	glutAddMenuEntry("Open Gate 1", 1);
	glutAddMenuEntry("Open Gate 2", 2);
	glutAddMenuEntry("Open Gate 3", 3);
	glutAddMenuEntry("Close Gate 1", 4);
	glutAddMenuEntry("Close Gate 2", 5);
	glutAddMenuEntry("Close Gate 3", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}

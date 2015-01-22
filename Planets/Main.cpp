#include <windows.h>
#include <GL/gl.h>
#include <glut.h>

int a[3] = { 10, 10, 10 }, b[3] = { 10, -10, 10 },
c[3] = { -10, -10, 10 }, d[3] = { -10, 10, 10 },
e[3] = { 10, 10, -10 }, f[3] = { 10, -10, -10 },
g[3] = { -10, -10, -10 }, h[3] = { -10, 10, -10 };

float angle = 1.0;

void drawcube(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3iv(a);
	glVertex3iv(b);
	glVertex3iv(c);
	glVertex3iv(d);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3iv(a);
	glVertex3iv(e);
	glVertex3iv(f);
	glVertex3iv(b);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3iv(d);
	glVertex3iv(h);
	glVertex3iv(g);
	glVertex3iv(c);	
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3iv(e);
	glVertex3iv(f);
	glVertex3iv(g);
	glVertex3iv(h);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 0x1B:
	case 'q':
	case 'Q':
		exit(0);
		break;
	}
}

void mouse(int btn, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (btn == GLUT_LEFT_BUTTON)
			angle = angle + 1.0f;
		else if (btn == GLUT_RIGHT_BUTTON)
			angle = angle - 1.0f;
		else
			angle = 0.0f;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Glut rotate");
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(drawcube);
	glutIdleFunc(drawcube);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutMainLoop();
	return(0);
}
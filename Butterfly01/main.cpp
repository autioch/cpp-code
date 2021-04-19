#include <windows.h> 
#include <GL/glut.h> 
#include <math.h>
#include <time.h>


float pozycja=0.0;
float przyrost=0.01;

float alfa=0.0;
float d_alfa=-2.0;

float beta=0.0;
float d_beta=0.3;

float gamma=0.0;
float d_gamma=0.05;

void skrzydlo()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5, 0.0, 0.2);	glVertex3f( 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.9, 0.0);	glVertex3f( 0.0, 1.5, 0.0);
	glColor3f(1.0, 0.8, 0.0);	glVertex3f(-0.5, 2.5, 0.0);
	glColor3f(0.9, 0.7, 0.2);	glVertex3f(-1.5, 2.0, 0.0);
	glColor3f(0.8, 0.7, 0.0);	glVertex3f(-2.0, 1.5, 0.0);
	glColor3f(0.0, 0.0, 1.0);   glVertex3f(-0.5,-0.5, 0.0);
	glColor3f(0.9, 0.7, 0.0);	glVertex3f(-1.5, 0.0, 0.0);
	glColor3f(1.0, 0.8, 0.0);	glVertex3f(-1.0,-1.0, 0.0);
	glColor3f(1.0, 0.9, 0.0);	glVertex3f(-0.5,-1.5, 0.0); 
	glColor3f(1.0, 1.0, 0.0);	glVertex3f( 0.0,-0.5, 0.0);
	glEnd();
}

void uklad()
{
  
  glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); //zielona o� X
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0); 

    glColor3f(0.0, 0.0, 1.0); // niebieska o� Y
	glVertex3f(0.0, -5.0, 0.0);
	glVertex3f(0.0,  5.0, 0.0);
	
	glColor3f(0.0,  0.0, 0.0); // czarna o� Z
	glVertex3f(0.0, 0.0, -5.0);
	glVertex3f(0.0, 0.0,  5.0);
	  
  glEnd();

}

void init()
{
  glClearColor(1.0,1.0,1.0,1.0); //kolor t�a okna
  glEnable(GL_DEPTH_TEST); // w��czenie testu g��boko�ci
	
  glMatrixMode(GL_PROJECTION);
  gluPerspective(60.0,1.0,0.1,32.0); 
  gluLookAt(12.0,12.0,12.0, 0.0,0.0,0.0, 0.0,0.0,1.0); 
  glMatrixMode(GL_MODELVIEW); // nic wi�cej na stosie rzutowania
                              // si� nie znajdzie   
}




void scena()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPointSize(10);
  
   
  glLoadIdentity();// przed kolejn� klatk� animacyjn�
                   // na stosie modelowania nie mog�
                   // znajdowa� si� �adne macierze z 
                   // poprzedniej klatki animacyjnej

  uklad();
  
  

  glColor3f(1.0, 0.0, 0.0);
  
  glRotatef(beta, 0.0, 0.0, 1.0);
  glTranslatef(8.0, 0.0, sin(gamma));
  
  glBegin(GL_LINE_STRIP);
  glVertex3f( 0.0, 1.5, 0.0);
  glVertex3f( 0.1, 1.8, 0.0);
  glVertex3f( 0.3, 2.1, 0.0);
  glVertex3f( 0.6, 2.4, 0.0);
  glEnd();

  glBegin(GL_LINE_STRIP);
  glVertex3f(-0.0, 1.5, 0.0);
  glVertex3f(-0.1, 1.8, 0.0);
  glVertex3f(-0.3, 2.1, 0.0);
  glVertex3f(-0.6, 2.4, 0.0);
  glEnd();

  glPushMatrix();
  glRotatef(alfa, 0.0, 1.0, 0.0);
  skrzydlo();
  glPopMatrix();

  glPushMatrix();
  glRotatef(180-alfa, 0.0, 1.0, 0.0);
  skrzydlo();
  glPopMatrix();

  glFlush();
  glutSwapBuffers(); // zamiana bufor�w koloru 
}
 

void anim()
{
  alfa+=d_alfa;
  if (alfa>40) d_alfa*=-1;
  else if (alfa<-40) d_alfa*=-1;

  beta+=d_beta;

  gamma+=d_gamma;

  glutPostRedisplay();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
  glutInitWindowSize(400,400);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Butterfly 01");
  glutDisplayFunc(scena);
  glutIdleFunc(anim);//rejestracja funkcji animacyjnej
  srand ( time(NULL) );
  init();
  glutMainLoop();
}
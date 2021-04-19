#include <windows.h> 
#include <GL/glut.h> 
#include <math.h>
#include <time.h>

float kat=15.0;
float d_kat=2.0;

float pion=0.0;
float d_pion=0.1;

float obrot=0.0;
float d_obrot=1.0;

void skrzydlo()
{
    glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f( 0.0, 0.0, 0.0);
    glVertex3f( 0.0, 4.0, 0.0);
    
    glColor3f(0.3, 0.3, 1.0);    
    glVertex3f( 2.0, 5.0, 0.0);
	glVertex3f( 5.0, 5.0, 0.0);
	
    glColor3f(1.0, 0.8, 0.5);	
    glVertex3f( 7.0, 4.0, 0.0);
    glVertex3f( 7.0, 2.0, 0.0);    
    
    glColor3f(1.0, 0.8, 0.5);    
  	glVertex3f( 6.0, 0.0, 0.0);
    glVertex3f( 5.0,-1.0, 0.0);
    
    glColor3f(1.0, 1.0, 0.0);    
    glVertex3f( 4.0,-3.0, 0.0);
    glVertex3f( 3.0,-4.0, 0.0);
    
    glColor3f(1.0, 0.5, 0.0);    
    glVertex3f( 1.0,-4.0, 0.0);
    
    glColor3f(0.5, 0.5, 0.5);    
    glVertex3f( 0.0,-2.0, 0.0);
  	glEnd();
}

void skrzydlo2()
{
    glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f( 0.0, 0.0, 0.0);
    glVertex3f( 0.0, 4.0, 0.0);
    
    glColor3f(0.3, 0.3, 1.0);    
    glVertex3f( 2.0, 5.0, 0.0);
	glVertex3f( 5.0, 5.0, 0.0);
	
    glColor3f(1.0, 0.8, 0.5);	
    glVertex3f(10.0, 4.0, 0.0);
    glVertex3f( 7.5, 3.5, 0.0);    
    glVertex3f( 7.0, 2.0, 0.0);    
    
    glColor3f(1.0, 0.8, 0.5);    
  	glVertex3f( 6.0, 0.0, 0.0);
    glVertex3f( 5.0,-1.0, 0.0);
    
    glColor3f(1.0, 1.0, 0.0);    
    glVertex3f( 4.0,-3.0, 0.0);
    glVertex3f( 3.0,-4.0, 0.0);
    glVertex3f( 1.5, -6.0, 0.0);
    
    glColor3f(1.0, 0.5, 0.0);    
    glVertex3f( 1.0,-10.0,0.0);
    
    glColor3f(0.5, 0.5, 0.5);    
    glVertex3f( 0.0,-2.0, 0.0);
  	glEnd();
}

void motyl(float kat)
{

  glPushMatrix();
  glRotatef(kat, 0.0, 1.0, 0.0);
  skrzydlo2();
  glPopMatrix();

  glPushMatrix();
  glRotatef(180-kat, 0.0, 1.0, 0.0);
  skrzydlo2();
  glPopMatrix();
}

void uklad()
{
  
  glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); //zielona o? X
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0); 

    glColor3f(0.0, 0.0, 1.0); // niebieska o? Y
	glVertex3f(0.0, -5.0, 0.0);
	glVertex3f(0.0,  5.0, 0.0);
	
	glColor3f(0.0,  0.0, 0.0); // czarna o? Z
	glVertex3f(0.0, 0.0, -5.0);
	glVertex3f(0.0, 0.0,  5.0);
	  
  glEnd();

}

void init()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);
	
  glMatrixMode(GL_PROJECTION);
  gluPerspective(60.0,1.0,0.1,96.0); 
  gluLookAt(36.0,36.0,36.0, 0.0,0.0,0.0, 0.0,0.0,1.0); 
  glMatrixMode(GL_MODELVIEW);
}




void scena()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  uklad();
  glRotatef(obrot, 0.0, 0.0, 1.0);
  glTranslatef(sin(pion)+16.0, 0.0, 2.0*sin(pion));
  motyl(kat);
  glFlush();
  glutSwapBuffers();
}
 

void anim()
{
  kat+=d_kat;
  if (kat>40) d_kat*=-1;
  else if (kat<-60) d_kat*=-1;
  pion+=d_pion;
  obrot+=d_obrot;
  glutPostRedisplay();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
  glutInitWindowSize(400,400);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Butterfly 02");
  glutDisplayFunc(scena);
  glutIdleFunc(anim);//rejestracja funkcji animacyjnej
  srand ( time(NULL) );
  init();
  glutMainLoop();
}

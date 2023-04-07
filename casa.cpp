//g++ nomeArquivo.cpp -o nomeExecução -lGL -lGLU -lglut -lm

#include <GL/glut.h>
#include <math.h>

void reshape(int w, int h) {

    if(w == 0) w = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-100, 100, -100*h/w, 100*h/w, -10, 10);
    //Estabelece a janela de seleção (left, right, bottom, top)
    gluOrtho2D(0.0f, 200.0f, 0.0f, 200.0f*h/w);

    glMatrixMode(GL_MODELVIEW);
}

void drawCircle(GLfloat x, GLfloat y, GLfloat raio){
	int i;
	int qntdTriang = 20; //quantidade de triangulos usados para fazer o círculo
	
	GLfloat twicePi = 2.0f * 3.14;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // ponto central do círculo
		for(i = 0; i <= qntdTriang; i++) { 
			glVertex2f(
		        x + (raio * cos(i *  twicePi / qntdTriang)), 
			    y + (raio * sin(i * twicePi / qntdTriang))
			);
		}
	glEnd();
}

void display(void) {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Desenha a janela do telhado
    glColor3f(0.4f,0.2f,0.2f);
    drawCircle(80.0f, 58.0f, 4.0f);

    glBegin(GL_POLYGON);
        //Desenha o primeiro telhado
        glColor3f(0.5f,0.2f,0.0f);

        glVertex3f(80.0f, 70.0f, 0.0f);
        glVertex3f(60.0f, 50.0f, 0.0f);
        glVertex3f(100.0f, 50.0f, 0.0f);
    glEnd();

    //Desenha a Maçaneta
    glColor3f(0.2f,0.1f,0.2f);
    drawCircle(82.0f, 14.0f, 0.6f);
        

    glBegin(GL_QUADS);
        //Desenha a Porta
        glColor3f(0.5f,0.2f,0.0f);

        glVertex3f(76.7f, 37.0f, 0.0f); // top left
        glVertex3f(83.3f, 37.0f, 0.0f); // top right 
        glVertex3f(83.3f, 10.0f, 0.0f); // bottom right
        glVertex3f(76.7f, 10.0f, 0.0f); // bottom left
    glEnd();

    glBegin(GL_QUADS);
        //Desenha a primeira parte da casa 
        glColor3f(0.7f,0.5f,0.6f);

        glVertex3f(60.0f, 50.0f, 0.0f); // top left
        glVertex3f(100.0f, 50.0f, 0.0f); // top right 
        glVertex3f(100.0f, 10.0f, 0.0f); // bottom right
        glVertex3f(60.0f, 10.0f, 0.0f); // bottom left
    glEnd();

    glBegin(GL_QUADS);
        //Desenha a segunda parte do telhado
        glColor3f(0.4f,0.2f,0.0f);

        glVertex3f(80.0f, 70.0f, 0.0f); // top left
        glVertex3f(120.0f, 70.0f, 0.0f); // top right 
        glVertex3f(140.0f, 50.0f, 0.0f); // bottom right
        glVertex3f(100.0f, 50.0f, 0.0f); // bottom left
    glEnd();

    glBegin(GL_QUADS);
        //Desenha a parte de cima da chaminé 
        glColor3f(0.2f,0.1f,0.2f);

        glVertex3f(95.0f, 74.5f, 0.0f); // top left
        glVertex3f(105.0f, 74.5f, 0.0f); // top right 
        glVertex3f(105.0f, 72.0f, 0.0f); // bottom right
        glVertex3f(95.0f, 72.0f, 0.0f); // bottom left
    glEnd();

    glBegin(GL_QUADS);
        //Desenha a parte de baixo da Chaminé 
        glColor3f(0.3f,0.2f,0.2f);

        glVertex3f(97.0f, 72.0f, 0.0f); // top left
        glVertex3f(103.0f, 72.0f, 0.0f); // top right 
        glVertex3f(103.0f, 70.0f, 0.0f); // bottom right
        glVertex3f(97.0f, 70.0f, 0.0f); // bottom left
    glEnd();

    glBegin(GL_QUADS);
        //Desenha a primeira janela ARRUMAR
        glColor3f(0.2f,0.1f,0.2f);
        glVertex3f(109.5f, 37.0f, 0.0f); // top left
        glVertex3f(115.5f, 37.0f, 0.0f); // top right

        glColor3f(0.3f,0.2f,0.2f);
        glVertex3f(115.5f, 30.0f, 0.0f); // bottom right
        glVertex3f(109.5f, 30.0f, 0.0f); // bottom left
    glEnd();

    glBegin(GL_QUADS);
        //Desenha a segunda janela ARRUMAR
        glColor3f(0.2f,0.1f,0.2f);
        glVertex3f(124.5f, 37.0f, 0.0f); // top left
        glVertex3f(130.5f, 37.0f, 0.0f); // top right 

        glColor3f(0.3f,0.2f,0.2f);
        glVertex3f(130.5f, 30.0f, 0.0f); // bottom right
        glVertex3f(124.5f, 30.0f, 0.0f); // bottom left
    glEnd();

    glBegin(GL_QUADS);
        //Desenha a segunda parte da casa
        glColor3f(0.7f,0.4f,0.5f);

        glVertex3f(100.0f, 50.0f, 0.0f); // top left
        glVertex3f(140.0f, 50.0f, 0.0f); // top right 
        glVertex3f(140.0f, 10.0f, 0.0f); // bottom right
        glVertex3f(100.0f, 10.0f, 0.0f); // bottom left
    glEnd();

    glutSwapBuffers();

}

void meuInit(int w, int h){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100*h/w, 100*h/w, -10, 10); //OU glOrtho(0, w, 0, h, -10, 10);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Casinha da Iarinha");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    meuInit(640, 480);

    //glutFullScreen();
    glutMainLoop();

    return 0; /* ANSI C requires main to return int. */
}


#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;

float angle = 0.0;
bool f1Pressed = false;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    // glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis

    int numSegments = 12; // Number of segments to approximate the wheel
    float radius = 1.0f;  // Radius of the wheel

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white for the center
    glVertex2f(0.0f, 0.0f);      // Center of the wheel

    for (int i = 0; i <= numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Calculate the angle for this segment
        float x = radius * cosf(theta);                                  // Calculate the x coordinate
        float y = radius * sinf(theta);                                  // Calculate the y coordinate

        // Alternate colors for each segment
        if (i % 2 == 0)
            glColor3f(1.0f, 0.0f, 0.0f); // Red
        else
            glColor3f(0.0f, 0.0f, 1.0f); // Blue

        glVertex2f(x, y); // Output vertex
    }

    glEnd();

    if (f1Pressed)
    {
        glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white
        glRasterPos2f(-1.0f, 1.0f);  // Position the text
        const char *text = "F1 key was pressed";
        for (const char *c = text; *c != '\0'; c++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }

    glutSwapBuffers();
    angle += 0.1f;
    glutPostRedisplay(); // Ensure continuous rendering
}
void init()
{
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 800, 600); // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

void special(int key, int x, int y)
{
    if (key == GLUT_KEY_F1)
    {
        f1Pressed = true;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Test");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMainLoop();
    return 0;
}


#include <GL/glut.h>

float angle = 0.0; 

void init() {
    glClearColor(0.0, 0.0, 1.0, 1.0); // Blue background
    glEnable(GL_DEPTH_TEST);         // Enable depth testing
    glEnable(GL_LIGHTING);           // Enable lighting
    glEnable(GL_LIGHT0);             // Default light
    glEnable(GL_COLOR_MATERIAL);     // Use color for material
    glShadeModel(GL_SMOOTH);         // Smooth shading
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Camera setup
    gluLookAt(0.0, 0.0, 10.0,   // Eye position
              0.0, 0.0, 0.0,    // Look-at point
              0.0, 1.0, 0.0);   // Up direction

    // Rotate the teapot
    glRotatef(angle, 0.0, 1.0, 0.0); 

    // Set teapot color
    glColor3f(1.0, 0.0, 0.0); 

    // Draw larger teapot
    glutSolidTeapot(3.0);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w/h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    angle += 1.0; // Increment rotation
    if (angle > 360.0) angle -= 360.0;
    glutPostRedisplay();          // Request redraw
    glutTimerFunc(16, timer, 0);  // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rotating 3D Teapot");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0); // Start animation
    glutMainLoop();
    return 0;
}


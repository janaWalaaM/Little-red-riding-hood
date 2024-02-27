#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>      
#include   <cmath>
#else
#include <GL/glew.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <GL/freeglut.h>    
#endif

#include <iostream>

#include <conio.h>

// For Audios
#include <Windows.h>
#include <mmsystem.h>

GLint win_width = 500,
win_hight = 500;

int done1 = 0, done2 = 0, done3 = 0, done4 = 0, done5 = 0, done6 = 0, done7 = 0,
done8 = 0, done9 = 0, done10 = 0, done11 = 0, done12 = 0, done13 = 0, done14 = 0;

float lillaValuex;
float wolfValuey;
float lillaValuey;
float wolfValuex;

// Texture Buffers
GLuint woodTreeTextur;

// Texture Path
char woodTreePath[] = "C:/Users/amer7/OneDrive/”ÿÕ «·„ﬂ »/woodTree.bmp";

GLuint LoadTexture(const char* filename, int width, int height)
{
    GLuint texture;
    unsigned char* data;
    FILE* file;

    //The following code will read in our RAW file
    fopen_s(&file, filename, "rb");

    if (file == NULL)
    {
        //cout << "Unable to open the image file" << endl << "Program will exit :(" << endl;
        exit(0);
        return 0;
    }
    data = (unsigned char*)malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);

    fclose(file);
    // reorder the image colors to RGB not BGR
    for (int i = 0; i < width * height; ++i)
    {
        int index = i * 3;
        unsigned char B, R;
        B = data[index];
        R = data[index + 2];

        data[index] = R;
        data[index + 2] = B;

    }

    glGenTextures(1, &texture);            //generate the texture with the loaded data
    glBindTexture(GL_TEXTURE_2D, texture); //bind the texture to it's array

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //set texture environment parameters

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    free(data); //free the texture array

    if (glGetError() != GL_NO_ERROR)
        printf("GLError in genTexture()\n");

    return texture; //return whether it was successfull  
}

// Start Circles 
GLdouble PI = 3.14159265359;
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}
void drawFilledHalfCircle(GLfloat x, GLfloat y, GLfloat radius) {//HALF
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = -1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
// End Circles 
static void special(int key, int x, int y)
{
    //handle special keys
    switch (key) {

    case GLUT_KEY_HOME:
        break;
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_RIGHT:
        break;
    case GLUT_KEY_UP:
        break;
    case GLUT_KEY_DOWN:
        break;
    default:
        break;
        //----------------------
    }
}
static void motion(int x, int y)
{}
static void play(void)
{
    glutPostRedisplay();
}
// Start Other Objects
void MyBascket() {
    glLineWidth(7.0f);
    glColor3f(0.3f, 0.0f, 0.0f);
    drawHollowCircle(-.47, .3, .13);

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.32f, 0.26f);
    glVertex2f(-0.63f, 0.26f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.36f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.26f);
    glVertex2f(-0.62f, 0.26f);
    glVertex2f(-0.6f, 0.2f);
    glEnd();
    glFlush();
}
void MyTable()
{
    // the table's surface
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.0f);
    glVertex2f(-0.165f, -0.35f);
    glVertex2f(-0.88f, -0.35f);
    glVertex2f(-0.88f, -0.42f);
    glVertex2f(-0.165f, -0.42f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.24f, -0.24f);
    glVertex2f(-0.79f, -0.24f);
    glVertex2f(-0.88f, -0.35f);
    glVertex2f(-0.165f, -0.35f);
    glEnd();

    // the table's legs
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.2f, -0.42f);
    glVertex2f(-0.22f, -0.42f);
    glVertex2f(-0.22f, -0.8f);
    glVertex2f(-0.2f, -0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.3f, -0.42f);
    glVertex2f(-0.32f, -0.42f);
    glVertex2f(-0.32f, -0.6f);
    glVertex2f(-0.3f, -0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.8f, -0.42f);
    glVertex2f(-0.82f, -0.42f);
    glVertex2f(-0.82f, -0.8f);
    glVertex2f(-0.8f, -0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.72f, -0.42f);
    glVertex2f(-0.74f, -0.42f);
    glVertex2f(-0.74f, -0.6f);
    glVertex2f(-0.72f, -0.6f);
    glEnd();

    // the food on the table
    glBegin(GL_QUADS);
    glColor3f(1.8f, 1.8f, 1.8f);
    glVertex2f(-0.32f, -0.28f);
    glVertex2f(-0.46f, -0.28f);
    glVertex2f(-0.46f, -0.3f);
    glVertex2f(-0.32f, -0.3f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-.47, -.28, .02);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-.32, -.28, .02);

    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle(-.37, -.25, .04);

    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle(-.41, -.25, .04);

    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle(-.44, -.25, .04);
}
void button() {
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.05, 0.05, 0.12); //play button
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.01, 0.1);
    glVertex2f(-0.108, 0.1);
    glVertex2f(-0.04, -0.04);
    glEnd();
}

void GeomatricB() {
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);
    button();
    glPopMatrix();
}
// End Other Objects
// Start Characters
// Start Mother
void mother(GLfloat mouth_angle) {
    glBegin(GL_QUADS); //hair
    glColor3f(0.9, 0.8, 0.3);
    glVertex2f(0.15, 0.1);
    glVertex2f(-0.15, 0.1);
    glVertex2f(-0.15, -0.15);
    glVertex2f(0.15, -0.15);
    glEnd();
    glBegin(GL_QUADS); //hair side
    glColor3f(0.9, 0.8, 0.3);
    glVertex2f(0.2, 0.05);
    glVertex2f(-0.2, 0.05);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glEnd();
    glBegin(GL_QUADS); //head
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-0.14, 0.05);
    glVertex2f(-0.14, -0.14);
    glVertex2f(0.14, -0.14);
    glVertex2f(0.14, 0.05);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//eye
    drawFilledCircle(-0.06, 0.0, 0.02);

    glColor3f(0.0, 0.0, 0.0);//eye
    drawFilledCircle(0.06, 0.0, 0.02);

    //mouth
    glLineWidth(1.5f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.05f, -.08f);
    glVertex2f(mouth_angle, -0.1);
    glVertex2f(-.05f, -.08f);
    glEnd();

    glBegin(GL_QUADS); //neck
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-0.06, -0.2);
    glVertex2f(0.06, -0.2);
    glVertex2f(0.06, -0.12);
    glVertex2f(-0.06, -0.12);
    glEnd();

    glBegin(GL_QUADS); //dress
    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(-0.2, -0.55);
    glVertex2f(0.2, -0.55);
    glVertex2f(0.07, -0.2);
    glVertex2f(-0.08, -0.2);
    glEnd();

    glBegin(GL_QUADS); //dress
    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(-0.08, -0.2);
    glVertex2f(0.07, -0.2);
    glVertex2f(0.07, -0.18);
    glVertex2f(-0.08, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    //// leg Left
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.04f, -.65f);
    glVertex2f(-.12f, -.65f);
    glVertex2f(-.12f, -.55f);
    glVertex2f(-.04f, -.55f);
    glEnd();

    glBegin(GL_QUADS);
    // leg Right
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(.04f, -.65f);
    glVertex2f(.12f, -.65f);
    glVertex2f(.12f, -.55f);
    glVertex2f(.04f, -.55f);
    glEnd();
    // Shose Left
    glBegin(GL_QUADS);
    glColor3f(0.2, 0, 0);
    glVertex2f(-.12f, -.65f);
    glVertex2f(-.04f, -.65f);
    glVertex2f(-.04f, -.61f);
    glVertex2f(-.12f, -.61f);
    glEnd();
    //shoes Right
    glBegin(GL_QUADS);
    glColor3f(0.2, 0, 0);
    glVertex2f(.12f, -.65f);
    glVertex2f(.04f, -.65f);
    glVertex2f(.04f, -.61f);
    glVertex2f(.12f, -.61f);
    glEnd();

    glBegin(GL_QUADS);
    // Arm Left
    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(-.1f, -0.35f);
    glVertex2f(-.1f, -.25f);
    glVertex2f(-.25f, -.29f);
    glVertex2f(-.25f, -0.39f);
    // Hand
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.32f, -0.39f);
    glVertex2f(-.25f, -0.39f);
    glVertex2f(-.25f, -.29f);
    glVertex2f(-.32f, -.29f);
    glEnd();

    glBegin(GL_QUADS);
    // Arm Right

    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(.1f, -0.35f);
    glVertex2f(.1f, -.25f);
    glVertex2f(.25f, -.29f);
    glVertex2f(.25f, -0.39f);
    // Hand
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(.32f, -0.39f);
    glVertex2f(.25f, -0.39f);
    glVertex2f(.25f, -.29f);
    glVertex2f(.32f, -.29f);
    glEnd();
}
void mother2(GLfloat mouth_angle) {
    glBegin(GL_QUADS); //hair
    glColor3f(0.9, 0.8, 0.3);
    glVertex2f(0.15, 0.1);
    glVertex2f(-0.15, 0.1);
    glVertex2f(-0.15, -0.15);
    glVertex2f(0.15, -0.15);
    glEnd();
    glBegin(GL_QUADS); //hair side
    glColor3f(0.9, 0.8, 0.3);
    glVertex2f(0.2, 0.05);
    glVertex2f(-0.2, 0.05);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glEnd();
    glBegin(GL_QUADS); //head
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-0.14, 0.05);
    glVertex2f(-0.14, -0.14);
    glVertex2f(0.14, -0.14);
    glVertex2f(0.14, 0.05);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//eye
    drawFilledCircle(-0.06, 0.0, 0.02);

    glColor3f(0.0, 0.0, 0.0);//eye
    drawFilledCircle(0.06, 0.0, 0.02);

    //mouth
    glLineWidth(1.5f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.05f, -.08f);
    glVertex2f(mouth_angle, -0.1);
    glVertex2f(-.05f, -.08f);
    glEnd();



    glBegin(GL_QUADS); //neck
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-0.06, -0.2);
    glVertex2f(0.06, -0.2);
    glVertex2f(0.06, -0.12);
    glVertex2f(-0.06, -0.12);

    glEnd();

    glBegin(GL_QUADS); //dress
    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(-0.2, -0.55);
    glVertex2f(0.2, -0.55);
    glVertex2f(0.07, -0.2);
    glVertex2f(-0.08, -0.2);

    glEnd();

    glBegin(GL_QUADS); //dress
    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(-0.08, -0.2);
    glVertex2f(0.07, -0.2);
    glVertex2f(0.07, -0.18);
    glVertex2f(-0.08, -0.18);
    glEnd();

    ///////////////

    glBegin(GL_QUADS);
    //// leg Left
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.04f, -.65f);
    glVertex2f(-.12f, -.65f);
    glVertex2f(-.12f, -.55f);
    glVertex2f(-.04f, -.55f);

    glEnd();

    glBegin(GL_QUADS);
    // leg Right
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(.04f, -.65f);
    glVertex2f(.12f, -.65f);
    glVertex2f(.12f, -.55f);
    glVertex2f(.04f, -.55f);


    glEnd();
    // Shose Left
    glBegin(GL_QUADS);
    glColor3f(0.2, 0, 0);
    glVertex2f(-.12f, -.65f);
    glVertex2f(-.04f, -.65f);
    glVertex2f(-.04f, -.61f);
    glVertex2f(-.12f, -.61f);
    glEnd();
    //shoes Right
    glBegin(GL_QUADS);
    glColor3f(0.2, 0, 0);
    glVertex2f(.12f, -.65f);
    glVertex2f(.04f, -.65f);
    glVertex2f(.04f, -.61f);
    glVertex2f(.12f, -.61f);
    glEnd();

    glBegin(GL_QUADS);
    // Arm Right

    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(.1f, -0.35f);
    glVertex2f(.1f, -.25f);
    glVertex2f(.25f, -.29f);
    glVertex2f(.25f, -0.39f);
    // Hand
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(.32f, -0.39f);
    glVertex2f(.25f, -0.39f);
    glVertex2f(.25f, -.29f);
    glVertex2f(.32f, -.29f);
    glEnd();
}
void GeomatricM0() {
    glPushMatrix();
    glTranslatef(-0.4, -0.1, 0.0);
    glScalef(0.7, 0.7, 1.0);
    mother(0.0);
    glPopMatrix();
}
void GeomatricM02() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.4, -0.1, 0.0);
    glScalef(1.0, 1.0, 1.0);
    mother2(0.0);
    glPopMatrix();
    glEnd();
    glFlush();
}
void mother_Hand() {
    glBegin(GL_QUADS);
    // Arm Left
    glColor3f(0.8, 0.0, 0.4);
    glVertex2f(-.1f, -0.35f);
    glVertex2f(-.1f, -.25f);
    glVertex2f(-.25f, -.29f);
    glVertex2f(-.25f, -0.39f);
    // Hand
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.32f, -0.39f);
    glVertex2f(-.25f, -0.39f);
    glVertex2f(-.25f, -.29f);
    glVertex2f(-.32f, -.29f);
    glEnd();
}
void GHandMother() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.4, -0.3, 0.0);
    glRotatef(-180.0, 0.0, 1.0, 0.0);
    glScalef(0.7, 0.7, 1.0);
    mother_Hand();
    glPopMatrix();
    glEnd();

}
// End Mother
// Start Lailla
void lailla_body(GLfloat mouth_angle) {
    // mouth_angle (0.0 smile, 0.025 sad)
    // Hair
    glBegin(GL_QUADS);
    glColor3f(0.96, 0.42, 0.22);
    glVertex2f(.15f, -.1f);
    glVertex2f(.15f, .1f);
    glVertex2f(-.15f, .1f);
    glVertex2f(-.15f, -.1f);
    // Upper Side Hair
    glVertex2f(.1f, .1f);
    glVertex2f(.1f, .15f);
    glVertex2f(-.1f, .15f);
    glVertex2f(-.1f, .1f);
    // Face
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(.1f, -.02f);
    glVertex2f(.1f, .1f);
    glVertex2f(-.1f, .1f);
    glVertex2f(-.1f, -.02f);
    // Neak
    glVertex2f(.05f, -.05f);
    glVertex2f(.05f, -.02f);
    glVertex2f(-.05f, -.02f);
    glVertex2f(-.05f, -.05f);
    glEnd();
    // Left Eye
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(-.05f, .05f, 0.015f);
    // Right Eye
    drawFilledCircle(.05f, .05f, 0.015f);
    // Mouth
    glLineWidth(1.5f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.04f, .01f);
    glVertex2f(-.0f, mouth_angle);
    glVertex2f(-.04f, .01f);
    glEnd();
    // Dress
    glBegin(GL_QUADS);
    glColor3f(0.36, 0.91, 0.87);
    glVertex2f(.2f, -.35f);
    glVertex2f(.05f, -.05f);
    glVertex2f(-.05f, -.05f);
    glVertex2f(-.2f, -.35f);
    glEnd();
}
void lailla_leg(GLfloat red, GLfloat green, GLfloat blue) {//not change
    glBegin(GL_QUADS);
    // leg
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.04f, -.45f);
    glVertex2f(-.04f, -.35f);
    glVertex2f(-.12f, -.35f);
    glVertex2f(-.12f, -.45f);
    // Shose
    glColor3f(0.2, 0, 0);
    glVertex2f(-.04f, -.5f);
    glVertex2f(-.04f, -.45f);
    glVertex2f(-.12f, -.45f);
    glVertex2f(-.12f, -.5f);
    glEnd();
}
void lailla_hand() {//not change
    glBegin(GL_QUADS);
    // Arm
    glColor3f(0.36, 0.91, 0.87);
    glVertex2f(-.1f, -.04f);
    glVertex2f(-.1f, -.12f);
    glVertex2f(-.3f, -.12f);
    glVertex2f(-.3f, -.04f);
    // Hand
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.3f, -.04f);
    glVertex2f(-.3f, -.12f);
    glVertex2f(-.35f, -.12f);
    glVertex2f(-.35f, -.04f);
    glEnd();
}
void lailla_home() {
    // Body
    lailla_body(0.0);
    // Left Leg
    lailla_leg(1.0, 1.0, 1.0);
    // Right Leg
    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    lailla_leg(1.0, 1.0, 1.0);
    // Left Hand
    glTranslatef(-0.1f, 0.03f, 0.0f);
    glRotatef(25.0, 0.0f, 0.0f, 1.0f);
    lailla_hand();
    glPopMatrix();
    // Right Hand
    glPushMatrix();
    glTranslatef(-0.11f, -0.12f, 0.0f);
    glRotatef(155.0, 0.0f, 0.0f, 1.0f);
    lailla_hand();
    glPopMatrix();
}
void lailla_front_robe(GLfloat mouth_angle) {
    // Robe Head
    glColor3f(1.00, 0.10, 0.10);
    drawFilledCircle(-.0f, .05f, 0.17f);
    // Body
    lailla_body(mouth_angle);
    // Left Leg
    lailla_leg(0.55f, 0.18f, 0.00f);
    // Right Leg
    glPushMatrix();
    glTranslatef(0.16f, 0.0f, 0.0f);
    lailla_leg(0.55f, 0.18f, 0.00f);
    // Robe
    glPushMatrix();
    glTranslatef(-.16, .0, .0);
    glBegin(GL_TRIANGLES);
    // Left Robe
    glColor3f(1.00, 0.10, 0.10);
    glVertex2f(-.23f, -.4f);
    glVertex2f(-.05f, -0.4f);
    glVertex2f(-.05f, -.05f);
    // Right Robe
    glColor3f(1.00, 0.10, 0.10);
    glVertex2f(.23f, -.4f);
    glVertex2f(.05f, -0.4f);
    glVertex2f(.05f, -.05f);
    glEnd();
    // Neak Robe
    glBegin(GL_QUADS);
    glColor3f(1.00, 0.10, 0.10);
    glVertex2f(.05f, -.1f);
    glVertex2f(.05f, -.05f);
    glVertex2f(-.05f, -.05f);
    glVertex2f(-.05f, -.1f);
    glEnd();
    glPopMatrix();
}
void lailla_side_robe(GLfloat mouth_angle) { //not change
    // mouth_angle -0.04 smile, -0.02 sad
    // Robe Head
    glColor3f(1.00, 0.10, 0.10);
    drawFilledCircle(-.0f, .0f, 0.1f);
    // Robe
    glPushMatrix();
    glTranslatef(.06, .02, .0);
    glBegin(GL_TRIANGLES);
    // Left Robe
    glColor3f(1.00, 0.10, 0.10);
    glVertex2f(-.25f, -.4f);
    glVertex2f(-.0f, -0.4f);
    glVertex2f(-.05f, -.05f);
    glEnd();
    glPopMatrix();
    // Neak Robe
    glBegin(GL_QUADS);
    glColor3f(1.00, 0.10, 0.10);
    glVertex2f(.05f, -.1f);
    glVertex2f(.05f, -.05f);
    glVertex2f(-.05f, -.05f);
    glVertex2f(-.05f, -.1f);
    glEnd();
    // Face
    glColor3f(1.0, 0.8, 0.6);
    drawFilledCircle(.022f, .0f, 0.07f);
    // Hair
    glBegin(GL_QUADS);
    glColor3f(0.96, 0.42, 0.22);
    glVertex2f(.09f, .03f);
    glVertex2f(.09f, .07f);
    glVertex2f(-.035f, .07f);
    glVertex2f(-.035f, .03f);
    // Side Hair Left
    glVertex2f(-.01f, -.045f);
    glVertex2f(-.01f, .04f);
    glVertex2f(-.05f, .04f);
    glVertex2f(-.05f, -.045f);
    // Side Hair Right
    glVertex2f(.08f, -.045f);
    glVertex2f(.08f, .04f);
    glVertex2f(.11f, .04f);
    glVertex2f(.11f, -.045f);
    glEnd();
    // Left Eye
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(.015f, .01f, 0.0135f);
    // Right Eye
    drawFilledCircle(.065f, .01f, 0.0135f);
    // Mouth
    glLineWidth(1.5f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.02f, -.03f);
    glVertex2f(.05f, mouth_angle);
    glVertex2f(.07f, -.03f);
    glEnd();
}
void lailla_holding_basket() {
    // Lailla
    lailla_front_robe(.0);
    // Basket
    glPushMatrix();
    glTranslatef(0.12, -0.48, 0.0);
    glScalef(0.6, 0.6, 1.0);
    MyBascket();
    glPopMatrix();
}
void lailla_talking() {
    // Right Leg
    glPushMatrix();
    glTranslatef(0.05f, 0.01f, 0.0f);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();
    // Left Leg
    lailla_leg(0.55f, 0.18f, 0.00f);

    // body
    lailla_side_robe(-0.02);

    // Mouth
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.02f, -.03f);
    glVertex2f(.05f, -0.02);
    glVertex2f(.07f, -.03f);
    glVertex2f(.05f, -0.045);
    glEnd();
}
void lailla_take_flower() {
    // Right Leg
    glPushMatrix();
    glTranslatef(0.05f, 0.01f, 0.0f);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();
    // Left Leg
    lailla_leg(0.55f, 0.18f, 0.00f);

    glPushMatrix();
    glRotatef(-10.0, 0.0, 0.0, 1.0);

    glPushMatrix();
    // Left Hand
    glTranslatef(-0.15f, -0.15f, 0.0f);
    glScalef(1.0, .7, 1.0);
    glRotatef(-10.0, 0.0, 0.0, 1.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    lailla_hand();
    glPopMatrix();

    // Right Hand
    glPushMatrix();
    glTranslatef(-0.15f, -0.13f, 0.0f);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glScalef(1.0, .7, 1.0);
    lailla_hand();
    glPopMatrix();

    // body
    lailla_side_robe(-0.02);

    glPopMatrix();
}
void lailla_standing_ByTable() {
    // Right Leg
    glPushMatrix();
    glTranslatef(-0.07f, 0.01f, 0.0f);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();
    // Left Leg
    lailla_leg(0.55f, 0.18f, 0.00f);

    glPushMatrix();
    glRotatef(-10.0, 0.0, 0.0, 1.0);

    glPushMatrix();
    // Left Hand
    glTranslatef(-0.15f, -0.15f, 0.0f);
    glScalef(1.0, .7, 1.0);
    glRotatef(-10.0, 0.0, 0.0, 1.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    lailla_hand();
    glPopMatrix();

    // Right Hand
    glPushMatrix();
    glTranslatef(-0.15f, -0.13f, 0.0f);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glScalef(1.0, .7, 1.0);
    lailla_hand();
    glPopMatrix();

    // body
    lailla_side_robe(-0.04);

    glPopMatrix();
}
void lailla_surprised() {
    // Right Leg
    glPushMatrix();
    glTranslatef(0.05f, 0.01f, 0.0f);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();
    // Left Leg
    lailla_leg(0.55f, 0.18f, 0.00f);
    // body
    lailla_side_robe(-0.02);
    // Mark
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(.13f, -.07f, 0.011f);
    drawFilledCircle(.16f, -.07f, 0.011f);

    glLineWidth(2.5f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(.131f, .02);
    glVertex2f(.135f, -.04f);
    glVertex2f(.135f, .02);
    glVertex2f(.135f, -.04f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(.161f, .02);
    glVertex2f(.161f, -.04f);
    glVertex2f(.165f, .02);
    glVertex2f(.165f, -.04f);
    glEnd();
}
void lailla_running() {
    glPushMatrix();
    // Left Hand
    glTranslatef(0.15f, -0.1f, 0.0f);
    glScalef(1.0, .7, 1.0);
    lailla_hand();
    glPopMatrix();

    // Right Hand
    glPushMatrix();
    glTranslatef(0.15f, -0.1f, 0.0f);
    glRotatef(15.0, 0.0, 0.0, 1.0);
    glScalef(1.0, .7, 1.0);
    lailla_hand();
    glPopMatrix();

    // Right Leg
    glPushMatrix();
    glTranslatef(-0.046f, 0.1f, 0.0f);
    glRotatef(30.0, 0.0, 0.0, 1.0);
    glScalef(.9, 1.3, 1.0);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();

    // Left Leg
    glPushMatrix();
    glTranslatef(0.3f, 0.03f, 0.0f);
    glRotatef(-30.0, 0.0, 0.0, 1.0);
    glScalef(.9, 1.3, 1.0);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();

    // body
    glPushMatrix();
    glRotatef(180.0, 0.0, 1.0, 0.0);
    lailla_side_robe(-0.02);
    glPopMatrix();
}
void GeomatricLayla() {
    glPushMatrix();
    glTranslatef(0.2, -0.3, 0.0);
    glScalef(0.7, 0.7, 1.0);
    lailla_home();
    glPopMatrix();
    glEnd();
}
void lailla_Crying() {
    glPushMatrix();
    // Left Hand
    glTranslatef(0.15f, -0.1f, 0.0f);
    glScalef(1.2, .8, 1.0);
    lailla_hand();
    glPopMatrix();

    // Right Leg
    glPushMatrix();
    glTranslatef(-0.046f, 0.1f, 0.0f);
    glRotatef(30.0, 0.0, 0.0, 1.0);
    glScalef(.9, 1.3, 1.0);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();

    // Left Leg
    glPushMatrix();
    glTranslatef(0.05f, 0.1f, 0.0f);
    glScalef(.9, 1.3, 1.0);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();

    // body
    glPushMatrix();
    glRotatef(180.0, 0.0, 1.0, 0.0);
    lailla_side_robe(-0.02);
    glPopMatrix();
}
void GLaylaCrying() {
    glPushMatrix();
    glTranslatef(-0.25, -0.3, 0.0);
    glScalef(0.8, 0.8, 1.0);
    lailla_Crying();
    glPopMatrix();
}
// End Lailla
// Start Wolf
void wolf() {
    //head
    glColor3f(0.7f, 0.7f, 0.7f);

    drawFilledCircle(0, 0.5, .16);

    //right ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.05f, 0.63f);
    glVertex2f(0.15f, 0.53f);
    glVertex2f(0.22f, 0.7f);
    glEnd();

    //left ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.05f, 0.63f);
    glVertex2f(-0.15f, 0.53f);
    glVertex2f(-0.22f, 0.7f);
    glEnd();

    //right Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(0.055, 0.53, 0.025);
    drawFilledCircle(0.055, 0.53, 0.01);

    // Left Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(-0.055, 0.53, 0.025);
    drawFilledCircle(-0.055, 0.53, 0.01);

    //right brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.58f);
    glVertex2f(0.03f, 0.57f);
    glEnd();

    //left brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.08f, 0.58f);
    glVertex2f(-0.03f, 0.57f);
    glEnd();

    //nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.02f, 0.46f);
    glVertex2f(-0.02f, 0.46f);
    glEnd();

    //mouth
    drawFilledHalfCircle(0, 0.43, 0.04);

    //neck
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.04f, 0.35f);
    glVertex2f(0.04f, 0.29f);
    glVertex2f(-0.04f, 0.35f);
    glVertex2f(-0.04f, 0.29f);
    glEnd();

    //body
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.13f, -0.2f);
    glVertex2f(0.13f, 0.29f);
    glVertex2f(-0.13f, -0.2f);
    glVertex2f(-0.13f, 0.29f);
    glEnd();

    //right leg
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.13f, -0.2f);
    glVertex2f(0.13f, -0.4f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.05f, -0.4f);
    glEnd();

    //left leg
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.13f, -0.2f);
    glVertex2f(-0.13f, -0.4f);
    glVertex2f(-0.05f, -0.2f);
    glVertex2f(-0.05f, -0.4f);
    glEnd();

    //left foot
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.13f, -0.4f);
    glVertex2f(-0.13f, -0.45f);
    glVertex2f(-0.05f, -0.4f);
    glVertex2f(-0.05f, -0.45f);
    glEnd();

    //right foot
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(0.13f, -0.4f);
    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.05f, -0.4f);
    glEnd();

    //right leg claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.065f, -0.54f);
    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.08f, -0.45f);
    glEnd();

    //right claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.07f, -0.45f);
    glVertex2f(0.11f, -0.45f);
    glVertex2f(0.094f, -0.54f);
    glEnd();

    //right claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.1f, -0.45f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(0.12f, -0.54f);
    glEnd();

    //left claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.065f, -0.54f);
    glVertex2f(-0.05f, -0.45f);
    glVertex2f(-0.08f, -0.45f);
    glEnd();

    //left claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.07f, -0.45f);
    glVertex2f(-0.11f, -0.45f);
    glVertex2f(-0.094f, -0.54f);
    glEnd();

    //left claws
    glBegin(GL_TRIANGLES);
    glColor3f(-0.3f, 0.3f, 0.3f);
    glVertex2f(-0.1f, -0.45f);
    glVertex2f(-0.13f, -0.45f);
    glVertex2f(-0.12f, -0.54f);
    glEnd();

    //right arm
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.13f, 0.15);
    glVertex2f(0.13f, 0.29f);
    glVertex2f(0.17f, -0.05f);
    glVertex2f(0.23f, -0.05f);
    glEnd();

    //left arm
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.13f, 0.15);
    glVertex2f(-0.13f, 0.29f);
    glVertex2f(-0.17f, -0.05f);
    glVertex2f(-0.23f, -0.05f);
    glEnd();

    //right claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.17f, -0.05f);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.195f, -0.13f);
    glEnd();

    //right claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.17f, -0.05f);
    glVertex2f(0.22f, -0.05f);
    glVertex2f(0.22f, -0.13f);
    glEnd();

    //right claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.23f, -0.05f);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.24f, -0.13f);
    glEnd();

    //left claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.17f, -0.05f);
    glVertex2f(-0.2f, -0.05f);
    glVertex2f(-0.195f, -0.13f);
    glEnd();

    //left claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.17f, -0.05f);
    glVertex2f(-0.22f, -0.05f);
    glVertex2f(-0.22f, -0.13f);
    glEnd();

    //Left Claws
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.23f, -0.05f);
    glVertex2f(-0.2f, -0.05f);
    glVertex2f(-0.24f, -0.13f);
    glEnd();

}
void wolf_left_arm() {
    //right arm
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.13f, 0.15);
    glVertex2f(-0.13f, 0.29f);
    glVertex2f(-0.17f, -0.05f);
    glVertex2f(-0.23f, -0.05f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.17f, -0.05f);
    glVertex2f(-0.2f, -0.05f);
    glVertex2f(-0.195f, -0.13f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.17f, -0.05f);
    glVertex2f(-0.22f, -0.05f);
    glVertex2f(-0.22f, -0.13f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.23f, -0.05f);
    glVertex2f(-0.2f, -0.05f);
    glVertex2f(-0.24f, -0.13f);
    glEnd();
}
void wolf_right_arm() {
    //right arm
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(0.13f, 0.15);
    glVertex2f(0.13f, 0.29f);
    glVertex2f(0.17f, -0.05f);
    glVertex2f(0.23f, -0.05f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.17f, -0.05f);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.195f, -0.13f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.17f, -0.05f);
    glVertex2f(0.22f, -0.05f);
    glVertex2f(0.22f, -0.13f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.23f, -0.05f);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.24f, -0.13f);
    glEnd();
}
void wolf_head() {
    //head
    glColor3f(0.7f, 0.7f, 0.7f);
    drawFilledCircle(0, 0.5, .16);

    //right ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.05f, 0.63f);
    glVertex2f(0.15f, 0.53f);
    glVertex2f(0.22f, 0.7f);
    glEnd();

    //left ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.05f, 0.63f);
    glVertex2f(-0.15f, 0.53f);
    glVertex2f(-0.22f, 0.7f);
    glEnd();

    //right Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(0.055, 0.53, 0.025);
    drawFilledCircle(0.048, 0.53, 0.01);

    // Left Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(-0.055, 0.53, 0.025);
    drawFilledCircle(-0.062, 0.53, 0.01);

    //right brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.58f);
    glVertex2f(0.03f, 0.57f);
    glEnd();

    //left brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.08f, 0.58f);
    glVertex2f(-0.03f, 0.57f);
    glEnd();

    //nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.02f, 0.46f);
    glVertex2f(-0.02f, 0.46f);
    glEnd();

    //mouth
    drawFilledHalfCircle(0, 0.43, 0.04);
}
void wolf_body() {
    //head
    glColor3f(0.7f, 0.7f, 0.7f);
    drawFilledCircle(0, 0.5, .16);

    //right ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.05f, 0.63f);
    glVertex2f(0.15f, 0.53f);
    glVertex2f(0.22f, 0.7f);
    glEnd();

    //left ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.05f, 0.63f);
    glVertex2f(-0.15f, 0.53f);
    glVertex2f(-0.22f, 0.7f);
    glEnd();

    //right Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(0.055, 0.53, 0.025);
    drawFilledCircle(0.062, 0.53, 0.01);

    // Left Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(-0.055, 0.53, 0.025);
    drawFilledCircle(-0.048, 0.53, 0.01);

    //right brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.58f);
    glVertex2f(0.03f, 0.57f);
    glEnd();

    //left brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.08f, 0.58f);
    glVertex2f(-0.03f, 0.57f);
    glEnd();

    //nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.02f, 0.46f);
    glVertex2f(-0.02f, 0.46f);
    glEnd();

    //mouth
    drawFilledHalfCircle(0, 0.43, 0.04);

    //neck
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.04f, 0.35f);
    glVertex2f(0.04f, 0.29f);
    glVertex2f(-0.04f, 0.35f);
    glVertex2f(-0.04f, 0.29f);
    glEnd();

    //body
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.13f, -0.2f);
    glVertex2f(0.13f, 0.29f);
    glVertex2f(-0.13f, -0.2f);
    glVertex2f(-0.13f, 0.29f);
    glEnd();
}
void wolf_body1() {

    //neck
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.04f, 0.35f);
    glVertex2f(0.04f, 0.29f);
    glVertex2f(-0.04f, 0.35f);
    glVertex2f(-0.04f, 0.29f);
    glEnd();

    //body
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.13f, -0.2f);
    glVertex2f(0.13f, 0.29f);
    glVertex2f(-0.13f, -0.2f);
    glVertex2f(-0.13f, 0.29f);
    glEnd();
}
void wolf_leg() {
    // leg
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(0.13f, -0.2f);
    glVertex2f(0.13f, -0.4f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.05f, -0.4f);
    glEnd();

    // foot
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(0.13f, -0.4f);
    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.05f, -0.4f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.065f, -0.54f);
    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.08f, -0.45f);
    glEnd();

    //„Œ«·» «·Ì„Ì‰
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.07f, -0.45f);
    glVertex2f(0.11f, -0.45f);
    glVertex2f(0.094f, -0.54f);
    glEnd();

    //„Œ«·» «·Ì„Ì‰
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.1f, -0.45f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(0.12f, -0.54f);
    glEnd();
}
void wolf_leg(GLfloat r, GLfloat g, GLfloat b) {
    // leg
    glBegin(GL_QUAD_STRIP);
    glColor3f(r, g, b);
    glVertex2f(0.13f, -0.2f);
    glVertex2f(0.13f, -0.4f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.05f, -0.4f);
    glEnd();

    // foot
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(0.13f, -0.4f);
    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.05f, -0.4f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.065f, -0.54f);
    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.08f, -0.45f);
    glEnd();

    //„Œ«·» «·Ì„Ì‰
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.07f, -0.45f);
    glVertex2f(0.11f, -0.45f);
    glVertex2f(0.094f, -0.54f);
    glEnd();

    //„Œ«·» «·Ì„Ì‰
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.1f, -0.45f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(0.12f, -0.54f);
    glEnd();
}
void wolf_right_arm_pointing() {
    //right arm
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.13f, 0.15);
    glVertex2f(0.13f, 0.29f);
    glVertex2f(0.17f, -0.05f);
    glVertex2f(0.23f, -0.05f);
    glEnd();

    //„Œ«·»
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.23f, -0.05f);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.24f, -0.13f);
    glEnd();
}
void wolf_at_forest() {
    //body
    wolf_body();
    //right leg
    wolf_leg();

    wolf_left_arm();

    glPushMatrix();
    //left leg
    glTranslatef(-0.18f, 0.0f, 0.0f);
    wolf_leg();
    glPopMatrix();

    glPushMatrix();
    // Left Hand
    glTranslatef(0.17f, 0.02f, 0.0f);
    glRotatef(50, 0.0f, 0.0f, 1.0f);
    wolf_right_arm_pointing();
    glPopMatrix();
}
void wolf_at_grandmotherHome() {
    //head
    glPushMatrix();
    glRotatef(30, 0.0f, 1.0f, 0.0f);
    wolf_head();
    glPopMatrix();

    //body
    glPushMatrix();
    glRotatef(45, 0.0f, 1.0f, 0.0f);
    wolf_body1();
    glPopMatrix();

    // right arm
    glPushMatrix();
    glTranslatef(-0.22f, 0.2f, 0.0f);
    glRotatef(-50, 0.0f, 0.0f, 1.0f);
    wolf_right_arm();
    glPopMatrix();

    //left arm
    glPushMatrix();
    glTranslatef(-0.1f, 0.01f, 0.0f);
    glRotatef(-45, 0.0f, 0.0f, 1.0f);
    wolf_left_arm();
    glPopMatrix();

    //right leg
    glPushMatrix();
    glTranslatef(-0.05f, 0.0f, 0.0f);
    wolf_leg(0.45f, 0.45f, 0.45f);
    glPopMatrix();

    //left leg
    glPushMatrix();
    glTranslatef(-0.123f, 0.0f, 0.0f);
    glRotatef(35, 0.0f, 1.0f, 0.0f);
    wolf_leg(0.45f, 0.45f, 0.45f);
    glPopMatrix();
}
void wolf_half_body() {

    //head
    glColor3f(0.7f, 0.7f, 0.7f);
    drawFilledCircle(0, 0.5, .16);

    //right ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.05f, 0.63f);
    glVertex2f(0.15f, 0.53f);
    glVertex2f(0.22f, 0.7f);
    glEnd();

    //left ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.05f, 0.63f);
    glVertex2f(-0.15f, 0.53f);
    glVertex2f(-0.22f, 0.7f);
    glEnd();

    //right Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(0.055, 0.53, 0.025);
    drawFilledCircle(0.055, 0.53, 0.01);

    // Left Eye
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(-0.055, 0.53, 0.025);
    drawFilledCircle(-0.055, 0.53, 0.01);

    //right brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.58f);
    glVertex2f(0.03f, 0.57f);
    glEnd();

    //left brow
    glLineWidth(2.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.08f, 0.58f);
    glVertex2f(-0.03f, 0.57f);
    glEnd();

    //nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.02f, 0.46f);
    glVertex2f(-0.02f, 0.46f);
    glEnd();

    //mouth
    drawFilledHalfCircle(0, 0.43, 0.04);
    //neck
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.04f, 0.35f);
    glVertex2f(0.04f, 0.29f);
    glVertex2f(-0.04f, 0.35f);
    glVertex2f(-0.04f, 0.29f);
    glEnd();

    //body
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.13f, -0.2f);
    glVertex2f(0.13f, 0.29f);
    glVertex2f(-0.13f, -0.2f);
    glVertex2f(-0.13f, 0.29f);
    glEnd();

    // Glassess
        // Glassess Circles
    glPushMatrix();
    glTranslatef(0.0f, 0.53f, 0.0f);
    glColor3f(1.0, 1.0, 1.0);
    drawHollowCircle(0.057, -0.0, 0.035);
    drawHollowCircle(-0.06, -.0, 0.035);

    // Glassrss Lines
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    // middle line
    glVertex2f(-.03f, -.0);
    glVertex2f(.02f, -.0);
    // right line
    glVertex2f(.09f, .0);
    glVertex2f(.15f, -.05);
    // left lind
    glVertex2f(-.09f, .0);
    glVertex2f(-.15f, -.05);
    glEnd();
    glPopMatrix();

}
void wolf_running() {

    glPushMatrix();
    glRotatef(30, 0.0f, 1.0f, 0.0f);
    wolf_head();
    glPopMatrix();

    //body
    glPushMatrix();
    glRotatef(45, 0.0f, 1.0f, 0.0f);
    wolf_body1();
    glPopMatrix();

    // right arm
    glPushMatrix();
    glTranslatef(-0.22f, 0.2f, 0.0f);
    glRotatef(-50, 0.0f, 0.0f, 1.0f);
    wolf_right_arm();
    glPopMatrix();

    //left arm
    glPushMatrix();
    glTranslatef(-0.1f, 0.01f, 0.0f);
    glRotatef(-45, 0.0f, 0.0f, 1.0f);
    wolf_left_arm();
    glPopMatrix();

    //right leg
    glPushMatrix();
    glTranslatef(-0.1f, -0.01f, 0.0f);
    glRotatef(20, 0.0f, 0.0f, 1.0f);
    wolf_leg(0.5f, 0.5f, 0.5f);
    glPopMatrix();

    //left leg
    glPushMatrix();
    glTranslatef(-0.07f, 0.05f, 0.0f);
    glRotatef(-20, 0.0f, 0.0f, 1.0f);
    wolf_leg(0.5f, 0.5f, 0.5f);
    glPopMatrix();
}
// End Wolf

// Start Grandmother
void grandmother() {
    glBegin(GL_QUADS); //hair
    glColor3f(0.73, 0.71, 0.72);
    glVertex2f(0.15, 0.1);
    glVertex2f(-0.15, 0.1);
    glVertex2f(-0.15, -0.15);
    glVertex2f(0.15, -0.15);
    glEnd();
    glBegin(GL_QUADS); //hair side
    glColor3f(0.73, 0.71, 0.72);
    glVertex2f(0.2, 0.05);
    glVertex2f(-0.2, 0.05);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glEnd();
    glBegin(GL_QUADS); //head
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-0.14, 0.05);
    glVertex2f(-0.14, -0.14);
    glVertex2f(0.14, -0.14);
    glVertex2f(0.14, 0.05);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//eye
    drawFilledCircle(-0.06, 0.0, 0.02);

    glColor3f(0.0, 0.0, 0.0);//eye
    drawFilledCircle(0.06, 0.0, 0.02);


    glBegin(GL_QUADS); //neck
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-0.06, -0.2);
    glVertex2f(0.06, -0.2);
    glVertex2f(0.06, -0.12);
    glVertex2f(-0.06, -0.12);

    glEnd();

    glBegin(GL_QUADS); //dress
    glColor3f(0.95, 0.64, 0.51);
    glVertex2f(-0.2, -0.55);
    glVertex2f(0.2, -0.55);
    glVertex2f(0.07, -0.2);
    glVertex2f(-0.08, -0.2);

    glEnd();

    glBegin(GL_QUADS); //dress
    glColor3f(0.95, 0.64, 0.51);
    glVertex2f(-0.08, -0.2);
    glVertex2f(0.07, -0.2);
    glVertex2f(0.07, -0.18);
    glVertex2f(-0.08, -0.18);
    glEnd();

    ///////////////

    glBegin(GL_QUADS);
    //// leg Left
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.04f, -.65f);
    glVertex2f(-.12f, -.65f);
    glVertex2f(-.12f, -.55f);
    glVertex2f(-.04f, -.55f);

    glEnd();

    glBegin(GL_QUADS);
    // leg Right
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(.04f, -.65f);
    glVertex2f(.12f, -.65f);
    glVertex2f(.12f, -.55f);
    glVertex2f(.04f, -.55f);


    glEnd();
    // Shose Left
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.18, 0.00);
    glVertex2f(-.12f, -.65f);
    glVertex2f(-.04f, -.65f);
    glVertex2f(-.04f, -.61f);
    glVertex2f(-.12f, -.61f);
    glEnd();
    //shoes Right
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.18, 0.00);
    glVertex2f(.12f, -.65f);
    glVertex2f(.04f, -.65f);
    glVertex2f(.04f, -.61f);
    glVertex2f(.12f, -.61f);
    glEnd();

    glBegin(GL_QUADS);
    // Arm Left
    glColor3f(0.95, 0.64, 0.51);
    glVertex2f(-.1f, -0.35f);
    glVertex2f(-.1f, -.25f);
    glVertex2f(-.25f, -.29f);
    glVertex2f(-.25f, -0.39f);
    // Hand
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(-.32f, -0.39f);
    glVertex2f(-.25f, -0.39f);
    glVertex2f(-.25f, -.29f);
    glVertex2f(-.32f, -.29f);
    glEnd();

    glBegin(GL_QUADS);
    // Arm Right
    glColor3f(0.95, 0.64, 0.51);
    glVertex2f(.1f, -0.35f);
    glVertex2f(.09f, -.25f);
    glVertex2f(.25f, -.29f);
    glVertex2f(.25f, -0.39f);
    // Hand
    glColor3f(1.0, 0.8, 0.6);
    glVertex2f(.32f, -0.39f);
    glVertex2f(.25f, -0.39f);
    glVertex2f(.25f, -.29f);
    glVertex2f(.32f, -.29f);
    glEnd();

    //mouth
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.05f, -.08f);
    glVertex2f(-.05f, -.08f);
    glEnd();

    // Glassess
    // Glassess Circles
    glColor3f(1.0, 1.0, 1.0);
    drawHollowCircle(0.057, -0.0, 0.035);
    drawHollowCircle(-0.06, -.0, 0.035);

    // Glassrss Lines
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    // middle line
    glVertex2f(-.03f, -.0);
    glVertex2f(.02f, -.0);
    // right line
    glVertex2f(.09f, .0);
    glVertex2f(.15f, -.05);
    // left lind
    glVertex2f(-.09f, .0);
    glVertex2f(-.15f, -.05);
    glEnd();

    // Mark
    glPushMatrix();
    glTranslatef(0.1, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(.13f, -.07f, 0.011f);
    drawFilledCircle(.16f, -.07f, 0.011f);

    glLineWidth(2.5f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(.131f, .02);
    glVertex2f(.135f, -.04f);
    glVertex2f(.135f, .02);
    glVertex2f(.135f, -.04f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(.161f, .02);
    glVertex2f(.161f, -.04f);
    glVertex2f(.165f, .02);
    glVertex2f(.165f, -.04f);
    glPopMatrix();
    glEnd();

}
// End Grandmother



// End Characters
// Start Backgrounds
// Start Lailla House Background
void HomeLayla() {
    // glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glBegin(GL_QUADS); //Wall
    glColor3f(1.0f, 0.7f, 0.8f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //Wall
    glColor3f(1.0f, 0.8f, 0.8f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.5f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //floor
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-2.0f, -0.5f);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(-1.0f, -2.0f);
    glVertex2f(1.0f, -2.0f);
    glEnd();
}
void MyWindow() {
    // the big squer
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.26, 0.16f);  // down to the right
    glVertex2f(-0.75, 0.16f);  // down to the left
    glVertex2f(-0.75f, 0.66f);  // up to the left
    glVertex2f(-0.26f, 0.66f);  // up to the right
    glEnd();

    // the left lower small squer
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 0.9f);
    glVertex2f(-0.51, 0.2f);
    glVertex2f(-0.71, 0.2f);
    glVertex2f(-0.71f, 0.39f);
    glVertex2f(-0.51f, 0.39f);
    glEnd();

    // the right lower small squer
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 0.9f);
    glVertex2f(-0.3, 0.2f);
    glVertex2f(-0.48, 0.2f);
    glVertex2f(-0.48f, 0.39f);
    glVertex2f(-0.3f, 0.39f);
    glEnd();

    // the right upper small squer
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 0.9f);
    glVertex2f(-0.3, 0.62f);
    glVertex2f(-0.48, 0.62f);
    glVertex2f(-0.48f, 0.42f);
    glVertex2f(-0.3f, 0.42f);
    glEnd();

    // the left upper small squer
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 0.9f);
    glVertex2f(-0.51, 0.62f);
    glVertex2f(-0.71, 0.62f);
    glVertex2f(-0.71f, 0.42f);
    glVertex2f(-0.51f, 0.42f);
    glEnd();

    // the outer  edge
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.6f, 0.0f);
    glVertex2f(-0.26, 0.16f);
    glVertex2f(-0.75, 0.16f);
    glVertex2f(-0.81f, 0.13f);
    glVertex2f(-0.21f, 0.13f);
    glEnd();

    // the inner edge
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.4f, 0.0f);
    glVertex2f(-0.21, 0.13f);
    glVertex2f(-0.81, 0.13f);
    glVertex2f(-0.81f, 0.08f);
    glVertex2f(-0.21f, 0.08f);
    glEnd();
}
void GeomatricWin() {
    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.0);
    MyWindow();
    glPopMatrix();
}
void watch() {
    // first circle
    glColor3f(0.5f, 0.5f, 0.5f);
    drawFilledCircle(0, 0, .39);

    //white circle
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0, 0, .35);

    //middle circle
    glColor3f(0.5f, 0.5f, 0.5f);
    drawFilledCircle(0, 0, .02);

    glLineWidth(4.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.25f);
    glEnd();


    glLineWidth(4.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.21f, 0.0f);
    glEnd();
}
void GeomatricClock() {
    glPushMatrix();
    glTranslatef(-0.7, 0.7, 0.0);
    glScalef(0.5, 0.5, 1.0);
    watch();
    glPopMatrix();
}
void layla_hood() {
    glColor3f(1.0, 0.1, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.07399, 0.01475);
    glVertex2f(0.27862, -0.50154);
    glVertex2f(-0.08, -0.50154);
    glEnd();

    drawFilledCircle(0.07952, -0.04052, 0.13);
}
void GeomatricLH() {
    glPushMatrix();
    glTranslatef(0.7, 0.6, 0.0);
    glScalef(0.8, 0.8, 1.0);
    layla_hood();
    glPopMatrix();
}
// End Lailla House Background
// Start Forest Background 
void forest() {
    glBegin(GL_QUADS);
    //--> sky
    glColor3f(0.0, 0.8, 0.9);
    glVertex2f(-0.99193, 1.19555);
    glVertex2f(1.00649, 1.19555);
    glVertex2f(0.99193, -0.71696);
    glVertex2f(-1.00649, -0.71696);

    //--> greas

    glColor3f(0.1, 0.5, 0.1);
    glVertex2f(-1.00021, -0.51581);
    glColor3f(0.0, 0.69, 0.0);

    glVertex2f(0.98752, -0.51833);
    glColor3f(0.0, 0.59, 0.0);
    glVertex2f(1.00287, -1.07806);
    glColor3f(0.0, 0.45, 0.0);
    glVertex2f(-0.9979, -1.0794);

    //--> dirt

    glColor3f(0.6, 0.4, 0.3);
    glVertex2f(-0.8, -0.52);
    glVertex2f(-0.5, -0.52);
    glVertex2f(0.5, -1.1);
    glVertex2f(0.2, -1.1);

    glEnd();



    //--> clouds

        //right
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.8, 0.7, 0.14);

    drawFilledCircle(0.6, 0.7, 0.09);
    drawFilledCircle(0.69, 0.65, 0.08);
    drawFilledCircle(0.69, 0.75, 0.08);

    drawFilledCircle(1.0, 0.7, 0.09);
    drawFilledCircle(0.92, 0.65, 0.08);
    drawFilledCircle(0.92, 0.75, 0.08);


    //meddil

    drawFilledCircle(0.2, 0.4, 0.14);

    drawFilledCircle(0.0, 0.4, 0.09);
    drawFilledCircle(0.09, 0.35, 0.08);
    drawFilledCircle(0.09, 0.45, 0.08);

    drawFilledCircle(0.40, 0.4, 0.09);
    drawFilledCircle(0.32, 0.35, 0.08);
    drawFilledCircle(0.32, 0.45, 0.08);




    //left meddil
    drawFilledCircle(-0.2, 1.0, 0.14);

    drawFilledCircle(0.0, 1.0, 0.09);
    drawFilledCircle(-0.09, 0.95, 0.08);
    drawFilledCircle(-0.09, 1.05, 0.08);

    drawFilledCircle(-0.4, 1.0, 0.09);
    drawFilledCircle(-0.32, 0.95, 0.08);
    drawFilledCircle(-0.32, 1.05, 0.08);



    //left
    drawFilledCircle(-0.7, 0.6, 0.14);

    drawFilledCircle(-0.5, 0.6, 0.09);
    drawFilledCircle(-0.59, 0.55, 0.08);
    drawFilledCircle(-0.59, 0.65, 0.08);

    drawFilledCircle(-0.9, 0.6, 0.09);
    drawFilledCircle(-0.82, 0.55, 0.08);
    drawFilledCircle(-0.82, 0.65, 0.08);
}
void grass() {

    glBegin(GL_QUADS);

    glColor3f(0.0, 0.4, 0.2);
    glVertex2f(0.40353, -0.71506);
    glVertex2f(0.79846, -0.71707);
    glVertex2f(0.8, -0.8);
    glVertex2f(0.4, -0.8);

    glEnd();

    glColor3f(0.0, 0.4, 0.2);

    drawFilledCircle(0.39, -0.7, 0.10);
    drawFilledCircle(0.58, -0.67, 0.13);
    drawFilledCircle(0.78, -0.7, 0.10);

    glColor3f(0.8, 0.2, 0.1);
    drawFilledCircle(0.37, -0.7, 0.02);
    drawFilledCircle(0.58, -0.62, 0.02);
    drawFilledCircle(0.51, -0.72, 0.02);
    drawFilledCircle(0.65, -0.74, 0.02);

    drawFilledCircle(0.78, -0.7, 0.02);

}
// Tree
void tree() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, woodTreeTextur);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(0.55f, -0.4f);
    glTexCoord2f(0.0, 1.0); glVertex2f(0.55f, 0.1f);
    glTexCoord2f(1.0, 1.0);  glVertex2f(0.4f, 0.1f);
    glTexCoord2f(1.0, 0.0); glVertex2f(0.4f, -0.4f);
    glEnd();

    glDisable(GL_TEXTURE_2D);


    // Leaf
    glBegin(GL_TRIANGLES);
    glColor3f(0.00f, 0.23f, 0.07f);
    glVertex2f(0.7f, -0.1f);
    glVertex2f(0.48f, 0.3f);
    glVertex2f(0.25f, -0.1f);
    glEnd();
}
// Flowers
void flowers() {
    glLineWidth(5.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.62f, 0.239f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.5f);
    glEnd();

    glColor3f(0.851f, 0.176f, 0.078f);
    drawFilledHalfCircle(0, 0, .15);

    //left triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.851f, 0.176f, 0.078f);
    glVertex2f(0.0f, -0.03f);
    glVertex2f(-0.15f, -0.03f);
    glVertex2f(-0.2f, 0.25f);
    glEnd();

    //middle triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.851f, 0.176f, 0.078f);
    glVertex2f(0.0f, 0.25f);
    glVertex2f(-0.15f, -0.03f);
    glVertex2f(0.15f, -0.03f);
    glEnd();

    //right triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.851f, 0.176f, 0.078f);
    glVertex2f(0.0f, -0.03f);
    glVertex2f(0.15f, -0.03f);
    glVertex2f(0.2f, 0.25f);
    glEnd();

    //down triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.31f, 0.62f, 0.239f);
    glVertex2f(0.0f, -0.25f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.1f, -0.2f);
    glEnd();
}
void forest_background() {

    forest();


    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-1.7, -0.3, 0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.8, -0.3, 0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-0.6, -0.5, 0.0);
    tree();
    glPopMatrix();
    //    
    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.3, -0.30, 0.0);
    tree();
    glPopMatrix();

    //    
    //    
    //////////////
    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-1.85, 0.0, 0.0);
    grass();
    glPopMatrix();


    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-0.32, -0.17, 0.0);
    grass();
    glPopMatrix();


    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-0.0, 0.01, 0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.55, -0.1, 0.0);
    grass();
    glPopMatrix();

    //

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(1.9, -3.9, 0.0);
    flowers();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(2.5, -4.0, 0.0);
    flowers();
    glPopMatrix();
    //
    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(2.9, -4.6, 0.0);
    flowers();
    glPopMatrix();
    //
    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(3.9, -3.6, 0.0);
    flowers();
    glPopMatrix();
    //
    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(3.3, -3.6, 0.0);
    flowers();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(3.7, -4.3, 0.0);
    flowers();
    glPopMatrix();
}
void forest_wolf_hiding() {
    forest();

    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-1.7, -0.3, 0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1.0);
    glRotatef(-0.95, 0.0, 0.0, 1.0);
    glTranslatef(0.55, -0.8, 0.0);
    wolf();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.8, -0.3, 0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-0.6, -0.5, 0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.3, -0.30, 0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-1.85, 0.0, 0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-0.32, -0.17, 0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-0.0, 0.01, 0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.55, -0.1, 0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(1.9, -3.9, 0.0);
    flowers();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(2.5, -4.0, 0.0);
    flowers();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(2.9, -4.6, 0.0);
    flowers();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(3.9, -3.6, 0.0);
    flowers();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(3.3, -3.6, 0.0);
    flowers();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1.0);
    glTranslatef(3.7, -4.3, 0.0);
    flowers();
    glPopMatrix();

}
// End Forest Background 
// Start Grandma House Background
void MyFloor() {
    glBegin(GL_QUADS);
    glColor3f(0.72f, 0.60f, 0.82f);
    glVertex2f(-1.f, -1.f);
    glVertex2f(-1.f, 1.f);
    glVertex2f(1.f, 1.f);
    glVertex2f(1.f, -1.f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.0f);
    glVertex2f(1.f, -0.6f);
    glVertex2f(-1.f, -0.6f);
    glVertex2f(-1.f, -1.f);
    glVertex2f(1.f, -1.f);
    glEnd();
}
void bed() {
    glBegin(GL_QUADS);
    // Back
    glColor3f(0.55f, 0.18f, 0.00f);
    glVertex2f(0.9f, -0.4f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.6f, 0.05f);
    glVertex2f(0.6f, -0.15f);
    // Base 1
    glColor3f(0.55f, 0.18f, 0.00f);
    glVertex2f(0.9f, -0.7f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, -0.7f);
    // Base 2
    glVertex2f(0.75f, -0.65f);
    glVertex2f(0.75f, -0.5f);
    glVertex2f(0.65f, -0.5f);
    glVertex2f(0.65f, -0.65f);
    // Base 3
    glVertex2f(0.0f, -0.65f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(-0.1f, -0.65f);
    // Base 4
    glVertex2f(0.2f, -0.8f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.1f, -0.8f);
    // Side Edge
    glColor3f(0.55f, 0.18f, 0.00f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.9f, -0.4f);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.1f, -0.7f);
    // Front Edge
    glColor3f(0.55f, 0.18f, 0.00f);
    glVertex2f(0.1f, -0.7f);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(-0.1f, -0.4f);
    // Surface
    glColor3f(0.64f, 0.27f, 0.00f);
    glVertex2f(0.9f, -0.4f);
    glVertex2f(0.6f, -0.15f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.1f, -0.6f);
    glEnd();
    // Pillow
    glPushMatrix();
    glTranslatef(0.5f, -0.3f, 0.0f);
    glRotatef(40.0, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.25f, -0.29f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.0f, 0.08f);
    glVertex2f(0.05f, -0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, -0.43f, 0.0f);
    glRotatef(-60.0, 0.0, 0.0, 1.0);
    glScalef(0.8, 0.8, 1.0);
    wolf_half_body(); ////////////////////////
    glPopMatrix();

    // Blanket
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.60, 0.81);
    glVertex2f(0.7f, -0.45f);
    glVertex2f(0.4f, -0.19f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.1f, -0.6f);
    glEnd();
}
void myClock() {
    // first circle
    glColor3f(0.5f, 0.5f, 0.5f);
    drawFilledCircle(0, 0, .39);

    //white circle
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0, 0, .35);

    //middle circle
    glColor3f(0.5f, 0.5f, 0.5f);
    drawFilledCircle(0, 0, .02);

    glLineWidth(4.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.25f);
    glEnd();

    glLineWidth(4.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.21f, 0.0f);
    glEnd();
}
void MyPinting()
{
    // the frame
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.0f, 0.0f);
    glVertex2f(0.9, 0.9f);
    glVertex2f(0.44, 0.9f);
    glVertex2f(0.44f, 0.52f);
    glVertex2f(0.9f, 0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.86, 0.86f);
    glVertex2f(0.48, 0.86f);
    glVertex2f(0.48f, 0.57f);
    glVertex2f(0.86f, 0.57f);
    glEnd();

    // the tree
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.0f);
    glVertex2f(0.75f, 0.82f);
    glVertex2f(0.58f, 0.82f);
    glVertex2f(0.58f, 0.66f);
    glVertex2f(0.75f, 0.66f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(0.68f, 0.72f);
    glVertex2f(0.66f, 0.72f);
    glVertex2f(0.66f, 0.6f);
    glVertex2f(0.68f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(0.645f, 0.735f);
    glVertex2f(0.638f, 0.73f);
    glVertex2f(0.66f, 0.705f);
    glVertex2f(0.66f, 0.72f);
    glEnd();
}
// End Grandma House Background
// End Backgrounds
// Start Scenes
void scene0() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    HomeLayla();
    GeomatricM0();
    GeomatricWin();
    GeomatricLH();
    GeomatricClock();
    GeomatricLayla();
    GeomatricB();

    glFlush();
    glutSwapBuffers();
}
void scene1() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    HomeLayla(); // Background
    GeomatricWin();
    GeomatricLH();
    GeomatricClock();
    GeomatricM0();
    GeomatricLayla();
    glLoadIdentity();
    glFlush();
    if (done1 == 0)
    {
        PlaySound(TEXT("audios\\P1.wav"), NULL, SND_SYNC);
        done1 = 1;
    }
    glutSwapBuffers();
}
void scene2() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    HomeLayla();
    GeomatricM0();
    GeomatricWin();
    GeomatricLH();
    GeomatricClock();
    GeomatricLayla();

    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.23, -1.08, 0.0);
    MyBascket();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done2 == 0)
    {
        PlaySound(TEXT("audios\\P2.wav"), NULL, SND_SYNC);
        done2 = 1;
    }
    glutSwapBuffers();
}
void scene3() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    forest_background();
    glPushMatrix();
    glScalef(0.4, 0.4, 1.0);
    glTranslatef(-0.9, -1.3, 0.0);
    lailla_holding_basket();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done3 == 0)
    {
        PlaySound(TEXT("audios\\P3.wav"), NULL, SND_SYNC);
        done3 = 1;
    }
    glutSwapBuffers();
}
void scene4() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    forest_wolf_hiding();
    // Lailla
    // Right Leg
    glPushMatrix();
    glTranslatef(-0.07f, -0.55f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();
    // Left Leg
    glPushMatrix();
    glTranslatef(-0.1f, -0.56f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    lailla_leg(0.55f, 0.18f, 0.00f);
    glPopMatrix();
    // Lailla Body
    glPushMatrix();
    glTranslatef(-0.1f, -0.55f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    lailla_side_robe(-0.04);
    glPopMatrix();
    // Basket
    glPushMatrix();
    glTranslatef(0.1f, -0.81f, 0.0f);
    glScalef(0.3, 0.3, 1.0);
    MyBascket();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done4 == 0)
    {
        PlaySound(TEXT("audios\\P4.wav"), NULL, SND_SYNC);
        done4 = 1;
    }
    glutSwapBuffers();
}
void scene5() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    // Forest
    forest_background();
    // Wolf Standing
    glPushMatrix();
    glTranslatef(-0.2f, -0.55f, 0.0f);
    glScalef(0.45, 0.45, 1.0);
    wolf();
    glPopMatrix();

    // Lailla Body
    glPushMatrix();
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glTranslatef(-0.21f, -0.55f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    lailla_talking();
    glPopMatrix();
    // Basket
    glPushMatrix();
    glTranslatef(0.3f, -0.81f, 0.0f);
    glScalef(0.3, 0.3, 1.0);
    MyBascket();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done5 == 0)
    {
        PlaySound(TEXT("audios\\P5.wav"), NULL, SND_SYNC);
        done5 = 1;
    }
    glutSwapBuffers();
}
void scene6() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color bufferS
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    // Forest
    forest_background();
    // Wolf
    glPushMatrix();
    glTranslatef(-0.2f, -0.55f, 0.0f);
    glScalef(0.45, 0.45, 1.0);
    wolf_at_forest();
    glPopMatrix();

    // Lailla
    glPushMatrix();
    glTranslatef(0.28f, -0.7f, 0.0f);
    glScalef(0.5, 0.5, 1.0);
    lailla_take_flower();
    glPopMatrix();

    // Basket
    glPushMatrix();
    glTranslatef(0.3f, -0.76f, 0.0f);
    glScalef(0.3, 0.3, 1.0);
    MyBascket();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done6 == 0)
    {
        PlaySound(TEXT("audios\\P6.wav"), NULL, SND_SYNC);
        done6 = 1;
    }
    glutSwapBuffers();
}
void scene7() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    // Background
    MyFloor();
    // Window
    glPushMatrix();
    glTranslatef(1.3f, 0.0f, 0.0f);
    MyWindow();
    glPopMatrix();
    // GrandMother
    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.1f, -0.21f, 0.0f);
    grandmother();
    glPopMatrix();
    // Wolf
    glPushMatrix();
    glScalef(1.1, 1.1, 1.0);
    glTranslatef(-0.7f, -0.19f, 0.0f);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    wolf_at_grandmotherHome();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done7 == 0)
    {
        PlaySound(TEXT("audios\\P7.wav"), NULL, SND_SYNC);
        done7 = 1;
    }
    glutSwapBuffers();
}
void scene8() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    MyFloor();
    MyWindow();
    bed();

    glPushMatrix();
    glTranslatef(0.3f, 0.5f, 0.0f);
    glScalef(00.5, 0.5, 1.0f);
    myClock();
    glPopMatrix();
    glFlush();
    glLoadIdentity();
    if (done8 == 0)
    {
        PlaySound(TEXT("audios\\P8.wav"), NULL, SND_SYNC);
        done8 = 1;
    }
    glutSwapBuffers();
}
void scene9() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    MyFloor();
    MyWindow();
    bed();

    glPushMatrix();
    glTranslatef(0.3f, 0.5f, 0.0f);
    glScalef(00.5, 0.5, 1.0f);
    myClock();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.03f, -0.25f, 0.0f);
    lailla_talking();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done9 == 0)
    {
        PlaySound(TEXT("audios\\P9.wav"), NULL, SND_SYNC);
        done9 = 1;
    }
    glutSwapBuffers();
}
void scene10() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    MyFloor();
    MyWindow();
    MyPinting();
    MyTable();

    glPushMatrix();
    glRotatef(180.f, 0.f, 1.f, 0.f);
    glScalef(1.2, 1.2, 1.0);
    glTranslatef(0.1, -0.01, 0.0);
    lailla_standing_ByTable();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done10 == 0)
    {
        PlaySound(TEXT("audios\\P10.wav"), NULL, SND_SYNC);
        done10 = 1;
    }
    glutSwapBuffers();
}

void scene11() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    MyFloor();
    MyWindow();
    bed();
    
    glPushMatrix();
    glTranslatef(0.3f, 0.5f, 0.0f);
    glScalef(00.5, 0.5, 1.0f);
    myClock();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.03f, -0.25f, 0.0f);
    lailla_talking();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done11 == 0)
    {
        PlaySound(TEXT("audios\\P11.wav"), NULL, SND_SYNC);
        done11 = 1;
    }
    glutSwapBuffers();
}
void scene12() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    MyFloor();
    glPushMatrix();
    glTranslatef(1.3f, 0.0f, 0.0f);
    MyWindow();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.25f, 0.0f);
    glScalef(0.8, 0.8, 1.0f);
    wolf_at_grandmotherHome();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f, -0.1f, 0.0f);
    lailla_surprised();
    glPopMatrix();
    glLoadIdentity();
    glFlush();
    if (done12 == 0)
    {
        PlaySound(TEXT("audios\\P12.wav"), NULL, SND_SYNC);
        done12 = 1;
    }
    glutSwapBuffers();
}

void scene13() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    forest_background();

   

    if (wolfValuex >= -0.3) {
        glPushMatrix();
        glTranslatef(wolfValuex, wolfValuey, 0);
        glScalef(0.5, 0.5, 1.0);
        wolf_running();
        glPopMatrix();
    }
    // lailla
    if (lillaValuex >= -0.4) {
        glPushMatrix();
        glTranslatef(lillaValuex, lillaValuey, 0);
        glScalef(0.5, 0.5, 1.0);
        lailla_running();
        glPopMatrix();
    }
    glLoadIdentity();
    glFlush();
    if (done13 == 0)
    {
        PlaySound(TEXT("audios\\P13.wav"), NULL, SND_SYNC);
        done13 = 1;
    }
    glutSwapBuffers();
}

void scene14() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    HomeLayla();
    GeomatricM02();
    GeomatricWin();
    GeomatricClock();
    GLaylaCrying();
    GHandMother();
    glLoadIdentity();
    glFlush();
    if (done14 == 0)
    {
        PlaySound(TEXT("audios\\P14.wav"), NULL, SND_SYNC);
        done14 = 1;
    }
    glutSwapBuffers();
}
// End Scenes
// End Scenes

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    glFlush();
    glutSwapBuffers();
}
void reshapeFun(GLint newWidth, GLint newHight)
{
    glViewport(0, 0, newWidth, newHight);
    win_width = newWidth;
    win_hight = newHight;
}
static void key(unsigned char key, int x, int y) // key handling
{
    switch (key) {
    case 'r':
        wolfValuey += 0.1;
        lillaValuey += 0.1;
        wolfValuex -= 0.1;
        lillaValuex -= 0.1;
        break;
    case '0':
        glutDisplayFunc(scene0);
        break;
    case '1':
        glutDisplayFunc(scene1);
        break;
    case '2':
        glutDisplayFunc(scene2);
        break;
    case '3':
        glutDisplayFunc(scene3);
        break;
    case '4':
        glutDisplayFunc(scene4);
        break;
    case '5':
        glutDisplayFunc(scene5);
        break;
    case '6':
        glutDisplayFunc(scene6);
        break;
    case '7':
        glutDisplayFunc(scene7);
        break;
    case '8':
        glutDisplayFunc(scene8);
        break;
    case '9':
        glutDisplayFunc(scene9);
        break;
    case 'A':
        glutDisplayFunc(scene10);
        break;
    case 'B':
        glutDisplayFunc(scene11);
        break;
    case 'C':
        glutDisplayFunc(scene12);
        break;
    case 'D':
        glutDisplayFunc(scene13);
        break;
    case 'E':
        glutDisplayFunc(scene14);
        break;
    case'q':
        exit(0);
        break;

    }
}
void init()
{
    //------- Texture ---------
    // Wood Tree Leg
    woodTreeTextur = LoadTexture(woodTreePath, 183, 275);
    if (woodTreeTextur == -1)
    {
        //cout << "Error in loading the texture" << endl;
    }
    else
        //cout << "The texture value is: " << woodTreeTextur << endl;

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to White and opaque
    glMatrixMode(GL_PROJECTION);

    glMatrixMode(GL_MODELVIEW);

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);   //  Specify the display Mode ñ RGB, RGBA or color //  Index, single or double Buffer
    //glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(win_width, win_hight);       // Set the window's initial width & height
    glutInitWindowPosition(50, 50);                 // Position the window's initial top-left corner
    glutCreateWindow("CG project - Little Red Hiding Hood");    // Create a window with the given title
    init();

    // Running Scene
    wolfValuey = 1.2f;
    lillaValuey = -0.7f;
    wolfValuex = 0.6f;
    lillaValuex = 0.0f;

    glutIdleFunc(play);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(scene0);                        // Register display
    glutMotionFunc(motion);
    glutReshapeFunc(reshapeFun);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);


    glutMainLoop();                                  // Enter the infinitely event-processing loop
    return 0;
}
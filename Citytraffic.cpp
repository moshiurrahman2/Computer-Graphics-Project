# Computer-Graphics-Project
/*Project: City Traffic

Features & Description:

1.This is a view of  city road, some vehicles,buildings, traffic light, zebra crossing, pedestrian,Airplane
2. Day, Night using keyboard interaction.
3. Moving clouds, birds, airplane manually
4. Moving and controlling vehicles using keyboard interaction.
5. Traffic Signal light controlling  using keyboard interaction
7. Crossing road with zebra_crossing */


#include<windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include<iostream>
#define PI 3.1416

using namespace std;

static float txB=0.0;
static float tyB=0.0;

static float txP=0.0;
static float tyP=0.0;

static float txC=0.0;
static float tyC=0.0;

float txPeo1=0.0;
float txPeo2=0.0;

float txSun=0.0;
float txMoon=0.0;


using namespace std;


float moveBus2_right = -6.0f;
float moveBus_right = -6.0f;
float moveCar5_right = -6.0f;
float moveCar4_right = -6.0f;

float moveCar2_left = 6.0f;
float moveCar3_left = 6.0f;
float moveCar_left= 6.0f;

void move_all()
{
    //all_move
    moveBus_right+= .012;
    moveBus2_right+= .012;
    moveCar4_right += .012;
    moveCar5_right += .012;
    moveCar_left -= .012;
    moveCar2_left -= .012;
    moveCar3_left -= .012;



    if(moveCar4_right>68)
    {
        moveCar4_right=-55.0;
    }
    if(moveCar5_right>70)
    {
        moveCar5_right=-62.0;
    }
    if(moveBus_right>95)
    {
        moveBus_right=-38.0;
    }
    if(moveBus2_right>100)
    {
        moveBus2_right=-18.0;



    }
    glutPostRedisplay();
    if
    (moveCar_left<-55)
    {
        moveCar_left =58.0;
    }

    if(moveCar3_left < -75)
    {
        moveCar3_left =40.0;
    }
    if(moveCar2_left < -85)
    {
        moveCar2_left =42.0;
    }

    glutPostRedisplay();

}

void move_right()
{
    //right_move
    moveBus_right+= .012;
    moveBus2_right+= .012;
    moveCar4_right += .012;
    moveCar5_right += .012;

    if(moveCar4_right>68)
    {
        moveCar4_right=-55.0;
    }
    if(moveCar5_right>70)
    {
        moveCar5_right=-62.0;
    }
    if(moveBus_right>95)
    {
        moveBus_right=-38.0;
    }
    if(moveBus2_right>100)
    {
        moveBus2_right=-18.0;
    }


    glutPostRedisplay();
}

void move_left()
{
    //left_move

    moveCar_left -= .012;
    moveCar2_left -= .012;
    moveCar3_left -= .012;

    if
    (moveCar_left<-55)
    {
        moveCar_left =58.0;
    }

    if(moveCar2_left < -85)
    {
        moveCar2_left =42.0;
    }

    if(moveCar3_left < -75)
    {
        moveCar3_left =40.0;
    }

    glutPostRedisplay();

}

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void sun()
{

    glPushMatrix();

    txSun=txSun+0.008;
    if(txSun>25)
    {
        txSun=25;

    }
    glTranslatef(0,txSun,0);
    glPushMatrix();
    glTranslated(-25,65,0);
    glScaled(0.5,1.5,0);
    glColor3f(10,100,0);
    circle(5,5);
    glPopMatrix();
    glPopMatrix();

}
void moon()
{

    glPushMatrix();

    txMoon=txMoon+0.008;
    if(txMoon>25)
    {
        txMoon=25;

    }
    glTranslatef(0,txMoon,0);
    glPushMatrix();
    glTranslated(-25,65,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,255,255);
    circle(5,5);
    glPopMatrix();
    glPopMatrix();
}

void cloud1()
{
    txC=txC+0.008;
    if(txC>90)
    {
        txC=-30;
    }

    glPushMatrix();
    glTranslated(5,95,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,90,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.0,93,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.0,93,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5.5);
    glPopMatrix();
}
void cloud2()
{
    txC=txC+0.008;
    if(txC>90)
    {
        txC=-30;
    }
    glPushMatrix();
    glTranslated(-40,95,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-40,90,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-41.0,93,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-39.0,93,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5.5);
    glPopMatrix();
}

void cloud3()
{
    txC=txC+0.008;
    if(txC>90)
    {
        txC=-30;
    }
    glPushMatrix();
    glTranslated(40,95,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(40,90,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(41.0,93,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39.0,93,0);
    glScaled(0.5,0.7,0);
    glColor3ub(245,255,250);
    circle(3,5.5);
    glPopMatrix();
}

void Bird1()
{

    txB=txB+0.008;
    if(txB>90)
    {
        txB=-30;
    }

    glLineWidth(5);//UperFan
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-24.5f, 80.0f);
    glVertex2f(-25.0f, 83.0f);
    glEnd();

    glPushMatrix();//Body
    glTranslated(-25,80,0);
    glScaled(0.5,1.5,0);
    glColor3ub(128, 128, 128);
    circle(3,1);
    glPopMatrix();

    glLineWidth(2);//
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-26.0f, 80.0f);
    glVertex2f(-27.0f, 80.0f);
    glEnd();

    glLineWidth(2);//
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-26.0f, 80.0f);
    glVertex2f(-27.0f, 82.0f);
    glEnd();

    glLineWidth(5);//LowerFan
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-24.5f, 80.0f);
    glVertex2f(-25.0f, 78.0f);



    glEnd();

    glPushMatrix();//Head
    glTranslated(-23.3,80,0);
    glScaled(0.5,1.5,0);
    glColor3ub(128, 128, 128);
    circle(0.8,0.8);
    glPopMatrix();

    glBegin(GL_POINTS);
    glColor3ub(0,0,0);
    glVertex2f(-23.2,80.6);
    glEnd();
    glLineWidth(2);//
    glBegin(GL_LINES);
    glColor3ub(204, 204, 0);
    glVertex2f(-23.0f, 80.0f);
    glVertex2f(-22.5f, 80.0f);
    glEnd();
}

void Bird2()
{
    txB=txB+0.008;
    if(txB>90)
    {
        txB=-30;
    }

    glLineWidth(5);//UperFan
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-20.5f, 84.0f);
    glVertex2f(-21.0f, 86.0f);
    glEnd();

    glPushMatrix();//Body
    glTranslated(-21,83,0);
    glScaled(0.5,1.5,0);
    glColor3ub(128, 128, 128);
    circle(3,1);
    glPopMatrix();

    glLineWidth(2);//
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-22.0f, 83.0f);
    glVertex2f(-23.0f, 86.0f);
    glEnd();

    glLineWidth(2);//
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-22.0f, 83.0f);
    glVertex2f(-23.0f, 83.0f);
    glEnd();

    glLineWidth(5);//LowerFan
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-20.5f, 83.0f);
    glVertex2f(-21.0f, 81.0f);



    glEnd();

    glPushMatrix();//Head
    glTranslated(-19.3,83,0);
    glScaled(0.5,1.5,0);
    glColor3ub(128, 128, 128);
    circle(0.8,0.8);
    glPopMatrix();

    glBegin(GL_POINTS);
    glColor3ub(0,0,0);
    glVertex2f(-19.2,83.6);
    glEnd();
    glLineWidth(2);//
    glBegin(GL_LINES);
    glColor3ub(204, 204, 0);
    glVertex2f(-19.0f, 83.0f);
    glVertex2f(-18.5f, 83.0f);
    glEnd();
}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 191, 255);
    glVertex2f(-50.0f, 110.0f);
    glVertex2f(50.0f, 110.0f);

    glVertex2f(50.0f, 25.0f);
    glVertex2f(-50.0f, 25.0f);
    glEnd();
}
void Nightsky()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-50.0f, 110.0f);
    glVertex2f(50.0f, 110.0f);

    glVertex2f(50.0f, 25.0f);
    glVertex2f(-50.0f, 25.0f);
    glEnd();
}



void FirstBuild()
{

    glBegin(GL_POLYGON);
    glColor3ub(218, 65, 147); //side

    glVertex2f(-38.0f, 25.0f);
    glVertex2f(-36.0f, 25.0f);
    glVertex2f(-36.0f, 64.0f);
    glVertex2f(-38.0f, 67.0f);

    glColor3ub(236, 197, 218); //front
    glVertex2f(-38.0f, 67.0f);
    glVertex2f(-45.0f, 67.0f);
    glVertex2f(-45.0f, 25.0f);
    glVertex2f(-38.0f, 25.0f);
    glEnd();
}


void FrstBuildWindow()
{


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //1st window

    glVertex2f(-44.0f, 62.0f);
    glVertex2f(-42.5f, 62.0f);
    glVertex2f(-42.5f, 57.0f);
    glVertex2f(-44.0f, 57.0f);

    glEnd();



    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-41.0f, 62.0f);
    glVertex2f(-39.5f, 62.0f);
    glVertex2f(-39.5f, 57.0f);
    glVertex2f(-41.0f, 57.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //3rd window

    glVertex2f(-44.0f, 51.0f);
    glVertex2f(-42.5f, 51.0f);
    glVertex2f(-42.5f, 46.0f);
    glVertex2f(-44.0f, 46.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-41.0f, 51.0f);
    glVertex2f(-39.5f, 51.0f);
    glVertex2f(-39.5f, 46.0f);
    glVertex2f(-41.0f, 46.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //5th window

    glVertex2f(-44.0f, 40.0f);
    glVertex2f(-42.5f, 40.0f);
    glVertex2f(-42.5f, 35.0f);
    glVertex2f(-44.0f, 35.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(-41.0f, 40.0f);
    glVertex2f(-39.5f, 40.0f);
    glVertex2f(-39.5f, 35.0f);
    glVertex2f(-41.0f, 35.0f);

    glEnd();

}

void SecondBuilding()
{
    glBegin(GL_POLYGON);

    glColor3ub(38, 17, 97);
    glVertex2f(-23.0, 69.0f);
    glVertex2f(-21.0f, 66.0f);
    glVertex2f(-21.0f, 25.0f);
    glVertex2f(-23.0f, 25.0f);

    glColor3ub(191, 185, 208);
    glVertex2f(-23.0f, 25.0f);
    glVertex2f(-30.0f, 25.0f);
    glVertex2f(-30.0f, 69.0f);
    glVertex2f(-23.0f, 69.0f);

    glEnd();
}

void secndBuildWindow()
{

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-29.0f, 63.0f);
    glVertex2f(-27.5f, 63.0f);
    glVertex2f(-27.5f, 58.0f);
    glVertex2f(-29.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-26.0f, 63.0f);
    glVertex2f(-24.5f, 63.0f);
    glVertex2f(-24.5f, 58.0f);
    glVertex2f(-26.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-29.0f, 52.0f);
    glVertex2f(-27.5f, 52.0f);
    glVertex2f(-27.5f, 47.0f);
    glVertex2f(-29.0f, 47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-26.0f, 52.0f);
    glVertex2f(-24.5f, 52.0f);
    glVertex2f(-24.5f, 47.0f);
    glVertex2f(-26.0f, 47.0f);
    glEnd();
}

void thrdBuilding()
{

    glBegin(GL_POLYGON);

    glColor3ub(135, 73, 19);
    glVertex2f(-10.0, 75.0f);
    glVertex2f(-8.0f, 72.0f);
    glVertex2f(-8.0f, 25.0f);
    glVertex2f(-10.0f, 25.0f);

    glColor3ub(205, 146, 94);
    glVertex2f(-10.0f, 25.0f);
    glVertex2f(-17.0f, 25.0f);
    glVertex2f(-17.0f, 75.0f);
    glVertex2f(-10.0f, 75.0f);

    glEnd();


}

void thirdBildWindow()
{


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-16.0f, 63.0f);
    glVertex2f(-14.5f, 63.0f);
    glVertex2f(-14.5f, 58.0f);
    glVertex2f(-16.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-13.0f, 63.0f);
    glVertex2f(-11.5f, 63.0f);
    glVertex2f(-11.5f, 58.0f);
    glVertex2f(-13.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-16.0f, 52.0f);
    glVertex2f(-14.5f, 52.0f);
    glVertex2f(-14.5f, 47.0f);
    glVertex2f(-16.0f, 47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-13.0f, 52.0f);
    glVertex2f(-11.5f, 52.0f);
    glVertex2f(-11.5f, 47.0f);
    glVertex2f(-13.0f, 47.0f);
    glEnd();


}
void FrthBuilding()
{

    glBegin(GL_POLYGON);
    glColor3ub(29,122,97);

    glVertex2f(3.0, 80.0f);
    glVertex2f(5.0f, 77.0f);
    glVertex2f(5.0f, 25.0f);
    glVertex2f(3.0f, 25.0f);

    glColor3ub(108,220,190);
    glVertex2f(3.0f, 25.0f);
    glVertex2f(-4.0f, 25.0f);
    glVertex2f(-4.0f, 80.0f);
    glVertex2f(3.0f, 80.0f);

    glEnd();

}

void frthBuildingWindow()
{


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-3.0f, 78.0f);
    glVertex2f(-1.5f, 78.0f);
    glVertex2f(-1.5f, 73.0f);
    glVertex2f(-3.0f, 73.0f);
    glEnd();
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(0.0f, 78.0f);
    glVertex2f(1.5f, 78.0f);
    glVertex2f(1.5f, 73.0f);
    glVertex2f(0.0f, 73.0f);
    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-3.0f, 68.0f);
    glVertex2f(-1.5f, 68.0f);
    glVertex2f(-1.5f, 63.0f);
    glVertex2f(-3.0f, 63.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(0.0f, 68.0f);
    glVertex2f(1.5f, 68.0f);
    glVertex2f(1.5f, 63.0f);
    glVertex2f(0.0f, 63.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(-3.0f, 57.0f);
    glVertex2f(-1.5f, 57.0f);
    glVertex2f(-1.5f, 52.0f);
    glVertex2f(-3.0f, 52.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(0.0f, 57.0f);
    glVertex2f(1.5f, 57.0f);
    glVertex2f(1.5f, 52.0f);
    glVertex2f(0.0f, 52.0f);
    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //7th window

    glVertex2f(-3.0f, 47.0f);
    glVertex2f(-1.5f, 47.0f);
    glVertex2f(-1.5f, 42.5f);
    glVertex2f(-3.0f, 42.5f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //8th window

    glVertex2f(0.0f, 47.0f);
    glVertex2f(1.5f, 47.0f);
    glVertex2f(1.5f, 42.5f);
    glVertex2f(0.0f, 42.5f);
    glEnd();

}

void fthBuilding()
{
    glBegin(GL_POLYGON);
    glColor3ub(148,35,23);

    glVertex2f(16.0, 77.0f);
    glVertex2f(18.0f, 74.0f);
    glVertex2f(18.0f, 25.0f);
    glVertex2f(16.0f, 25.0f);
    glColor3ub(218,101,88);
    glVertex2f(16.0f, 25.0f);
    glVertex2f(9.0f, 25.0f);
    glVertex2f(9.0f, 77.0f);
    glVertex2f(16.0f, 77.0f);

    glEnd();

}

void fthBuildingWindow()
{

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(10.0f, 68.0f);
    glVertex2f(11.5f, 68.0f);
    glVertex2f(11.5f, 63.0f);
    glVertex2f(10.0f, 63.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(13.0f, 68.0f);
    glVertex2f(14.5f, 68.0f);
    glVertex2f(14.5f, 63.0f);
    glVertex2f(13.0f, 63.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(10.0f, 57.0f);
    glVertex2f(11.5f, 57.0f);
    glVertex2f(11.5f, 52.0f);
    glVertex2f(10.0f, 52.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(13.0f, 57.0f);
    glVertex2f(14.5f, 57.0f);
    glVertex2f(14.5f, 52.0f);
    glVertex2f(13.0f, 52.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(10.0f, 47.0f);
    glVertex2f(11.5f, 47.0f);
    glVertex2f(11.5f, 42.5f);
    glVertex2f(10.0f, 42.5f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(13.0f, 47.0f);
    glVertex2f(14.5f, 47.0f);
    glVertex2f(14.5f, 42.5f);
    glVertex2f(13.0f, 42.5f);
    glEnd();

}

void SixBuilding()
{

    glBegin(GL_POLYGON);
    glColor3ub(128,128,128);

    glVertex2f(29.0, 73.0f);
    glVertex2f(31.0f, 70.0f);
    glVertex2f(31.0f, 25.0f);
    glVertex2f(29.0f, 25.0f);

    glColor3ub(192,192,192);
    glVertex2f(29.0f, 25.0f);
    glVertex2f(22.0f, 25.0f);
    glVertex2f(22.0f, 73.0f);
    glVertex2f(29.0f, 73.0f);

    glEnd();


}

void SxthBuildingWindow()
{


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(23.0f, 71.0f);
    glVertex2f(24.5f, 71.0f);
    glVertex2f(24.5f, 66.0f);
    glVertex2f(23.0f, 66.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(26.0f, 71.0f);
    glVertex2f(27.5f, 71.0f);
    glVertex2f(27.5f, 66.0f);
    glVertex2f(26.0f, 66.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(23.0f, 60.0f);
    glVertex2f(24.5f, 60.0f);
    glVertex2f(24.5f, 55.0f);
    glVertex2f(23.0f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(26.0f, 60.0f);
    glVertex2f(27.5f, 60.0f);
    glVertex2f(27.5f, 55.0f);
    glVertex2f(26.0f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(23.0f, 49.0f);
    glVertex2f(24.5f, 49.0f);
    glVertex2f(24.5f, 44.0f);
    glVertex2f(23.0f, 44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(26.0f, 49.0f);
    glVertex2f(27.5f, 49.0f);
    glVertex2f(27.5f, 44.0f);
    glVertex2f(26.0f, 44.0f);
    glEnd();
}

void sevenBuilding()
{

    glBegin(GL_POLYGON);
    glColor3ub(153,153,0);

    glVertex2f(41.0, 70.0f);
    glVertex2f(43.0f, 67.0f);
    glVertex2f(43.0f, 25.0f);
    glVertex2f(41.0f, 25.0f);
    glColor3ub(204,204,0);
    glVertex2f(41.0f, 25.0f);
    glVertex2f(34.0f, 25.0f);
    glVertex2f(34.0f, 70.0f);
    glVertex2f(41.0f, 70.0f);

    glEnd();

}

void sevenBuildingWindow()
{

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(35.0f, 63.0f);
    glVertex2f(36.5f, 63.0f);
    glVertex2f(36.5f, 58.0f);
    glVertex2f(35.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(38.0f, 63.0f);
    glVertex2f(39.5f, 63.0f);
    glVertex2f(39.5f, 58.0f);
    glVertex2f(38.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(35.0f, 52.0f);
    glVertex2f(36.5f, 52.0f);
    glVertex2f(36.5f, 47.0f);
    glVertex2f(35.0f, 47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(38.0f, 52.0f);
    glVertex2f(39.5f, 52.0f);
    glVertex2f(39.5f, 47.0f);
    glVertex2f(38.0f, 47.0f);
    glEnd();



}



void FrstBuildWindowN()
{
    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);  //1st window

    glVertex2f(-44.0f, 73.0f);
    glVertex2f(-42.5f, 73.0f);
    glVertex2f(-42.5f, 68.0f);
    glVertex2f(-44.0f, 68.0f);

    glEnd();



    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //2nd window

    glVertex2f(-41.0f, 73.0f);
    glVertex2f(-39.5f, 73.0f);
    glVertex2f(-39.5f, 68.0f);
    glVertex2f(-41.0f, 68.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);  //3rd window

    glVertex2f(-44.0f, 62.0f);
    glVertex2f(-42.5f, 62.0f);
    glVertex2f(-42.5f, 57.0f);
    glVertex2f(-44.0f, 57.0f);

    glEnd();



    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);  //4rth window

    glVertex2f(-41.0f, 62.0f);
    glVertex2f(-39.5f, 62.0f);
    glVertex2f(-39.5f, 57.0f);
    glVertex2f(-41.0f, 57.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);  //5th window

    glVertex2f(-44.0f, 51.0f);
    glVertex2f(-42.5f, 51.0f);
    glVertex2f(-42.5f, 46.0f);
    glVertex2f(-44.0f, 46.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);
    glVertex2f(-41.0f, 51.0f);
    glVertex2f(-39.5f, 51.0f);
    glVertex2f(-39.5f, 46.0f);
    glVertex2f(-41.0f, 46.0f);

    glEnd();

}


void secndBuildWindowN()
{

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //1st window

    glVertex2f(-29.0f, 75.0f);
    glVertex2f(-27.5f, 75.0f);
    glVertex2f(-27.5f, 70.0f);
    glVertex2f(-29.0f, 70.0f);
    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //2nd window

    glVertex2f(-26.0f, 75.0f);
    glVertex2f(-24.5f, 75.0f);
    glVertex2f(-24.5f, 70.0f);
    glVertex2f(-26.0f, 70.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //3rd window

    glVertex2f(-29.0f, 63.0f);
    glVertex2f(-27.5f, 63.0f);
    glVertex2f(-27.5f, 58.0f);
    glVertex2f(-29.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //4th window

    glVertex2f(-26.0f, 63.0f);
    glVertex2f(-24.5f, 63.0f);
    glVertex2f(-24.5f, 58.0f);
    glVertex2f(-26.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //5th window

    glVertex2f(-29.0f, 52.0f);
    glVertex2f(-27.5f, 52.0f);
    glVertex2f(-27.5f, 47.0f);
    glVertex2f(-29.0f, 47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //6th window

    glVertex2f(-26.0f, 52.0f);
    glVertex2f(-24.5f, 52.0f);
    glVertex2f(-24.5f, 47.0f);
    glVertex2f(-26.0f, 47.0f);
    glEnd();
}



void thirdBildWindowN()
{

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //1st window

    glVertex2f(-16.0f, 75.0f);
    glVertex2f(-14.5f, 75.0f);
    glVertex2f(-14.5f, 70.0f);
    glVertex2f(-16.0f, 70.0f);
    glEnd();
    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //2nd window

    glVertex2f(-13.0f, 75.0f);
    glVertex2f(-11.5f, 75.0f);
    glVertex2f(-11.5f, 70.0f);
    glVertex2f(-13.0f, 70.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //3rd window

    glVertex2f(-16.0f, 63.0f);
    glVertex2f(-14.5f, 63.0f);
    glVertex2f(-14.5f, 58.0f);
    glVertex2f(-16.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //4th window

    glVertex2f(-13.0f, 63.0f);
    glVertex2f(-11.5f, 63.0f);
    glVertex2f(-11.5f, 58.0f);
    glVertex2f(-13.0f, 58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //5th window

    glVertex2f(-16.0f, 52.0f);
    glVertex2f(-14.5f, 52.0f);
    glVertex2f(-14.5f, 47.0f);
    glVertex2f(-16.0f, 47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(243, 243, 57);   //6th window

    glVertex2f(-13.0f, 52.0f);
    glVertex2f(-11.5f, 52.0f);
    glVertex2f(-11.5f, 47.0f);
    glVertex2f(-13.0f, 47.0f);
    glEnd();


}

void AirPlane()
{
    txP=txP+0.05;
    if(txP>90)
    {
        txP=-100;
    }
    glBegin(GL_QUADS);//upper Side

    glColor3ub(0,76,153);


    glVertex2f(34.0f,93.0f);
    glVertex2f(32.0f,93.0f);
    glVertex2f(30.0f,100.0f);
    glVertex2f(32.0f,100.0f);

    glEnd();

    glBegin(GL_QUADS);//Body

    glColor3ub(96,96,96);

    glVertex2f(26.0f,87.0f);
    glVertex2f(37.0f,87.0f);
    glVertex2f(37.0f,95.0f);
    glVertex2f(26.0f,95.0f);
    glEnd();
    glLineWidth(4);

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(31.0f, 91.0f);
    glVertex2f(31.0f, 92.5f);
    glEnd();

    glLineWidth(4);

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(33.0f, 91.0f);
    glVertex2f(33.0f, 92.5f);
    glEnd();

    glLineWidth(4);

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(35.0f, 91.0f);
    glVertex2f(35.0f, 92.5f);
    glEnd();


    glBegin(GL_QUADS);//Front

    glColor3ub(96,96,96);

    glVertex2f(37.0f,87.0f);
    glVertex2f(40.0f,88.0f);
    glVertex2f(40.0f,92.0f);
    glVertex2f(37.0f,95.0f);
    glEnd();
    glLineWidth(4);

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(37.5f, 92.0f);
    glVertex2f(38.5f, 92.0f);
    glEnd();


    glBegin(GL_QUADS);//Back
    glColor3ub(0,76,153);

    glVertex2f(26.0f,94.0f);
    glVertex2f(28.0f,94.0f);
    glVertex2f(27.0f,103.0f);
    glVertex2f(26.0f,103.0f);

    glEnd();

    glBegin(GL_QUADS);//Lower Side

    glColor3ub(0,76,153);

    glVertex2f(30.0f,83.0f);
    glVertex2f(32.0f,83.0f);
    glVertex2f(34.0f,90.0f);
    glVertex2f(32.0f,90.0f);

    glEnd();
}

void middle()
{
    glBegin(GL_POLYGON);
    glColor3ub(135, 73, 19);

    glVertex2f(-40.0f, -110.0f); //side
    glVertex2f(-38.0f, -110.0f);
    glVertex2f(-38.0f, -37.0f);
    glVertex2f(-40.0f, -34.0f);

    glColor3ub(205, 146, 94);//front

    glVertex2f(-40.0f, -34.0f);
    glVertex2f(-47.0f, -34.0f);
    glVertex2f(-47.0f, -90.0f);
    glVertex2f(-40.0f, -90.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(29,122,97);

    glVertex2f(-28.0f, -110.0f); //side
    glVertex2f(-26.0f, -110.0f);
    glVertex2f(-26.0f, -34.0f);
    glVertex2f(-28.0f, -31.0f);

    glColor3ub(108,220,190);//front

    glVertex2f(-28.0f, -31.0f);
    glVertex2f(-35.0f, -31.0f);
    glVertex2f(-35.0f, -90.0f);
    glVertex2f(-28.0f, -90.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 17, 97);
    glVertex2f(28.0f, -110.0f); //side
    glVertex2f(26.0f, -110.0f);
    glVertex2f(26.0f, -34.0f);
    glVertex2f(28.0f, -31.0f);

    glColor3ub(191, 185, 208);//front

    glVertex2f(28.0f, -31.0f);
    glVertex2f(35.0f, -31.0f);
    glVertex2f(35.0f, -90.0f);
    glVertex2f(28.0f, -90.0f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(148,35,23);

    glVertex2f(40.0f, -110.0f); //side
    glVertex2f(38.0f, -110.0f);
    glVertex2f(38.0f, -37.0f);
    glVertex2f(40.0f, -34.0f);

    glColor3ub(218,101,88);//front

    glVertex2f(40.0f, -34.0f);
    glVertex2f(47.0f, -34.0f);
    glVertex2f(47.0f, -90.0f);
    glVertex2f(40.0f, -90.0f);
    glEnd();


//window

    glBegin(GL_POLYGON);
    glColor3ub(243, 243, 57);

    glVertex2f(-45.0f, -37.0f);
    glVertex2f(-43.0f, -39.0f);
    glVertex2f(-43.0f, -39.0f);
    glVertex2f(-45.0f, -37.0f);
    glEnd();


//Field





//road

    glBegin(GL_POLYGON);
    glColor3ub(128,128,128);
    glVertex2f(-100.0f, -20.0f);
    glVertex2f(-3.0f, -20.0f);
    glVertex2f(-1.0f, 17.00f);
    glVertex2f(-100.0f, 17.00f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(128,128,128);
    glVertex2f(100.0f, -20.0f);
    glVertex2f(3.0f, -20.0f);
    glVertex2f(1.0f, 17.0f);
    glVertex2f(100.0f, 17.0f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-100.0f, 2.0f);
    glVertex2f(-1.5f, 2.0f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(100.0f, 2.0f);
    glVertex2f(1.5f, 2.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,128,128);
    glVertex2f(-100.0f, 25.0f);
    glVertex2f(-100.0f, 17.0f);
    glVertex2f(100.0f, 17.0f);
    glVertex2f(100.0f, 25.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,128,128);
    glVertex2f(-100.0f, -20.0f);
    glVertex2f(-100.0f, -30.0f);
    glVertex2f(100.0f, -30.0f);
    glVertex2f(100.0f, -20.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
//Middle Road
    glVertex2f(1.0f, 17.0f);
    glVertex2f(-1.0f, 17.0f);
    glVertex2f(-3.0f, -20.0f);
    glVertex2f(3.0f, -20.0f);
    glEnd();
    glLineWidth(5.0); //Zebra Road 1st
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(1.1f, 15.0f);
    glVertex2f(-1.1f, 15.0f);
    glEnd();
    glLineWidth(6.0); //Zebra Road 2nd
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(1.3f, 12.0f);
    glVertex2f(-1.3f, 12.0f);
    glEnd();
    glLineWidth(7.0); //Zebra Road 3rd
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(1.5f, 8.5f);
    glVertex2f(-1.5f, 8.5f);
    glEnd();
    glLineWidth(8.0); //Zebra Road 4th
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(1.7f, 4.5f);
    glVertex2f(-1.7f, 4.5f);
    glEnd();
    glLineWidth(9.0); //Zebra Road 5th
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(1.9f, -1.0f);
    glVertex2f(-1.9f, -1.0f);
    glEnd();
    glLineWidth(10.0); //Zebra Road 6th
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(2.1f, -6.0f);
    glVertex2f(-2.1f, -6.0f);
    glEnd();
    glLineWidth(11.0); //Zebra Road 7th
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(2.5f, -12.0f);
    glVertex2f(-2.5f, -12.0f);
    glEnd();
    glLineWidth(12.0); //Zebra Road 8th
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(2.8f, -18.0f);
    glVertex2f(-2.8f, -18.0f);
    glEnd();
//Under Background
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2f(-55.0f, -28.0f);
    glVertex2f(-55.0f, -110.0f);
    glVertex2f(55.0f, -110.0f);
    glVertex2f(55.0f, -28.0f);
    glEnd();



    //eleventh Building
    glBegin(GL_POLYGON);
    glColor3ub(236, 197, 218); //front

    glVertex2f(3.0f, 25.0f);
    glVertex2f(3.0f, 77.0f);
    glVertex2f(8.5f, 77.0f);
    glVertex2f(8.5f, 25.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(221,160,221); //side

    glVertex2f(8.5f, 25.0f);
    glVertex2f(8.5f, 77.0f);
    glVertex2f(9.0f, 74.0f);
    glVertex2f(9.0f, 25.0f);

    glEnd();

    //twelve Building
    glBegin(GL_POLYGON);
    glColor3ub(191, 185, 208); //front

    glVertex2f(22.0f, 25.0f);
    glVertex2f(22.0, 72.0f);
    glVertex2f(16.5f, 72.0f);
    glVertex2f(16.5f, 25.0f);

    glEnd();

    //thirteen Building
    glBegin(GL_POLYGON);
    glColor3ub(205, 146, 94);//front

    glVertex2f(29.5f, 69.0f);
    glVertex2f(29.5f, 25.0f);
    glVertex2f(34.0f, 25.0f);
    glVertex2f(34.0f, 69.0f);
    glEnd();

    //fourteenth Building
    glBegin(GL_POLYGON);
    glColor3ub(236, 197, 218);//front

    glVertex2f(41.5f, 65.0f);
    glVertex2f(41.5f, 25.0f);
    glVertex2f(48.5f, 25.0f);
    glVertex2f(48.5f, 65.0f);
    glEnd();

    //Under First Building
    glBegin(GL_POLYGON);
    glColor3ub(191, 185, 208); //side

    glVertex2f(-46.0f, -110.0f);
    glVertex2f(-45.0f, -105.0f);
    glVertex2f(-45.0f, -23.0f);
    glVertex2f(-46.0f, -27.0f);

    glColor3ub(230, 230, 250); //front
    glVertex2f(-46.0f, -110.0f);
    glVertex2f(-55.0f, -110.0f);
    glVertex2f(-55.0f, -27.0f);
    glVertex2f(-46.0f, -27.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(216,191,216); //Rooftop
    glVertex2f(-55.0f, -27.0f);
    glVertex2f(-46.0f, -27.0f);
    glVertex2f(-45.0f, -23.0f);
    glVertex2f(-54.0f, -23.0f);

    glEnd();

    //Under First Building Window

    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-51.0f, -37.0f);
    glVertex2f(-49.5f, -37.0f);
    glVertex2f(-49.5f, -33.0f);
    glVertex2f(-51.0f, -33.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);  //2nd window

    glVertex2f(-48.5f, -37.0f);
    glVertex2f(-47.0f, -37.0f);
    glVertex2f(-47.0f, -33.0f);
    glVertex2f(-48.5f, -33.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-51.0f, -43.0f);
    glVertex2f(-49.5f, -43.0f);
    glVertex2f(-49.5f, -47.0f);
    glVertex2f(-51.0f, -47.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //4th window

    glVertex2f(-48.5f, -43.0f);
    glVertex2f(-47.0f, -43.0f);
    glVertex2f(-47.0f, -47.0f);
    glVertex2f(-48.5f, -47.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);  //5th window

    glVertex2f(-48.5f, -53.0f);
    glVertex2f(-47.0f, -53.0f);
    glVertex2f(-47.0f, -57.0f);
    glVertex2f(-48.5f, -57.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(-51.0f, -53.0f);
    glVertex2f(-49.5f, -53.0f);
    glVertex2f(-49.5f, -57.0f);
    glVertex2f(-51.0f, -57.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //7th window

    glVertex2f(-51.0f, -63.0f);
    glVertex2f(-49.5f, -63.0f);
    glVertex2f(-49.5f, -67.0f);
    glVertex2f(-51.0f, -67.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //8th window

    glVertex2f(-48.5f, -63.0f);
    glVertex2f(-47.0f, -63.0f);
    glVertex2f(-47.0f, -67.0f);
    glVertex2f(-48.5f, -67.0f);

    glEnd();

    //Under Second Building
    glBegin(GL_POLYGON);
    glColor3ub(153,153,0); //side

    glVertex2f(-38.0f, -30.0f);
    glVertex2f(-36.0f, -25.0f);
    glVertex2f(-36.0f, -107.0f);
    glVertex2f(-38.0f, -110.0f);

    glColor3ub(204,204,0); //front
    glVertex2f(-38.0f, -110.0f);
    glVertex2f(-45.0f, -110.0f);
    glVertex2f(-45.0f,-30.0f);
    glVertex2f(-38.0f, -30.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(189,183,107); //Rooftop
    glVertex2f(-45.0f, -30.0f);
    glVertex2f(-44.0f, -25.0f);
    glVertex2f(-36.0f, -25.0f);
    glVertex2f(-38.0f, -30.0f);

    glEnd();

    //Under Second Building Window

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //1st window

    glVertex2f(-44.0f, -40.0f);
    glVertex2f(-42.5f, -40.0f);
    glVertex2f(-42.5f, -35.0f);
    glVertex2f(-44.0f, -35.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-41.0f, -40.0f);
    glVertex2f(-39.5f, -40.0f);
    glVertex2f(-39.5f, -35.0f);
    glVertex2f(-41.0f, -35.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //3rd window

    glVertex2f(-44.0f, -51.0f);
    glVertex2f(-42.5f, -51.0f);
    glVertex2f(-42.5f, -46.0f);
    glVertex2f(-44.0f, -46.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-41.0f, -51.0f);
    glVertex2f(-39.5f, -51.0f);
    glVertex2f(-39.5f, -46.0f);
    glVertex2f(-41.0f, -46.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-41.0f, 40.0f);
    glVertex2f(-39.5f, 40.0f);
    glVertex2f(-39.5f, 35.0f);
    glVertex2f(-41.0f, 35.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(-41.0f, -62.0f);
    glVertex2f(-39.5f, -62.0f);
    glVertex2f(-39.5f, -57.0f);
    glVertex2f(-41.0f, -57.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);  //6th window

    glVertex2f(-44.0f, -62.0f);
    glVertex2f(-42.5f, -62.0f);
    glVertex2f(-42.5f, -57.0f);
    glVertex2f(-44.0f, -57.0f);
    glEnd();

    //Under Third Building
    glBegin(GL_POLYGON);
    glColor3ub(148,35,23);

    glVertex2f(-30.0f, -32.0f); //side
    glVertex2f(-28.0f, -28.0f);
    glVertex2f(-28.0f, -107.0f);
    glVertex2f(-30.0f, -110.0f);

    glColor3ub(218,101,88);

    glVertex2f(-37.0f, -32.0f); //front
    glVertex2f(-37.0f, -110.0f);
    glVertex2f(-30.0f, -110.0f);
    glVertex2f(-30.0f, -32.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(165,42,42); //Rooftop
    glVertex2f(-37.0f, -32.0f);
    glVertex2f(-35.5f, -28.0f);
    glVertex2f(-28.0f, -28.0f);
    glVertex2f(-29.0f, -32.0f);

    glEnd();

    //Under Third Building Window
    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-34.0f, -39.0f);
    glVertex2f(-35.5f, -39.0f);
    glVertex2f(-35.5f, -34.0f);
    glVertex2f(-34.0f, -34.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-31.0f, -39.0f);
    glVertex2f(-32.5f, -39.0f);
    glVertex2f(-32.5f, -34.0f);
    glVertex2f(-31.0f, -34.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-34.0f, -49.0f);
    glVertex2f(-35.5f, -49.0f);
    glVertex2f(-35.5f, -44.0f);
    glVertex2f(-34.0f, -44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-31.0f, -49.0f);
    glVertex2f(-32.5f, -49.0f);
    glVertex2f(-32.5f, -44.0f);
    glVertex2f(-31.0f, -44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(-34.0f, -60.0f);
    glVertex2f(-35.5f, -60.0f);
    glVertex2f(-35.5f, -55.0f);
    glVertex2f(-34.0f, -55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(-31.0f, -60.0f);
    glVertex2f(-32.5f, -60.0f);
    glVertex2f(-32.5f, -55.0f);
    glVertex2f(-31.0f, -55.0f);
    glEnd();


    //Under Fourth building
    glBegin(GL_POLYGON);

    glColor3ub(128,128,128); // side
    glVertex2f(-23.0, -100.0f);
    glVertex2f(-21.0f, -97.0f);
    glVertex2f(-21.0f, -27.0f);
    glVertex2f(-23.0f, -33.0f);

    glColor3ub(192,192,192); // front
    glVertex2f(-23.0f, -33.0f);
    glVertex2f(-30.0f, -33.0f);
    glVertex2f(-30.0f, -100.0f);
    glVertex2f(-23.0f, -100.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(169,169,169); //Rooftop
    glVertex2f(-30.0f, -33.0f);
    glVertex2f(-28.5f, -27.0f);
    glVertex2f(-21.0f, -27.0f);
    glVertex2f(-23.0f, -33.0f);

    glEnd();

    //Under Fourth Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-29.0f, -41.0f);
    glVertex2f(-27.5f, -41.0f);
    glVertex2f(-27.5f, -36.0f);
    glVertex2f(-29.0f, -36.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-26.0f, -41.0f);
    glVertex2f(-24.5f, -41.0f);
    glVertex2f(-24.5f, -36.0f);
    glVertex2f(-26.0f, -36.0f);
    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-29.0f, -52.0f);
    glVertex2f(-27.5f, -52.0f);
    glVertex2f(-27.5f, -47.0f);
    glVertex2f(-29.0f, -47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-26.0f, -52.0f);
    glVertex2f(-24.5f, -52.0f);
    glVertex2f(-24.5f, -47.0f);
    glVertex2f(-26.0f, -47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(-29.0f, -63.0f);
    glVertex2f(-27.5f, -63.0f);
    glVertex2f(-27.5f, -58.0f);
    glVertex2f(-29.0f, -58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(-26.0f, -63.0f);
    glVertex2f(-24.5f, -63.0f);
    glVertex2f(-24.5f, -58.0f);
    glVertex2f(-26.0f, -58.0f);
    glEnd();

    //Under Fifth building
    glBegin(GL_POLYGON);
    glColor3ub(38, 17, 97);

    glVertex2f(28.0, -100.0f); //side
    glVertex2f(30.0f, -97.0f);
    glVertex2f(30.0f, -26.0f);
    glVertex2f(28.0f, -30.0f);

    glColor3ub(191, 185, 208);
    glVertex2f(28.0f, -30.0f); // front
    glVertex2f(21.0f, -30.0f);
    glVertex2f(21.0f, -100.0f);
    glVertex2f(28.0f, -100.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,61,139);
    glVertex2f(28.0f, -30.0f); //Rooftop
    glVertex2f(21.0f, -30.0f);
    glVertex2f(22.0f, -26.0f);
    glVertex2f(30.0f, -26.0f);

    glEnd();

    //Under Fifth Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(22.3f, -38.0f);
    glVertex2f(23.8f, -38.0f);
    glVertex2f(23.8f, -33.0f);
    glVertex2f(22.3f, -33.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(25.5f, -38.0f);
    glVertex2f(27.0f, -38.0f);
    glVertex2f(27.0f, -33.0f);
    glVertex2f(25.5f, -33.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(22.3f, -49.0f);
    glVertex2f(23.8f, -49.0f);
    glVertex2f(23.8f, -44.0f);
    glVertex2f(22.3f, -44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(25.5f, -49.0f);
    glVertex2f(27.0f, -49.0f);
    glVertex2f(27.0f, -44.0f);
    glVertex2f(25.5f, -44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(22.3f, -60.0f);
    glVertex2f(23.8f, -60.0f);
    glVertex2f(23.8f, -55.0f);
    glVertex2f(22.3f, -55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(25.5f, -60.0f);
    glVertex2f(27.0f, -60.0f);
    glVertex2f(27.0f, -55.0f);
    glVertex2f(25.5f, -55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //7th window

    glVertex2f(22.3f, -71.0f);
    glVertex2f(23.8f, -71.0f);
    glVertex2f(23.8f, -66.0f);
    glVertex2f(22.3f, -66.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //8th window

    glVertex2f(25.5f, -71.0f);
    glVertex2f(27.0f, -71.0f);
    glVertex2f(27.0f, -66.0f);
    glVertex2f(25.5f, -66.0f);
    glEnd();


    //Under Sixth Building
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glColor3ub(205, 146, 94);//front

    glVertex2f(28.7f, -110.0f);
    glVertex2f(28.7f, -30.0f);
    glVertex2f(34.0f, -30.0f);
    glVertex2f(34.0f, -110.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,133,63);
    glVertex2f(28.7f, -30.0f); //Rooftop
    glVertex2f(34.0f, -30.0f);
    glVertex2f(36.0f, -27.0f);
    glVertex2f(30.7f, -27.0f);

    glEnd();

    //Under Sixth Building Window

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(29.5f, -42.0f);
    glVertex2f(31.0f, -42.0f);
    glVertex2f(31.0f, -37.0f);
    glVertex2f(29.5f, -37.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(32.1f, -42.0f);
    glVertex2f(33.6f, -42.0f);
    glVertex2f(33.6f, -37.0f);
    glVertex2f(32.1f, -37.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(29.5f, -53.0f);
    glVertex2f(31.0f, -53.0f);
    glVertex2f(31.0f, -48.0f);
    glVertex2f(29.5f, -48.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(32.1f, -53.0f);
    glVertex2f(33.6f, -53.0f);
    glVertex2f(33.6f, -48.0f);
    glVertex2f(32.1f, -48.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(29.5f, -64.0f);
    glVertex2f(31.0f, -64.0f);
    glVertex2f(31.0f, -59.0f);
    glVertex2f(29.5f, -59.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(32.1f, -64.0f);
    glVertex2f(33.6f, -64.0f);
    glVertex2f(33.6f, -59.0f);
    glVertex2f(32.1f, -59.0f);
    glEnd();

    //Under Seventh Building
    glBegin(GL_POLYGON);

    glColor3ub(218, 65, 147);
    glVertex2f(41.0, -110.0f); //side
    glVertex2f(43.0f, -107.0f);
    glVertex2f(43.0f, -26.0f);
    glVertex2f(41.0f, -30.0f);

    glColor3ub(236, 197, 218);
    glVertex2f(41.0f, -30.0f); //front
    glVertex2f(34.0f, -30.0f);
    glVertex2f(34.0f, -110.0f);
    glVertex2f(41.0f, -110.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(219,112,147);
    glVertex2f(34.0f, -30.0f); //Rooftop
    glVertex2f(41.0f, -30.0f);
    glVertex2f(43.0f, -26.0f);
    glVertex2f(36.0f, -26.0f);

    glEnd();

    //Under Seventh Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(35.0f, -41.0f);
    glVertex2f(36.5f, -41.0f);
    glVertex2f(36.5f, -36.0f);
    glVertex2f(35.0f, -36.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(38.0f, -41.0f);
    glVertex2f(39.5f, -41.0f);
    glVertex2f(39.5f, -36.0f);
    glVertex2f(38.0f, -36.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(35.0f, -52.0f);
    glVertex2f(36.5f, -52.0f);
    glVertex2f(36.5f, -47.0f);
    glVertex2f(35.0f, -47.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(38.0f, -52.0f);
    glVertex2f(39.5f, -52.0f);
    glVertex2f(39.5f, -47.0f);
    glVertex2f(38.0f, -47.0f);
    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(35.0f, -63.0f);
    glVertex2f(36.5f, -63.0f);
    glVertex2f(36.5f, -58.0f);
    glVertex2f(35.0f, -58.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(38.0f, -63.0f);
    glVertex2f(39.5f, -63.0f);
    glVertex2f(39.5f, -58.0f);
    glVertex2f(38.0f, -58.0f);
    glEnd();


    //Under Eighth Building
    glBegin(GL_POLYGON);

    glColor3ub(0,128,128); //side
    glVertex2f(48.0f, -32.0f);
    glVertex2f(50.0f, -26.0f);
    glVertex2f(50.0f, -107.0f);
    glVertex2f(48.0f, -110.0f);

    glColor3ub(108,220,190);//front
    glVertex2f(41.5f, -110.0f);
    glVertex2f(41.5f, -32.0f);
    glVertex2f(47.9f, -32.0f);
    glVertex2f(47.9f, -110.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(32,178,170);
    glVertex2f(41.5f, -32.0f); //Rooftop
    glVertex2f(48.0f, -32.0f);
    glVertex2f(50.0f, -26.0f);
    glVertex2f(43.5f, -26.0f);

    glEnd();

    //Under Eighth Building Window

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(42.5f, -39.0f);
    glVertex2f(44.0f, -39.0f);
    glVertex2f(44.0f, -34.0f);
    glVertex2f(42.5f, -34.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(45.5f, -39.0f);
    glVertex2f(47.0f, -39.0f);
    glVertex2f(47.0f, -34.0f);
    glVertex2f(45.5f, -34.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(42.5f, -50.0f);
    glVertex2f(44.0f, -50.0f);
    glVertex2f(44.0f, -45.0f);
    glVertex2f(42.5f, -45.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(45.5f, -50.0f);
    glVertex2f(47.0f, -50.0f);
    glVertex2f(47.0f, -45.0f);
    glVertex2f(45.5f, -45.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(42.5f, -61.0f);
    glVertex2f(44.0f, -61.0f);
    glVertex2f(44.0f, -56.0f);
    glVertex2f(42.5f, -56.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(45.5f, -61.0f);
    glVertex2f(47.0f, -61.0f);
    glVertex2f(47.0f, -56.0f);
    glVertex2f(45.5f, -56.0f);
    glEnd();

    //Field
    glBegin(GL_POLYGON);

    glColor3ub(29,122,97);

    glVertex2f(-20.95f, -97.0f);
    glVertex2f(20.95f, -97.0f);
    glVertex2f(19.8f, -28.0f);
    glVertex2f(-19.8f, -28.0f);
    glEnd();

    //Field Rooftop

    glBegin(GL_POLYGON);

    glColor3ub(169,169,169);

    glVertex2f(-21.5f, -38.0f);
    glVertex2f(21.0f, -38.0f);
    glVertex2f(20.0f, -28.0f);
    glVertex2f(-20.0f, -28.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-18.5f, -38.0f);
    glVertex2f(-17.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-15.5f, -38.0f);
    glVertex2f(-14.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-12.5f, -38.0f);
    glVertex2f(-11.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-9.5f, -38.0f);
    glVertex2f(-8.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-6.5f, -38.0f);
    glVertex2f(-5.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-3.5f, -38.0f);
    glVertex2f(-2.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-0.5f, -38.0f);
    glVertex2f(1.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(2.5f, -38.0f);
    glVertex2f(4.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(5.5f, -38.0f);
    glVertex2f(7.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(8.5f, -38.0f);
    glVertex2f(10.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(11.5f, -38.0f);
    glVertex2f(13.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(14.5f, -38.0f);
    glVertex2f(16.0f, -28.0f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(17.5f, -38.0f);
    glVertex2f(19.0f, -28.0f);
    glEnd();

    //Field Chair

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(-19.0f, -40.0f);
    glVertex2f(-17.5f, -40.0f);
    glVertex2f(-17.5f, -38.0f);
    glVertex2f(-19.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(-16.0f, -40.0f);
    glVertex2f(-14.5f, -40.0f);
    glVertex2f(-14.5f, -38.0f);
    glVertex2f(-16.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(-13.0f, -40.0f);
    glVertex2f(-11.5f, -40.0f);
    glVertex2f(-11.5f, -38.0f);
    glVertex2f(-13.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(-10.0f, -40.0f);
    glVertex2f(-8.5f, -40.0f);
    glVertex2f(-8.5f, -38.0f);
    glVertex2f(-10.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(-7.0f, -40.0f);
    glVertex2f(-5.5f, -40.0f);
    glVertex2f(-5.5f, -38.0f);
    glVertex2f(-7.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(-4.0f, -40.0f);
    glVertex2f(-2.5f, -40.0f);
    glVertex2f(-2.5f, -38.0f);
    glVertex2f(-4.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(2.0f, -40.0f);
    glVertex2f(3.5f, -40.0f);
    glVertex2f(3.5f, -38.0f);
    glVertex2f(2.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(5.0f, -40.0f);
    glVertex2f(6.5f, -40.0f);
    glVertex2f(6.5f, -38.0f);
    glVertex2f(5.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(8.0f, -40.0f);
    glVertex2f(9.5f, -40.0f);
    glVertex2f(9.5f, -38.0f);
    glVertex2f(8.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(11.0f, -40.0f);
    glVertex2f(12.5f, -40.0f);
    glVertex2f(12.5f, -38.0f);
    glVertex2f(11.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(14.0f, -40.0f);
    glVertex2f(15.5f, -40.0f);
    glVertex2f(15.5f, -38.0f);
    glVertex2f(14.0f, -38.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(224,255,255);

    glVertex2f(17.0f, -40.0f);
    glVertex2f(18.5f, -40.0f);
    glVertex2f(18.5f, -38.0f);
    glVertex2f(17.0f, -38.0f);
    glEnd();

    //Field Border

    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-20.0f, -42.0f);
    glVertex2f(-2.0f, -42.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(-2.0f, -42.8f);
    glVertex2f(-2.0f, -37.9f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(20.0f, -42.0f);
    glVertex2f(1.5f, -42.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,128,128);
    glVertex2f(1.5f, -42.8f);
    glVertex2f(1.5f, -37.9f);
    glEnd();

    //Field Gate
    glBegin(GL_QUADS);

    glColor3ub(128,128,0);

    glVertex2f(-2.0f, -38.2f);
    glVertex2f(1.5f, -38.2f);
    glVertex2f(1.5f, -39.2f);
    glVertex2f(-2.0f, -39.2f);
    glEnd();

    //Cricket Pitch

    glBegin(GL_POLYGON);

    glColor3ub(210,180,140);

    glVertex2f(-9.5f, -55.0f);
    glVertex2f(9.5f, -55.0f);
    glVertex2f(9.5f, -65.0f);
    glVertex2f(-9.5f, -65.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);   // Pitch Line
    glVertex2f(-8.3f, -55.0f);
    glVertex2f(-8.3f, -65.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);  //Pitch Line
    glVertex2f(8.3f, -55.0f);
    glVertex2f(8.3f, -65.0f);
    glEnd();

    glPointSize(5.0);  //Stump
    glBegin(GL_POINTS);
    glColor3ub(192,192,192);
    glVertex2f(-9.5f, -58.5f);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3ub(192,192,192);
    glVertex2f(-9.5f, -60.0f);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3ub(192,192,192);
    glVertex2f(-9.5f, -61.5f);
    glEnd();

    glPointSize(5.0);  //Stump 2nd Side
    glBegin(GL_POINTS);
    glColor3ub(192,192,192);
    glVertex2f(9.5f, -58.5f);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3ub(192,192,192);
    glVertex2f(9.5f, -60.0f);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3ub(192,192,192);
    glVertex2f(9.5f, -61.5f);
    glEnd();

    // Eighth Building
    glBegin(GL_POLYGON);
    glColor3ub(218,101,88);

    glVertex2f(-37.0f, 25.0f);
    glVertex2f(-37.0f, 66.0f);
    glVertex2f(-30.0f, 66.0f);
    glVertex2f(-30.0f, 25.0f);

    glEnd();



    // Eighth Building
    glBegin(GL_POLYGON);
    glColor3ub(218,101,88);

    glVertex2f(-37.0f, 25.0f);
    glVertex2f(-37.0f, 66.0f);
    glVertex2f(-30.0f, 66.0f);
    glVertex2f(-30.0f, 25.0f);

    glEnd();


    //  Eighth Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-31.0f, 60.0f);
    glVertex2f(-32.5f, 60.0f);
    glVertex2f(-32.5f, 55.0f);
    glVertex2f(-31.0f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-34.0f, 60.0f);
    glVertex2f(-35.5f, 60.0f);
    glVertex2f(-35.5f, 55.0f);
    glVertex2f(-34.0f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-31.0f, 49.0f);
    glVertex2f(-32.5f, 49.0f);
    glVertex2f(-32.5f, 44.0f);
    glVertex2f(-31.0f, 44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-34.0f, 49.0f);
    glVertex2f(-35.5f, 49.0f);
    glVertex2f(-35.5f, 44.0f);
    glVertex2f(-34.0f, 44.0f);
    glEnd();


    //Ninth Building
    glBegin(GL_POLYGON);
    glColor3ub(153,153,0);

    glVertex2f(-22.0f, 66.0f);
    glVertex2f(-22.0f, 25.0f);
    glVertex2f(-17.0f, 25.0f);
    glVertex2f(-17.0f, 66.0f);

    glEnd();

    //Ninth Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-21.0f, 60.0f);
    glVertex2f(-19.5f, 60.0f);
    glVertex2f(-19.5f, 55.0f);
    glVertex2f(-21.0f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-18.0f, 60.0f);
    glVertex2f(-17.0f, 60.0f);
    glVertex2f(-17.0f, 55.0f);
    glVertex2f(-18.0f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-21.0f, 49.0f);
    glVertex2f(-19.5f, 49.0f);
    glVertex2f(-19.5f, 44.0f);
    glVertex2f(-21.0f, 44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-18.0f, 49.0f);
    glVertex2f(-17.0f, 49.0f);
    glVertex2f(-17.0f, 44.0f);
    glVertex2f(-18.0f, 44.0f);
    glEnd();

    //Tenth Building
    glBegin(GL_POLYGON);
    glColor3ub(192,192,192);

    glVertex2f(-9.5f, 73.0f);
    glVertex2f(-9.5f, 25.0f);
    glVertex2f(-4.0f, 25.0f);
    glVertex2f(-4.0f, 73.0f);

    glEnd();

    //Tenth Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(-8.5f, 70.0f);
    glVertex2f(-7.0f, 70.0f);
    glVertex2f(-7.0f, 65.0f);
    glVertex2f(-8.5f, 65.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-5.5f, 70.0f);
    glVertex2f(-4.1f, 70.0f);
    glVertex2f(-4.1f, 65.0f);
    glVertex2f(-5.5f, 65.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(-8.5f, 60.0f);
    glVertex2f(-7.0f, 60.0f);
    glVertex2f(-7.0f, 55.0f);
    glVertex2f(-8.5f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(-5.5f, 60.0f);
    glVertex2f(-4.1f, 60.0f);
    glVertex2f(-4.1f, 55.0f);
    glVertex2f(-5.5f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(-8.5f, 49.0f);
    glVertex2f(-7.0f, 49.0f);
    glVertex2f(-7.0f, 44.0f);
    glVertex2f(-8.5f, 44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(-5.5f, 49.0f);
    glVertex2f(-4.1f, 49.0f);
    glVertex2f(-4.1f, 44.0f);
    glVertex2f(-5.5f, 44.0f);
    glEnd();

    //Eleventh Building
    glBegin(GL_POLYGON);
    glColor3ub(236, 197, 218); //front

    glVertex2f(3.0f, 25.0f);
    glVertex2f(3.0f, 77.0f);
    glVertex2f(8.5f, 77.0f);
    glVertex2f(8.5f, 25.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(221,160,221); //side

    glVertex2f(8.5f, 25.0f);
    glVertex2f(8.5f, 77.0f);
    glVertex2f(9.0f, 74.0f);
    glVertex2f(9.0f, 25.0f);

    glEnd();

    //Eleventh Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(3.7f, 71.0f);
    glVertex2f(5.2f, 71.0f);
    glVertex2f(5.2f, 66.0f);
    glVertex2f(3.7f, 66.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(6.2f, 71.0f);
    glVertex2f(7.7f, 71.0f);
    glVertex2f(7.7f, 66.0f);
    glVertex2f(6.2f, 66.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(3.7f, 60.0f);
    glVertex2f(5.2f, 60.0f);
    glVertex2f(5.2f, 55.0f);
    glVertex2f(3.7f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(6.2f, 60.0f);
    glVertex2f(7.7f, 60.0f);
    glVertex2f(7.7f, 55.0f);
    glVertex2f(6.2f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(3.7f, 49.0f);
    glVertex2f(5.2f, 49.0f);
    glVertex2f(5.2f, 44.0f);
    glVertex2f(3.7f, 44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(6.2f, 49.0f);
    glVertex2f(7.7f, 49.0f);
    glVertex2f(7.7f, 44.0f);
    glVertex2f(6.2f, 44.0f);
    glEnd();

    //Twelve Building
    glBegin(GL_POLYGON);
    glColor3ub(191, 185, 208); //front

    glVertex2f(22.0f, 25.0f);
    glVertex2f(22.0, 72.0f);
    glVertex2f(16.5f, 72.0f);
    glVertex2f(16.5f, 25.0f);

    glEnd();

    //Twelve Building Window
    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);  //1st window

    glVertex2f(17.2f, 67.0f);
    glVertex2f(18.7f, 67.0f);
    glVertex2f(18.7f, 62.0f);
    glVertex2f(17.2f, 62.0f);
    glEnd();



    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(19.7f, 67.0f);
    glVertex2f(21.2f, 67.0f);
    glVertex2f(21.2f, 62.0f);
    glVertex2f(19.7f, 62.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //3rd window

    glVertex2f(17.2f, 56.0f);
    glVertex2f(18.7f, 56.0f);
    glVertex2f(18.7f, 51.0f);
    glVertex2f(17.2f, 51.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(19.7f, 56.0f);
    glVertex2f(21.2f, 56.0f);
    glVertex2f(21.2f, 51.0f);
    glVertex2f(19.7f, 51.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //5th window

    glVertex2f(17.2f, 45.0f);
    glVertex2f(18.7f, 45.0f);
    glVertex2f(18.7f, 40.0f);
    glVertex2f(17.2f, 40.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(19.7f, 45.0f);
    glVertex2f(21.2f, 45.0f);
    glVertex2f(21.2f, 40.0f);
    glVertex2f(19.7f, 40.0f);

    glEnd();


    //Thirteen Building
    glBegin(GL_POLYGON);
    glColor3ub(205, 146, 94);//front

    glVertex2f(29.5f, 69.0f);
    glVertex2f(29.5f, 25.0f);
    glVertex2f(34.0f, 25.0f);
    glVertex2f(34.0f, 69.0f);
    glEnd();

    //Thirteen Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(30.2f, 64.0f);
    glVertex2f(31.7f, 64.0f);
    glVertex2f(31.7f, 59.0f);
    glVertex2f(30.2f, 59.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(32.7f, 64.0f);
    glVertex2f(34.0f, 64.0f);
    glVertex2f(34.0f, 59.0f);
    glVertex2f(32.7f, 59.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(30.2f, 53.0f);
    glVertex2f(31.7f, 53.0f);
    glVertex2f(31.7f, 48.0f);
    glVertex2f(30.2f, 48.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(32.7f, 53.0f);
    glVertex2f(34.0f, 53.0f);
    glVertex2f(34.0f, 48.0f);
    glVertex2f(32.7f, 48.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(30.2f, 42.0f);
    glVertex2f(31.7f, 42.0f);
    glVertex2f(31.7f, 37.0f);
    glVertex2f(30.2f, 37.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(32.7f, 42.0f);
    glVertex2f(34.0f, 42.0f);
    glVertex2f(34.0f, 37.0f);
    glVertex2f(32.7f, 37.0f);
    glEnd();

    //Fourteenth Building
    glBegin(GL_POLYGON);

    glColor3ub(165,42,42); //side
    glVertex2f(48.1f, 25.0f);
    glVertex2f(50.0f, 25.0f);
    glVertex2f(50.0f, 62.0f);
    glVertex2f(48.1f, 65.0f);

    glColor3ub(240,128,128);//front
    glVertex2f(41.5f, 65.0f);
    glVertex2f(41.5f, 25.0f);
    glVertex2f(48.0f, 25.0f);
    glVertex2f(48.0f, 65.0f);
    glEnd();

//Fourteenth Building Window
    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //1st window

    glVertex2f(42.5f, 60.0f);
    glVertex2f(44.0f, 60.0f);
    glVertex2f(44.0f, 55.0f);
    glVertex2f(42.5f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(45.5f, 60.0f);
    glVertex2f(47.0f, 60.0f);
    glVertex2f(47.0f, 55.0f);
    glVertex2f(45.5f, 55.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //3rd window

    glVertex2f(42.5f, 49.0f);
    glVertex2f(44.0f, 49.0f);
    glVertex2f(44.0f, 44.0f);
    glVertex2f(42.5f, 44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //4th window

    glVertex2f(45.5f, 49.0f);
    glVertex2f(47.0f, 49.0f);
    glVertex2f(47.0f, 44.0f);
    glVertex2f(45.5f, 44.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //5th window

    glVertex2f(42.5f, 38.0f);
    glVertex2f(44.0f, 38.0f);
    glVertex2f(44.0f, 33.0f);
    glVertex2f(42.5f, 33.0f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //6th window

    glVertex2f(45.5f, 38.0f);
    glVertex2f(47.0f, 38.0f);
    glVertex2f(47.0f, 33.0f);
    glVertex2f(45.5f, 33.0f);
    glEnd();

//Fifteen Building
    glBegin(GL_POLYGON);
    glColor3ub(29,122,97); //side

    glVertex2f(-46.0f, 25.0f);
    glVertex2f(-45.0f, 25.0f);
    glVertex2f(-45.0f, 66.0f);
    glVertex2f(-46.0f, 69.0f);

    glColor3ub(108,220,190); //front
    glVertex2f(-46.0f, 69.0f);
    glVertex2f(-55.0f, 69.0f);
    glVertex2f(-55.0f, 25.0f);
    glVertex2f(-46.0f, 25.0f);
    glEnd();

//Fifteen Building Window
    glBegin(GL_QUADS);
    glColor3ub(50, 46, 48);  //1st window

    glVertex2f(-48.5f, 62.0f);
    glVertex2f(-47.0f, 62.0f);
    glVertex2f(-47.0f, 57.0f);
    glVertex2f(-48.5f, 57.0f);
    glEnd();



    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);   //2nd window

    glVertex2f(-51.0f, 62.0f);
    glVertex2f(-49.5f, 62.0f);
    glVertex2f(-49.5f, 57.0f);
    glVertex2f(-51.0f, 57.0f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(50, 46, 48);  //3rd window

    glVertex2f(-48.5f, 51.0f);
    glVertex2f(-47.0f, 51.0f);
    glVertex2f(-47.0f, 46.0f);
    glVertex2f(-48.5f, 46.0f);

    glEnd();
}

void people1()
{

    glPushMatrix();//body
    glTranslated(0,-20,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,100,100);
    circle(1,2.5);
    glPopMatrix();

    glPushMatrix();//head
    glTranslated(0,-14.5,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,255,0);
    circle(1,1);
    glPopMatrix();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.1f, -23.0f);
    glVertex2f(0.3f, -27.0f);
    glEnd();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.3f, -23.0f);
    glVertex2f(-0.5f, -27.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.5f, -17.0f);
    glVertex2f(0.7f, -20.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-.4f, -17.0f);
    glVertex2f(-0.7f, -20.0f);
    glEnd();

}
void people2()
{

    glPushMatrix();//body
    glTranslated(0,25,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,100,100);
    circle(1,2.5);
    glPopMatrix();

    glPushMatrix();//head
    glTranslated(0,30,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,255,0);
    circle(1,1);
    glPopMatrix();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.3f, 18.0f);
    glVertex2f(0.1f, 22.0f);
    glEnd();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.5f, 18.0f);
    glVertex2f(-0.3f, 22.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.7f, 24.0f);
    glVertex2f(-0.4f, 27.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.5f, 24.0f);
    glVertex2f(0.3f, 27.0f);
    glEnd();

}

void people9()
{
    glPushMatrix();


    txPeo1=txPeo1+0.01;
    if(txPeo1>45)
    {
        txPeo1=45;

    }
    glTranslatef(0,txPeo1,0);
    glPushMatrix();//body
    glTranslated(0,-20,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,100,100);
    circle(1,2.5);
    glPopMatrix();

    glPushMatrix();//head
    glTranslated(0,-14.5,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,255,0);
    circle(1,1);
    glPopMatrix();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.1f, -23.0f);
    glVertex2f(0.3f, -27.0f);
    glEnd();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.3f, -23.0f);
    glVertex2f(-0.5f, -27.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.5f, -17.0f);
    glVertex2f(0.7f, -20.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-.4f, -17.0f);
    glVertex2f(-0.7f, -20.0f);
    glEnd();
    glPopMatrix();
}
void people10()
{
    glPushMatrix();


    txPeo2=txPeo2-0.01;
    if(txPeo2<-45)
    {
        txPeo2=-45;

    }
    glTranslatef(0,txPeo2,0);
    glPushMatrix();//body
    glTranslated(0,25,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,100,100);
    circle(1,2.5);
    glPopMatrix();

    glPushMatrix();//head
    glTranslated(0,30,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,255,0);
    circle(1,1);
    glPopMatrix();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.3f, 18.0f);
    glVertex2f(0.1f, 22.0f);
    glEnd();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.5f, 18.0f);
    glVertex2f(-0.3f, 22.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.7f, 24.0f);
    glVertex2f(-0.4f, 27.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(0.5f, 24.0f);
    glVertex2f(0.3f, 27.0f);
    glEnd();

    glPopMatrix();

}
void people3()
{
    glPushMatrix();//body
    glTranslated(-6,-21,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,100,100);
    circle(1,2.5);
    glPopMatrix();

    glPushMatrix();//head
    glTranslated(-6,-15.5,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,255,0);
    circle(1,1);
    glPopMatrix();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-6.3f, -24.0f);
    glVertex2f(-6.5f, -28.0f);
    glEnd();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-5.95f, -24.0f);
    glVertex2f(-5.75f, -28.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-6.4f, -18.0f);
    glVertex2f(-6.6f, -21.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-5.6f, -18.0f);
    glVertex2f(-5.4f, -21.0f);
    glEnd();
}
void people4()
{
    glPushMatrix();//body
    glTranslated(32,47,0);
    glPushMatrix();//body
    glTranslated(-6,-21,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,0,250);
    circle(1,2.5);
    glPopMatrix();

    glPushMatrix();//head
    glTranslated(-6,-15.5,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,255,0);
    circle(1,1);
    glPopMatrix();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-6.3f, -24.0f);
    glVertex2f(-6.5f, -28.0f);
    glEnd();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-5.95f, -24.0f);
    glVertex2f(-5.75f, -28.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-6.4f, -18.0f);
    glVertex2f(-6.6f, -21.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-5.6f, -18.0f);
    glVertex2f(-5.4f, -21.0f);
    glEnd();
    glPopMatrix();
}


void people5()
{
    glPushMatrix();//body
    glTranslated(48,0,0);
    glPushMatrix();//body
    glTranslated(-6,-18,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,100,100);
    circle(1,2.5);
    glPopMatrix();

    glPushMatrix();//head
    glTranslated(-6,-12.5,0);
    glScaled(0.5,1.5,0);
    glColor3ub(255,255,0);
    circle(1,1);
    glPopMatrix();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-6.3f, -21.0f);
    glVertex2f(-6.5f, -25.0f);
    glEnd();

    glLineWidth(3);//leg
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-5.95f, -21.0f);
    glVertex2f(-5.75f, -25.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-6.4f, -15.0f);
    glVertex2f(-6.6f, -18.0f);
    glEnd();

    glLineWidth(3);//hand
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-5.6f, -15.0f);
    glVertex2f(-5.4f, -18.0f);
    glEnd();
    glPopMatrix();
}




void Traffic()
{



    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(3.0f, 18.0f);
    glVertex2f(4.0f, 18.0f);
    glVertex2f(4.0f, 38.0f);
    glVertex2f(3.0f, 38.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(-4.0f, 38.0f);
    glVertex2f(5.0f, 38.0f);
    glVertex2f(5.0f, 50.0f);
    glVertex2f(-4.0f, 50.0f);
    glEnd();

    glPushMatrix();
    glTranslated(-2.5,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,0,0);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(10,100,0);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(0,255,0);
    circle(1.5,1.5);
    glPopMatrix();
}

void TrRed()
{



    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(3.0f, 18.0f);
    glVertex2f(4.0f, 18.0f);
    glVertex2f(4.0f, 38.0f);
    glVertex2f(3.0f, 38.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(-4.0f, 38.0f);
    glVertex2f(5.0f, 38.0f);
    glVertex2f(5.0f, 50.0f);
    glVertex2f(-4.0f, 50.0f);
    glEnd();

    glPushMatrix();
    glTranslated(-2.5,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,0,0);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,255,255);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,255,255);
    circle(1.5,1.5);
    glPopMatrix();



}

void TrYel()

{
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(3.0f, 18.0f);
    glVertex2f(4.0f, 18.0f);
    glVertex2f(4.0f, 38.0f);
    glVertex2f(3.0f, 38.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(-4.0f, 38.0f);
    glVertex2f(5.0f, 38.0f);
    glVertex2f(5.0f, 50.0f);
    glVertex2f(-4.0f, 50.0f);
    glEnd();

    glPushMatrix();
    glTranslated(-2.5,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,255,255);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(10,100,0);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,255,255);
    circle(1.5,1.5);
    glPopMatrix();

}

void TrGN()
{

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(3.0f, 18.0f);
    glVertex2f(4.0f, 18.0f);
    glVertex2f(4.0f, 38.0f);
    glVertex2f(3.0f, 38.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);

    glVertex2f(-4.0f, 38.0f);
    glVertex2f(5.0f, 38.0f);
    glVertex2f(5.0f, 50.0f);
    glVertex2f(-4.0f, 50.0f);
    glEnd();

    glPushMatrix();
    glTranslated(-2.5,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,255,255);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(255,255,255);
    circle(1.5,1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,44,0);
    glScaled(0.5,1.5,0);
    glColor3f(0,255,0);
    circle(1.5,1.5);
    glPopMatrix();
}

void bus()
{
    glPushMatrix();
    glTranslatef(moveBus_right,0.0f,0.0f);
    // bus right
    glPushMatrix();
    glTranslatef(-47.0f, 3.0f, 0.0f);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(16.50f, -6.0f);
    glVertex2f(16.50f, -16.0f);
    glVertex2f(26.0f, -16.0f);
    glVertex2f(26.0f, -13.0f);
    glVertex2f(25.7f, -13.0f);
    glVertex2f(25.20f, -6.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(17.0f, -7.0f);
    glVertex2f(17.0f, -12.50f);
    glVertex2f(25.0f, -12.50f);
    glVertex2f(25.0f, -7.0f);
    glEnd();

    // bus-wheel-left
    glPushMatrix();
    glTranslatef(18.30f, -16.10f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 1.5 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // tire-right
    glPushMatrix();
    glTranslatef(24.0f, -16.10f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 1.5 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void bus2()
{
    glPushMatrix();
    glTranslatef(moveBus_right,0.0f,0.0f);
    // bus left
    glPushMatrix();
    glTranslatef(-58.0f, 3.0f, 0.0f);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex2f(16.50f, -6.0f);
    glVertex2f(16.50f, -16.0f);
    glVertex2f(26.0f, -16.0f);
    glVertex2f(26.0f, -13.0f);
    glVertex2f(25.7f, -13.0f);
    glVertex2f(25.20f, -6.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(17.0f, -7.0f);
    glVertex2f(17.0f, -12.50f);
    glVertex2f(25.0f, -12.50f);
    glVertex2f(25.0f, -7.0f);

    glEnd();

    // bus2-wheel-left
    glPushMatrix();
    glTranslatef(18.30f, -16.10f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 1.5 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // tire-right
    glPushMatrix();
    glTranslatef(24.0f, -16.10f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 1.5 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void car()
{
    glPushMatrix();
    glTranslatef(moveCar_left,0.0f,0.0f);
    // car left
    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 0.0f);

    // body
    glBegin(GL_QUADS);
    glColor3ub(128,0,128);
    glVertex2f(-21.0f, 7.0f);
    glVertex2f(-10.0f, 7.0f);
    glVertex2f(-10.0f, 10.0f);
    glVertex2f(-21.0f, 10.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 200, 105);
    glVertex2f(-12.0f, 10.0f);
    glVertex2f(-18.20f, 10.0f);
    glVertex2f(-16.20f, 14.70f);
    glVertex2f(-14.0f, 14.70f);
    glEnd();

    // car-wheel-right
    glPushMatrix();
    glTranslatef(-12.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // car-wheel-left
    glPushMatrix();
    glTranslatef(-19.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void car2()
{
    glPushMatrix();
    glTranslatef(moveCar2_left,0.0f,0.0f);
    // car right
    glPushMatrix();
    glTranslatef(53.0f, 0.0f, 0.0f); //27, 0, 0

    // body
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(-21.0f, 7.0f);
    glVertex2f(-10.0f, 7.0f);
    glVertex2f(-10.0f, 10.0f);
    glVertex2f(-21.0f, 10.0f);
    glEnd();

    // window
    glBegin(GL_QUADS);
    glColor3f(0, 0.5, 1);
    glVertex2f(-15.0f, 10.0f);
    glVertex2f(-18.20f, 10.0f);
    glVertex2f(-16.20f, 14.70f);
    glVertex2f(-14.0f, 14.70f);
    glEnd();

    // car-wheel-right
    glPushMatrix();
    glTranslatef(-12.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // car-wheel-left
    glPushMatrix();
    glTranslatef(-19.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void car3()
{
    glPushMatrix();
    glTranslatef(moveCar3_left,0.0f,0.0f);    // car left
    glPushMatrix();
    glTranslatef(41.0f, 0.0f, 0.0f); // -24, 0, 0

    // body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-21.0f, 7.0f);
    glVertex2f(-10.0f, 7.0f);
    glVertex2f(-10.0f, 10.0f);
    glVertex2f(-21.0f, 10.0f);
    glEnd();

    // window
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.5, 1); // 3ub(100,200,105)
    glVertex2f(-10.0f, 10.0f);
    glVertex2f(-18.20f, 10.0f);
    glVertex2f(-16.20f, 14.70f);
    glVertex2f(-14.0f, 14.70f);
    glEnd();

    // car-wheel-right
    glPushMatrix();
    glTranslatef(-12.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // car-wheel-left
    glPushMatrix();
    glTranslatef(-19.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}

void car4()
{
    glPushMatrix();
    glTranslatef(moveCar4_right,0.0f,0.0f);
    // car left
    glPushMatrix();
    glTranslatef(30.0f, -19.0f, 0.0f);

    // body
    glBegin(GL_QUADS);
    glColor3ub(128,0,128);
    glVertex2f(-21.0f, 7.0f);
    glVertex2f(-10.0f, 7.0f);
    glVertex2f(-10.0f, 10.0f);
    glVertex2f(-21.0f, 10.0f);
    glEnd();

    // window
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.5, 1); // 3ub(100,200,105)
    glVertex2f(-12.0f, 10.0f);
    glVertex2f(-21.20f, 10.0f);
    glVertex2f(-16.20f, 14.70f);
    glVertex2f(-14.0f, 14.70f);
    glEnd();

    // car-wheel-right
    glPushMatrix();
    glTranslatef(-12.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // car-wheel-left
    glPushMatrix();
    glTranslatef(-19.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void car5()
{
    glPushMatrix();
    glTranslatef(moveCar5_right,0.0f,0.0f);
    // car left
    glPushMatrix();
    glTranslatef(5.0f, -19.0f, 0.0f);

    // body
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f); // 3ub(220,220,0)
    glVertex2f(-21.0f, 7.0f);
    glVertex2f(-10.0f, 7.0f);
    glVertex2f(-10.0f, 10.0f);
    glVertex2f(-21.0f, 10.0f);
    glEnd();

    // window
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.5, 1); // 3ub(100,200,105)
    glVertex2f(-12.0f, 10.0f);
    glVertex2f(-21.20f, 10.0f);
    glVertex2f(-16.20f, 14.70f);
    glVertex2f(-14.0f, 14.70f);
    glEnd();

    // car-wheel-right
    glPushMatrix();
    glTranslatef(-12.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // car-wheel-left
    glPushMatrix();
    glTranslatef(-19.0f, 6.40f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        glColor3f(1, 1, 1);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 0.7;
        float x = r * cos(A);
        float y = r * 2 * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void Daydisplay(void)
{


    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();
    glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);


    sky();
    sun();

    FirstBuild();
    FrstBuildWindow();
    SecondBuilding();
    secndBuildWindow();
    thrdBuilding();
    thirdBildWindow();
    FrthBuilding();
    frthBuildingWindow();
    fthBuilding();
    fthBuildingWindow();
    SixBuilding();
    SxthBuildingWindow();
    sevenBuilding();
    sevenBuildingWindow();

    glPushMatrix();
    glTranslatef(txB,tyB,0);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();






    glPushMatrix();
    glTranslatef(txP,tyP,0);
    AirPlane();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(txB,tyB,0);
    Bird1();
    Bird2();
    glPopMatrix();



    middle();
    people1();
    people2();
    people3();
    people4();
    people5();
    Traffic();
    bus();
    bus2();
    car();
    car2();
    car3();
    car4();
    car5();




    glPopMatrix();
    glFlush();
    glutPostRedisplay();
}

void nightDisplay(void)
{




    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);


    Nightsky();
    moon();




    FirstBuild();
    FrstBuildWindow();
    SecondBuilding();
    secndBuildWindow();
    thrdBuilding();
    thirdBildWindow();
    FrthBuilding();
    frthBuildingWindow();
    fthBuilding();
    fthBuildingWindow();
    SixBuilding();
    SxthBuildingWindow();
    sevenBuilding();
    sevenBuildingWindow();






    middle();
    Traffic();
    bus2();
    car();
    car2();
    car4();
    car5();




    glPopMatrix();
    glFlush();
    glutPostRedisplay();

}

void Red(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();
    glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);


    sky();
    sun();

    FirstBuild();
    FrstBuildWindow();
    SecondBuilding();
    secndBuildWindow();
    thrdBuilding();
    thirdBildWindow();
    FrthBuilding();
    frthBuildingWindow();
    fthBuilding();
    fthBuildingWindow();
    SixBuilding();
    SxthBuildingWindow();
    sevenBuilding();
    sevenBuildingWindow();

    glPushMatrix();
    glTranslatef(txB,tyB,0);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();






    glPushMatrix();
    glTranslatef(txP,tyP,0);
    AirPlane();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(txB,tyB,0);
    Bird1();
    Bird2();
    glPopMatrix();



    middle();
    people1();
    people2();
    people3();
    people4();
    people5();
    Traffic();
    TrRed();
    bus();
    bus2();
    car();
    car2();
    car3();
    car4();
    car5();




    glPopMatrix();
    glFlush();
    glutPostRedisplay();
}

void Yellow(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();
    glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);


    sky();
    sun();

    FirstBuild();
    FrstBuildWindow();
    SecondBuilding();
    secndBuildWindow();
    thrdBuilding();
    thirdBildWindow();
    FrthBuilding();
    frthBuildingWindow();
    fthBuilding();
    fthBuildingWindow();
    SixBuilding();
    SxthBuildingWindow();
    sevenBuilding();
    sevenBuildingWindow();

    glPushMatrix();
    glTranslatef(txB,tyB,0);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();






    glPushMatrix();
    glTranslatef(txP,tyP,0);
    AirPlane();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(txB,tyB,0);
    Bird1();
    Bird2();
    glPopMatrix();



    middle();
    people1();
    people2();
    people3();
    people4();
    people5();
    Traffic();
    TrYel();
    bus();
    bus2();
    car();
    car2();
    car3();
    car4();
    car5();




    glPopMatrix();
    glFlush();
    glutPostRedisplay();
}

void Green(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();
    glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);


    sky();
    sun();

    FirstBuild();
    FrstBuildWindow();
    SecondBuilding();
    secndBuildWindow();
    thrdBuilding();
    thirdBildWindow();
    FrthBuilding();
    frthBuildingWindow();
    fthBuilding();
    fthBuildingWindow();
    SixBuilding();
    SxthBuildingWindow();
    sevenBuilding();
    sevenBuildingWindow();

    glPushMatrix();
    glTranslatef(txB,tyB,0);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();






    glPushMatrix();
    glTranslatef(txP,tyP,0);
    AirPlane();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(txB,tyB,0);
    Bird1();
    Bird2();
    glPopMatrix();



    middle();
    people1();
    people2();
    people3();
    people4();
    people5();
    Traffic();
    TrGN();
    bus();
    bus2();
    car();
    car2();
    car3();
    car4();
    car5();




    glPopMatrix();
    glFlush();
    glutPostRedisplay();
}

void PeopleMoving(void)

{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();
    glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);


    sky();
    sun();

    FirstBuild();
    FrstBuildWindow();
    SecondBuilding();
    secndBuildWindow();
    thrdBuilding();
    thirdBildWindow();
    FrthBuilding();
    frthBuildingWindow();
    fthBuilding();
    fthBuildingWindow();
    SixBuilding();
    SxthBuildingWindow();
    sevenBuilding();
    sevenBuildingWindow();

    glPushMatrix();
    glTranslatef(txB,tyB,0);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();






    glPushMatrix();
    glTranslatef(txP,tyP,0);
    AirPlane();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(txB,tyB,0);
    Bird1();
    Bird2();
    glPopMatrix();



    middle();
    people9();
    people10();
    people3();
    people4();
    people5();
    Traffic();
    TrRed();
    bus();
    bus2();
    car();
    car2();
    car3();
    car4();
    car5();




    glPopMatrix();
    glFlush();
    glutPostRedisplay();

}

void handleKeypress(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'd':

        glutDisplayFunc(Daydisplay);
        glutPostRedisplay();


        break;

    case 'D':

        glutDisplayFunc(Daydisplay);

        glutPostRedisplay();

        break;
    case 'n':
        glutDisplayFunc(nightDisplay);
        glutPostRedisplay();
        break;

    case 'N':
        glutDisplayFunc(nightDisplay);
        glutPostRedisplay();
        break;
    case 'r':
        glutIdleFunc(move_right);

        break;
    case 'R':
        glutIdleFunc(move_right);
        break;

    case 'l':
        glutIdleFunc(move_left);
        break;
    case 'L':
        glutIdleFunc(move_left);

        break;
    case 'S':
        glutIdleFunc(move_all);
        break;
    case 's':
        glutIdleFunc(move_all);
        break;

    case 'e':
        glutIdleFunc(NULL);
        break;
    case 'E':
        glutIdleFunc(NULL);
        break;
    case 'z':
        glutDisplayFunc(Red);
        glutPostRedisplay();
        break;

    case 'x':
        glutDisplayFunc(Yellow);
        glutPostRedisplay();
        break;

    case 'c':
        glutDisplayFunc(Green);
        glutPostRedisplay();
        break;

    case 'm':
        glutDisplayFunc(PeopleMoving);
        glutPostRedisplay();
        break;


    }
}

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GLUT_SINGLE| GLUT_RGB);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);
}

int main(int arg, char **argv)
{
    glutInit(&arg, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1920, 1080);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("City View");
    init();

    glutDisplayFunc(Daydisplay);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979
static GLfloat ang = 0;
static double cx = 0, cy = 0, angc = 0;
static double g = 0.000005, re = 0.8;
static double cpleg, legy = 702, dcx = 0, dcy = 0;
static int fd = 0, cj = 0, cc = 0;

static struct leg1 leg;

static struct object Ao;
static struct object Bo;
static struct object Co;
static struct object Do;

static struct circle Ac;
static struct circle Bc;
static struct circle Cc;
static struct circle Dc;

struct leg1
{
  double x1;
  double y1;
  double x2;
  double y2;
  double x3;
  double y3;
  double x4;
  double y4;
  double x5;
  double y5;
  double x6;
  double y6;
  double xc;
  double yc;
  double ang1;
  double speedx;
  double speedy;
  double legspeed;
};

struct object
{
  int j;
  double px;
  double py;
  double pbx;
  double pby;
  double speedx;
  double speedy;
};
       
struct circle
{
  double px;
  double py;
  double r;
  double ro;
  double speedx;
  double speedy;
  double pxb;
  int xs;
  int ys;
};

//======================================================================================================================================================================================

void display(void)
{
  if(cc == 0)
  {
    cc = 1;
    Ao.px = 5;
    Ao.py = 5;
    Bo.px = 5;
    Bo.py = 5;
    Co.px = 5;
    Co.py = 5;
    Do.px = 5;
    Do.py = 5;
  }
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  
  //leg
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2d(leg.x1, leg.y1);
  glVertex2d(leg.x2, leg.y2);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2d(leg.x3, leg.y3);
  glVertex2d(leg.x4, leg.y4);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2d(leg.x3, leg.y3);
  glVertex2d(leg.x6, leg.y6);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2d(leg.x5, leg.y5);
  glEnd();
  
  //circle A
  glColor3f(255.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2d(Ac.px, Ac.py);
  for (angc = 0 + Ac.ro; angc <= 370 + Ac.ro; angc += 10)
  {
    glColor3f(0.0, 0.0, 0.0);
    cx = Ac.r * cos(angc * PI / 180);
    cy = Ac.r * sin(angc * PI / 180);
    if(angc < 70 + Ac.ro)
      glColor3f(0.0, 0.0, 500.0);
    glVertex2d(cx + Ac.px, cy + Ac.py);
  }
  glEnd();
  
  //circle B
  glColor3f(255.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2d(Bc.px, Bc.py);
  for (angc = 0 + Bc.ro; angc <= 370 + Bc.ro; angc += 10)
  {
    glColor3f(0.0, 0.0, 0.0);
    cx = Bc.r * cos(angc * PI / 180);
    cy = Bc.r * sin(angc * PI / 180);
    if(angc < 70 + Bc.ro)
      glColor3f(0.0, 500.0, 0.0);
    glVertex2d(cx + Bc.px, cy + Bc.py);
  }
  glEnd();
  
  //object A
  if(Ao.px < 4)
  {
    glColor3f(125.0, 125.0, 125.0);
    glBegin(GL_POLYGON);
    glVertex2d(Ao.px, Ao.py);
    for (angc = 0; angc <= 370; angc += 10)
    {
      glColor3f(255.0, 255.0, 0.0);
      cx = 0.05 * cos(angc * PI / 180);
      cy = 0.05 * sin(angc * PI / 180);
      glVertex2d(cx + Ao.px, cy + Ao.py);
    }
    glEnd();
  }
  
  //object B
  if(Bo.px < 4)
  {
    glColor3f(125.0, 125.0, 125.0);
    glBegin(GL_POLYGON);
    glVertex2d(Bo.px, Bo.py);
    for (angc = 0; angc <= 370; angc += 10)
    {
      glColor3f(255.0, 255.0, 0.0);
      cx = 0.05 * cos(angc * PI / 180);
      cy = 0.05 * sin(angc * PI / 180);
      glVertex2d(cx + Bo.px, cy + Bo.py);
    }
    glEnd();
  }
  
  //object C
  if(Co.px < 4)
  {
    glColor3f(125.0, 125.0, 125.0);
    glBegin(GL_POLYGON);
    glVertex2d(Co.px, Co.py);
    for (angc = 0; angc <= 370; angc += 10)
    {
      glColor3f(255.0, 255.0, 0.0);
      cx = 0.05 * cos(angc * PI / 180);
      cy = 0.05 * sin(angc * PI / 180);
      glVertex2d(cx + Co.px, cy + Co.py);
    }
    glEnd();
  }
  
  //object D
  if(Do.px < 4)
  {
    glColor3f(125.0, 125.0, 125.0);
    glBegin(GL_POLYGON);
    glVertex2d(Do.px, Do.py);
    for (angc = 0; angc <= 370; angc += 10)
    {
      glColor3f(255.0, 255.0, 0.0);
      cx = 0.05 * cos(angc * PI / 180);
      cy = 0.05 * sin(angc * PI / 180);
      glVertex2d(cx + Do.px, cy + Do.py);
    }
    glEnd();
  }
    
  //fd
  if(fd == 0)
  {
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    for(dcx = 0, dcy = 0; dcx < 2; dcx += 0.01, dcy -= 0.01)
    {
      glVertex2d(0.5, dcy);
      glVertex2d(dcx + 0.5, 0);
      glVertex2d(-dcy + 0.5, 0);
      glVertex2d(0.5, -dcx);
    }
    glVertex2d(2 + 0.5, 0);
    glVertex2d(0 + 0.5, 0);
    glVertex2d(0 + 0.5, -2);
    glVertex2d(2 + 0.5, -2);
    glVertex2d(0 + 0.5, -2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0, 10, 10);
    glVertex2d(0.80, -0.25);
    glVertex2d(0.85, -0.25);
    glColor3f(0, 0, 0);
    glVertex2d(0.85, -0.75);
    glVertex2d(0.80, -0.75);
    glEnd();
    
    cpleg = -0.75 + (702 - legy) / 207 * 0.5;
    glBegin(GL_POLYGON);
    glColor3f(0, 150, 0);
    glVertex2d(0.75, cpleg);
    glVertex2d(0.90, cpleg);
    glVertex2d(0.90, cpleg - 0.05);
    glVertex2d(0.75, cpleg - 0.05);
    glEnd();
    
  }
  
  glFlush();
  glPopMatrix();
  glutSwapBuffers();
}

//======================================================================================================================================================================================

void init(void)
{
  glClearColor(0.088, 0.080, 0.165, 1.0);
  //glClearColor(1, 1, 1, 1.0);
}

//======================================================================================================================================================================================

void move(void)
{
  int n = 0;
  double gsx, gsy, gsx1, gsy1, gsg, dxAB, dyAB;
  double r1 = 0.1414213562373095, r2 = 0.412310562, r3 = 0.5, r4 = 0.22360679775;
  
  leg.x1 = r1 * cos((225 - ang) * PI * 2 / 360) + leg.xc;
  leg.y1 = r1 * sin((225 - ang) * PI * 2 / 360) + leg.yc;
  leg.x2 = r1 * cos((135 - ang) * PI * 2 / 360) + leg.xc;
  leg.y2 = r1 * sin((135 - ang) * PI * 2 / 360) + leg.yc;
  leg.x3 = r2 * cos((14 - ang) * PI * 2 / 360) + leg.xc;
  leg.y3 = r2 * sin((14 - ang) * PI * 2 / 360) + leg.yc;
  leg.x4 = r2 * cos((346 - ang) * PI * 2 / 360) + leg.xc;
  leg.y4 = r2 * sin((346 - ang) * PI * 2 / 360) + leg.yc;
  leg.x5 = r3 * cos((323 - ang) * PI * 2 / 360) + leg.xc;
  leg.y5 = r3 * sin((323 - ang) * PI * 2 / 360) + leg.yc;
  leg.x6 = r4 * cos((333 - ang) * PI * 2 / 360) + leg.xc;
  leg.y6 = r4 * sin((333 - ang) * PI * 2 / 360) + leg.yc;
    
  ang = ang + 1 * leg.ang1;
  
  if ( ang >= 134.99 && ang <= 135.01 )
    leg.ang1 = 0.0;
  
  gsx = Ac.speedx / 100;
  gsy = Ac.speedy / 100;
  gsx1 = Bc.speedx / 100;
  gsy1 = Bc.speedy / 100;
  gsg = g / 100;
  
  Ac.ro = -(Ac.pxb - Ac.speedx) / 0.001745329;
  Ac.pxb = Ac.px;
  Bc.ro = -(Bc.pxb - Bc.speedx) / 0.001745329;
  Bc.pxb = Bc.px;
  
  while(n != 100)
  {
    //------------------------------circleA
    
    if(Ac.xs == 2)
      Ac.px -= gsx;
    else
      Ac.px += gsx;
      
    if(Ac.ys == 2)
      Ac.py -= gsy;
    else
      Ac.py += gsy;
    
//    if(Ac.speedy > 0.0001 || Ac.py > -0.8999)
      
      if(Ac.ys == 1)
        Ac.speedy -= gsg;
      else
        Ac.speedy += gsg;
        
      if(Ac.speedy < 0)
      {
        Ac.speedy *= -1;
        Ac.ys = 2;
      }
      gsy = Ac.speedy / 100;
    
    //------------------------------circleB kabe
    
    if(Ac.px < -0.9)
    {
      Ac.xs = 1;
      Ac.px = -0.9;
      Ac.speedx *= re;
      gsx = Ac.speedx / 100;
      Ac.speedy *= 0.99995;
      gsy = Ac.speedy / 100;
    }
    
    if(Ac.px > 0.9)
    {
      Ac.xs = 2;
      Ac.px = 0.9;
      Ac.speedx *= re;
      gsx = Ac.speedx / 100;
      Ac.speedy *= 0.99995;
      gsy = Ac.speedy / 100;
    }
    
    if(Ac.py < -0.9)
    {
      Ac.ys = 1;
      Ac.py = -0.9;
      Ac.speedy *= re;
      gsy = Ac.speedy / 100;
      Ac.speedx *= 0.99995;
      gsx = Ac.speedx / 100;
    }
    
    if(Ac.py > 0.9)
    {
      Ac.ys = 2;
      Ac.py = 0.9;
      Ac.speedy *= re;
      gsy = Ac.speedy / 100;
      Ac.speedx *= 0.99995;
      gsx = Ac.speedx / 100;
    }
    
    //------------------------------circleB leg shoutotu
    
    /*if((leg.x1 - 0.1) < Ac.px && Ac.px < (leg.x3 + 0.1) && (leg.y1 - 0.1) < Ac.py && Ac.py < (leg.x3 + 0.1))
    {Ac.speedx += 1.5;
      if((leg.x1 - 0.1) < Ac.px && Ac.px < leg.x3 && (leg.y1 - 0.1) < Ac.py && Ac.py < leg.x3)
      {
        Ac.xs = 2;
        Ac.speedx *= 0.9;
        if(ang < 90)
        {
          Ac.ys = 1;
          Ac.speedx *= 0.9;
        }
        else if(ang > 90)
        {
          Ac.ys = 2;
          Ac.speedx *= 0.9;
        }
      }
    }*/
    
    //------------------------------circleB
    if(Bc.xs == 2)
      Bc.px -= gsx1;
    else
      Bc.px += gsx1;
      
    if(Bc.ys == 2)
      Bc.py -= gsy1;
    else
      Bc.py += gsy1;
    
//    if(Ac.speedy > 0.0001 || Ac.py > -0.8999)
      
      if(Bc.ys == 1)
        Bc.speedy -= gsg;
      else
        Bc.speedy += gsg;
        
      if(Bc.speedy < 0)
      {
        Bc.speedy *= -1;
        Bc.ys = 2;
      }
      gsy1 = Bc.speedy / 100;
    
    
    
    if(Bc.px < -0.9)
    {
      Bc.xs = 1;
      Bc.px = -0.9;
      Bc.speedx *= re;
      gsx1 = Bc.speedx / 100;
      Bc.speedy *= 0.99995;
      gsy1 = Bc.speedy / 100;
    }
    
    if(Bc.px > 0.9)
    {
      Bc.xs = 2;
      Bc.px = 0.9;
      Bc.speedx *= re;
      gsx1 = Bc.speedx / 100;
      Bc.speedy *= 0.99995;
      gsy1 = Bc.speedy / 100;
    }
    
    if(Bc.py < -0.9)
    {
      Bc.ys = 1;
      Bc.py = -0.9;
      Bc.speedy *= re;
      gsy1 = Bc.speedy / 100;
      Bc.speedx *= 0.99995;
      gsx1 = Bc.speedx / 100;
    }
    
    if(Bc.py > 0.9)
    {
      Bc.ys = 2;
      Bc.py = 0.9;
      Bc.speedy *= re;
      gsy1 = Bc.speedy / 100;
      Bc.speedx *= 0.99995;
      gsx1 = Bc.speedx / 100;
    }
    
    //------------------------------circle shoutotu
    dxAB = Ac.px - Bc.px;
    dyAB = Ac.py - Bc.py;
    double cxs, cys;
    if(sqrt(dxAB * dxAB + dyAB * dyAB) < 0.2)
    {
      if(Ac.xs != Bc.xs)
      {
        if((Ac.xs == 2 && (Ac.px > Bc.px)) || (Ac.xs == 1 && (Ac.px < Bc.px)))
        {
          cxs = Ac.xs;
          Ac.xs = Bc.xs;
          Bc.xs = cxs;
        }
        else if((Ac.xs == 2 && (Ac.px <= Bc.px)) || (Ac.xs == 1 && (Ac.px >= Bc.px)));
      }
      else if(Ac.xs == Bc.xs)
      {
        cxs = Ac.speedx;
        Ac.speedx = Bc.speedx;
        Bc.speedx = cxs;
      }
  //  if(Ac.speedy != 0 && Bc.speedy != 0)
    //{
      if(Ac.ys != Bc.ys)
      {
        if((Ac.ys == 2 && (Ac.py > Bc.py)) || (Ac.ys == 1 && (Ac.py < Bc.py)))
        {
          cys = Ac.ys;
          Ac.ys = Bc.ys;
          Bc.ys = cys;
          if(Ac.py > Bc.py && Ac.speedy < g)
          {
            if(Ac.px > Bc.px)
              Ac.px += 0.01;
            else if(Ac.px <= Bc.px)
              Ac.px -= 0.01;
          }
          if(Ac.py < Bc.py && Bc.speedy < g)
          {
            if(Ac.px < Bc.px)
              Bc.px += 0.01;
            else if(Ac.px >= Bc.px)
              Bc.px -= 0.01;
          }
        }
      }
      else if(Ac.ys == Bc.ys)
      {
        if((Ac.ys == 2 && (Ac.py < Bc.py)) || (Ac.ys == 1 && (Ac.py > Bc.py)))
        {
          cxs = Ac.speedy;
          Ac.speedy = Bc.speedy;
          Bc.speedy = cxs;
        }
        if((Ac.ys == 2 && (Ac.py < Bc.py)) || (Ac.ys == 1 && (Ac.py > Bc.py)))
        {
          cxs = Ac.speedy;
          Ac.speedy = Bc.speedy;
          Bc.speedy = cxs;
        }
      }
   // }
  }
    
    //------------------------------circleA shoutotu leg
    dxAB = Ac.px - leg.x5;
    dyAB = Ac.py - leg.y5;
    if(sqrt(dxAB * dxAB + dyAB * dyAB) < 0.1 && leg.ang1 != 0)
    {
      if(Ac.xs == 1 && ang < 135.01)
      {
        Ac.xs = 2;
        Ac.speedx *= 0.9;
        Ac.speedx += leg.speedx;
        gsx = Ac.speedx / 100;
      }
      if(ang < 90 && Ac.ys == 1)
      {
      Ac.ys = 2;
      Ac.speedy *= 0.9;
      Ac.speedy += leg.speedy;
      gsy = Ac.speedy / 100;
      }
      else if(ang > 90 && Ac.ys == 2)
      {
      Ac.ys = 1;
      Ac.speedy *= 0.9;
      Ac.speedy += leg.speedy;
      gsy = Ac.speedy / 100;
      }
    }
    
    //------------------------------circleB shoutotu leg
    dxAB = Bc.px - leg.x5;
    dyAB = Bc.py - leg.y5;
    if(sqrt(dxAB * dxAB + dyAB * dyAB) < 0.1 && leg.ang1 != 0)
    {
      if(Bc.xs == 1 && ang < 135.01)
      {
        Bc.xs = 2;
        Bc.speedx *= 0.9;
        Bc.speedx += leg.speedx;
        gsx1 = Bc.speedx / 100;
      }
      if(ang < 90 && Bc.ys == 1)
      {
      Bc.ys = 2;
      Bc.speedy *= 0.9;
      Bc.speedy += leg.speedy;
      gsy1 = Bc.speedy / 100;
      }
      else if(ang > 90 && Bc.ys == 2)
      {
      Bc.ys = 1;
      Bc.speedy *= 0.9;
      Bc.speedy += leg.speedy;
      gsy1 = Bc.speedy / 100;
      }
    }
    
    //------------------------------objectA
    if(Ao.px != 5)
    {
      int onc = 0;
      while(onc < 4)
      {
        if(onc == 0)
        {
        cxs = Ao.px;
        cys = Ao.py;
        }
        if(onc == 1)
        {
          cxs = Bo.px;
          cys = Bo.py;
        }
        if(onc == 2)
        {
          cxs = Co.px;
          cys = Co.py;
        }
        if(onc == 3)
        {
          cxs = Do.px;
          cys = Do.py;
        }
      
        dxAB = cxs - Ac.px;
        dyAB = cys - Ac.py;
        if(sqrt(dxAB * dxAB + dyAB * dyAB) < 0.15)
        {
          if(Ac.xs == 1)
            Ac.xs = 2;
          else
            Ac.xs = 1;
          if(Ac.ys == 1)
            Ac.ys = 2;
          else
            Ac.ys = 1;
          
        }
        dxAB = cxs - Bc.px;
        dyAB = cys - Bc.py;
        if(sqrt(dxAB * dxAB + dyAB * dyAB) < 0.15)
        {
          if(Bc.xs == 1)
            Bc.xs = 2;
          else
            Bc.xs = 1;
          if(Bc.ys == 1)
            Bc.ys = 2;
          else
            Bc.ys = 1;
        }
        ++onc;
      }
    }
    
    ++n;
    //printf("Ac.xs%d  Ac.ys%d  Bc.xs%d  Bc.ys%d\n" ,Ac.xs, Ac.ys, Bc.xs, Bc.ys);
    //printf("px%lf  py%lf\n" ,Ac.px, Ac.py);
    glutPostRedisplay();
  }
   
}

//======================================================================================================================================================================================

void first(void)
{
  ang = 0;
  leg.xc = 0.55;
  leg.yc = -0.49;
  leg.ang1 = 1.0;
  leg.x1 = -0.1 + 0.55;
  leg.x2 = -0.1 + 0.55;
  leg.x3 = 0.4 + 0.55;
  leg.x4 = 0.4 + 0.55;
  leg.x5 = 0.4 + 0.55;
  leg.x6 = 0.2 + 0.55;
  leg.y1 = -0.1 - 0.49;
  leg.y2 = 0.1 - 0.49;
  leg.y3 = 0.1 - 0.49;
  leg.y4 = -0.1 - 0.49;
  leg.y5 = -0.3 - 0.49;
  leg.y6 = -0.1 - 0.49;
  leg.speedx = leg.legspeed + 0.0001;
  leg.speedx = leg.legspeed + 0.0001;
  
  Ac.speedx = 0.005;
  Ac.speedy = 0.004;
  Ac.px = -0.5;
  Ac.py = 0;
  Ac.xs = 1;
  Ac.ys = 2;
  Ac.r = 0.1;
  Ac.ro = 0;
  
  Bc.speedx = 0.002;
  Bc.speedy = 0.003;
  Bc.px = 0.7;
  Bc.py = 0.7;
  Bc.xs = 2;
  Bc.ys = 2;
  Bc.r = 0.1;
  Bc.ro = 0;
  
  Ac.pxb = Ac.px;
  Bc.pxb = Bc.px;
  
  if(cj == 1)
  {
    cj = 0;
    glutPostRedisplay();
    glutIdleFunc(init);
  }
  else
  {
    glutPostRedisplay();
    glutIdleFunc(move);
  }
}

//======================================================================================================================================================================================

void reset(void)
{
  ang = 0;
  leg.xc = 0.55;
  leg.yc = -0.49;
  leg.ang1 = 1.0;
  leg.x1 = -0.1 + 0.55;
  leg.x2 = -0.1 + 0.55;
  leg.x3 = 0.4 + 0.55;
  leg.x4 = 0.4 + 0.55;
  leg.x5 = 0.4 + 0.55;
  leg.x6 = 0.2 + 0.55;
  leg.y1 = -0.1 - 0.49;
  leg.y2 = 0.1 - 0.49;
  leg.y3 = 0.1 - 0.49;
  leg.y4 = -0.1 - 0.49;
  leg.y5 = -0.3 - 0.49;
  leg.y6 = -0.1 - 0.49;
  leg.speedx = 0.0001;
  leg.speedx = 0.0001;
  leg.legspeed = 0.0;
  
  Ac.speedx = 0.005;
  Ac.speedy = 0.004;
  Ac.px = -0.5;
  Ac.py = 0;
  Ac.xs = 1;
  Ac.ys = 2;
  Ac.r = 0.1;
  Ac.ro = 0;
  
  Bc.speedx = 0.002;
  Bc.speedy = 0.003;
  Bc.px = 0.7;
  Bc.py = 0.7;
  Bc.xs = 2;
  Bc.ys = 2;
  Bc.r = 0.1;
  Bc.ro = 0;
  
  Ao.j = 0;
  Ao.px = 5;
  Ao.py = 5;
  Bo.j = 0;
  Bo.px = 5;
  Bo.py = 5;
  Co.j = 0;
  Co.px = 5;
  Co.py = 5;
  Do.j = 0;
  Do.px = 5;
  Do.py = 5;
  
  fd = 0;
  
  glutPostRedisplay();
  glutIdleFunc(init);
  
}

//======================================================================================================================================================================================

void mouse(int button, int state, int x, int y){
  switch (button) {
     case GLUT_LEFT_BUTTON:
     	if ( state == GLUT_DOWN)
     	{
       	++cc;
       	cj = 1;
       	Ao.pbx = x;
       	Ao.pby = y;
       	  if(718 < x && x < 743 && 495 < y && y < 702)
     	    {
     	      leg.legspeed = (702 - y) * 0.0001;
     	      legy = y;
       	  }
       	  else if(Ao.pbx == x && Ao.pby == y)
       	  {
     	      if(Ao.j == 0 && cc > 2)
     	        {
     	          Ao.px = -1 + Ao.pbx / 400;
     	          Ao.py = 1 - Ao.pby / 400;
       	        Ao.j = 1;
       	      }
       	    else if(Bo.j == 0 && cc > 2)
     	        {
     	          Bo.px = -1 + Ao.pbx / 400;
     	          Bo.py = 1 - Ao.pby / 400;
     	          Bo.j = 1;
       	      }
       	    else if(Co.j == 0 && cc > 2)
       	      {
       	        Co.px = -1 + Ao.pbx / 400;
     	          Co.py = 1 - Ao.pby / 400;
     	          Co.j = 1;
     	        }
     	      else if(Do.j == 0 && cc > 2)
     	        {
     	          Do.px = -1 + Ao.pbx / 400;
     	          Do.py = 1 - Ao.pby / 400;
     	          Do.j = 1;
       	      }
       	  }
       	  glutIdleFunc(first);
       	  glutPostRedisplay();
       	}
     	break;
     case GLUT_RIGHT_BUTTON:
		if ( state == GLUT_DOWN)
     		glutIdleFunc(NULL);
     	break; 
     default:
     	break; 
  }
}

//======================================================================================================================================================================================

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case '\x73':
      glutIdleFunc(first);
      fd = 1;
      break;
    case '\x72':
      legy = 702;
      glutIdleFunc(reset);
      break;
    case '\x1b':
      exit(0);
  }
}

//======================================================================================================================================================================================

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 800);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
  return 0;
}

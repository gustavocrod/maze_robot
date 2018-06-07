#include "Robby.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Robby::Robby(const Point& iniPos, Maze*l, int maxSteps): Robot(iniPos, l, maxSteps){
    roboTex = LoadTexture("b9.jpg", false);
}

void Robby::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = iniPos.getX();
    int y = iniPos.getY();
    int lx = x;
    int ly = y;
    steps.push_back(Point(x,y));
    int dir=0;
    int dx, dy;
    while(!saiu && cont < maxSteps){
        dx = 0;
        dy = 0;
        switch(dir){
          case 0:	dx = 1; //vai pra direita, anda em x
              break;
          case 1:	dy = 1; //vai pra baixo, anda em Y
              break;
          case 2:	dy = -1; //vai pra cima, anda em Y
              break;
          case 3: dx = -1; //vai pra esquerda, anda em X
              break;
          default:
              dir = 0;
              break;
        }
        if(maze->isEmpty(Point(x+dx, y+dy))){ //se existe o proximo ponto
          y += dy; // conta o proximo passo
          x += dx; // vai pro proximo passo
          steps.push_back(Point(x, y));
          cont++; //computa passo
        }else //se n pode ir, troca o lado para o proximo
          dir++;

        if(x >= maze->getWidth() || x < 0 || y >= maze->getHeight() || y < 0)
            saiu = true;
    }
}

void Robby::draw()
{
    float rx,ry;
    float deltax = GL::getDeltaX();
    float deltay = GL::getDeltaY();
    rx = pos.getX() * deltax;
    ry = pos.getY() * deltay;
    GL::enableTexture(roboTex->texid);
    GL::setColor(255,255,255);
    GL::drawRect(rx, ry, rx+deltax, ry+deltay);
    GL::disableTexture();
}

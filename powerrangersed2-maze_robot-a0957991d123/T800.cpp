#include "T800.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

T800::T800(const Point& iniPos, Maze*l, int maxSteps)
    : Robot(iniPos, l, maxSteps)
{
    srand(time(NULL));
    roboTex = LoadTexture("walle.jpg", false);
}

int T800::next(int dir, int x, int y){

    if(dir == 0){// se ta indo pra direita
        if(maze->isEmpty(Point(x, y+1))){ //testa se pode ir pra cima, pois esquerda da direita é cima
            dir = 1;
        }
        else if(maze->isEmpty(Point(x+1, y))){//senao testa se pode ir pra frente, continuar pra direita
            return 0;
        }
        else if(maze->isEmpty(Point(x, y-1))){ //senao testa se pode ir pra baixo
            dir = 3;
        }
        else{ //ou entao ele vai pra tras
            dir = 2;
        }
    }
    else if(dir == 1){ //se está indo para baixo
        if(maze->isEmpty(Point(x-1, y))){ //testa se pode ir pra direita
            dir = 2;
        }
        else if(maze->isEmpty(Point(x, y+1))){ //testa se pode continuar pra baixo
            return 1;
        }
        else if(maze->isEmpty(Point(x+1, y))){ //ou entao vai pra esquerda
            dir = 0;
        }
        else{//e por ultimo faz o retorno
            dir = 3;
        }
    }
    else if(dir == 2){//se estiver indo pra esquerda
        if(maze->isEmpty(Point(x, y-1))){ //testa se pode ir pra baixo q eh a esquerda da esquerda '-'
            dir = 3;
        }
        else if(maze->isEmpty(Point(x-1, y))){ //se n der testa se pode continuar indo pra frente - esquerda
            return 2;
        }
        else if(maze->isEmpty(Point(x, y+1))){ //ou entao vai pra cima
            dir = 1;
        }
        else{//ou retorna
            dir = 0;
        }

    }
    else{//se estiver indo pra cima
        if(maze->isEmpty(Point(x+1, y))){ //testa se pode ir pra esquerda, q eh a esquerda da cima '-'
            dir = 0;
        }
        else if(maze->isEmpty(Point(x, y-1))){//senao testa se pode ir pra cima - continuar pra frente
            return 3;
        }
        else if(maze->isEmpty(Point(x-1, y))){ //ou entao vai pra direita
            dir = 2;
        }
        else{ //e por fim retorna
            dir = 1;
        }
    }

    return dir;
}

void T800::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = iniPos.getX();
    int y = iniPos.getY();
    steps.push_back(Point(x,y));
    int dir = 0;

    while(!saiu && cont < maxSteps)
    {
        int dx, dy;
        do {
            dx = 0;
            dy = 0;

            dir = T800::next(dir, x, y);
            switch(dir) {
                case 0: dx = 1; //direita
                    break;
                case 1: dy = 1; //vai pra baixo, anda em Y
                    break;
                case 2: dx = -1; //vai pra esquerda, anda em X
                    break;
                case 3: dy = -1; //vai pra cima, anda em Y
                    break;
            }
        }
        while(!maze->isEmpty(Point(x+dx, y+dy)));
        x += dx;
        y += dy;

        steps.push_back(Point(x, y)); //computa o step
        cont++; //conta passo
        if(x >= maze->getWidth() || x < 0 || y >= maze->getHeight() || y < 0)
            saiu = true;
    }
}

void T800::draw()
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

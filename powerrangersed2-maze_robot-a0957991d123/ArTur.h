#ifndef ROBOTARTUR_H
#define ROBOTARTUR_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class ArTur: public Robot {
	public:
        ArTur(const Point& iniPos, Maze*l, int maxSteps);	// Constructor
        void draw();
        void generateSteps();
        vector<Point> getSteps();
        int next(int dir, int x, int y);
    private:
        TEX* roboTex; // robot texture id
};

#endif

#ifndef ROBOTT800_H
#define ROBOTT800_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class T800: public Robot {
	public:
        T800(const Point& iniPos, Maze*l, int maxSteps);	// Constructor
        void draw();
        void generateSteps();
        vector<Point> getSteps();
        int next(int dir, int x, int y);
    private:
        TEX* roboTex; // robot texture id
};

#endif

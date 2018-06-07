#include "TestMaze.h"
#include "Robby.h"
#include "ArTur.h"
#include "T800.h"
#include "GL.h"

using namespace std;

int main()
{
    GL::init();
    // Load the test maze
    Maze* lab = new TestMaze();
    lab->loadMaze("maze3.txt");
    Point posIni = lab->getIniPos();
    cout << "Starting pos: " << posIni.getX() << ", " << posIni.getY() << endl;

      if(lab->getRobot() == 1){
      	Robby* robo = new Robby(posIni, lab, 200);
        cout << "Robby" << endl;
        GL::setMazeRobot(lab, robo);
      }else if(lab->getRobot() == 2){
      	ArTur* robo = new ArTur(posIni, lab, 200);
      	cout << "Ar-thur" << endl;
        GL::setMazeRobot(lab, robo);
      }else if(lab->getRobot() == 3){
      	cout << "T-800" << endl;
      	T800* robo = new T800(posIni, lab, 2000);
        GL::setMazeRobot(lab, robo);
      }

  //GL::setMazeRobot(lab, robo);//nao funciona aq pq robo ta dentro de cada if
	GL::loop();
}

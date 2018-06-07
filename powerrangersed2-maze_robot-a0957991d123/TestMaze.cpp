#include "TestMaze.h"
#include <iostream>

TestMaze :: TestMaze() {
}
// Should load the maze from a text file
// Here is just creates boundaries with an exit at the bottom
void TestMaze :: loadMaze(string arquivo){
    std::ifstream file(arquivo);
    //por pregruica eu to lendo palavra por palavra
    if (!file) {cout << "unable to open the file";}
    if (!(file >> buffer)){cout << "unable to read the file";}//primeira string eh "dim"
    if (!(file >> dimx)){cout << "unable to read the file";} //primeiro valor
    if (!(file >> dimy)){cout << "unable to read the file";} //segundo valor
    //cout << "x " << dimx << " y " << dimy;
    if (!(file >> buffer)){cout << "unable to read the file";} //quarta string eh "pos"
    if (!(file >> inix)){cout << "unable to read the file";} //primeiro valor
    if (!(file >> iniy)){cout << "unable to read the file";} //segundo valor
    if (!(file >> buffer)){cout << "unable to read the file";} //mais um lixo
    if (!(file >> robot)){cout << "unable to read the file";}//valor do robo

    //depois q eu sei o tamanho da matriz
    //percorre o arquivo lendo char por char e  redirecionando cada char pra uma posicao da matriz
    for(int i=0; i<dimx; i++){
        for(int j=0; j<dimy; j++){
            file.get(lab[i][j]); //adiciona o valor em cada posicao da matrix
            if (lab[i][j] == '\n') file.get(lab[i][j]); //gambiarra se ler o fim da linha
            cout << lab[i][j]; //print
        }
        cout << "\n"; //ao fim da linha quebra a linha
    }
    posIni = Point(inix, iniy);
    file.close();
}

// Returns true if the x,y pos is empty
bool TestMaze :: isEmpty(const Point& pos) const {
    if(pos.getX()<0 || pos.getX()>=dimx || pos.getY()<0 || pos.getY()>=dimy) return true;
    return (lab[pos.getY()][pos.getX()]==' ');
}

// Return the maze dimensions
int TestMaze :: getWidth() { return dimx; }
int TestMaze :: getHeight() { return dimy; }

int TestMaze::getRobot() { return robot; }

Point TestMaze::getIniPos() { return posIni; }

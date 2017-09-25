#include "texture.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>


// "C:\\Users\\aleez\\Desktop\\faculdade\\Computação Grafica\\Projeto Codeblocks GLUT\\exercicioDino\\dino.dat"


using namespace std;

Texture::Texture(){

    int atual = 0;
    fstream myFile;
    myFile.open("C:\\Users\\aleez\\Desktop\\faculdade\\Computação Grafica\\Projeto Codeblocks GLUT\\exercicioDino\\dino.dat", ios::in);

    int x;
    int y;

    int q_nucleos;
    int q_pontos;

    vector<int> n;
    vector<int> p;

    myFile >> q_nucleos;
    n.push_back(q_nucleos);
    points.push_back(n);

    for(int i = 0; i < q_nucleos; i++){
            myFile >> q_pontos;
            p.push_back(q_pontos);
            points.push_back(p);
            p.clear();
            for(int j = 0; j < q_pontos; j++){
                myFile >> x >> y;
                p.push_back(x);
                p.push_back(y);
                points.push_back(p);
                p.clear();
            }
    }
    myFile.close();
}

vector< vector<int> > Texture::retornaPontos(){

    return points;
}

void Texture::printaPontos(){

    for(int i = 0; i < points.size(); i++){

        if(points.at(i).size() == 1)
            cout << points.at(i).at(0) << endl;
        else{
            cout << "x: " << points.at(i).at(0) << "  y:  " << points.at(i).at(1) << endl;
        }

    }
}

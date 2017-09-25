#ifndef TEXTURE_H
#define TEXTURE_H
#include <vector>
#include <string>

using namespace std;

class Texture{

private:
    vector< vector<int> > points;
public:
    Texture();
    vector< vector<int> > retornaPontos();
    void printaPontos();
};

#endif // TEXTURE_H


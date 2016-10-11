#ifndef TRANSICAO_H_
#define TRANSICAO_H_

#include <iostream>
#include <string>

class Estado;

using namespace std;

class Transicao{
    
   public:  
    Estado *estadoDestino;
    string simboloTransicao;     
};
#endif
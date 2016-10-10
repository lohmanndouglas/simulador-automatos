#ifndef TRANSICAO_H_
#define TRANSICAO_H_

#include <iostream>
#include <string>

class Estado;

using namespace std;

class Transicao{
    
    // variaveis
    Estado *estadoDestino;
    string simboloTransicao;     
  
  public:
    // construtor
    Transicao(Estado *ed, string s);
    // metodos
};
#endif
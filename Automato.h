#ifndef AUTOMATO_H_
#define AUTOMATO_H_

#include <iostream>
#include <string>
#include "Estado.h"


using namespace std;

class Automato{
    
    // variaveis
    Estado listastado[];
    int quantidadeEstados;
    
  public:

    // construtor
    Automato(int qtdEstados);

    // metodos
    int getAndar_atual();

};
#endif
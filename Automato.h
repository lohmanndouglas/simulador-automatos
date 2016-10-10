#ifndef AUTOMATO_H_
#define AUTOMATO_H_

#include <iostream>
#include <string>
#include "Estado.h"
#include <boost/unordered_map.hpp>
#include <fstream>
#include <sstream>

using namespace std;

class Automato{
    // variaveis
    int quantidadeEstados;
    boost::unordered_map <string, Estado>  mapStringInt;
  
  public:
    // construtor
    Automato(string arquivoEntrada);
};
#endif
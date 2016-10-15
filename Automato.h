#ifndef AUTOMATO_H_
#define AUTOMATO_H_

#include <iostream>
#include <string>
#include "Estado.h"
#include <boost/unordered_map.hpp>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Automato{

    int quantidadeEstados;
    string estadoInicial;
    boost::unordered_map <string, Estado*>  mapStringInt;
    int computarString(string inputString, string estadoAtual,  list<string> l);
  public:
    Automato(string arquivoEntrada);
    int computar(string arquivoStringEntrada);
};
#endif
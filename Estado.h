#ifndef ESTADO_H_
#define ESTADO_H_

#include <iostream>
#include <string>
#include "Transicao.h"
#include <boost/unordered_map.hpp>
#include <list>

using namespace std;

class Estado{
         
  public:
  	string nome;
  	bool inicial;
    bool aceitavel;
    list<Transicao> listaTransicoes;
};
#endif

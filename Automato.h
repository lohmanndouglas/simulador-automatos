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
    Estado *listaEstados;
    int quantidadeEstados;
    Estado estadoInicial;
    Estado estadosAceitaveis[];
    //map <string, int> mapeamento;
    boost::unordered_map <string, Estado>  mapStringInt;
	// boost::unordered_map <std::string, Atributos>::iterator verify;
  
  public:

    // construtor
    Automato(string arquivoEntrada);

    // metodos
    // void addTransicao(string estadoInicial, string estadoFinal, string simbolo);

};
#endif
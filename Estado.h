#ifndef ESTADO_H_
#define ESTADO_H_

#include <iostream>
#include <string>
#include "Transicao.h"
#include <list>

using namespace std;

class Estado{
         
  public:
  	string nome;
    list<Transicao> listaTransicao;
//    HallButton *hall_buttons[NUMBER_OF_FLOORS];
	//array<Transicao> AdjacencyList=new array<Transicao>();
    // construtor
    //Estado(string x,  y);
    // metodos
};
#endif

// #include <array> //for std::array

// std::array<std::string, N> data; //N is compile-time constant
// data[i] = "my name"; //for i >=0 and i < N
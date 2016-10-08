#include "Automato.h"


Automato::Automato(int qtdEstados){
  
  quantidadeEstados = qtdEstados;
  listaEstado=new Estado[qtdEstados];

  for(int i=0;i<qtdEstados;i++){
    listaEstado[i]=new Estado();
  }
}

void Automato::addTransicao(string estadoInicial, string estadoFinal, string simbolo){
  Transicao t=new Transicao(estadoInicial,estadoFinal,simbolo);
  listaEstado[s].AdjacenyList.add(t);// If it were an undirected graph add the edge to source as well as destination node
}


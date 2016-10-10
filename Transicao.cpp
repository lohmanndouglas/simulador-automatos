#include "Transicao.h"

Transicao::Transicao(Estado *ed, string s){
    estadoDestino = ed;
    simboloTransicao = s; 
}
#include "Estado.h"
#include "Automato.h"
#include "Transicao.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  
  Automato a("automato.txt");
  a.ComputarString("inputString.txt");
  return 0;
} 


//  Elevador e(2,6);
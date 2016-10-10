#include "Automato.h"


Automato::Automato(string arquivoEntrada){
  
    ifstream arq;
    arq.open(arquivoEntrada.c_str());
    string data;

    if (arq.is_open() && arq != NULL){
        cout << "Lendo arquivo" << endl; 
        cout << "=============" << endl; 
       
        getline(arq, data); // estados
        cout << "Estados: \n"<< data << endl; 
        istringstream iss(data);

        // Adiciona estados
        quantidadeEstados = 0;
        do {
            string sub;
            iss >> sub;
            if(sub != ""){
                cout << "Substring: " << sub << endl;
                quantidadeEstados++;
            }
        }while(iss);


//        Criar a lista de estados (passar o nome do estado);
//        Criar a hash 
        // listaEstados=new Estado[quantidadeEstados];
        // for(int i=0;i<quantidadeEstados;i++){
        //      listaEstados[i]=new Estado;
        // }

        getline(arq, data); // alfabeto
        cout << "Alfabeto: \n"<< data << endl; 
       
        getline(arq, data); // estado inicial
        cout << "Estado inicial: \n"<< data << endl; 


        //estadoInicial = new Estado();
       
        getline(arq, data); // estados finais 
        cout << "Estado(s) fina(l|is): \n"<< data << endl;

//      add transição para cada estado 
//      buscar na lista pela hash e atualizar
        cout << "Conjunto de transições:"<< endl; 
        while(!arq.fail() && !arq.eof()){ // transições
            getline(arq, data);
            cout << data << endl; 
        }
        arq.close();
    } else{
        cout << "Erro ao abrir o arquivo: " << arquivoEntrada << endl;
        cout << "Automato não foi criado" << endl;
    }
}


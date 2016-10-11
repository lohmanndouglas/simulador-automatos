#include "Automato.h"


Automato::Automato(string arquivoEntrada){
  
    ifstream arq;
    arq.open(arquivoEntrada.c_str());
    string data;
    string alf;
    string est;

    if (arq.is_open() && arq != NULL){
        cout << "Lendo arquivo" << endl; 
        cout << "=============" << endl; 
       
        getline(arq, est); // estados
        cout << "Estados: "<< est << endl; 
        istringstream iss(est);

        // Adiciona estados
        quantidadeEstados = 0;
        do {
            string sub;
            iss >> sub;
            if(sub != ""){
                // cout << "Estado: " << sub << endl;
                mapStringInt[sub] = new Estado();
                mapStringInt[sub]->nome = sub;
                mapStringInt[sub]->inicial = false;
                mapStringInt[sub]->aceitavel = false;
                quantidadeEstados++;
            }
        }while(iss);


        getline(arq, alf); // alfabeto
        cout << "Alfabeto: "<< alf << endl; 
       
        getline(arq, data); // estado inicial
        mapStringInt[data]->inicial = true;
        estadoInicial = data;
        cout << "Estado inicial: "<< data << endl; 
       
        getline(arq, data); // estados finais 
        // cout << "Estado(s) fina(l|is): \n"<< data << endl;
    
        istringstream iss2(data);
        do {
            string sub;
            iss2 >> sub;
            if(sub != ""){
                cout << "Estado aceitavel: " << sub << endl;
                mapStringInt[sub]->aceitavel = true;
            }
        }while(iss2);

        cout << "Transições" << endl;
        istringstream iss3(est); 
        do {
            string estA;
            iss3 >> estA;
            if(estA != ""){ // para o estado estA
                getline(arq, data);
                istringstream iss4(alf);
                istringstream iss5(data); 
                do {
                    string estadosPos;
                    string sub;
                    iss4 >> sub;
                    iss5 >> estadosPos;
                    if(sub != ""){ // para cada letra do alfabeto
                        cout << "   Do estado " << estA ;
                        cout << " com o simbolo " << sub;
                        string estDest;
                        istringstream iss6(estadosPos);
                        cout << " vai para ";                        
                        while(getline(iss6,estDest,',')){
                        	cout << estDest << " ";
                        } 
                        cout << endl;
                        // Adiciona na lista de transições do estado estA a transição <sub, estadoPos>
                        //mapStringInt[estA]->mapStringTransicao[sub].estadoDestino = mapStringInt[estadosPos];
                    }
                }while(iss4);
            }
        }while(iss3);
        // cout<< mapStringInt["q1"]->mapStringTransicao["1"].estadoDestino->nome << endl;
        arq.close();
        cout << " +===== Automato Criado =====+ " << endl << endl; 

    } else{
        cout << "Erro ao abrir o arquivo: " << arquivoEntrada << endl;
        cout << "Automato não foi criado" << endl;
    }
}

int Automato::ComputarString(string arquivoStringEntrada){
    ifstream arq;
    arq.open(arquivoStringEntrada.c_str());
    string data;
    string simbolo;
    string atual = estadoInicial;
    string tmp;
    if (arq.is_open() && arq != NULL){
        getline(arq, data);
        while(!arq.fail()){
            cout << " ** ComputarString: " << data << " **"<< endl;

            for(int i=0; i < data.length();i++){ //consumir todos os simbolos da string
                simbolo = data[i];
                cout << "  -Consome simbolo: " << simbolo; 
                tmp = mapStringInt[atual]->mapStringTransicao[simbolo].estadoDestino->nome;
                atual = tmp;
                cout << " | Vai para estado: " << atual << endl;
            }
            if(mapStringInt[atual]->aceitavel){
                cout << " ++ Aceita string ++ " << endl << endl;
                //return 1;
            } else {
                cout << " ++ Rejeita string ++ " << endl << endl;
                //return 0;           
            }
            getline(arq, data);
        }
        arq.close();
    }else{
        cout << "Erro: Arquivo de Entrada" << endl;
    }
}
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
                mapStringInt[sub].nome = sub;
                mapStringInt[sub].inicial = false;
                mapStringInt[sub].aceitavel = false;
                quantidadeEstados++;
            }
        }while(iss);


        getline(arq, alf); // alfabeto
        cout << "Alfabeto: "<< alf << endl; 
       
        getline(arq, data); // estado inicial
        mapStringInt[data].inicial = true;
        cout << "Estado inicial: "<< data << endl; 
       
        getline(arq, data); // estados finais 
        // cout << "Estado(s) fina(l|is): \n"<< data << endl;
    
        istringstream iss2(data);
        do {
            string sub;
            iss2 >> sub;
            if(sub != ""){
                cout << "Estado aceitavel: " << sub << endl;
                mapStringInt[sub].aceitavel = true;
            }
        }while(iss2);

        cout << "Transições" << endl;
        istringstream iss3(est); 
        do {
            string estA;
            iss3 >> estA;
            if(estA != ""){ // para o estado sub
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
                        cout << " vai para " << estadosPos << endl;
                        //mapStringInt[estadosPos].nome = "estadosPos";
                        mapStringInt[estA].mapStringTransicao[sub].simboloTransicao = sub; 
                        mapStringInt[estA].mapStringTransicao[sub].estadoDestino = mapStringInt[estadosPos];
                    }
                }while(iss4);
            }
        }while(iss3);

        arq.close();

    } else{
        cout << "Erro ao abrir o arquivo: " << arquivoEntrada << endl;
        cout << "Automato não foi criado" << endl;
    }
}
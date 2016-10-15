#include "Automato.h"


Automato::Automato(string arquivoEntrada){
  
    ifstream arq;
    arq.open(arquivoEntrada.c_str());
    string data;
    string alf;
    string est;

    if (arq.is_open() && arq != NULL){
        cout << " +===== Lendo arquivo  ======+ " << endl; 
       
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
    
        istringstream iss2(data);
        do {
            string sub;
            iss2 >> sub;
            if(sub != "" && sub != "-"){
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
                        string estDest;
                        istringstream iss6(estadosPos);                     
                        while(getline(iss6,estDest,',')){
                        	if(estDest != "-"){
                        		cout << "Do estado " << estA;
                       			cout << " com o simbolo " << sub;
		                        cout << " vai para ";   
                        		cout << estDest << endl;
                        		Transicao tempTrans;
                        		tempTrans.simboloTransicao = sub;
                        		tempTrans.estadoDestino = mapStringInt[estDest];
                        		mapStringInt[estA]->listaTransicoes.push_back(tempTrans);
                        	}
                        } 
                    }
                }while(iss4);
            }
        }while(iss3);
        arq.close();
        cout << " +===== Automato Criado =====+ " << endl;
        string aa;
    } else{
        cout << "Erro ao abrir o arquivo: " << arquivoEntrada << endl;
        cout << "Automato não foi criado";
    }
}

int Automato::computar(string arquivoStringEntrada){
    ifstream arq;
    arq.open(arquivoStringEntrada.c_str());
    string data;

    if (arq.is_open() && arq != NULL){
        getline(arq, data);
        while(!arq.fail()){
        	cout << " ** String: " << data ;
       	
       	    list<string> listaLoop;

        	if(computarString(data, estadoInicial, listaLoop)){
				cout << "    - Aceita" << endl;
        	}else{
        		cout << "    - Rejeita" << endl;
        	}
            getline(arq, data);
        }
        arq.close();
    }else{
        cout << "Erro: Arquivo de Entrada" << endl;
    }
}

int Automato::computarString(string inputString, string estadoAtual, list<string> l){
	list<Transicao>::iterator i;
	string a; 
	string b;
	a = inputString[0];
	int ver = 0;
    if(mapStringInt[estadoAtual]->aceitavel && inputString.length() <= 0 || \
    	(inputString == "-" && mapStringInt[estadoAtual]->aceitavel)){
       	return 1;
	} 
	if(!(mapStringInt[estadoAtual]->aceitavel) && inputString.length() <= 0){
       	return 0;           
    }
	// percore a lista de transições do estado atual
    for (i = mapStringInt[estadoAtual]->listaTransicoes.begin(); \
    	i != mapStringInt[estadoAtual]->listaTransicoes.end(); ++i){
        b = i->simboloTransicao;
    	if (a == b){ // se o simbolo de entrada é igual ao simbolo da transição
    		list<string> copia; 
        	ver += computarString(inputString.substr(1,inputString.length()),i->estadoDestino->nome, copia);
    	}
    	int status = 0;
    	if (find(l.begin(), l.end(), i->estadoDestino->nome) != l.end()){
    		//cout << "aafdsfdsfdsaa" << endl;
    		status = 1;
    	}
    	if (b == "e" && !(status)){ // verficiar se ta na lista
    		list<string> copia;
    		string s;
            list<string>::iterator interatorL;
	        for(interatorL=l.begin(); interatorL != l.end(); ++interatorL){ 
	        	string s = *interatorL;
	        	copia.push_back(s);
	    	}
	    	copia.push_back(i->estadoDestino->nome);
    		ver += computarString(inputString,i->estadoDestino->nome, copia);
    	} // se é uma transicao com epsilon
    }
    return ver;
}
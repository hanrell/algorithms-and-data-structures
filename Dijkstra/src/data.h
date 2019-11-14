#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


/** Classe que representará o grafo */
class Data {

private:
    void parseInstance(string caminhoInstancia);

    vector<vector<int>> matrizAdj;
    int size;

public:
    Data(string caminhoInstancia){
        parseInstance(caminhoInstancia);
    }

    ~Data(){
        
    }

    /** Função que retorna a matriz de adjacência do grafo */
    inline vector<vector<int>> getMatriz(){
        return  matrizAdj;
    }

    /** Função que retorna o número de vértices do grafo */
    inline int getGraphSize(){
        return size;
    }
};

#endif
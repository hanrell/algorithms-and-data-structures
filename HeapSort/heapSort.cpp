/***************************************************************************
/* Heap Máximo e HeapSort
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 05/11/2019
/***************************************************************************/


//BIBLIOTECAS
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//PROTÓTIPOS
void buildMaxHeap(vector<long int>&, int&);
void maxHeapify(vector<long int>&, int, int&);
void heapSort(vector<long int>&, int&);
int filhoEsquerdo(int);
int filhoDireito(int);




/*################################### MAIN ###################################*/
int main(int argc, char **argv){

    string filename;

    cout << "Digite o nome do arquivo de entrada (exemplo: 'num.1000.1.in'): " << endl;
    cin >> filename;

    string path = "input/" + filename;
    
    
    ifstream instancia(path, ios::in);                   // Caminho para o arquivo de instância passado como argumento de linha de comando.
    if(!instancia){
        cout << "O arquivo nao pode ser aberto" << endl;
         return -1; 
    }                              
    
    int tamanho;                                            // Guarda o tamanho do vetor a ser criado.

    instancia >> tamanho;                                   // A primeira linha do arquivo indica o tamanho do vetor.

    vector<long int> heap(tamanho);                    // Cria um vetor no tamanho adequado.

    int heapSize = tamanho - 1;

    for (int i = 0; i < tamanho; i++){
        instancia >> heap[i];                               // Insere todos os valores do arquivo no vetor.
    }

    instancia.close();

    heapSort(heap, heapSize);

    filename.erase(filename.length() - 2,filename.length());

    ofstream ordered ("output/" + filename + "out");
    if(!ordered){
        cout << "O arquivo nao pode ser criado" << endl;
         return -1; 
    }
   
    for (int i = 0; i < tamanho; i++){
        ordered << heap[i] << endl;
    }

    ordered.close();
}

/*Função que retorna o índice do filho esquerdo do nó raiz*/
int filhoEsquerdo(int i){
    return (2*i) + 1;
}

/*Função que retorna o índice do filho direito do nó raiz*/
int filhoDireito(int i){
    return (2*i) + 2;
}

/*
* Subrotina que mantém a propriedade de heap máximo. Supõe que heap->A[i]
* pode ser menor que seus filhos e as subárvores da esquerda e direita
* são heaps máximos.
*/
void maxHeapify (vector<long int> &heap, int i, int &heapSize){
    
    int left = filhoEsquerdo(i);
    int right = filhoDireito(i);
    int maior = i;                                          // Guarda o maior valor da (sub)árvore, começamos supondo que é o nó raiz.

    if(left <= heapSize && heap[left] > heap[maior]) maior = left;
    if(right <= heapSize && heap[right] > heap[maior]) maior = right;

    if(maior != i){                             
        swap(heap[i], heap[maior]);                         // Coloca o maior valor na raiz.
        maxHeapify(heap, maior, heapSize);                  // Rerganiza do resto da árvore para manter a integridade de Heap Máxima.
    }

}

/*Função que cria o Heap Máximo*/
void buildMaxHeap(vector<long int> &heap, int &heapSize){
    
    for (int i = ((heap.size() - 1)/2); i >= 0; i--)       // Vai do último nó não-folha para a raiz (0).
        maxHeapify(heap, i, heapSize);
}


/*Função que ordena o vetor em ordem crescente*/
void heapSort(vector<long int> &heap, int &heapSize){

    buildMaxHeap(heap, heapSize);
    for(int i = heap.size()-1; i > 0; --i){
        swap(heap[0], heap[i]);
        --heapSize;
        maxHeapify(heap, 0, heapSize);

    }
}

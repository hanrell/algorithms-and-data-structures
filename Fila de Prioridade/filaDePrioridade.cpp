/***************************************************************************
/* Heap Máximo e Fila de Prioridade Máxima
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 10/12/2019
/***************************************************************************/


//BIBLIOTECAS
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

//PROTÓTIPOS
void buildMaxHeap(vector<long int>&, int&);
void maxHeapify(vector<long int>&, int, int&);
int filhoEsquerdo(int);
int filhoDireito(int);
int pai(int);
long int maximum(vector<long int>&);
long int heapExtractMax(vector<long int>&, int&);
void heapIncreaseKey(vector<long int>&, int, int);
void maxHeapInsert(vector<long int>&, int&, int);




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

    vector<long int> heap(tamanho);                         // Cria um vetor no tamanho adequado.

    int heapSize = tamanho - 1;                             //Controle de ocupação.

    for (int i = 0; i < tamanho; i++){
        instancia >> heap[i];                               // Insere todos os valores do arquivo no vetor.
    }

    instancia.close();

    buildMaxHeap(heap, heapSize);

    for (int i = 0; i < tamanho; i++){
        cout <<  heap[i] << endl;
    }

    char opcao;
    /*Menu de opções para manipulação da fila de prioridade*/
	while(1){
		puts("\nO que voce deseja fazer?");
		puts("\tLer elemento de maior prioridade: M");
		puts("\tExtrair elemento de maior prioridade: E");
		puts("\tInserir elemento: I");
        puts("\tPara sair do programa: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'M':
				cout << endl << maximum(heap);
				break;
			case 'E':
                heapExtractMax(heap, heapSize);
                for (int i = 0; i <= heapSize; i++){
                    cout <<  heap[i] << endl;
                }
                break;
            case 'I':{
                int key;
                cout << endl << "Digite chave do novo elemento: ";
                cin >> key;
                maxHeapInsert(heap, heapSize, key);
                for (int i = 0; i <= heapSize; i++){
                    cout <<  heap[i] << endl;
                }
                break;
            case 'S':
                exit(0);
            default:
                cout <<  "Opção invalida" << endl;
            }
        }

    }

    
}

/*Função que retorna o índice do filho esquerdo do nó raiz*/
int filhoEsquerdo(int i){
    return (2*i) + 1;
}

/*Função que retorna o índice do filho direito do nó raiz*/
int filhoDireito(int i){
    return (2*i) + 2;
}

/*Função que retorna o índice do nó pai*/
int pai(int i){
    return ((i-1)/2);
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

/*Função que retorna o valor máximo da heap (raiz)*/
long int maximum(vector<long int> &heap){
    return heap[0];
}

/*Função que extrai e retorna o elemento de maior chave da heap (raiz)*/
long int heapExtractMax(vector<long int> &heap, int &heapSize){
    
    if (heapSize < 0){
        cout << "Heap underflow." << endl;
        return -1;
    }

    long int max = heap[0];
    heap[0] = heap[heapSize--];
    maxHeapify(heap, 0, heapSize);

    return max;
}

/*Função que aumenta a chave do elemento no índice heapSize para o novo 
* valor (int key) que se presume ser maior que o valor atual do elemento*/
void heapIncreaseKey(vector<long int> &heap, int heapSize, int key){

    if(key < heap[heapSize]){
        cout << "Nada a ser feito." << endl;
        return;
    }

    heap[heapSize] = key;

    int i = heapSize;
    while(i > 0 && (heap[i] > heap[pai(i)])){                           // Enquanto o pai for menor que o filho, troque-os.
        swap(heap[i], heap[pai(i)]);
        i = pai(i);
    }

}

/*Insere um elemento na heap com a chave desejada*/
void maxHeapInsert(vector<long int> &heap, int &heapSize, int key){

    if((heapSize + 1) == heap.size()){
        cout << "Vetor cheio." << endl;
        return;
    }

    heapSize++;
    long int minimum = std::numeric_limits<long int>::min();
    heap[heapSize] = minimum;
    heapIncreaseKey(heap, heapSize, key);

}
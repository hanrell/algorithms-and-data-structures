/***************************************************************************************
 * Heap Mínimo e Fila de Prioridade Mínima
 * Authors: Hanrell Ramon, Iderval Neto
 * Last update: 14/11/2019
 *
 * Fórmulas da heap:
 * Pai = (i-1)/2;
 * Filho esquerdo = i*2 + 1;
 * Filho direito = i*2 + 2;
 * 
 * A HEAP É UM PAR DE INTEIROS ONDE HEAP.FIRST = INDICE, HEAP.SECOND = VALOR ASSOCIADO.
 **************************************************************************************/

// BIBLIOTECAS
#include "heaps.h"

/***************************************************************************************/


/* Subrotina que mantém a propriedade de heap mínimo. Supõe que heap->A[i]
* pode ser maior que seus filhos e as subárvores da esquerda e direita
* são heaps mínimos.
*/
void minHeapify(vector<pair<int, int>> &heap, int no, int fim) {
  int menor = no;
  int esquerdo = no * 2 + 1;
  int direito = no * 2 + 2;

  if (esquerdo < fim) {
    if (heap[esquerdo].second < heap[menor].second) {
      menor = esquerdo;
    }
  }
  if (direito < fim) {
    if (heap[direito].second < heap[menor].second) {
      menor = direito;
    }
  }
  if (menor != no) {
    swap(heap[no], heap[menor]);
    minHeapify(heap, menor, fim);
  }
}

/*Função que retorna o indice e valor mínimo da heap (raiz)*/
pair<int, int> heapMin(vector<pair<int, int>> &heap) { 
  return heap[0]; 
}

/*Insere um elemento na heap com a chave desejada*/
void heapMinInsert(vector<pair<int, int>> &heap, int i, int value) {
  pair<int, int> p = {i, numeric_limits<int>::max()};                         // Adiciona um valor extremamente alto para que depois possa ser alterado.
  heap.push_back(p);
  heapDecreaseKey(heap, value, i);
}

/*Função que ajusta a chave do elemento no dado índice para o novo 
* valor (int value) que se presume ser menor que o valor atual do elemento*/
void heapDecreaseKey(vector<pair<int, int>> &heap, int value, int indice) {
  if (value < heap[indice].second) {
    heap[indice].second = value;

    if (heap.size() == 1)                                                     // Se só houver um elemento, não precisa fazer reajustes na heap.
      return;

    int pai = (indice - 1) / 2;
    while (heap[pai].second > heap[indice].second) {
      swap(heap[indice], heap[pai]);
      indice = pai;
      pai = (indice - 1) / 2;
    }
  }
}

/*Função que extrai e retorna o elemento de menor valor da heap (raiz)*/
pair<int, int> heapExtractMin(vector<pair<int, int>> &heap) {
  if (heap.size() < 1) {
    cout << "Underflow\n";
    exit(1);
  }
  pair<int, int> retorno = heap[0];
  swap(heap[0], heap[heap.size() - 1]);
  heap.pop_back();
  minHeapify(heap, 0, heap.size());

  return retorno;
}
/***************************************************************************************
 * Algorítmo de Dijkstra - Problema do Caminho Mínimo
 * Authors: Hanrell Ramon, Iderval Neto
 * Last update: 14/11/2019
 ***************************************************************************************/

//BIBLIOTECAS
#include "dijkstra.h"
#include <limits>


/*###################################### MAIN #########################################*/
int main(int argc, char **argv) {

  if (argc != 2) {
    cout << "Numero errado de argumentos! Utilize da seguinte forma:\n ./heap "
            "<caminho/da/instancia>\n";

    exit(0);
  }

  string caminho = argv[1];
  Data data(caminho);                                                                   //Grafo.
  vector<int> predecessores(data.getGraphSize());                                       //Vetor de nós predecessores.
  vector<int> distancia = gerarDistInicial(data.getGraphSize(), predecessores, 0);
  

  dijkstra(data, 0, distancia, predecessores);
  printMatriz(data);

  cout << endl;
  for (int i = 0; i < distancia.size(); i++) {
    cout << distancia[i] << " ";
  }
}
/*#####################################################################################*/

/* Função que inicia todas as distancias em infinito para posteriormente serem alteradas pelo algoritmo de Dijkstra */
vector<int> gerarDistInicial(int size, vector<int> &p, int source) {
  vector<int> dist(size);

  for (int i = 0; i < dist.size(); i++) {

    dist[i] = numeric_limits<int>::max();
    p[i] = -1;                                                                          // Todos os predecessores iniciam em -1;
  }
  dist[source] = 0;                                                                     // A origem começa com distancia 0.
  return dist;
}


void relaxar(pair<int, int> noAtual, int vizinho, Data data,
             vector<pair<int, int>> &heap, vector<int> &dist, vector<int> &p) {

  int aresta = noAtual.second + data.getMatriz()[noAtual.first][heap[vizinho].first];

  if (heap[vizinho].second > aresta) {
    dist[heap[vizinho].first] = aresta;

    heapDecreaseKey(heap, aresta, vizinho);

    p[vizinho] = noAtual.first;
  }
}

/********************** Algorítmo de Dijkstra ***************************/
void dijkstra(Data data, int source, vector<int> &dist, vector<int> &p) {
  vector<bool> visitados(data.getGraphSize());                                        //Vetor que irá guardar os nós já visitados.
  vector<pair<int, int>> heap;

  for (int i = 0; i < data.getGraphSize(); i++) {
    heapMinInsert(heap, i, dist[i]);
  }

  while (!heap.empty()) {

    pair<int, int> u = heapExtractMin(heap);

    visitados[u.first] = true;

    for (int i = 0; i < heap.size(); i++) {
        relaxar(u, i, data, heap, dist, p);
        for (int i = 0; i < heap.size(); i++) {
          cout << heap[i].second << " ";
        }
        cout << endl;


    }
  }
}

void printMatriz(Data data) {
  for (int i = 0; i < data.getGraphSize(); i++) {
    for (int j = 0; j < data.getGraphSize(); j++) {
      cout << data.getMatriz()[i][j] << " ";
    }
    cout << endl;
  }
}
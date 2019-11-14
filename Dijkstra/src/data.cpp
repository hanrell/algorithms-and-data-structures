#include "data.h"

void Data::parseInstance(string caminhoInstancia) {
  ifstream arquivo(caminhoInstancia, ios::in);

  if (!arquivo) {
    cerr << "Erro ao abrir instancia\n" << endl;
    exit(0);
  }



  int v;                                               // Número de vertices.
  arquivo >> v;
  vector<vector<int>> m(v, vector<int>(v));
  
  for (int i = 0; i < v; i++) {                        // Preenche a matriz de adjacências.
    for (int j = i; j < v; j++) {
      if (i == j)
        m[i][j] = 0;
      else
        arquivo >> m[i][j];
      m[j][i] = m[i][j];                              // Grafo não direcionado.
    }
  }


  matrizAdj = m;
  size = v;
}

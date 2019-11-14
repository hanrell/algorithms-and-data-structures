#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include "data.h"
#include "heaps.h"

using namespace std;

vector<int> gerarDistInicial(int size, vector<int> &p, int source);
void printMatriz(Data data);
void dijkstra(Data data, vector<int> &distance, vector<int> &p);

#endif

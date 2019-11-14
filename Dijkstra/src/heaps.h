#ifndef HEAPS_H
#define HEAPS_H

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

void minHeapify(vector<pair<int,int>> &heap, int no, int fim);
pair<int, int> heapMin(vector<pair<int, int>> &heap);
void heapMinInsert(vector<pair<int, int>> &heap, int i, int value);
void heapDecreaseKey(vector<pair<int, int>> &heap, int value, int indice) ;
pair<int, int> heapExtractMin(vector<pair<int, int>> &heap);

#endif

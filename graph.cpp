#include "graph.h"
#include <bits/stdc++.h>
#include <iostream>

#define INF 99999999

using namespace std;

graph :: graph(int ver){
  vertices = ver;
}
graph :: ~graph(){
}
void graph :: FW_alg(int** graph){
  int** matrix;
  // let matrix[][] = graph[][] 
  for(int i=0; i<vertices; i++){
    for(int j=0; j<vertices; j++){
      matrix[i][j] = graph[i][j];
    }
  }
  // 
  for(int k=0; k<vertices; k++){
    for(int i=0; i<vertices; i++){
      for(int j=0; j<vertices; j++){
        
      }
    }
  }
}
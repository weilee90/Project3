#include "graph.h"
#include <bits/stdc++.h>
#include <iostream>

#define INF 99999999

using namespace std;

graph :: graph(int ver, int adj, int ** graph, int start, int end){
  vertices = ver;
  build_graph(graph);
  // print_graph(ver, graph);
  start_graph(ver, adj, graph, start, end);
}
graph :: ~graph(){
}
void graph :: build_graph(int** graph){
  // initial
  int** dist = new int*[vertices];
  for (int i = 0; i <= vertices; i++)
    *(dist+i) = new int[vertices];
  
  for(int i=0; i<vertices; i++){
    for(int j=0; j<vertices; j++){
      dist[i][j] = graph[i][j];
    }
  }
  // 
  for(int k=0; k<vertices; k++){
    for(int i=0; i<vertices; i++){
      for(int j=0; j<vertices; j++){
        if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}
void graph :: print_graph(int ver, int** graph){
  for (int i = 0; i < ver; i++){
    for (int j = 0; j < ver; j++){
      cout << graph[i][j] << '\t';
    }
    cout<< endl;
  }
}
void graph :: start_graph(int ver, int adj, int ** graph, int start, int end){
  cout << "Command: start-graph " << start << " " << end << endl << endl;
  cout << "The graph G for the years " << start << "-" << end << " has:" << endl;
  cout << "\t|V| = " << ver << " vertices" << endl;
  cout << "\t|E| = " << adj << " edges" << endl;
  
}
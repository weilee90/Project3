#include "commands.h"
#include "graph.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#define INF 99999999

int main(int argc, char *argv[]) {
  std::fstream edges_file;
  std::fstream dates_file;
  std::fstream commands_file;

  edges_file.open(argv[1], ios::in);
  dates_file.open(argv[2], ios::in);
  commands_file.open(argv[3], ios::in);

  string command;
  int start_year, end_year;

  // read commands
  if (commands_file.is_open()) {
    getline(commands_file, command);
    string to_add = "";
    int time = 0;
    for (int i = 0; i <= command.length(); i++) {
      if (command[i] == ' ' || i == command.length()) {
        if (time == 0) {
          time++;
        } else if (time == 1) {
          start_year = stoi(to_add);
          time++;
        } else if (time == 2) {
          end_year = stoi(to_add);
        }
        to_add = "";
        i++;
      }
      to_add += command[i];
    }
  }
  
  string line;
  int ver_len = 0;
  int current_year, current_vertex;
  int *vertex_label = new int[416650];
  // read data
  if (dates_file.is_open()) {
    while (getline(dates_file, line)) {
      string to_add = "";
      for (int i = 0; i < line.length(); i++) {
        if (line[i] == '\t') {
          current_vertex = stoi(to_add);
          to_add = "";
          i++;
        }
        else if (i == line.length()-1) {
          to_add += line[line.length()-1];
          current_year = stoi(to_add);
        }
        to_add += line[i]; 
      }
      // store the vertex in the range
      if (current_year >= start_year && current_year <= end_year) {
        vertex_label[ver_len] = current_vertex;
        ver_len++;
      } else if (current_year > end_year) {        
        break;
      }
    }
  }

  // sort the vertices
  insertionSort(vertex_label, ver_len);

  line = "";
  int adj_len = 0;
  int this_vertex, passed_vertex;
  int **adjacency = new int*[ver_len];

  for (int i = 0; i < ver_len; i++){
    *(adjacency+i) = new int[ver_len];
    for (int j = 0; j < ver_len; j++){
      adjacency[i][j] = INF;
    }
  }

  // read edges
  if (edges_file.is_open()) {
    while (getline(edges_file, line)) {
      string to_add = "";
      this_vertex = 0;
      passed_vertex = 0;
      int time = 0;
      for (int i = 0; i < line.length(); i++) {
        if (line[i] == '\t' || i == line.length()-1) {
          if (time == 0) {
            this_vertex = stoi(to_add);
            time++;
          } else if (i == line.length()-1) {
            to_add += line[i];
            passed_vertex = stoi(to_add);
          }
          to_add = "";
          i++;
        }
        to_add += line[i];
      }
      
      // find the the empty spot to add the passed vertex
      for (int i = 0; i < ver_len; i++) {
        if (this_vertex == vertex_label[i]) {
          adj_len++;
          if (adjacency[i][0] == INF) {
            adjacency[i][0] = passed_vertex;
          } else {
            int j = 1;
            while (adjacency[i][j] != INF) {
              j++;
            }
            adjacency[i][j] = passed_vertex;
          }
        }
      }
    }
  }
  graph fw_graph(ver_len, adj_len, adjacency, start_year, end_year);

}
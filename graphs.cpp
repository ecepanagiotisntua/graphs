#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
 private:
 int size;
 bool **adj;
 enum state {UNVISITED, VISITED};
 
 
 public:
 
 Graph(int V)
 : adj(new bool*[V])
 {
   for(int i = 0; i < V; i++)
   {
     adj[i] = new bool[V];
     adj[i] = {0};
   }
 }

 ~Graph()
 {
   for(int i = 0; i < size; i++) delete [] adj[i];
   delete [] adj;
 }
 
 void addEdge(int u, int v)
 {
  adj[u][v] = 1;
 }

 bool cycle(vector<int> &path) const
 {
  
 
 }
};



bool cycle(vector<int>& path) 
{ 
    path = {0};
    
  
    // For every node of the graph 
    for (int i = 0; i < V; i++) { 
      for (int j = 0 ; j < V; j++){
        // If some node is adjacent to the current node 
        // and it has not already been visited 
        if (adj[i][j] == 1 ) { 
            path[i]++;
            cycle_help(j, )
        }
      }
    } 
} 
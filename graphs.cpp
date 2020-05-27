#include <iostream>  
#include <vector>  
#include <list>  
  
#define nullptr NULL  
  
using namespace std;  
  
class Graph {  
public:  
    Graph(int V) {  
        this->V = V;  
        adj = new list<int>[V];  
    }  
  
    ~Graph() { delete [] adj; }  
  
    void addEdge(int u, int v) {  
        adj[u].push_back(v);  
    }  
  
    bool cycle(vector<int> &path) const {  
        int stack[V];  
        bool visited[V];  
        for(int i = 0; i < V; i++) {  
          visited[i] = false;  
          stack[i] = -1;  
        }  
        int start = 0;  
        for (int i = 0; i < V; i++) {  
          int j = 0;  
          if (help (i, visited, stack, j, start)) {  
            for (int k = start; k < j; k++)  
              path.push_back(stack[k]);  
            return 1;  
          }  
        }  
        return 0;  
    }  
  
protected:  
    int V;  
    list<int> *adj;  
    bool help(int v, bool vis[], int st[], int &i, int &strt) const {  
        if (!vis[v]) {  
            vis[v] = true;  
            st[i] = v;  
            i++;  
        }  
        list<int>::iterator j;  
        for(j = adj[v].begin(); j != adj[v].end(); ++j) {  
            if(!vis[*j] && help(*j, vis, st, i, strt))  
                return true;  
            else {  
                for (int k = 0; k < i; k++) {  
                    if (st[k] == *j) {  
                    strt = k;  
                    return true;  
                    }  
                }  
            }  
        }  
        st[v] = -1;  
        i--;  
        return false;  
      }  
};
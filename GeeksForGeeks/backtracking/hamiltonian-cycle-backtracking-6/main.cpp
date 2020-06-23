#include <bits/stdc++.h>
using namespace std;


struct TEdge{
  int src, dst;
  TEdge(int source, int destination): src(source), dst(destination){};
};


class Graph{
  public: 
    vector<vector<int>> adj;
    vector<TEdge> edges;
    Graph(){
      adj = *new vector<vector<int>>();
      edges = *new vector<TEdge>();
    }
    void addEdge(int src, int dst){
      while(adj.size() <= src || adj.size() <= dst)
        adj.push_back(*new vector<int>());

      adj[src].push_back(dst);
      adj[dst].push_back(src);

      edges.push_back(*new TEdge(src, dst));
    }
    int size(){
      return adj.size();
    }
};





bool dfsUtil(vector<vector<int>> adj, int *visited, int *currPath, int *pathPos, int src){

  for(int i = 0 ; i < adj.size() ; i++)
    cout << currPath[i] << "  ";
  cout << endl;

  for(vector<int>::iterator itr = adj[src].begin() ; itr != adj[src].end() ; ++itr){
    
    if(!visited[*itr]){

      visited[*itr] = 1;
      currPath[(*pathPos)++] = *itr;

      if(dfsUtil(adj, visited, currPath, pathPos, *itr))
        return true;

      (*pathPos)--;
      visited[*itr] = 0;

    } else if((*itr == currPath[0]) && (*itr != src) && (*pathPos == adj.size())){
      return true;
    }
  }

  return false;
}



int findHamiltonianCycle(vector<vector<int>> adj, int *path){

  memset(path, 0, adj.size() * sizeof(int));
  int pathPos = 0;

  int *visited = new int[adj.size()];
  memset(visited, 0, adj.size() * sizeof(int));

  for(int i = 0 ; i < adj.size() ; i++){

    visited[i] = 1;
    path[pathPos++] = i;

    if(dfsUtil(adj, visited, path, &pathPos, i))
      return pathPos;

    pathPos--;
    visited[i] = 0;

  }
    
  
  return 0;
}




// https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/
int main(int argc, char **argv, char **envp){

  Graph G;
  int size, *path;
  
  
  G = *new Graph();
  G.addEdge(0, 1);
  G.addEdge(0, 3);
  G.addEdge(1, 2);
  G.addEdge(1, 3);
  G.addEdge(1, 4);
  G.addEdge(2, 4);
  G.addEdge(3, 4);
  path = new int[G.size()];
  size = findHamiltonianCycle(G.adj, path); 
  assert(size == G.size());




  G = *new Graph();
  G.addEdge(0, 1);
  G.addEdge(0, 3);
  G.addEdge(1, 2);
  G.addEdge(1, 3);
  G.addEdge(1, 4);
  G.addEdge(2, 4);
  path = new int[G.size()];
  size = findHamiltonianCycle(G.adj, path); 
  assert(size == 0);


  cout << "Program is exiting..." << endl; 
  return 0; 
}
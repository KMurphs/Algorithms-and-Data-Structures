#include <bits/stdc++.h>

using namespace std;

struct TEdge{
  int src, dst;
  TEdge(int _src, int _dst): src(_src), dst(_dst){}
};

class Graph{
  public:
    vector<TEdge *> edges;
    vector<vector<int>> adj;
    Graph(){ adj = *new vector<vector<int>>(); }
    int addEdge(TEdge *edge){
      edges.push_back(edge);

      while(adj.size() <= edge->src || adj.size() <= edge->dst) 
        adj.push_back(*new vector<int>);
      adj[edge->src].push_back(edge->dst);
    }
};







void connect(int **transitiveClosure, int size, int src, int dst){

  transitiveClosure[src][dst] = 1;

  for(int j = 0 ; j < size ; j++){
    if(transitiveClosure[dst][j] && dst != j && transitiveClosure[src][j] != 1){
      connect(transitiveClosure, size, src, j);
    }
  }

}


void buildTransitiveClosure_Util(vector<vector<int>> adj, int *visited, int **transitiveClosure, int src){

  visited[src] = 1;

  
  connect(transitiveClosure, adj.size(), src, src);
  
  vector<int>::iterator it;
  for(it = adj[src].begin(); it != adj[src].end(); ++it){
    if(!visited[*it]){
      buildTransitiveClosure_Util(adj, visited, transitiveClosure, *it);
    }
    connect(transitiveClosure, adj.size(), src, *it);
  }

}

// Given a directed graph, find out if a vertex v is reachable from 
// another vertex u for all vertex pairs (u, v) in the given graph. 
// Here reachable mean that there is a path from vertex u to v. 
// The reach-ability matrix is called transitive closure of a graph.
int ** buildTransitiveClosure(vector<vector<int>> adj){

  int *visited = new int[adj.size()];
  for(int i = 0 ; i < adj.size() ; i++){
    visited[i] = 0;
  }

  int **transitiveClosure = new int *[adj.size()];
  for(int i = 0 ; i < adj.size() ; i++){
    transitiveClosure[i] = new int[adj.size()];
    for(int j = 0 ; j < adj.size() ; j++){
      transitiveClosure[i][j] = 0;
    }
  }


  for(int i = 0 ; i < adj.size() ; i++){
      int *visited = new int[adj.size()];
      memset(visited, 0, adj.size()*sizeof(int));
      buildTransitiveClosure_Util(adj, visited, transitiveClosure, i);
  }

  return transitiveClosure;
}













int main(int argc, char **argv, char **envp){

  Graph G = *new Graph();
  G.addEdge(new TEdge(0, 1));
  G.addEdge(new TEdge(0, 2));
  G.addEdge(new TEdge(1, 2));
  G.addEdge(new TEdge(2, 0));
  G.addEdge(new TEdge(2, 3));


  int **matrix = buildTransitiveClosure(G.adj);

  for(int i = 0 ; i < G.adj.size(); i++){
    cout << endl;
    for(int j = 0 ; j < G.adj.size(); j++)
      cout << matrix[i][j] << "  ";
  }

  cout << "Program Exited Successfully...";
  return 0;
}
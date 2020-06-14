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

























void buildTransitiveClosure_Util2(vector<vector<int>> adj, int *visited, int **transitiveClosure, vector<int>& ancs, int src){

  visited[src] = 1;
  vector<int>::iterator it;


  for(it = ancs.begin(); it != ancs.end(); ++it){
    transitiveClosure[*it][src] = 1;
  }

  
  for(it = adj[src].begin(); it != adj[src].end(); ++it){
    if(!visited[*it]){
      ancs.push_back(*it);
      buildTransitiveClosure_Util2(adj, visited, transitiveClosure, ancs, *it);
      ancs.pop_back();
    }
  }

}

// Given a directed graph, find out if a vertex v is reachable from 
// another vertex u for all vertex pairs (u, v) in the given graph. 
// Here reachable mean that there is a path from vertex u to v. 
// The reach-ability matrix is called transitive closure of a graph.
int ** buildTransitiveClosure2(vector<vector<int>> adj){


  int **transitiveClosure = new int *[adj.size()];
  for(int i = 0 ; i < adj.size() ; i++){
    transitiveClosure[i] = new int[adj.size()];
    memset(transitiveClosure[i], 0, adj.size()*sizeof(int));
  }

  int *visited = new int[adj.size()];
  for(int i = 0 ; i < adj.size() ; i++){
      vector<int> ancs;
      ancs.push_back(i);
      memset(visited, 0, adj.size()*sizeof(int));
      buildTransitiveClosure_Util2(adj, visited, transitiveClosure, ancs, i);
  }

  return transitiveClosure;
}




















void buildTransitiveClosure_Util3(vector<vector<int>> adj, int **transitiveClosure, int src, int dst){

  transitiveClosure[src][dst] = 1;


  vector<int>::iterator it;
  for(it = adj[dst].begin(); it != adj[dst].end(); ++it){
    if(!transitiveClosure[src][*it]){
      buildTransitiveClosure_Util3(adj, transitiveClosure, src, *it);
    }
  }

}
// Given a directed graph, find out if a vertex v is reachable from 
// another vertex u for all vertex pairs (u, v) in the given graph. 
// Here reachable mean that there is a path from vertex u to v. 
// The reach-ability matrix is called transitive closure of a graph.
int ** buildTransitiveClosure3(vector<vector<int>> adj){


  int **transitiveClosure = new int *[adj.size()];
  for(int i = 0 ; i < adj.size() ; i++){
    transitiveClosure[i] = new int[adj.size()];
    memset(transitiveClosure[i], 0, adj.size()*sizeof(int));
  }


  for(int i = 0 ; i < adj.size() ; i++){
      buildTransitiveClosure_Util3(adj, transitiveClosure, i, i);
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



  int **matrix;
  vector<vector<int>> exp = *new vector<vector<int>>();
  exp = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {0, 0, 0, 1},
  };

  



  matrix = buildTransitiveClosure(G.adj);
  for(int i = 0 ; i < G.adj.size(); i++)
    for(int j = 0 ; j < G.adj.size(); j++)
      assert(matrix[i][j] == exp[i][j]);



  matrix = buildTransitiveClosure2(G.adj);
  for(int i = 0 ; i < G.adj.size(); i++)
    for(int j = 0 ; j < G.adj.size(); j++)
      assert(matrix[i][j] == exp[i][j]);


  matrix = buildTransitiveClosure3(G.adj);
  for(int i = 0 ; i < G.adj.size(); i++)
    for(int j = 0 ; j < G.adj.size(); j++)
      assert(matrix[i][j] == exp[i][j]);


  for(int i = 0 ; i < G.adj.size(); i++){
    cout << endl;
    for(int j = 0 ; j < G.adj.size(); j++){
      cout << matrix[i][j] << "  ";
    }
  }



  cout << "Program Exited Successfully...";
  return 0;
}
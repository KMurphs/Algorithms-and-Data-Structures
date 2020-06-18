#include <bits/stdc++.h>

using namespace std;


struct TEdge{
  int src, dst;
  TEdge(int s, int d): src(s), dst(d){}
};
class Graph{
  public:
    vector<TEdge> edges;
    vector<vector<TEdge>> adj;
    Graph(){
      edges = *new vector<TEdge>();
      adj = *new vector<vector<TEdge>>();
    }
    int addEdge(int source, int destination){
      while(adj.size() <= source || adj.size() <= destination)
        adj.push_back(*new vector<TEdge>());
      adj[source].push_back(*new TEdge(source, destination));
      edges.push_back(*new TEdge(source, destination));
    }
};





void dfsUtil(vector<vector<TEdge>> adj, bool *visited, int anc, int src){
  
  vector<TEdge>::iterator it;
  for(it = adj[src].begin() ; it != adj[src].end() ; ++it){

    if(anc == it->dst) continue;

    if(!visited[it->dst]){
      visited[it->dst] = 1;
      dfsUtil(adj, visited, anc, it->dst);
    }
    
  }
}



int findMotherVertex(vector<vector<TEdge>> adj){


  bool *visited = new bool[adj.size()];
  memset(visited, 0 , adj.size() * sizeof(bool));
  

  for(int i = 0 ; i < adj.size() ; i++){
    if(!visited[i])
      dfsUtil(adj, visited, i, i);
  }

  int vertex = -1, mVerticesCount = 0;
  for(int i = 0 ; i < adj.size() ; i++){
    if(!visited[i]){
      vertex = i;
      mVerticesCount++;
    }
  }

  return vertex;
}







void dfsUtil2(vector<vector<TEdge>> adj, bool *visited, int src){

  visited[src] = 1;

  for(vector<TEdge>::iterator itr = adj[src].begin() ; itr != adj[src].end() ; ++itr){
    if(!visited[itr->dst]){
      dfsUtil2(adj, visited, itr->dst);
    }
  }

}



int findMotherVertexKosaraju(vector<vector<TEdge>> adj){

  bool *visited = new bool[adj.size()];
  memset(visited, 0, adj.size() * sizeof(bool));

  int mVertex = -1;


  for(int i = 0 ; i < adj.size() ; i++){
    if(!visited[i]){
      dfsUtil2(adj, visited, i);
      mVertex = i;
    }
  }


  memset(visited, 0, adj.size() * sizeof(bool));
  dfsUtil2(adj, visited, mVertex);


  for(int i = 0 ; i < adj.size() ; i++){
    if(!visited[i]){
      return -1;
    }
  }

  return mVertex;
}





int main(int argc, char **argv, char **envp){

  Graph G = *new Graph();
  G.addEdge(0, 1); 
  G.addEdge(0, 2); 
  G.addEdge(1, 3); 
  G.addEdge(4, 1); 
  G.addEdge(5, 2); 
  G.addEdge(5, 6); 
  G.addEdge(6, 4); 
  G.addEdge(6, 0); 

  Graph G1 = *new Graph();
  G1.addEdge(0, 2); 
  G1.addEdge(0, 3); 
  G1.addEdge(1, 0); 
  G1.addEdge(2, 1); 
  G1.addEdge(3, 4); 

  int m = findMotherVertex(G.adj);
  assert(findMotherVertex(G.adj) == 5);
  assert(findMotherVertex(G1.adj) == 0);
  assert(findMotherVertexKosaraju(G.adj) == 5);
  assert(findMotherVertexKosaraju(G1.adj) == 0);

  cout << "Mother Vertex of Graph is vertex " << m << endl;

  cout << "Program Exited Successfully";
  return 0;
}
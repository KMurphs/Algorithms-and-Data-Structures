#include <bits/stdc++.h>

using namespace std;

struct TEdge{
  int src, dst;
  TEdge(int source, int destination): src(source), dst(destination){} 
};
class Graph{
  public:
    vector<TEdge> edges;
    vector<vector<int>> adj;
    Graph(){
      edges = *new vector<TEdge>();
      adj = *new vector<vector<int>>();
    }
    int addEdge(int source, int destination){
      while(adj.size() <= source || adj.size() <= destination)
        adj.push_back(*new vector<int>());
      adj[source].push_back(destination);
      adj[destination].push_back(source);
      edges.push_back(*new TEdge(source, destination));
    }

};






// Returns the longest path in the graph as long as stopPoint is not hit
// This works because the graph has no cycle and has exactly E = V + 1 edges
void dfsUtil(vector<vector<int>> adj, bool *visited, int src, int stopPoint, vector<int>& maxPath, vector<int>& tmpPath){

  visited[src] = 1;
  tmpPath.push_back(src);


  for(vector<int>::iterator itr = adj[src].begin(); itr != adj[src].end(); ++itr){
    if((!visited[*itr]) && (*itr != stopPoint)){
      dfsUtil(adj, visited, *itr, stopPoint, maxPath, tmpPath);
    }
  }

  if(tmpPath.size() > maxPath.size()){
    maxPath = *new vector<int>(tmpPath);
  }
  tmpPath.pop_back();
}






int findMaxProductPath(vector<vector<int>> adj){


  vector<int> maxPath = *new vector<int>();
  vector<int> tmpPath = *new vector<int>();
  bool *visited = new bool[adj.size()];


  // Get longest path in graph
  for(int i = 0; i < adj.size() ; i++){
    memset(visited, 0 , adj.size() * sizeof(bool));
    dfsUtil(adj, visited, i, -1, maxPath, tmpPath);
  }


  
  // Partition longest path in 2 equal size
  // Starting at opposite end of longest path, grow each end as much as possible
  // but within partition

  // Compute partitions limits
  int start1 = maxPath[0];
  int start2 = maxPath[maxPath.size() - 1];
  int end1 = maxPath[(maxPath.size() - 1)/2 + 0];
  int end2 = maxPath[(maxPath.size() - 1)/2 + (maxPath.size() & 1 ? 0 : 1)];

  // Init for operaiton
  tmpPath = *new vector<int>();
  vector<int> path1 = *new vector<int>();
  vector<int> path2 = *new vector<int>();
  memset(visited, 0 , adj.size() * sizeof(bool));

  // Explore partitions for max length within each partition
  dfsUtil(adj, visited, start1, end2, path1, tmpPath);
  dfsUtil(adj, visited, start2, end1, path2, tmpPath);




  for(vector<int>::iterator itr = path1.begin(); itr != path1.end(); ++itr)
    cout << *itr << "  ";
  cout << endl;
  for(vector<int>::iterator itr = path2.begin(); itr != path2.end(); ++itr)
    cout << *itr << "  ";
  cout << endl;


  // Return product of lengths
  int len1 = path1.size() - 1;
  int len2 = path2.size() - 1;
  if((maxPath.size() & 1) == 0) 
    return len1 * len2;
  if(len1 <= len2) 
    return (len1 + 1) * len2;
  if(len1 > len2) 
    return len1 * (len2 + 1);

  return -1;
}






int main(int argc, char **argv, char **envp){

  Graph G;
  int maxProd;

  G = *new Graph();
  G.addEdge(1, 2);
  G.addEdge(2, 3);
  G.addEdge(3, 4);
  maxProd = findMaxProductPath(G.adj);
  assert(maxProd == 1);


  G = *new Graph();
  G.addEdge(1, 3);
  G.addEdge(1, 8);
  G.addEdge(2, 6);
  G.addEdge(3, 5);
  G.addEdge(4, 8);
  G.addEdge(6, 8);
  G.addEdge(7, 8);
  maxProd = findMaxProductPath(G.adj);
  assert(maxProd == 6);


  cout << "Program Exited Successfully...";
  return 0;
}
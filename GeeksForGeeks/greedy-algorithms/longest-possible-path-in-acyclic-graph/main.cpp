#include <bits/stdc++.h>

using namespace std;

struct TEdge{
  int src, dst, wght;
  TEdge(int source, int destination, int weight): src(source), dst(destination), wght(weight){}
};


class Graph{
  public:
    vector<TEdge> edges;
    vector<vector<TEdge>> adj;
    Graph(){
      adj = *new vector<vector<TEdge>>();
    }
    void addEdge(int source, int destination, int weight){

      while(adj.size() <= source || adj.size() <= destination) 
        adj.push_back(*new vector<TEdge>());

      edges.push_back(*new TEdge(source, destination, weight));
      adj[source].push_back(*new TEdge(source, destination, weight));
      adj[destination].push_back(*new TEdge(destination, source, weight));
    }
};





int getLongestPathUtil(vector<vector<TEdge>> adj, int prev, int src){
  int localMax = INT_MIN;

  vector<TEdge>::iterator it;
  for(it = adj[src].begin() ; it != adj[src].end() ; ++it){
    if(it->dst == prev) continue;
    int neighMax = getLongestPathUtil(adj, src, it->dst) + it->wght;
    if(localMax < neighMax) localMax = neighMax;
  }

  return localMax == INT_MIN ? 0 : localMax;
}
int getLongestPath(vector<vector<TEdge>> adj){
  int globalMax = INT_MIN;

  for(int i = 0 ; i < adj.size() ; i++){
    int localMax = getLongestPathUtil(adj, i, i);
    if(globalMax < localMax) globalMax = localMax;
  }

  return globalMax;
}









void getLongestPathUtil2(vector<vector<TEdge>> adj, int *gMax, int lMax, int prev, int src){

  bool isLeaf = true;

  vector<TEdge>::iterator it;
  for(it = adj[src].begin() ; it != adj[src].end() ; ++it){
    if(it->dst == prev) continue;
    isLeaf = false;
    getLongestPathUtil2(adj, gMax, lMax + it->wght, src, it->dst);
  }


  if(isLeaf)
    if(*gMax < lMax)
      *gMax = lMax;
}

int getLongestPath2(vector<vector<TEdge>> adj){
  int globalMax = INT_MIN;

  for(int i = 0 ; i < adj.size() ; i++){
    if(adj[i].size() == 1){
      getLongestPathUtil2(adj, &globalMax, 0, i, i);
    }
  }

  return globalMax;
}















int getLongestPathUtil3(vector<vector<TEdge>> adj, int prev, int src){
  int localMax = INT_MIN;

  vector<TEdge>::iterator it;
  for(it = adj[src].begin() ; it != adj[src].end() ; ++it){
    if(it->dst == prev) continue;
    int tmpMax = getLongestPathUtil3(adj, src, it->dst) + it->wght;
    if(localMax < tmpMax) localMax = tmpMax;
  }

  return localMax == INT_MIN ? 0 : localMax;
}

int getLongestPath3(vector<vector<TEdge>> adj){
  #define SIZE 3
  int kMax[SIZE] = {INT_MIN, INT_MIN, INT_MIN};

  int i = 0;
  while((i < adj.size()) && (adj[i].size() < 2)) i++;


  for(int j = 0; j < adj[i].size() ; j++){
    kMax[2] = getLongestPathUtil3(adj, i, adj[i][j].dst) + adj[i][j].wght;
    // qsort is legacy and takes a function pointer - does not work with lambda expression
    sort(kMax, kMax + SIZE, [](const int& a, const int& b) -> bool { return a > b; });
  }


  return kMax[0] + kMax[1];
}




















// https://www.geeksforgeeks.org/longest-path-between-any-pair-of-vertices/
int main(int argc, char **argv, char **envp){

  Graph G = *new Graph();
  G.addEdge(1,2,3);
  G.addEdge(2,3,4);
  G.addEdge(2,6,2);
  G.addEdge(6,4,6);
  G.addEdge(6,5,5);

  assert(getLongestPath(G.adj) == 12);
  assert(getLongestPath2(G.adj) == 12);
  assert(getLongestPath3(G.adj) == 12);
  cout << "Longest Cable length in Graph is " << getLongestPath(G.adj) << endl;

  cout << "Program Exited Successfully...";
  return 0;
}
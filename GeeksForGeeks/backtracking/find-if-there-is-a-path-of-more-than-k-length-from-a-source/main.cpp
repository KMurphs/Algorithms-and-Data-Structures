#include <bits/stdc++.h>

using namespace std;


struct TEdge{
  int src, dst, wght;
  TEdge(int s, int d, int w): src(s), dst(d), wght(w){}
};
class Graph{
  public:
    vector<TEdge> edges;
    vector<vector<TEdge>> adj;
    Graph(){
      edges = *new vector<TEdge>();
      adj = *new vector<vector<TEdge>>();
    }
    int addEdge(int source, int destination, int weight){
      while(adj.size() <= source || adj.size() <= destination)
        adj.push_back(*new vector<TEdge>());
      adj[source].push_back(*new TEdge(source, destination, weight));
      adj[destination].push_back(*new TEdge(destination, source, weight));
      edges.push_back(*new TEdge(source, destination, weight));
    }
};




void dfsUtil(vector<vector<TEdge>> adj, int *visited, int *mPath, int *tPath, int *mDist, int tDist, int pos, int src, int k){

  if(tDist > *mDist && tDist > k){
    *mDist = tDist;
    for(int i = 0 ; i <= pos + 1 ; i++)
      mPath[i] = tPath[i];
  }



  for(vector<TEdge>::iterator it = adj[src].begin() ; it != adj[src].end() ; ++it){
    if(!visited[it->dst]){
      
      tPath[pos + 1] = it->dst;
      visited[it->dst] = 1;

      dfsUtil(adj, visited, mPath, tPath, mDist, tDist + it->wght, pos + 1, it->dst, k);
      visited[it->dst] = 0;

    }
  }

}












int findPathLongerThanK(vector<vector<TEdge>> adj, int src, int k){

  int mDist;

  int *visited = new int[adj.size()];
  memset(visited, 0, sizeof(int) * adj.size());


  int *tPath = new int[adj.size()];
  int *mPath = new int[adj.size()];
  memset(tPath, 0, sizeof(int) * adj.size());
  memset(mPath, 0, sizeof(int) * adj.size());


  mDist = INT_MIN, visited[src] = 1, tPath[0] = src;
  dfsUtil(adj, visited, mPath, tPath, &mDist, 0, 0, src, k);

  if(mDist > k){
    cout << "Found a Path Longer than '" << k << "' (" << mDist << ")" << endl;  
    for(int i = 0 ; i < adj.size() ; i++)
      cout << mPath[i] << "  ";
    cout << endl;
  }else{
    cout << "No Path Longer than '" << k << "' was found" << endl; 
  }

  return mDist;
}






// https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/
int main(int argc, char **argv, char **envp){

  int k, src;

  Graph G = *new Graph();
  G.addEdge(0, 1, 4); 
  G.addEdge(0, 7, 8); 
  G.addEdge(1, 2, 8); 
  G.addEdge(1, 7, 11); 
  G.addEdge(2, 3, 7); 
  G.addEdge(2, 5, 4); 
  G.addEdge(2, 8, 2); 
  G.addEdge(3, 4, 9); 
  G.addEdge(3, 5, 14); 
  G.addEdge(4, 5, 10); 
  G.addEdge(5, 6, 2); 
  G.addEdge(6, 7, 1); 
  G.addEdge(6, 8, 6); 
  G.addEdge(7, 8, 7); 



  k = 40, src = 2;
  assert(findPathLongerThanK(G.adj, src, k) > k);
  k = 58, src = 0;
  assert(findPathLongerThanK(G.adj, src, k) > k);
  k = 62, src = 0;
  assert(findPathLongerThanK(G.adj, src, k) < 0);




  cout << "Program Exited Successfully";
  return 0;
}
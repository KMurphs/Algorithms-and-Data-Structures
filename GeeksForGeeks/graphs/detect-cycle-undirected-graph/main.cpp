
// C program for flattening a linked list 
#include <stdio.h> 
#include <stdlib.h> 

#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src, dst, weight;
        Edge(int _src, int _dst, int _weight){
            src = _src;
            dst = _dst;
            weight = _weight;
        }
};
class Graph{
    public:
        int V;
        vector<Edge> edges;
        vector<vector<int>> adj;
        Graph(){
            adj = *new vector<vector<int>>();
        }
        void addEdge(int src, int dst){
            addEdge(src, dst, 0);
        }
        void addEdge(int src, int dst, int weight){
            
            Edge *e = new Edge(src, dst, weight);
            
            edges.push_back(*e);

            while(adj.size() <= src || adj.size() <= dst)
                adj.push_back(*new vector<int>());

            adj[e->src].push_back(e->dst);
            adj[e->dst].push_back(e->src);
        }
};





class DisjointSet{
    vector<int> reps;
    public:
        
        void addRep(int rep){
            while(reps.size() <= rep)
                reps.push_back(reps.size());
        }


        int findRep(int src){
            if(reps[src] == src)
                return src;
            return findRep(reps[src]);
        }

        void getUnion(int elmt1, int elmt2){
            int rep1 = findRep(elmt1);
            int rep2 = findRep(elmt2);

            reps[rep2] = rep1;
        }

};


bool detectCycle(vector<Edge> edges){

    DisjointSet set = *new DisjointSet();
    vector<Edge>::iterator it;

    for(it = edges.begin() ; it != edges.end() ; ++it){
        set.addRep((*it).src);
        set.addRep((*it).dst);
    }
    
    for(it = edges.begin() ; it != edges.end() ; ++it){
        int srcRep = set.findRep((*it).src);
        int dstRep = set.findRep((*it).dst);

        if(srcRep == dstRep) return true;
        set.getUnion(srcRep, dstRep);
    }

    return false;
}













bool detectCycle_DFSUtil(vector<vector<int>> adj, int *visited, int parent, int src){

    visited[src] = 1;


    vector<int>::iterator it;
    for(it = adj[src].begin() ; it != adj[src].end() ; ++it){
        if(*it == parent)
            continue;
        if(visited[*it])
            return true;
        if(detectCycle_DFSUtil(adj, visited, src, *it))
            return true;
    }


    return false;
}

bool detectCycle_DFS(vector<vector<int>> adj){

    int *visited = new int[adj.size()];
    memset(visited, 0, adj.size() * sizeof(int));
    
    for(int i = 0 ; i < adj.size() ; i++){
        if(!visited[i]){
            if(detectCycle_DFSUtil(adj, visited, -1, i)) 
                return true;
        }
    }

    return false;
}











// Driver program to test above functions 
int main() 
{ 
    bool hasCycle;

    Graph *graph = new Graph();
    graph->addEdge(0, 1); 
    graph->addEdge(0, 2); 
    graph->addEdge(0, 3); 
    graph->addEdge(1, 2); 
    graph->addEdge(3, 4);

    hasCycle = detectCycle(graph->edges);
    cout << "Grah " << (hasCycle ? "" : "does not ") << "contains a cycle" << endl;
    assert(hasCycle == true);
    assert(detectCycle_DFS(graph->adj) == true);




    graph = new Graph();
    graph->addEdge(0, 1); 
    graph->addEdge(1, 2); 
    graph->addEdge(2, 3); 

    hasCycle = detectCycle(graph->edges);
    cout << "Grah " << (hasCycle ? "" : "does not ") << "contains a cycle" << endl;
    assert(hasCycle == false);
    assert(detectCycle_DFS(graph->adj) == false);



    


    cout << "\n\nProgram exited successfully" << endl;
    return 0; 
} 

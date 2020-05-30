
// C program for flattening a linked list 
#include <stdio.h> 
#include <stdlib.h> 

#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int dst, weight;
        Edge(int _dst, int _weight){
            dst = _dst;
            weight = _weight;
        }
};
class Graph{
    public:
        int V;
        vector<vector<Edge>> adj;
        Graph(int _V){
            V = _V;
            for(int i = 0 ; i < V ; i++){
                vector<Edge> tmp;
                adj.push_back(tmp);
            }
        }
        void addEdge(int src, int dst, int weight){
            Edge *e;

            e = new Edge(dst, weight);
            adj[src].push_back(*e);
            
            e = new Edge(src, weight);
            adj[dst].push_back(*e);
        }
};


int pickLowestUnprocessed(Graph *G, int *dist, int *reg){
    int minVal = INT_MAX, minIdx = -1;
    for(int i = 0; i < G->V; i++)
        if(!reg[i] && dist[i] < minVal)
            minVal = dist[i], minIdx = i;
    return minIdx;
}



// https://stackoverflow.com/questions/37780779/memset-to-int-max-in-c
// The second parameter of memset() is a single byte. 
// memset() does not fill the specified area of memory with ints, but with single bytes.
// If you want to initialize your board array of ints, 
// you'll have to do it with the same kind of a loop that your test program uses to print its contents.

// Use memset if you want to fill block of memory with 0's or set everything to 0xff's


// Dijkstra
int *findMindDistSrcToAll(Graph *G, int src){
    int *reg = new int[G->V];
    int *dist = new int[G->V];

    // memset(reg, 0, G->V * sizeof(int));
    // memset(dist, 0xFF, G->V * sizeof(int));
    for(int i = 0; i < G->V; i++)
        reg[i] = 0, dist[i] = INT_MAX; 

    dist[src] = 0;

    for(int counter = 0; counter < G->V; counter++){
        int u = pickLowestUnprocessed(G, dist, reg);
        reg[u] = 1;


        vector<Edge>::iterator it;
        for(
            it = G->adj[u].begin();
            it != G->adj[u].end();
            ++it
        )
            if(
                !reg[it->dst] && dist[u] != INT_MAX && 
                dist[it->dst] > dist[u] + it->weight
            )
                dist[it->dst] = dist[u] + it->weight;
    }

    return dist;
}


// Driver program to test above functions 
int main() 
{ 
    // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    Graph *graph = new Graph(5);
    graph->addEdge(0, 1, 2); 
    graph->addEdge(0, 4, 3); 
    graph->addEdge(1, 2, 1); 
    graph->addEdge(1, 3, 4); 
    graph->addEdge(1, 4, 2); 
    graph->addEdge(2, 3, 3); 
    graph->addEdge(3, 4, 5); 

    int *dist = findMindDistSrcToAll(graph, 3);
    for(int i = 0; i < graph->V; i++)
        cout << dist[i] << "  ";


    cout << "\n\nProgram exited successfully" << endl;
    return 0; 
} 

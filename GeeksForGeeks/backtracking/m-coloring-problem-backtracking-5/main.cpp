#include <bits/stdc++.h>
using namespace std;



// nodesColor contains the current colors of all the nodes visited so far
bool dfsUtil(int **G, int nNodes, int *nodesColor, int src, int colors){

  int *usedColors = new int[colors];
  memset(usedColors, 0, sizeof(int) * colors);


  // Find available colors, by getting rid of colors of neighbours
  for(int i = 0 ; i < nNodes ; i++){
    
    // Only process nodes with an actual connection to src
    // aka neighbours
    int isNeighbour = G[src][i];
    if(isNeighbour == 0)
      continue;

    // Mark color of neighbours as taken
    if(nodesColor[i] != 0){
      usedColors[nodesColor[i] - 1] = 1;
    }
  }


  // For each one of the available colors:
  //    explore the possibility of a solution
  //    if src takes the current color
  bool hasNeighbours;
  for(int c = 1 ; c <= colors ; c++){
    if(usedColors[c - 1] != 1){

      nodesColor[src] = c;    // src takes the current color
      hasNeighbours = false;  // src has no unvisited neighbours

      // Go Process the neighbours
      for(int i = 0 ; i < nNodes ; i++){
        
        int isNeighbour = G[src][i];
        if(isNeighbour == 0)
          continue;
        if(nodesColor[i] != 0) // Only visit unvisted neighbours
          continue;

        // Processing valid neighbours
        hasNeighbours = true;
        if(dfsUtil(G, nNodes, nodesColor, i, colors)){
          return true;
        }
      }

      // src had no unvisited neighbours, we can return true
      // the color choices made exhausted all the nodes
      // while meeting the coloring condition
      if(!hasNeighbours)
        return true;

      // Reset src color, to try another possibility
      nodesColor[src] = 0;
    }
  }
  
  // If there was no colors available for source
  // If the different previous choices didn't lead to a local solution
  return false;
}



bool colorGraph(int **G, int nNodes, int nColors){

  int *nodesColor = new int[nNodes];
  memset(nodesColor, 0, sizeof(int) * nNodes);


  for(int i = 0 ; i < nNodes ; i++){
    if(dfsUtil(G, nNodes, nodesColor, i, nColors)){

      // Print solution
      for(int i = 0 ; i < nNodes ; i++){
        cout << nodesColor[i] << " "; 
      }
      cout << endl;
        
      // return, solution was found
      return true;
      
    }
  }


  return false;
}



// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
int main(int argc, char **argv, char **envp){

  int size, nColors, **G;
  bool isColored; 
  

  size = 4, G = new int*[size], nColors = 3;
  G[0] = new int[size]{ 0, 1, 1, 1 };
  G[1] = new int[size]{ 1, 0, 1, 0 };
  G[2] = new int[size]{ 1, 1, 0, 1 };
  G[3] = new int[size]{ 1, 0, 1, 0 };
  assert(colorGraph(G, size, nColors));



  size = 4, G = new int*[size], nColors = 3;
  G[0] = new int[size]{ 1, 1, 1, 1 };
  G[1] = new int[size]{ 1, 1, 1, 1 };
  G[2] = new int[size]{ 1, 1, 1, 1 };
  G[3] = new int[size]{ 1, 1, 1, 1 };
  assert(!colorGraph(G, size, nColors));

  // You can always color a graph with V colors
  // Each one of the V nodes would then have its own color 
  assert(colorGraph(G, size, 4)); 



  cout << "Program is exiting..." << endl; 
  return 0; 
}
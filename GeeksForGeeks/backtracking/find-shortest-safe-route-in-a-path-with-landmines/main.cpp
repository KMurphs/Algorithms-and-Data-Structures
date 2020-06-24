#include <bits/stdc++.h>

using namespace std;

#define R 12 
#define C 10 




#define MOVEMENTS 4
int **movements;
void initMovements(){
  movements = new int*[MOVEMENTS];
  movements[0] = new int[2]{ 0, 1 };
  movements[1] = new int[2]{ 1, 0 };
  movements[2] = new int[2]{ -1, 0 };
  movements[3] = new int[2]{ 0, -1 };
}




struct TCoord{
  int row, col;
  TCoord(int r, int c): row(r), col(c){}
  TCoord(TCoord *pt): row(pt->row), col(pt->col){}
  TCoord translate(int drow, int dcol){
    return *new TCoord(row + drow, col + dcol);
  }
};
class LNode{
  public:
    TCoord *pos;
    LNode *next;
    LNode(TCoord *_pos): pos(_pos), next(nullptr){}
};




bool isWithinLimits(int mat[R][C], TCoord pos){

  //Is point within limits
  if(pos.row < 0 || pos.row >= R) return false;
  if(pos.col < 0 || pos.col >= C) return false;

  return true;
}

bool isSafe(int mat[R][C], TCoord pos){

  // point is within limits 
  if(!isWithinLimits(mat, pos)) return false;

  // point is not mine
  if(mat[pos.row][pos.col] == 0) return false;

  // neighbours are not mines
  for(int i = 0 ; i < MOVEMENTS ; i++){
    TCoord next = pos.translate(movements[i][0], movements[i][1]);
    if(isWithinLimits(mat, next) && mat[next.row][next.col] == 0) return false;
  }
  
  return true;
}




void copyPath(LNode ***minRoot, LNode *tmpPath){
  if(tmpPath == nullptr)
    return;
  copyPath(minRoot, tmpPath->next);

  (**minRoot)->next = new LNode(new TCoord(tmpPath->pos));
  *minRoot = &((**minRoot)->next);
  (**minRoot)->next = nullptr;
}



void dfsUtil(int mat[R][C], TCoord curr, int currDist, int *minDist, LNode *minRoot, LNode *tmpPath){

  if(curr.col >= C - 1){
    if(*minDist > currDist){
      *minDist = currDist;
      LNode **ptrRoot = &minRoot;
      copyPath(&ptrRoot, tmpPath);
    }
    return;
  }


  for(int i = 0 ; i < MOVEMENTS ; i++){
    TCoord next = curr.translate(movements[i][0], movements[i][1]);

    if(isWithinLimits(mat, next) && (mat[next.row][next.col] == 1) && isSafe(mat, next)){ 

      // 1 means not visited, INT_MAX means visted
      mat[next.row][next.col] = INT_MAX;
      LNode* tmpRoot = new LNode(&next);
      tmpRoot->next = tmpPath; 

      dfsUtil(mat, next, currDist + 1, minDist, minRoot, tmpRoot);

      mat[next.row][next.col] = 1;
      tmpRoot->next = nullptr;
      free(tmpRoot);

    }

  }

}





LNode *findShortestPath(int mat[R][C]){

  int minDist = INT_MAX;
  LNode *dummyHead = new LNode(new TCoord(INT_MIN, INT_MIN));


  for(int row = 0 ; row < R ; row++){
    TCoord pos = *new TCoord(row, 0);
    if(isSafe(mat, pos)){
      mat[pos.row][pos.col] = INT_MAX;
      dfsUtil(mat, pos, 0, &minDist, dummyHead, new LNode(&pos));
      mat[pos.row][pos.col] = 1;
    }
  }

  return dummyHead->next;
}


int printPath(LNode *path){
  if(path == nullptr)
    return -1;
  cout << "(" << path->pos->row << ", " << path->pos->col << ")"<< endl;
  return 1 + printPath(path->next);
}

// https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/
int main(int argc, char **argv, char **envp){

  // input matrix with landmines shown with number 0 
  int mat[R][C] = { 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 } 
  }; 
  
  initMovements();

  // find shortest path 
  LNode *path = findShortestPath(mat); 

  int length = printPath(path);
  cout << "Path has Length: " << length << endl;




  cout << "Program Exited Successfully";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define SIZE 5

struct TCoord{
    int x, y;
    TCoord(int _x, int _y): x(_x), y(_y){}
};




int findIslands(int space[SIZE][SIZE], TCoord *pos){

    #define INCREMENTS 8
    TCoord increments[INCREMENTS] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    
    int islands[SIZE][SIZE];
    for(int i = 0 ; i < SIZE ; i++)
        for(int j = 0 ; j < SIZE ; j++)
            islands[i][j] = -1;


    vector<TCoord *> qOnes;
    vector<TCoord *> qZeros;
    TCoord *curr;

    int currIsland = 1;

    if(space[pos->x][pos->y] == 0) qZeros.push_back(pos);
    else qOnes.push_back(pos);
    

    while(qOnes.size() != 0 || qZeros.size() != 0){

        if(qOnes.size() != 0){
            curr = qOnes.front();
            qOnes.erase(qOnes.begin());
            islands[curr->x][curr->y] = currIsland;
            



            for(int inc = 0 ; inc < INCREMENTS ; inc++ ){
                TCoord *nextPos = new TCoord(curr->x + increments[inc].x, curr->y + increments[inc].y);
                if(
                    0 <= nextPos->x && nextPos->x < SIZE && 
                    0 <= nextPos->y && nextPos->y < SIZE && 
                    islands[nextPos->x][nextPos->y] < 0
                ){
                    if(space[nextPos->x][nextPos->y] == 0) qZeros.push_back(nextPos);
                    else qOnes.push_back(nextPos);
                }
            }


            if(qOnes.size() == 0 && qZeros.size() != 0) currIsland++;

        } else if (qZeros.size() != 0){
            curr = qZeros.front();
            qZeros.erase(qZeros.begin());
            islands[curr->x][curr->y] = 0;



            for(int inc = 0 ; inc < INCREMENTS ; inc++ ){
                TCoord *nextPos = new TCoord(curr->x + increments[inc].x, curr->y + increments[inc].y);
                if(
                    0 <= nextPos->x && nextPos->x < SIZE && 
                    0 <= nextPos->y && nextPos->y < SIZE && 
                    islands[nextPos->x][nextPos->y] < 0
                ){
                    if(space[nextPos->x][nextPos->y] == 0) qZeros.push_back(nextPos);
                    else qOnes.push_back(nextPos);
                }
            }

        }

        
    }



    return currIsland;
}


int findIslands_DFS_Util(int space[SIZE][SIZE], int visited[SIZE][SIZE], int *currIsland, TCoord *pos){
    

    #define INCREMENTS_ 8
    TCoord increments[INCREMENTS_] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    
    visited[pos->x][pos->y] = *currIsland;

    for(int inc = 0 ; inc < INCREMENTS ; inc++ ){
        TCoord *nextPos = new TCoord(pos->x + increments[inc].x, pos->y + increments[inc].y);
        if(
            nextPos->x >= 0 && nextPos->y >= 0 && 
            nextPos->x < SIZE && nextPos->y < SIZE && 
            visited[nextPos->x][nextPos->y] < 0 &&
            space[nextPos->x][nextPos->y] == 1
        ){
            findIslands_DFS_Util(space, visited, currIsland, nextPos);
        }
    }


}
int findIslands_DFS(int space[SIZE][SIZE], TCoord *pos){

    int currIsland = 0;

    int visited[SIZE][SIZE];
    for(int i = 0 ; i < SIZE ; i++)
        for(int j = 0 ; j < SIZE ; j++)    
            visited[i][j] = -1;

    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            if(visited[i][j] < 0){
                if(space[i][j] == 1){
                    currIsland = currIsland + 1;
                    findIslands_DFS_Util(space, visited, &currIsland, new TCoord(i, j));
                }else{
                    visited[i][j] = 0;
                }
            }

        }
    }

    return currIsland;
}



int main(int argc, char **argv, char **envp){
    int space[SIZE][SIZE] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1},
    };


    assert(findIslands(space, new TCoord(0, 0)) == 5);
    assert(findIslands_DFS(space, new TCoord(0, 0)) == 5);


    cout << "Program exited successfully...";
    return 0;
}
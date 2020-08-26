#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void grow(vector<vector<char>>& board, int rows, int cols, int row, int col) {
    
        // if(row < 0 || row >= rows) return;
        // if(col < 0 || col >= cols) return;
        
        if(board[row][col] == 'O'){ 
            board[row][col] = '1';
            if(row >= 1) grow(board, rows, cols, row - 1, col);
            if(row < rows - 1) grow(board, rows, cols, row + 1, col);
            if(col >= 1) grow(board, rows, cols, row, col - 1);
            if(col < cols - 1) grow(board, rows, cols, row, col + 1);
        }
    
    }
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        if(rows == 0) return;
        
        int cols = board[0].size();
        if(cols == 0) return;


        for(int row = 0; row < rows; ++row){
            
            // Processing first elmt of current row
            grow(board, rows, cols, row, 0);
            
            // Processing inbetween elemts for first and last rows
            if(row == 0 || row == rows - 1){
                for(int col = 1; col < cols - 1; ++col){
                    grow(board, rows, cols, row, col);
                }
            }
            
            // Processing last elmt of current row
            grow(board, rows, cols, row, cols - 1);

        }
        
        
        // At this point, the elemnts that must remain 'O' have the value '1'
        // Everything else can be changed to 'X'
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){

                if(board[row][col] == '1'){
                    board[row][col] = 'O';
                }else{
                    board[row][col] = 'X';
                }
                
            } 
        }
        
        
    }
};


int main() {
    
    #define SIZE 4

    vector<vector<char>> board = *new vector<vector<char>>();
    for(int r = 0 ; r < SIZE ; r++){
        board.push_back(*new vector<char>(SIZE, 'X'));

        // std::vector<int> vect2(10);
        // std::vector<int> vect2(10, someValue);

        // std::vector<int> vect2;
        // vect2.reserve(10);
        // fill(vect2.begin(), vect2.end(), someValue); 

        // vector<int> vect2{ 10, 20, 30 }; 
        // vector<int> vect2(vect1.begin(), vect1.end()); 
        
    
        // for (int x : vect) 
        //     cout << x << " "; 
    }
    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'O';
    board[3][1] = 'O';

    vector<vector<char>> exp = *new vector<vector<char>>();
    for(int r = 0 ; r < SIZE ; r++){
        exp.push_back(*new vector<char>(SIZE, 'X'));
    }
    exp[3][1] = 'O';


    Solution().solve(board);
    
    

    for(int r = 0 ; r < SIZE ; r++){
        for(int c = 0 ; c < SIZE ; c++){
            cout << board[r][c] << "  ";
        }
        cout << endl;
    }


    bool isCorrect;
    for(int r = 0 ; r < SIZE ; r++){
        isCorrect = false;
        assert(board[r] == exp[r]);
        isCorrect = true;
    }
    
    cout << "Board was" << (isCorrect ? "" : " not ") << " correctly solved" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
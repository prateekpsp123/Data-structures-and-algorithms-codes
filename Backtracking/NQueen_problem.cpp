#include<bits/stdc++.h>
using namespace std;

void display_Board(vector<vector<bool>>board){
    int row = board.size();
    int col = board[0].size();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(board[i][j] == false){
                cout<<"-"<<" ";
            }
            else{
                cout<<"Q"<<" ";
            }
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<bool>>&board, int row, int col){
    int lastRowindex = board.size()-1;
    int lastColindex = board[0].size()-1;

    //check for the vertical
    for(int i = 0; i<row; i++){
        if(board[i][col] == true){
            return false;
        }
    }
    //check for the Left diagonal
    // how many time it has to run is to check is the min of row and how many blocks at left.
    int maxLeft = min(row,col);
    for(int i=1; i<=maxLeft; i++){
        if(board[row-i][col-i] == true){
            return false;
        }
    }
    // check for right diagonal
    //  how many time it has to run is to check is the last col index - currcol index.
     int maxRight = min(row,lastColindex-col);
    for(int i=1; i<=maxRight; i++){
        if(board[row-i][col+i] == true){
            return false;
        }
    }

    return true;
}

void NQueen(vector<vector<bool>>&board, int row){

    if(row == board.size()){
        display_Board(board);
        cout<<endl;
        return;
    }

    for(int col=0; col < board[0].size(); col++){

        if(isSafe(board,row,col))
        {
            board[row][col] = true;
            NQueen(board,row+1);
            //BackTracking
            board[row][col] = false;
        }
    }
}


int main(){

    vector<vector<bool>>board(4,vector<bool>(4,false));
    NQueen(board,0);

    return 0;
}
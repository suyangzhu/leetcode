#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> xIndex;
    vector<int> yIndex;
    void solve(vector<vector<char> > &board) {
        int row = board.size();
        if (row == 0) 
            return ;
        int col = board[0].size();
        if (col == 0) 
            return;
        xIndex.clear();
        yIndex.clear();
        int i, j;
        for (i = 0; i < col; i++) 
            if (board[0][i] == 'O') {
                xIndex.push_back(0);
                yIndex.push_back(i);
            }
        for (i = 0; i < col; i++) 
            if (board[row-1][i] == 'O') {
                xIndex.push_back(row-1);
                yIndex.push_back(i);
            }
        for (i = 0; i < row; i++) 
            if (board[i][0] == 'O') {
                xIndex.push_back(i);
                yIndex.push_back(0);
            }
        for (i = 0; i < row; i++) 
            if (board[i][col-1] == 'O') {
                xIndex.push_back(i);
                yIndex.push_back(col-1);
            }
        int k = 0;
        while (k < xIndex.size()) {
            int x = xIndex[k];
            int y = yIndex[k];
            board[x][y] = 'Y';
            if ( x-1>=0 && board[x-1][y] == 'O') {xIndex.push_back(x-1); yIndex.push_back(y);}
            if ( x+1 < row && board[x+1][y] == 'O') {xIndex.push_back(x+1); yIndex.push_back(y);}
            if (y-1>=0 && board[x][y-1] == 'O')     {xIndex.push_back(x); yIndex.push_back(y-1);}
            if (y+1<col && board[x][y+1] == 'O') {xIndex.push_back(x); yIndex.push_back(y+1);}
	    k++;
        }
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++)  { 
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};

int main() {
	return 0;
}

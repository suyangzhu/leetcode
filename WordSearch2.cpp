#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
/**
 * DFS using a stack. time limit exceeding.
 */
using namespace std;

class Solution {
public:
    bool isBoarded(int x, int y, int row, int col) {
	    if (x < 0 ||
	        x >= row ||
		y < 0 ||
		y >= col)
		    return false;
	    return true;
    }
    bool DFS(int x, int y, int row, int col, int n, vector<vector<char> >& board, string& word, vector<vector<bool> >& visited) {
	    if (n == word.size()) return true;
	    bool result = false;
	    if (isBoarded(x, y, row, col)) {
		   if (!visited[x][y] && board[x][y] == word[n]) {
			   visited[x][y] = true;
			   result = DFS(x, y+1, row, col, n+1, board, word, visited) ||
				    DFS(x, y-1, row, col, n+1, board, word, visited) ||
				    DFS(x-1, y, row, col, n+1, board, word, visited) ||
				    DFS(x+1, y, row, col, n+1, board, word, visited);
			   visited[x][y] = false;
		   }
	    } 
	    return result;
	    
    }
    bool exist(vector<vector<char> > &board, string word) {
	    int row = board.size();
	    int i, j;
	    if (!row) 
		    return false;
	    int col = board[0].size();
	    if (!col)
		    return false;
	    vector<vector<bool> > visited;
	    for (i = 0; i < row; i++) {
		    vector<bool> vec;
		    for (j = 0; j < col; j++) {
			    vec.push_back(false);
		    }
		    visited.push_back(vec);
	    }
	    for (i = 0; i < row; i++)
		    for (j = 0; j < col; j++) 
			    if (DFS(i, j, row, col, 0, board, word, visited))
				    return true;
	    return false;
    }
};

int main() {
	vector<vector<char> > board;
	vector<char> vec, vec1, vec2;
	vec.push_back('C');
	vec.push_back('A');
	vec.push_back('A');
//	vec.push_back('E');
	
	vec1.push_back('A');
	vec1.push_back('A');
	vec1.push_back('A');
//	vec1.push_back('S');

	vec2.push_back('B');
	vec2.push_back('C');
	vec2.push_back('D');
//	vec2.push_back('E');
	board.push_back(vec);
	board.push_back(vec1);
	board.push_back(vec2);
	Solution sol;
	while (1) {
		string str;
		cin >> str;
		if (sol.exist(board, str))
			std::cout << "T" << std::endl;
		else 
			std::cout << "F" << std::endl;
	}
	return 0;
}

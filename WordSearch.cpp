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
    vector<vector<int> > adjacent(vector<int> &coordinate, int row, int col) {
        int x = coordinate[0];
        int y = coordinate[1];
        int i, j;

        vector<vector<int> > result;
        for (i = x-1; i <= x+1; i++) {
            for (j = y-1; j <= y+1; j++) {
                if ((i == x && j == y) || i < 0 || i >= row || j < 0 || j >= col ||
		    (i == x-1 && j == y-1) ||
		    (i == x-1 && j == y+1) ||
		    (i == x+1 && j == y-1) ||
		    (i == x+1 && j == y+1)) 
                    continue;
                vector<int> coor;
                coor.push_back(i);
                coor.push_back(j);
                result.push_back(coor);
            }
        }
	return result;
    }
    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size();
        if (row == 0)
            return false;
        int col = board[0].size();
        if (col == 0) 
            return false;
        int i, j, k, m, n;
        bool visited[row][col];
        stack<vector<int> > coordinateStack;
        int len = word.size();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
		for (m  = 0; m < row; m++) 
			for (n = 0; n < col; n++)
				visited[m][n] = false;
                int cur = 0; 
                if (board[i][j] == word[cur]) {
                    vector<int> coor;
                    coor.push_back(i);
                    coor.push_back(j);
                    coordinateStack.push(coor);
                    visited[i][j] = true;
                    cur++;
		    if (cur == len)
			    return true;
                }
                while (!coordinateStack.empty()) {
                    vector<int> prev = coordinateStack.top();
                    coordinateStack.pop();
                    vector<vector<int> > neighbors = adjacent(prev, row, col);
		    bool find = false; 
		    std::cout << word[cur] << std::endl;
                    for (k = 0; k < neighbors.size(); k++) {
                        if (!visited[neighbors[k][0]][neighbors[k][1]] &&
		            board[neighbors[k][0]][neighbors[k][1]] == word[cur]) {
                            vector<int> next;
                            next.push_back(neighbors[k][0]);
                            next.push_back(neighbors[k][1]);
                            coordinateStack.push(next);
                            visited[neighbors[k][0]][neighbors[k][1]] = true;
			    find = true;
                        } 
                    }
		    if (find) 
			    cur++;
		    if (cur == len)
			    return true;
                }
            }
        }
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

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
class Solution {
public:
// sort and then see if repeating.
    bool hasRepeat(vector<char>& row) {
        int size = row.size();
        if (size == 0) 
            return false;
        int i;
        sort(row.begin(), row.end());
        for (i = 0; i < size - 1; i++) {
            if(row[i] != '.' && row[i] == row[i+1])
                return true;
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        int rowNum = board.size();
        if (rowNum == 0) 
            return true;
        int colNum = board[0].size();
        int i;
        int j;
        std::cout << "rowNum " << rowNum << " colNum  " << colNum << std::endl; 
        for (i = 0; i < rowNum; i++) {
            vector<char> col;
            std::cout << "3" << std::endl;
            for (j = 0; j < colNum; i++) {
              std::cout << "colNum  " << colNum  << "  " << i <<  "  " << j << std::endl;
              std::cout << board[i][j] << std::endl;
  //              col.push_back(board[i][j]);
            }
            std::cout << "2" << std::endl;
            if (hasRepeat(col)) {
                return false;
            }
        }
        std::cout << "1" << std::endl;
        for (i = 0; i < rowNum; i++) {
            if (hasRepeat(board[i]))
                return false;
        }
        return true;
    }
};

int main() {
  vector<vector<char> > board;
  vector<char> s1;
  s1.push_back('.');
  s1.push_back('1');
  vector<char> s2;
  s2.push_back('2');
  s2.push_back('.');

  /*
  vector<char> s2('2', '.', '.', '.', '.', '.', '.', '.', '.');
  vector<char> s3('3', '.', '.', '.', '.', '.', '.', '.', '.');
  vector<char> s4('4', '.', '.', '.', '.', '.', '.', '.', '.');
  vector<char> s5('5', '.', '.', '.', '.', '.', '.', '.', '.');
  vector<char> s6('6', '.', '.', '.', '.', '.', '.', '.', '.');
  vector<char> s7('7', '.', '.', '.', '.', '.', '.', '.', '.');
  vector<char> s8('8', '.', '.', '.', '.', '.', '.', '.', '.');
  vector<char> s9('9', '.', '.', '.', '.', '.', '.', '.', '.');
  */
  board.push_back(s1);
  board.push_back(s2);
  /*
  board.push_back(s2);
  board.push_back(s3);
  board.push_back(s4);
  board.push_back(s5);
  board.push_back(s6);
  board.push_back(s7);
  board.push_back(s8);
  board.push_back(s9);
*/

  Solution sol;
  if (sol.isValidSudoku(board)) 
    std::cout << "valid" << std::endl;
  else 
    std::cout << "not valid" << std::endl;
  return 0;

}

"....5..1.",
".4.3.....",
".....3..1",
"8......2.",
"..2.7....",
".15......",
".....2...",
".2.9.....",
"..4......"




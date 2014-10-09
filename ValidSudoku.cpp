#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
class Solution {
public:
    void Reset(vector<int> &vec) {
        for (int i = 0; i < vec.size();i++) vec[i] = 0;
    }
    bool isValidSudoku(const vector<vector<char> > &board) {
        vector<int> cnt(10, 0);
        // check row && column;
        for (int i = 0; i < 9; i++) {
            Reset(cnt);
            for (int j = 0; j < 9; j++) {
		    std::cout << i << " " << j << board[i][j] << std::endl;
                if (board[i][j] != '.') {
			
                    if (cnt[board[i][j]-'0']) {
			    std::cout <<"1" << std::endl;
			    return false;
		    }
		    
                    cnt[board[i][j]-'0']++;
                }
            }
	} 
	std::cout << "end line" <<std::endl;
	for (int i = 0; i < 9; i++) {
            Reset(cnt);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
			std::cout <<j << " " << i << " " << board[j][i] << std::endl;
                    if (cnt[board[j][i]-'0']) {
			    std::cout << j <<" " << i << " " << cnt[board[j][i]-'0'] << " " <<board[j][i] <<std::endl;
			    std::cout <<"2" <<std::endl;
			    return false;
		    }
                    cnt[board[j][i]-'0']++;
		}
                
            }
        }
        // check squre;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int xBegin = 3*i;
                int yBegin = 3*j;
                Reset(cnt);
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        if (board[xBegin+m][yBegin+n] != '.') {
                            if (cnt[board[xBegin+m][yBegin+n]-'0']) {
				    std::cout <<"3" <<std::endl;
				    return false;
			    }
                            cnt[board[xBegin+m][yBegin+n]-'0']++;
                        }
                    }
                }
            }
        }
        return true;
    }
};
int main() {
  vector<vector<char> > board;
  vector<char> s1;
  s1.push_back('.');
  s1.push_back('8');
  s1.push_back('7');
  s1.push_back('6');
  s1.push_back('5');
  s1.push_back('4');
  s1.push_back('3');
  s1.push_back('2');
  s1.push_back('1');
  board.push_back(s1);
  s1[0] = '2';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);
  s1[0] = '3';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);
  s1[0] = '4';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);
  s1[0] = '5';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);
  s1[0] = '6';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);
  s1[0] = '7';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);
  s1[0] = '8';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);
  s1[0] = '9';
  s1[1] = '.';
  s1[2] = '.';
  s1[3] = '.';
  s1[4] = '.';
  s1[5] = '.';
  s1[6] = '.';
  s1[7] = '.';
  s1[8] = '.';
  board.push_back(s1);

  Solution sol;
  if (sol.isValidSudoku(board)) 
    std::cout << "valid" << std::endl;
  else 
    std::cout << "not valid" << std::endl;
  return 0;

}





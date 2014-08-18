#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool can_place(int a[], int row, int k) {
        int i, j;
        for (i = 0; i < row; i++) {
            if (a[i] == k)
                return false;
        }
        for (i = 0; i < row; i++) {
          std::cout << "a[i] "<<a[i] << "  " << i << std::endl;
          std::cout << "row " << row << " " << k << std::endl; 
            if ((a[i] - i) == (row - k) ||
                (a[i] - i) == (k - row))
                return false;
        }
        return true;
    }
    void queen(int  a[], int n, int row, vector<vector<string> >& result) {
        int i, j, k;
        if (row == n) {
            vector<string> oneSol;
            for (i = 0; i < n; i++) {
                string sol = "";
                for (j = 0; j < n; j++) {
                    if (j == a[i]) 
                        sol = sol + "Q";
                    else 
                        sol = sol + ".";
                }  
                oneSol.push_back(sol);
            }
            result.push_back(oneSol);
        } else {
            for (k = 0; k < n; k++) {
                if (can_place(a, row, k)) {
                    a[row] = k;
                    queen(a, n, row+1, result);
                }
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        int a[n];
        queen(a, n, 0, result);
        return result;
    }
};

int main() {
  Solution sol;
  vector<vector<string> > result = sol.solveNQueens(4);
  int i, j, k;
  for (i = 0; i < result.size(); i++) {
    for (j = 0; j < result[i].size(); j++) {
      std::cout << result[i][j] << std::endl;
    }

    std::cout << "-----------" << std::endl;
  }
  return 0;
}


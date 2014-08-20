#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int fifthMax(int a, int b, int c, int d, int e) {
        int f = a>b?a:b;
        int g = c>d?c:d;
        int h = f>g?f:g;
        return h>e?h:e;
    }
    bool canRectangle(vector<vector<char> > &matrix, int i, int j, int m, int n) {
        int row, col;
        for (row = m; row <= i; row++) {
            for (col = n; col <= j; col++) {
                if (matrix[row][col] == '0')
                    return false;
            }
        }
        return true;
    }
    int brutalForceArea(vector<vector<char> > &matrix, int i, int j) {
        int row, col;
        int area = 0;
        int max = 0;
        for (row = 0; row <= i; row++) {
            for (col = 0; col <= j; col++) {
                if(canRectangle(matrix, i, j, row, col)) {
                    area = (i-row+1)*(j-col+1);
                    max = max > area? max: area;
                    if (row == 0 && col == 0)
                        return max;
                }
            }
        } 
        return max;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row, col;
        int i, j;
        int rowSize = matrix.size();
        int colSize;
        int cnt, k, cnt2;
        // empty
        if (rowSize == 0)
            return 0;
        colSize = matrix[0].size();
        if (colSize == 0)
            return 0;
        int arr[rowSize][colSize];
        for (i = 0; i < rowSize; i++) {
            for (j = 0; j < colSize; j++) {
                arr[i][j] = 0;
            }
        }
        for (i = 0; i < rowSize; i++) {
            arr[i][0] = brutalForceArea(matrix, i, 0);
        }
        for (j = 0; j < colSize; j++) {
            arr[0][j] = brutalForceArea(matrix, 0, j);
        }
        for (i = 1; i < rowSize; i++) {
            for (j = 1; j < colSize; j++) {
                if (matrix[i][j] == '0') {
                    arr[i][j] = fifthMax(arr[i-1][j-1], arr[i-1][j], arr[i][j-1], 0, 0);
                } else 
                if (matrix[i-1][j] == '0' && matrix[i][j-1] == '0') {
                    arr[i][j] = fifthMax(arr[i-1][j-1], arr[i-1][j], arr[i][j-1], 0, 0);
                } else
                if (matrix[i-1][j] == '0') {
                    cnt = 0;
                    for (k = j; k>=0; k--) {
                        if (matrix[i][k] == '0')
                            break;
                        cnt++;
                    } 
                    arr[i][j] = fifthMax(arr[i-1][j-1], arr[i-1][j], arr[i][j-1], cnt, 0);
                } else 
                if (matrix[i][j-1] == '0') {
                    cnt = 0;
                    for (k = i; k >= 0; k--) {
                        if (matrix[k][j] == '0')
                            break;
                        cnt++;
                    }
                    arr[i][j] = fifthMax(arr[i-1][j-1], arr[i-1][j], arr[i][j-1], cnt, 0);
                } else 
                if (matrix[i-1][j-1] == '0') {
                    cnt = 0;
                    cnt2 = 0;
                    for (k = i; k >= 0; k--) {
                        if (matrix[k][j] == '0')
                            break;
                        cnt++;
                    }
                    for (k = j; k >=0; k--) {
                        if (matrix[i][j]=='0')
                            break;
                        cnt2++;
                    }
                    arr[i][j] = fifthMax(arr[i-1][j-1], arr[i-1][j], arr[i][j-1], cnt, cnt2);
                } else {
                    arr[i][j] = brutalForceArea(matrix, i, j);
                }
            }
        }
        return arr[rowSize-1][colSize-1];
    }
};

int main() {
  vector<vector<char> > vec;
  vector<char> sub;
  vector<char> sub2;
  sub.push_back('0');
  sub.push_back('0');
  sub.push_back('0');
  sub2.push_back('1');
  sub2.push_back('1');
  sub2.push_back('0');
  vec.push_back(sub);
  vec.push_back(sub2);
  Solution sol;
  std::cout << sol.maximalRectangle(vec) << std::endl;
  return 0;
}

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int size = s.size();
        int numBlg = size/(2*nRows-2) + 1;
        int col = numBlg * (nRows-1);
        int i, j;
        int x, y;
        char array[nRows][col];
        for (i = 0; i < nRows;i++) {
            for (j = 0; j < col; j++) 
                array[i][j] = ' ';
        }
        x = 0;
        y = 0;
        for (i = 0; i < size; i++) {
            array[x][y] = s[i];
            if (y % (nRows -1) == 0 && x != nRows-1) {
                x = x+1;
            } else 
            if (y % (nRows-1) == 0 && x == nRows-1) {
                x = x-1;
                y = y+1;
            } else {
                x = x-1;
                y = y+1;
            }
        }
        string result = "";
        for (i = 0; i < nRows; i++) {
            for (j = 0; j < col; j++) {
                if (array[i][j] != ' ')
                    result += array[i][j];
            }
        }
        return result;
    }
};

int main () {
  Solution sol;
  std::cout << sol.convert("PAYPALISHIRING", 3) << std::endl;
  return 0;

}

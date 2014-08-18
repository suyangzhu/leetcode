#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(string& str) {
        int size = str.size();
        int i;
        int maxI = 0;
        int maxJ;
        char tmp;
        
        if (size < 2)
            return;
        for (i = 1; i < size; i++) {
            if(str[i-1] < str[i])
                maxI=i;
        } 
        if (maxI == 0) {
            sort(str.begin(), str.end());
            return;
        }
        maxJ = maxI;
        for (i = maxI; i < size; i++) {
            if (str[maxI-1] < str[i])
                maxJ = i;
        }
        tmp = str[maxJ];
        str[maxJ] = str[maxI-1];
        str[maxI-1] = tmp;
        sort(str.begin() + maxI, str.end());
        return;
    }
    string getPermutation(int n, int k) {
        char arr[10] = {'0', '1', '2', '3', '4',
                        '5', '6', '7', '8', '9'}; 
        int i;
        string result = "";
        vector<char> vec;
        for (i = 1; i < 10; i++) {
          vec.push_back(arr[i]);
        }
        int tmp = k - 1;
        int total;
        int sub;
        int x;
        for (x = n; x>=1; x--)
        {
          total =1;
          sub = 1;
          for (i = 1; i <= x-1; i++) 
            sub *= i;
          total = sub * x;
          result = result + vec[tmp / sub];
          vec.erase(vec.begin() + tmp/sub);
          tmp = tmp % sub;
        }
        /*
        for (i = 1; i <=n; i++) {
          result += arr[i];
        }
        for (i = 0; i < k-1;i++) {
            nextPermutation(result);
        }
        */
        return result;
        
    }
};

int main() {
  Solution sol;
  std::cout << sol.getPermutation(9, 196883) << std::endl;
  return 0;
}

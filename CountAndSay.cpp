#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        int size;
        int i;
        int cnt;
        string result = "";
        string str[10] = {"0", "1", "2", "3", "4", "5", "6","7", "8", "9"};
        if (n == 0)
            return result;
        if (n == 1) 
            return "1";
        if (n == 2) 
            return "11";
        
        string prevStr = countAndSay(n-1);
        size = prevStr.size();
        cnt = 1;
        i = 0;
        while (i < size) {
            if ((i < size -1) && prevStr[i] == prevStr[i+1]) {
                cnt++;
                i++;
            } else
            if (i == (size-1)){
                result += str[cnt];
                result += prevStr[i];
                break;
            } else {
                result += str[cnt];
                result += prevStr[i];
                i++;
                cnt = 1;
            }
        }
        return result;
    }
};
int main() {
  Solution sol;
  int i;
  for (i = 3; i < 22; i++) {
    std::cout << sol.countAndSay(i) << std::endl;
  }
}

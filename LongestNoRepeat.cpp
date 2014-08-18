#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool repeat(string&s, int start, int end) {
        unordered_map<char, int> HashMap;
        int i;
        for (i = start; i <= end; i++) {
            if (HashMap.find(s[i])== HashMap.end())
                HashMap[s[i]] = i;
            else 
                return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0)
            return 0;
        vector<int> length(size, 0);
        int i, j;
        length[0] = 1;
        for (i = 1; i < size; i++) {
            // The maxium number of ASCII is 95.
            if (length[i-1] == 95)
                return 95;
            if (repeat(s, i-length[i-1], i))
                length[i] = length[i-1];
            else 
                length[i] = length[i-1] + 1;
        }
        return length[size-1];
    }
};
int main() {
  Solution sol;
  string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345678 " 
          ; 
//    cin >> str;
    std::cout << str << " : " << sol.lengthOfLongestSubstring(str) 
    << std::endl;
  
  return 0;
}

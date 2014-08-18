#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int i;
        int size1 = s1.size();
        int size2 = s2.size();
        if (s1 == s2)
            return true;
        if (size1 == 0) 
            return true;
        if (size1 == 1) {
            if (s1 == s2)
                return true;
            else 
                return false;
        }
        if (size1 == 2) {
            if ((s1[0] == s2[1] && s1[1] == s2[0]))
                return true;
            else 
                return false;
        }
        for (i = 1; i < size1; i++) {
          string sub1 = s1.substr(0, i);
          string sub2 = s1.substr(i, size1 - i);
          string sub3 = s2.substr(0, i);
          string sub4 = s2.substr(i, size2 - i);
          if ((sub2+sub1) == (sub3 + sub4) || sub1 + sub2 == sub4 + sub3) {
            return true;
          } else
          if (sub1 == sub3 && isScramble(sub2, sub4)) {
            return true;
          } else 
          if (isScramble(sub1, sub3) && sub2 == sub4) {
            return true;
          } else 
          if (isScramble(sub1, sub3) && isScramble(sub2, sub4)) {
              return true;
          } 
        }
        return false;
    }
};

int main() {
  Solution sol;
  if (sol.isScramble("abc", "bac"))
    std::cout << "T" << std::endl;
  else 
    std::cout << "F" << std::endl;
  return 0;
}


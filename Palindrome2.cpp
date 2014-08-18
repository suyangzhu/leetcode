#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
  bool isPalindrome (string str) {
    int size = str.size();
    int i;
    for (i = 0; i < size/2; i++) {
      if (str[i] != str[size-i-1])
        return false;
    }
    return true;
  }
  vector<vector<string> > partition(string s) {
    int i, j, k;

    int size = s.size();
    string sub1, sub2;
    vector<vector<string> > result; 
    if (size == 0) {
      return result;
    }
    if (size == 1 ) {
      vector<string> vec;
      vec.push_back(s);
      result.push_back(vec);
      return result;
    }
    if (isPalindrome(s)) {
      vector<string> vec;
      vec.push_back(s);
      result.push_back(vec);
    }
    vector<vector<string> > subVec; 
    for (i = size -1; i >= 0; i--) {
      sub1 = s.substr(0, i);
      sub2 = s.substr(i, size-i);
      if (isPalindrome(sub2)) {
        subVec = partition(sub1);
        for (j = 0; j < subVec.size(); j++) {
           subVec[j].push_back(sub2);
           result.push_back(subVec[j]);
        }
      }
    }
    return result;
  }
};
int main() {
  Solution sol;
  int i, j;
  vector<vector<string> > result = sol.partition("bb"); 
  
  for (i = 0; i < result.size(); i++) {
    for (j = 0; j < result[i].size(); j++) 
      std::cout << result[i][j] << "  ";
    std::cout << std::endl;
  }
  return 0;
}

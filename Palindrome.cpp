#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string> > merge(vector<vector<string> >& vec1, vector<vector<string> >& vec2) {
       int size1 = vec1.size();
       int size2 = vec2.size();
       vector<vector<string> > result;
       int i, j;
       for (i = 0; i < size1; i++) {

           for (j = 0; j < size2; j++) {
                vector<string> tmp = vec1[i];
                tmp.insert(tmp.end(), vec2[j].begin(), vec2[j].end());   
                result.push_back(tmp);
           }
       }
       return result;
    }
    bool isPalindrome(string& str) {
        int size = str.size();
        int i;
        for (i = 0; i < size/2; i++) {
            if (str[i]!=str[size-i-1])
                return false;
        }
        return true;
    }
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        int size = s.size();
        int size2;
        int i, j, k, l;
        if (size == 0) {
            return result;
        }
        if (isPalindrome(s)) {
            vector<string> tmp;
            tmp.push_back(s);
            if(find(result.begin(), result.end(), tmp) == result.end()) {
                result.push_back(tmp);
            }
        }
        for(i = 1; i < size; i++) {
            string left(s.begin(), s.begin() + i);
            string right(s.begin()+i, s.end());
            vector<vector<string> > leftStrVec = partition(left);
            vector<vector<string> > rightStrVec = partition(right);
            vector<vector<string> > tmpResult = merge(leftStrVec, rightStrVec);
            size2 = tmpResult.size();
            for (j = 0; j < size2; j++) {
                if (find(result.begin(), result.end(), tmpResult[j]) == result.end()) 
                    result.push_back(tmpResult[j]);
            }
        }
        return result;
    }
};

int main() {
  Solution sol;
  int i, j;
  vector<vector<string> > result = sol.partition("amanaplanacanalpanama"); 
  for (i = 0; i < result.size(); i++) {
    for (j = 0; j < result[i].size(); j++) 
      std::cout << result[i][j] << "  ";
    std::cout << std::endl;
  }
  return 0;
}

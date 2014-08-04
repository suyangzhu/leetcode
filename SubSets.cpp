#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int i, j, k;
        int size = S.size();
        vector<vector<int> > result;
        queue<vector<int> > queueVec;
        vector<int> zeroVec;
        result.push_back(zeroVec);
        if (size == 0) {
            
            return result;
        }
        
        for (k = 1; k <= size; k++) {
            for (i = 0; i < size; i++) {
                vector<int> vec;
                vec.push_back(i);
                queueVec.push(vec);
            }
            while (!queueVec.empty()) {
                vector<int> vec = queueVec.front();
                queueVec.pop();
                int vecSize = vec.size();
                if (vecSize == k) {
                    int m;
                    vector<int> vec2;
                    for (m = 0; m < k; m++) 
                        vec2.push_back(S[vec[m]]);
                    if (find(result.begin(), result.end(), vec2) == result.end()) 
                        result.push_back(vec2);
                } else {
                    for (j = vec.back() + 1; j < size; j++) {
                        vector<int> vec2 = vec;
                        vec2.push_back(j);
                        queueVec.push(vec2);
                        std::cout << "endless here ?" << std::endl;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
  vector<int> S;
  S.push_back(1);
//  S.push_back(2);
//  S.push_back(2);
//  S.push_back(2);
  Solution sol;
  vector<vector<int> > result = sol.subsetsWithDup(S);
  int i, j;
  for (i = 0; i < result.size(); i++) {
    for (j = 0; j < result[i].size(); j++) {
      std::cout << result[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}

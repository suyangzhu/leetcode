#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sum(vector<int>& vec, vector<int>& cand) {
        int val = 0;
        int size = vec.size();
        if (size == 0)
            return val;
        int i;
        for (i = 0; i < size; i++) {
            val += cand[vec[i]];
        }
        return val;      
    }
/* brutal force. A queue for vector. if sum of vector == target. push_back. 
   if sum is larger discard. if less add another number. */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        int size = candidates.size();
        
        vector<int> availVec;
        int i;
        sort(candidates.begin(), candidates.end());
        for (i = 0; i < size; i++) {
            if (candidates[i] > target)
                break;
            availVec.push_back(candidates[i]);
        }
        size = availVec.size();
        sort(availVec.begin(), availVec.end());
        
        if (size == 0)
            return result;
        queue<vector<int> > vecQueue;
        for (i = 0; i < size; i++) {
            vector<int> vec;
            vec.push_back(i);
            if (availVec[i] == target) {
                vector<int> tmp;
                tmp.push_back(availVec[i]);
                result.push_back(tmp);
            }
            if (availVec[i] < target)
                vecQueue.push(vec);
        }
        
        while (!vecQueue.empty()) {
            vector<int> vec = vecQueue.front();
            vecQueue.pop();
            for (i = vec.back(); i < size; i++) {
                vector<int> tmpVec = vec;
                tmpVec.push_back(i);
                int tmpSum = sum(tmpVec, availVec);
                if (tmpSum < target) 
                    vecQueue.push(tmpVec);
                if (tmpSum == target) {
                    vector<int> tmp;
                    int indexSize = tmpVec.size();
                    int k;
                    for (k = 0; k < indexSize; k++) 
                      tmp.push_back(availVec[tmpVec[k]]);
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};

int main() {
  vector<int> vec;
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(8);
  vec.push_back(4);
//  vec.push_back(7);
  Solution sol;
  vector<vector<int> > result = sol.combinationSum(vec, 6);
  int size = result.size();
  int i, j;
  
  for (i = 0; i < size; i++) {
    for (j = 0; j < result[i].size(); j++) {
      std::cout << result[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}








#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;
class Solution {
public:
    int sum (vector<int>& vec, vector<int>& cand) {
        int size;
        int i;
        int result = 0;
        size = vec.size();
        for (i = 0; i < size; i++) {
            result += cand[vec[i]];
        }
        return result;
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        int size = num.size();
        int size2;
        int i, k;
        if (size == 0)
            return result;
        queue<vector<int> > bfsQueue;
        sort(num.begin(), num.end());
        for (i = 0; i < size; i++) {
            vector<int> seed;
            if (num[i] == target) {
                seed.push_back(num[i]);
                if (find(result.begin(), result.end(), seed) == result.end())
                    result.push_back(seed);
            } else
            if (num[i] < target) {
                seed.push_back(i);
                bfsQueue.push(seed);
            } else {
                continue;
            }
        }
        while (!bfsQueue.empty()) {
            vector<int> indexVec = bfsQueue.front();
            bfsQueue.pop();
            for(i = indexVec.back() + 1; i < size; i++) {
              std::cout << indexVec[0]<< std::endl;
                vector<int> tmp = indexVec; 
                std::cout << sum(indexVec, num) << "  " << num[i] << std::endl;
                if (sum(indexVec, num) + num[i] == target) {
                    size2 = tmp.size();
                    vector<int> vec;
                    for (k = 0; k < size2; k++)
                        vec.push_back(num[tmp[k]]);
                    vec.push_back(num[i]);
                    if (find(result.begin(), result.end(), vec) == result.end())
                        result.push_back(vec);
                }  else 
                if (sum(indexVec, num) + num[i] < target) {
                    tmp.push_back(i);
                    bfsQueue.push(tmp);
                } else {
                    continue;
                }
            }
        }
        return result;
    }
};



int main() {
  vector<int> vec;
  vec.push_back(1);
//  vec.push_back(3);
//  vec.push_back(8);
  vec.push_back(1);
//  vec.push_back(7);
  Solution sol;
  vector<vector<int> > result = sol.combinationSum2(vec, 2);
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





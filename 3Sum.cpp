#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int error(int val, int target) {
        return val > target?val - target:target-val;
    }
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        queue<vector<int> > triple;
        int size = num.size();
        int i, j;
        for (i = 0; i < size; i++) {
            vector<int> vec;
            vec.push_back(i);
            triple.push(vec);
        }
        int sum = num[0] + num[1] + num[2];
        int sum2 = sum;
        int min = error(sum, target);
        while (!triple.empty()) {
            vector<int> vec = triple.front();
            triple.pop();
            if (vec.size() == 3) {
              std::cout << vec[0] << vec[1] << vec[2] << std::endl;
                sum = num[vec[0]] + num[vec[1]] + num[vec[2]];
                if (min > error(sum, target)) {
                    min = error(sum, target);
                    sum2 = sum;
                }
            } else {
                for (j = vec.back()+1; j < size; j++) {
                    vector<int> tmpVec = vec;
                    tmpVec.push_back(j);
                    triple.push(tmpVec);
                }
            }
        }
        return sum2;
    }
};

int main() {
  Solution sol;
  vector<int> vec;
  vec.push_back(-3);
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);

  std::cout << sol.threeSumClosest(vec, 1) << std::endl;
  return 0;
}

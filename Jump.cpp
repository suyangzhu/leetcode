#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int index = 0;
        int i;
        int preIndex = 0;
        int cnt = 0;
       
        if (A[0] >= n-1)
            return 1;
        while (index < n) {
            int max = index;
            int preMax = 0;
            for (i = 1; i <= A[index]; i++) {
                if (index+i>=n-1) {
                  cnt++;
                    return cnt;
                }
                if (((index+i) + A[index+i]) > preMax){
                    max = index+i;
                    preMax = index+i+A[index+i];
                }
            }
            cnt++;
//            if (max >= n-1) {
//                return cnt;
//            }
            index = max;
        }
        cnt++;
        return cnt;
    }
};

int main() {
  int A[9] = {6,9,1,5,6,0,0,5,9};
  Solution sol;
  std::cout << sol.jump(A,9) << std::endl;
  return 0;
}

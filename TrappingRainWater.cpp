#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int nextHighest(int A[], int begin, int end) {
        int i; 
        i = begin;
        int maxIndex = begin;
        while (i < end) {
            maxIndex = A[maxIndex] > A[i] ?maxIndex:i;
            i++;
        }
        return maxIndex;
    } 
    int trap(int A[], int n) {
        int sum = 0;
        int i;
        int currentHighest = A[0];
        for (i = 0; i < n; i++) {
            int index = nextHighest(A, i , n);
            if (A[index] >= currentHighest) {
                currentHighest = currentHighest > A[i] ? currentHighest:A[i];
            } else {
                currentHighest = A[index];
            }
            std::cout << "current Highest" <<  currentHighest << std::endl;
            sum += currentHighest;
        }
//        sum += A[n-1];
        for (i = 0; i < n; i++) {
            sum -= A[i];
        }
        return sum;
    }
};

int main() {
  int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
  int B[3] = {4, 2, 3};
  Solution sol;
  std::cout << sol.trap(B, 3) << std::endl;
  return 0;
}

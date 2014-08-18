#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int binary(int start, int end, int result) {
      if (end < start) 
          return -1;
      int mid = (start+end)/2;
      if (start*start == result) 
          return start;
      if (end * end == result)
          return end; 
      if (mid*mid == result) {
         return mid;
      } else 
      if ((mid-1)*(mid-1) < result && (mid+1)*(mid+1) > result) {
        int tmp = mid*mid;
        if (tmp < result)
            return mid;
        else 
            return mid-1;

      } else 
      if ( (mid-1)*(mid-1) <= result && mid*mid > result) {
          return mid-1;
       }else
       if(mid*mid < result && (mid+1)*(mid+1) > result) {
         return mid;
       } else
      if ((mid*mid < result) )
        return binary(mid+1, end, result);
      else 
      if (mid*mid > result) 
        return binary(start, mid-1, result);
    }
    
    int sqrt(int x) {
        if (x== 0)
            return 0;
        if (x < 4)
            return 1;
        int i;
        int index = 0;
        int num = x;
        int res = 1;
        while (num > 0) {
            index++;
            num /= 2;

        }
        index--;
        for (i = 0; i < index/2; i++) {
          res*=2;
        }
        return binary(res, 2*res, x);
    }
};

int main () {
  Solution sol;
  long num;
  cin >> num ;
//  for (num = 100000000000000; num < 100000000000001; num++) {
//    if (sol.sqrt(num) != (int)sqrt(num)) {
      std::cout << "num: " << num << "  sol: " << sol.sqrt(num) << "  sqrt: " << (int)sqrt(num) << std::endl; 
//    }
//  }
  return 0;
}

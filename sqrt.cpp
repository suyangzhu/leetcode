#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define EPS 0.000001
float binarysqrt(float n) {
  float start = 0; 
  float end = n;
  float mid = (start+end)/2;
  float last;
  if (n < 0)  {
    return n;
  }
  do { 
      if (mid*mid > n)
        end = mid;
      else 
        start = mid;
      last = mid;
      mid = (end+start)/2;
  } while (abs(last - mid) > EPS);
  return mid;
}

int main() {
  std::cout << binarysqrt(2) << std::endl;
  return 0;
}

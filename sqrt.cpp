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

float Newton(float n) {
  float val = n;
  float last;
  do {
    last = val;
    val = (val + n/val)/2;
  }  while(abs(last-val) > 0.00001);
  return val;
}

int NewtonInt(int n) {
  int val = n;
  int last;
  do {
    last = (val + n/val)/2;
    if(last >= val)
      break;
    val = last;
  } while (1);
  return val;
}

int main() {
  int num;
  while (1) {cin >> num;
  std::cout << NewtonInt(num) << std::endl;
  }
  return 0;
}

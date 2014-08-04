#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

double Pow(double x, int n) {
  double result = 1.0;
  int i;
  for(i = 0; i < n; i++) 
    result *= x;
  return result;
}

int main() {
  std::cout << Pow(1.1, 2) << std::endl;
  return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int oneTimeMaxProfit(vector<int>& prices, int start, int end) {
        int max = 0;
        int min;
        int i;
        // No need to trade;
        if (end-start <=1)
            return 0;
        // most one time;
        min = prices[start];
        for (i = start; i < end; i++) {
           int tmp = prices[i]-min;
           min = min < prices[i] ? min : prices[i];
           max = max > tmp? max: tmp;
        }
        return max;
    }
    int maxProfit(vector<int> &prices) {
        int max = 0;
        int max1 = 0;
        int size = prices.size();
        int i;
        if (size <= 1)
            return 0;
        bool tag = false;
        for (i = 0; i < size -1; i++) {
          if (prices[i] < prices[i+1]) {

            tag = true;
            break;
            }
        }
        if (!tag)
            return 0;
        for (i = 0; i < size; i++) {
            max1 = oneTimeMaxProfit(prices, 0, i) + oneTimeMaxProfit(prices, i, size);
            if (max1 > max) {
                max = max1;

            }
            if (max > 0)
               std::cout << max << std::endl;
        } 
        std::cout << max << std::endl;
        return max;
    }
};

int main() { 
  Solution sol;
  int i; 
  
  vector<int> vec;
  for (i  = 0; i <10000; i++) 
      vec.push_back(10000-i);
  for (i = 0; i < 10000; i++) 
      vec.push_back(0);

  std::cout << sol.maxProfit(vec) << std::endl;

  return 0;
}

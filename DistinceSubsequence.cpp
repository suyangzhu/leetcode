#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    int combination(int a, int b) {
        int i;
        int numerator = 1;
        int denominator = 1;
        for (i = 0; i < a; i++) {
            numerator = numerator*(b-i);
            denominator = denominator*(i+1);
        }
        return numerator/denominator;
    }
    int numDistinct(string S, string T) {
        int strSize = S.size();
        int substrSize = T.size();
        if (strSize < substrSize)
            return 0;
        int i, j, k;
        int cnt0 = 1;
        int cnt1 = 0;
        int result = 1;
        for (i = 0; i < S.size(); i++) {
            if (T[0] == S[i])
                break;
        }
        if (i == strSize)
            return 0;
        for (j = 0; j < substrSize; j++) {
            while ((j < substrSize - 1) && (T[j] == T[j+1])) {
                j++;
                cnt0++;
            }
            while(i < strSize && S[i] != T[j]) {
                i++;
            }
            if (i == strSize) 
                return 0;
            while (i < strSize && S[i] == T[j]) {
                i++;
                cnt1++;
            }
            if (cnt1 < cnt0)
                return 0;
            result  = result * combination(cnt0, cnt1);
            cnt0 = 1;
            cnt1 = 0;
            
        }
        return result;
    }
};
int main() {
  Solution sol;
  string s1 = "aacaacca";
  string s2 = "ca";
  std::cout << "solution = " << sol.numDistinct(s1, s2) << std::endl;
  return 0;

}

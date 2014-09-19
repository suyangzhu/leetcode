#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
class Solution {
public:
   int divide(int dividend, int divisor) {
        int result = 0;
        if (divisor == 0) 
            return -1;
        if (abs(dividend) < abs(divisor)) 
            return 0;
        int sign;
        if (dividend > 0  && divisor > 0 || dividend < 0 && divisor < 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        if (abs(dividend) == abs(divisor))  
            return sign;
        unsigned int dividendWithoutSign = (unsigned int) abs(dividend);
        unsigned int divisorWithoutSign = (unsigned int) abs(divisor);
        int cnt = 0;
        while (dividendWithoutSign > divisorWithoutSign) {
            divisorWithoutSign = divisorWithoutSign << 1;   // mutiply divisorWithoutSign by 2. 
            cnt++;
        }
        cnt--;
        divisorWithoutSign = divisorWithoutSign >> 1;       // now the divisorWithoutSign is right smaller than dividentWithoutSign;
        int numOfDoubleTimes = pow(2,cnt);
        int reminder = (int) (dividendWithoutSign - divisorWithoutSign);
        return sign * (numOfDoubleTimes+divide(reminder, abs(divisor)));
    }
};
int main() {
	Solution sol;
	int c = INT_MIN;
	std::cout << abs(INT_MIN)<< std::endl;
	std::cout << sol.divide(10, 3) << std::endl;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>

class Solution {
public:
   int divide(int dividend, int divisor) {
	    if (divisor == 0) 
		    return -1;
	    if (dividend == 0) 
		    return 0;
	    unsigned long up = dividend >0? dividend:-dividend;
	    unsigned long down = divisor >0? divisor:-divisor;
	    int pos = ((dividend >0 && divisor >0 )|| (dividend < 0 && divisor < 0)) ? 1:-1;
	    if (up < down)
		    return 0;
	    if (up == down)
		    return 1*pos;
	    int cnt = 0;
	    int cnt2 = 1;
	    while (up > down) {
		    down = down <<1;
		    cnt++;
	    }
	    cnt--;
	    while (cnt) {
		    cnt2 *= 2;
		    cnt--;
	    }
	    std::cout << cnt2 << std::endl;
	    up -= down/2;
	    if(pos==-1) 
	    	return -(cnt2 + divide((int)up, abs(divisor)));
	    else 
	        return (cnt2+divide((int)up, abs(divisor)));
    }
};

int main() {
	Solution sol;
	std::cout << sol.divide(10, 3) << std::endl;
	return 0;
}

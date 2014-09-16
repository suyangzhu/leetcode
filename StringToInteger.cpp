#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    unsigned long digit(int n) {
	    unsigned long result = 1;
	    int i; 
	    for (i = 1; i < n; i++)
		    result *= 10;
	    return result;
    }
    bool isDigit(const char c) {
	    if (c >= 48 && c <= 57)
		    return true;
	    else
		    return false;
    }
    int atoi(const char *str) {
    	int i = 0;
	int sign = 1;
	unsigned long result = 0;
       	vector<int> digits;
	while (str[i] != '\0' && str[i] == ' ') {
			i++;
	}
	if (!(str[i] == '-' || str[i] == '+' || isDigit(str[i])))
		return 0;
	if (str[i] == '-') { 
		i++;
		sign = -1;
	}
	else 
	if (str[i] == '+') {
		i++;
		sign = 1;
	}
	if (!isDigit(str[i]))
		return 0;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0' && isDigit(str[i])) {
		digits.push_back(str[i]-48);
		i++;
	}
	int len = digits.size();
	if (len > 10) {
		if (sign == 1)
			return INT_MAX;
		else
			return INT_MIN;
	}
	for (i = len-1; i >=0; i--) {
		unsigned long part = digits[i] * digit(len-i);
		result += part;	
	}
	if (result > INT_MAX) {
		if (sign == 1)
			return INT_MAX;
		else 
			return INT_MIN;
	} else
		return sign * (int) result;
    }
};

int main() {
//	while (1) {
		char str[1000] = "      010";
		Solution sol;
		std::cout << sol.atoi(str) << std::endl;
//	}
	return 0;
}

#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // add two strings 
    string add(string num1, string num2) {
	    
	    int len1 = num1.size();
	    int len2 = num2.size();
	    int m = len1-1;
	    int n = len2-1;
	    string result = "";
	    int carry = 0;
	    while (m >=0 && n >= 0) {
		    int first = num1[m--]-'0';
		    int second = num2[n--]-'0';
		    int cur = first+second+carry;
		    if (cur >9) {
			    carry = 1;
			    cur = cur % 10;
		    } else {
			    carry = 0;
		    }
		    result = to_string(cur)+result;
	    } 
	    while (m >= 0) {
		    int first = num1[m--]-'0';
		    int second = 0;
		    int cur = first+second+carry;
		    if (cur >9) {
			    carry = 1;
			    cur = cur % 10;
		    } else {
			    carry = 0;
		    }
		    result = to_string(cur)+result;
		    
	    } 
	    while (n>=0) {
		    int first = 0;
		    int second = num2[n--]-'0';
		    int cur = first+second+carry;
		    if (cur >9) {
			    carry = 1;
			    cur = cur % 10;
		    } else {
			    carry = 0;
		    }
		    result = to_string(cur)+result;
	    } 
	    if (carry) 
		    result = "1" + result;
	    return result;
    }
    // multiply one digit with a string
    string multi(string num1, char num2) // num1 is multi-digits while num2 is signle digit.
    {
	    int len = num1.size();
	    int carry = 0;
	    int first;
	    int second = num2 - '0';
	    int i;
	    if (num2 == '0')
		    return "0";
	    string result = "";
	    for (i = len-1; i >= 0; i--) {
		    first = num1[i]-'0';
		    int cur = first * second + carry;
		    if (cur >9) {
			    carry = cur/10;
			    cur = cur % 10;
		    } else {
			    carry = 0;
		    }
		    result = to_string(cur) + result;
	    }
	    if (carry)
		    result = to_string(carry) + result;
	    return result;
    }
    string multiply(string num1, string num2) {
	    int len1 = num1.size();
	    int len2 = num2.size();
	    int i,j;
	    if (num1[0] == '0' || num2[0] == '0')
		    return "0";
	    string result = "";
	    for (i = len1-1; i >= 0; i--) {
		    int num = num1[i]- '0';

		    string tmpResult = multi(num2, num1[i]);
		    int digit = len1-i-1;
		    for (j = 0; j < digit; j++) {
			    tmpResult = tmpResult + "0";
		    }
		    result = add(result, tmpResult);
	    }
	    return result;
    }
};

int main() {
	Solution sol;
	std::cout << sol.multiply("999", "999") << std::endl;
//	std::cout << sol.multiply("88887654321234567876543234567", "9752323238787878686868100000") << std::endl;
	return 0;
}

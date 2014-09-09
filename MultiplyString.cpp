#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
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
    string multiply(string num1, string num2) {
	    int len1 = num1.size();
	    int len2 = num2.size();
	    int i,j;
	    if (num1[0] == '0' || num2[0] == '0')
		    return "0";
	    string result = "";
	    for (i = len1-1; i >= 0; i--) {
		    int num = num1[i]- '0';
		    string tmpResult = "";
		    for (j = 0; j < num; j++) {
			    tmpResult = add(num2, tmpResult);
		    }
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
	std::cout << sol.multiply("9369162965141127216164882458728854782080715827760307787224298083754", "71103396869999767678843") << std::endl;
	return 0;
}

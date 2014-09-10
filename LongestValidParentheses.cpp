#include <stack>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
// This is a DP solution for this problem.
// keep record of a vector vec where vec[i] 
// is the longest valid parentheses ending with
// s[i];

// if s[i] == '('  vec[i] = 0 because no valid 
// parentheses end with '('

// if s[i] == ')' 
// - if s[i-1] == '('  vec[i] = s[i-2] +2;
// - if s[i-1] == ')'  we need to find the first non-valid 
// parentheses from right to left to see if it can make a 
// pair with s[i]. If s[i-vec[i-1]-1] = '(', 
// vec[i] = vec[i-vec[i-1]-2] + vec[i-1] + 2;
// Then we pick the largest from the vec.

class Solution {
public:
    	int longestValidParentheses(string s) {
		int len = s.size();
		if (len < 2) 
			return 0;
		vector<int> parenthesesLength(len, 0);
		int i;
	        parenthesesLength[0] = 0;
		if (s[0] == '(' && s[1] == ')')
			parenthesesLength[1] = 2;
		else
			parenthesesLength[1] = 0;
		for (i = 2; i < len; i++) {
			if (s[i] == '(') {
				parenthesesLength[i] = 0;
			} else 
			if (s[i-1] == '('){
				parenthesesLength[i] = parenthesesLength[i-2] + 2;
			} else // check if out of boundry.
			if ((i-parenthesesLength[i-1]-1)>=0 && s[i-parenthesesLength[i-1]-1] == '(') {
				if ((i-parenthesesLength[i-1]-2)>=0)
				parenthesesLength[i] = parenthesesLength[i-parenthesesLength[i-1]-1-1] +
						       parenthesesLength[i-1] +
						       2;
				else 
					parenthesesLength[i] = parenthesesLength[i-1]+2;
			}
		}
		int max = 0;
		for (i = 0; i < len; i++) {
			max = max > parenthesesLength[i]?max:parenthesesLength[i];
		}
		return max;
    	}
};

int main() {
	Solution sol;
	while (1) {
		string str;
		cin >> str;
		std::cout << sol.longestValidParentheses(str) << std::endl;
		
	}
	return 0;
}

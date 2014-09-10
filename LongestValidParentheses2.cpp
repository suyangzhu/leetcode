#include <stack>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    	int fullParenthese(string& s, int begin, int end) {
		int i;
    		if (end - begin < 1)
			return 0;
		stack<char> pStack;
		int result = 0;
		for (i = begin; i<= end; i++) {
			if (s[i] == '(')
				pStack.push(s[i]) ;
			else {
				if (!pStack.empty() && pStack.top() == '(') {
					pStack.pop();
					result += 2;		
				} else 
					pStack.push(s[i]);
			}
		}
		if (pStack.empty())
			return result;		
		else 
			return 0;
    	}
    	int longestValidParentheses(string s) {
		int len = s.size();
		int i, j;
		if (len < 2)
			return 0;
		int max = 0;
		for (i = 0; i < len; i++) {
			int tmp = fullParenthese(s, 0, i) + fullParenthese(s, i+1, len-1);
			max = max > tmp? max:tmp;
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

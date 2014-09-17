#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
	    if (*p == '\0') return *s == '\0';
	    if (*(p+1) == '*') {		// 0 to a number of substr can be matched using the char
		    				// before star.
	    	while (*s && (*s == *p || *p == '.')) {
			if (isMatch(s, p+2))	// there is no need to consume all the chars can be match.
						// example: aabbaa aab*baa. If * consumes all the b. the string 
						// cannot match. So we need to match each time.  
				return true;
			s++;
		}
		return isMatch(s, p+2);		// consume all the chars that * can match.
	    } else {
		    return *s && (*s == *p || *p == '.') && isMatch(s+1, p+1);
	    }
    }
};

int main() {
	Solution sol;
	char a[] = "aaa";
	char b[] = "ab*a*c*a";
	if (sol.isMatch(a, b))
		std::cout << "T" << std::endl;
	else 
		std::cout << "F" << std::endl;
	
	return 0;
}

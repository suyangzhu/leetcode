#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
/**
 * A recursion solution for wildcard matching. Time consuming 
 */
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
	    if(*s == '\0' && *p == '\0')
		    return true;
	    if (*s == '\0') {
		    while (*p == '*') p++;
		    return *p == '\0';
	    } 
	    if (*p == '\0')
		    return false;
	    int i;
	    for (i = 0; s[i] && p[i]; i++) {
		    if (s[i] == p[i] || p[i] == '?')
			    continue;
		    else 
	            if (p[i] == '*'){
			    s = s+i;
			    p = p+i;
			    return isMatch(s+1, p) 	// * matches one char .
				   || isMatch(s, p+1);	// * matches zero.
		    } else
			    return false;
	    }
	    return isMatch(s+i, p+i);
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

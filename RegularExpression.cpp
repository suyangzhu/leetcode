#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
	    stack<char> strStack;
	    stack<char> regex;
	    int i = 0;
	    while (s[i] != '\0') 
		   strStack.push(s[i++]);
	    i = 0;
	    while (p[i] != '\0')
		    regex.push(p[i++]);
	    char last;
	    while (!strStack.empty()) {
		    char tmp = strStack.top();
		    strStack.pop();
		    if (regex.empty()) 
			    return false;
		    if (tmp == regex.top() || regex.top() == '.') {
			    regex.pop();
		    } else
	            if (regex.top() == '*') {
			    if (regex.empty()) {
				    return false;
			    }
			    regex.pop();
			    
			    if (regex.top() == '.' || regex.top() == tmp) {
				    regex.push('*');
				    if (strStack.empty())
					    last = tmp;
			    } else {
				    if (regex.empty()) {
					    return false;
				    }
				    regex.pop();
				    if (regex.empty())
				    {
					    return false;
				    }
				    //keep removing the * which does not match
				    bool quit = false;
				    while (regex.top() == '*') {
					    regex.pop();
					    // *match, do not pop;
					    if (regex.top() == '.' || regex.top() == tmp) {
						    regex.push('*');
						    quit = true;
						    break;
					    } else {
						    regex.pop();
					    }
				    }
				    if (quit)
					    continue;
				    if (regex.empty() || (regex.top() != tmp &&regex.top() != '.'))  {
					    return false;
				    }
				    else 
					    // match. pop from regex stack;
					    regex.pop();
				    
			    }
		    } else {
			    return false;
		    }
	    }
	    if (regex.empty()) 
		    return true;
	    else {
		    while (!regex.empty() && regex.top() == '*') {
			    regex.pop();
			    regex.pop();
		    }
		    if (regex.empty())
			    return true;
		    else  {
			    if (regex.top() == last || regex.top() =='.') 
				    regex.pop();
			    if (regex.empty())
				    return true;
			    return false;
		    }
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

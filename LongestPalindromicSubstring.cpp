#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        
    }
    bool isPalindromic(string s) {
	    int i;
	    int len = s.size();
	    for (i = 0; i < len; i++) {
		    if (s[i] != s[len-i-1])
			    return false;
	    }
	    return true;
    }
    string brutalForce(string s) {
	    int i, j;
	    int len = s.size();
	    string str = "";
	    string result = str;
	    for (i = 0; i < len; i++) {
		    for (j = i; j < len; j++) {
			    str = s.substr(i, j-i+1);
			    if (str.size() > result.size()&&isPalindromic(str))
				   result = str; 
		    }
	    }
	    return result;
    }

    string DPsolution(string s) {

	    int len = s.size();
	    int i, j,k;
	    if (len < 2)
		    return s;
	    bool isPalindrome[len][len];
	    int kmax = 0;
	    int start;
	    // initialization.
	    for (i = 0; i < len; i++) {
		    for (j = 0; j < len; j++) { 
			    if (i >= j)
				    isPalindrome[i][j] = true;
			    else 
				    isPalindrome[i][j] = false;
		    }
	    }

	    for (k = 1; k < len; k++) {
		    for (i = 0; i + k < len; i++) {
			int j = i+k;
			if (s[i] != s[j])
	    			isPalindrome[i][j] = false;
			else {
				isPalindrome[i][j] = isPalindrome[i+1][j-1];
				if (isPalindrome[i][j]) {
					kmax = kmax>j-i+1?kmax:j-i+1;
					start = i;
				}
			}			
		    }
	    }
	    return s.substr(start, kmax);
    }
};
int main() {
	Solution sol;
	std::cout << sol.brutalForce("cbabccb") << std::endl;
	std::cout <<  sol.DPsolution("cbabccb") << std::endl;
	return 0;
}

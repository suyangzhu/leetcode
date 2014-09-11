#include <iostream>
#include <string>
using namespace std;
// s3 is interleaving by s1 & s2.
// DFS solution. time limit exceeds
class Solution {
public:
    bool DFS(int cur1, int cur2, int n, string& s1, string& s2, string& s3) {
	    if (n == s3.size()) 
		    return true;
	    bool result = false;
	    if (cur1 < s1.size() && s1[cur1] == s3[n]) {    
		result = result || DFS(cur1+1, cur2, n+1, s1, s2, s3);
	    }
	    if (cur2 < s2.size() && s2[cur2] == s3[n]) {
	    	result = result || DFS(cur1, cur2+1, n+1, s1, s2, s3);
	    }
	    return result;
    }
    bool isInterleave(string s1, string s2, string s3) {
	    int len1 = s1.size();
	    int len2 = s2.size();
	    int len3 = s3.size();
	    if (len3 != len1 + len2)
		    return false;
	    return DFS(0, 0, 0, s1, s2, s3);
    }
};

int main() {
	string str1 = "aabcc";
	string str2 = "dbbca";
	string str3 =  "aadbbbaccc";
	Solution sol;
	if (sol.isInterleave(str1, str2, str3)) 
		std::cout << "T" << std::endl;
	else 
		std::cout << "F" << std::endl;
	return 0;
}

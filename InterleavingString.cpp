#include <iostream>
#include <string>
using namespace std;
// s3 is interleaving by s1 & s2.
// DP solution. AC however time is long.
// 3 dimension array. If s1[cur1] = s3[cur3], it should be meets s1[cur1-1], s2[cur2] and s3[cur3-1] interleaving. 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
	    int len1 = s1.size();
	    int len2 = s2.size();
	    int len3 = s3.size();
	    if (len3 != len1 + len2)
		    return false;
	    bool isTrue[len1+1][len2+1][len3+1];
	    int i,j, k;
	    for (i = 0; i < len1+1; i++) 
		    for (j = 0; j < len2+1; j++) 
			    for (k = 0; k < len3+1; k++)
				    isTrue[i][j][k] = false;
	    isTrue[0][0][0] = true;
	    for (k = 1; k < len3+1; k++) {
		    for(i = 0; i < len1 +1; i++) {
			    for (j = 0;j < len2 +1; j++) {
				    if (i-1>=0 && s3[k-1] == s1[i-1] && isTrue[i-1][j][k-1])
					    isTrue[i][j][k] = true;
				    if (j-1>=0 && s3[k-1] == s2[j-1] && isTrue[i][j-1][k-1])
					    isTrue[i][j][k] = true;
			    }
		    }
	    }
	    return isTrue[len1][len2][len3];
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

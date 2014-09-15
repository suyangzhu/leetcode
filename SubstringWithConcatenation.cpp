#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
	    vector<int> result;
	    int len1 = S.size();
	    int len2 = L.size();
	    if (len1 == 0 || len2 == 0) 
		    return result;
	    int wordLen = L[0].size();
	    int i, j, k;
	    map<string, int> expectCnt;
	    map<string, int> realCnt;
	    for (i = 0; i < len2; i++) {
		    expectCnt[L[i]]++;
	    }
	    for (i = 0; i <= (int)len1-len2*wordLen; i++) {
		    realCnt.clear();
		    for (j= 0; j < len2; j++) {
			    string str = S.substr(i+j*wordLen, wordLen);
			    if (expectCnt.find(str)!=expectCnt.end())
				    realCnt[str]++;
			    else 
				    break;
			    if (realCnt[str] > expectCnt[str])
				    break;
		    }
		    if (j == len2)
			    result.push_back(i);
	    }
	    return result;
    }
};

int main() {
	string s = "abababab";
	vector<string> l;
	l.push_back("a");
	l.push_back("b");
	l.push_back("a");
//	l.push_back("bar");
	Solution sol;
	vector<int> result = sol.findSubstring(s, l) ;
        int i;
 	for (i = 0; i < result.size(); i++) 
		std::cout << result[i] << " ";
	std::cout << std::endl;
	return 0;	
}

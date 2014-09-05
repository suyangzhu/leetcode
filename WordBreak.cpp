#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
	    string str = "#" + s;
	    int len = str.size();
	    vector<bool> possible(len, false);
	    int i, k;

	    possible[0] = true;
	    for (i = 1; i < len; i++) {
		    for (k = 0; k < i; k++) {
			    possible[i] = possible[k] &&
				    	  dict.find(s.substr(k+1, i-k)) != dict.end();
			    if (possible[i])
				    break;
		    }
	    }
	    return possible[len-1];
    }
};

int main() {
	string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	unordered_set<string> dict = {"a", "aa", "aaaaa", "aaaaaaa"};
	Solution sol;
	if (sol.wordBreak(str, dict))
		std::cout << "T" << std::endl;
	else 
		std::cout << "F" << std::endl;
	return 0;
}

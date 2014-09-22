#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordBreak2(string s, unordered_set<string> &dict) {
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
    bool wordBreak(string s, unordered_set<string> &dict) {
        int stringLength = s.size();
        if (stringLength == 0 || dict.count(s) > 0) return true;
        int i;
        for (i = 1; i < stringLength; i++) {
            string word = s.substr(0, i);
            string remain = s.substr(i, stringLength-i);
	    std::cout << "word: " << word << " remain: " << remain << std::endl;
            if (dict.count(word) > 0) if (wordBreak(remain, dict)) return true;	// cannot return wordBreak(remain, dict) directly.
            if (dict.count(remain) > 0) if (return wordBreak(word, dict)) return true;
        }
        return false;
    }

};

int main() {
	string str1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        string str = "dogs"	;
	unordered_set<string> dict = {"dog", "s", "gs", "aaaaaaa"};
	Solution sol;
	if (sol.wordBreak(str, dict))
		std::cout << "T" << std::endl;
	else 
		std::cout << "F" << std::endl;
	return 0;
}

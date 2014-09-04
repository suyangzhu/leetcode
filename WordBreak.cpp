#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int i;
        int len = s.size();
	int dictVolume = dict.size();
	if (len == 0) 
		return true;
	if (dictVolume == 0)
		return false;
        string substr1;
        string substr2;
        if (dict.find(s) != dict.end()) 
            return true;
        // divided into two strings.
	
        for (unordered_set<string>::iterator it = dict.begin();
		       			     it != dict.end(); 
					     it++) {
		std::size_t found = s.find(*it);
		if (found == std::string::npos) {
			continue;
		}
		if (found == 0) {
			substr1 = s.substr((*it).size(), len-(*it).size());
			std::cout << substr1 << std::endl;
			if (wordBreak(substr1, dict))
				return true;
		} else {
			substr1 = s.substr(0, found);
			substr2 = s.substr(found+(*it).size(), len - substr1.size() - (*it).size());
			std::cout << substr1 << std::endl;
			std::cout << substr2 << std::endl;
			std::cout << "substr1 " << substr1 << " substr2 " << substr2 << std::endl;
			if (wordBreak(substr1, dict) && wordBreak(substr2, dict))
				return true;
		}
        }
        return false;
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

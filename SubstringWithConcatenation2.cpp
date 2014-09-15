#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
 	int len1 = S.size();
	int len2 = L.size();
	vector<int> result;

	if (len2 == 0 || len1 == 0)
		return result; 	// return empty result;
	int wordLen = L[0].size();
	int i, j, k, beg;
	unordered_multiset<string> wordSet;
	for (i = 0; i < len2; i++)  {
		wordSet.insert(L[i]);
	}
	unordered_multiset<string>::iterator it;
	i = 0;
	while (i <= len1 - len2*wordLen) {
		unordered_multiset<string> container (wordSet);
		beg = i;
		while ((it = container.find(S.substr(i, wordLen))) != container.end()) {
			container.erase(it);
			if (container.empty()) {
				result.push_back(beg);
			} else {
				i+= wordLen;
			}
		}
		i = beg+1;
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

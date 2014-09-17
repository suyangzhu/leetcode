#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> stringTokenizer(string &s) {
        int len = s.size();
        vector<string> result;
        if (len == 0) 
            return result;
        int i = 0;
        while (i < len) {
            if (s[i] == ' ') {	// skip all the spaces.
		    i++;  
		    continue;
	    }
            int start = i;
            while (i < len && s[i] != ' ') {	// locate the start index of a valid word.
                i++;
            }
            string str = s.substr(start, i-start);
            result.push_back(str);
        }
        return result;
    }
    void reverseWords(string &s) {
        vector<string> result = stringTokenizer(s);
	int len = result.size();
	int i;
	s ="";
	if (len == 0) 
		return;
	if (len == 1) {
		s=result[0];
		return;
	}
	for (i = 0; i < len-1; i++) {
		s = s+result[len-i -1]+" ";	
	}
	s+=result[0];
    }
};

int main() {
	Solution sol;
	string s = "  i am a   lawyer ";
	sol.reverseWords(s);
	std::cout <<s <<  std::endl;
	return 0;
}

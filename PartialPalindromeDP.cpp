#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	vector<vector<bool> > partialPalindrome(string &word) {
		int len = word.size();
		int i, j;
		vector<bool> vec(len, false);
		vector<vector<bool> > result(len, vec);
		if (len == 0) return result;
		else 
		if (len == 1) {
			result[0][0] = true;
			return result;
		} else {
			for (i = len-1; i  >= 0; i--) {
				for (j = i; j < len; j++) {
					if (j == i) 
						result[i][j] = true;
					else
					if (j == i+1) {
						result[i][j] = (word[i] == word[j]);
						result[j][i] = result[i][j];
					} else {
						result[i][j] = (word[i]==word[j]) && result[i+1][j-1];
						result[j][i] = result[i][j];
					}
				}
			}
		}
		return result;
	}
	    int minCut(string s) {
        int len = s.size();
        int Cut[len+1];
        bool isPalindrome[len][len];
        int i;
        for (i = 0; i <=len; i++) {
            Cut[i] = len - i;
        }
        for (i = 0; i < len; i++)
            for (j = 0; j < len; j++)
                isPalindrome[i][j] = false;
        for (i = len-1; i >=0; i--) {
            for (j = i; j < len; j++) {
                if (s[i] == s[j] && (j-i<2||isPalindrome[i+1][j-1])) {
                    Cut[i] = min(Cut[i], Cut[j+1]+1);
                    isPalindrome[i][j] = true;
                }
            }
        }
        return Cut[0]-1;
    }
};

int main() {
	int i, j; while(1) {
	string word ;
	cin >> word;
	Solution sol;
	vector<vector<bool> > result = sol.partialPalindrome(word);
	for (i = 0; i < result.size(); i++) {
		for (j = 0; j < result[0].size(); j++) 
			if (result[i][j])
				std::cout << "1" << " ";
			else 
				std::cout << "0" << " ";
		std::cout << std::endl;
	}
	}
	return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
// dual pointers. Shift the second one until contains all 
// chars in T. Then shift the first one. record then first = second.
// Instead of using unordered_map, use an 256 array to be the hashmap.
class Solution {
public:
    bool CoverAllCharacters(vector<int> &count, vector<int> &countT) {
        int i;
        for (i = 0; i < 256; i++) {
            if (countT[i] && count[i] < countT[i]) return false;
        }
        return true;
    }
    string minWindow(string S, string T) {
        int i, j;
        int minSize = INT_MAX;
        vector<int> count(256, 0);
        vector<int> countT(256, 0);
        int sSize = S.size();
        int tSize = T.size();
        int begin = 0;
        int end = 0;
        string result = "";
        if (sSize < tSize)
            return result;
        if (tSize == 0) return result;
        for (i = 0; i < tSize; i++) {
            countT[T[i]]++;
        }
        i = 0; j = 0;
        while (i < sSize) {
		std::cout << i << std::endl;
            count[S[i]]++;
            if (!CoverAllCharacters(count, countT)) {
                i++;
		continue;
            } else {
                while (1) {
                    count[S[j]]--;
                    if (j < sSize && count[S[j]] < countT[S[j]]) break;
                    j++;
                }
                if (i-j+1<minSize) {
                    minSize = i-j+1;
                    begin = j;
                    i++;
                    j++;
                }  else {
                    i++;
                    j++;
                }
            }
        }
        if (minSize != INT_MAX)  return S.substr(begin, minSize);
        else    return "";
    }
};
int main() {
	string S = "ADOBECODEBANC";
	string T = "ABC";
	Solution sol;
	std::cout << sol.minWindow(S, T) << std::endl;
	return 0;
}

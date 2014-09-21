#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
// dual pointers. Shift the second one until contains all 
// chars in T. Then shift the first one. record then first = second.
class Solution { 
	public:
		bool hasAll(vector<int> &cnt, vector<int> &cntT) {
			int i; 
			for (i = 0; i < 256; i++)
				if (cntT[i] && cnt[i] < cntT[i])
					return false;
			return true;
		}	
		string minWindow(string S, string T) {
			int len1 = S.size();
			int len2 = T.size();
			if (len1 < len2) 
				return "";
			vector<int> cnt(256,0);
			vector<int> cntT(256, 0); 
			int i = 0, j=0, k;
			int beg = 0;
			int end = len1-1;
			int internal = INT_MAX;
			for (i = 0; i < len2; i++) 
				cntT[T[i]]++;
			i = 0;
			
			while (i < len1) {
				// pay attention that even if S[i] does not exisit in 
				// map, wordCnt[S[i]] returns 0
				cnt[S[i]]++;
				if (!hasAll(cnt, cntT)) {
					i++;
					continue;
				} else { 
					while(1) {
						cnt[S[j]]--;
						if (j < len1 && cnt[S[j]] < cntT[S[j]])
							break;
						j++;
					}
					if (i-j+1 < internal) {
						internal= i-j+1;
						beg = j;
						end = i;
						i++;
						j++;
					} else {
						i++;
						j++;
					}
				}			
			}
			 
			if (internal != INT_MAX)
				return S.substr(beg, internal);
			else 
				return "";
			
		}
};
int main() {
	string S = "ADOBECODEBANC";
	string T = "ABC";
	Solution sol;
	std::cout << sol.minWindow(S, T) << std::endl;
	return 0;
}

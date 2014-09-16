#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
/** cnt[n] = cnt[n-1] + // if s[n-1] forms a char 
 *           cnt[n-2]   // if s[n-1] && s[n-2] forms a char
 */
    int numDecodings(string s) {
        int len = s.size();
        if (len == 0) 
            return 0;
        if (len == 1) {
            if (s[0] == '0')
                return 0;
            else 
                return 1;
        }
        vector<int> cnt(len, 0);
        int i;
        if (s[0] != '0') cnt[0] = 1;
	if (s[0] != '0' && s[1] != '1') cnt[1]++;	// two seperate one digit. 
	if (s[0] == '1' || s[0]=='2' && s[1] <='6') cnt[1]++;	// one two digits decode.
        for (i = 2; i < len; i++) {
            if (s[i] != '0') cnt[i] += cnt[i-1];
            if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') 
                cnt[i] +=cnt[i-2];
	    if (cnt[i]==0)
		    return 0; 	// ..* dot 1 and do2 cannot form a valid decode. no need to check the rest.
        }
	for (i = 0; i < cnt.size(); i++) 
		std::cout << cnt[i] << " ";
	std::cout << std::endl;
        return cnt[len-1];
    }
};

int main() {
	string s = "301";
	Solution sol;
	std::cout << sol.numDecodings(s) << std::endl;
	return 0;
}


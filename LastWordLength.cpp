#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cnt = 0;
        while (*s != '\0') {
		std::cout << " + " << std::endl;
            if (*s == ' ') {
                s++;
                continue;
            }
            cnt = 0;
            while ( *s &&*s != ' ') {
                cnt++;
                s++;
            }
	    std::cout << " - " << std::endl;
        }
        return cnt;
    }
};
int main() {
	Solution sol;
	char s[50] = "qWnqNICa   ADGZNrBw  DdxMEuhNuvTJaETF   KhKKfVFX";
	std::cout << sol.lengthOfLastWord(s) << std::endl;
	return 0;

}

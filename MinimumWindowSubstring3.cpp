#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
/**
 * Two cursors
 * One hash table(fixed number of characters(256), use an array instead)
 */
    bool HasAll(const vector<int> &expectCnt, const vector<int> &actualCnt) {
        int size = expectCnt.size();
        for (int i = 0; i < 256; i++) {
            if (expectCnt[i] && actualCnt[i] < expectCnt[i]) 
                return false;
        }
        return true;
    }  
    string minWindow(string S, string T) {
        int TSize = T.size();
        int SSize = S.size();
        if (TSize > SSize) return "";
        vector<int> actualCnt(256, 0);
        vector<int> expectCnt(256, 0);
        for (int i = 0; i < TSize; i++)
            expectCnt[T[i]]++;
        int head = 0, tail = 0, begin = 0, end = 0, interval = INT_MAX;
        string result = "";
        
        while (head < SSize) {
            actualCnt[S[head]]++;
            if (!HasAll(expectCnt, actualCnt)) {
                
                head++;
            } else {
		    std::cout << "===" << std::endl;
                while (1) {
                    actualCnt[S[tail]]--;
                    if (tail < SSize && actualCnt[S[tail]] < expectCnt[S[tail]] ) 
                        break;
                    tail++;
                }
                if (head - tail+1 < interval) {
                    interval = head-tail+1;
                    begin = tail;
                    tail++;
                    head++;
                } else {
                    head++;
                    tail++;
                }
            }
        }
        if (interval != INT_MAX)
            result = S.substr(begin, interval);
        return result;
    }
};
int main() {
	Solution sol;
	std::cout << sol.minWindow("a", "b") << std::endl;
}

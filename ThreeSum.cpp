#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
     vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        int len = num.size();
        int i;
        if (len < 3)    // less than triple
            return result;
        sort(num.begin(), num.end());
        for (i = 0; i < len; i++) {
            int target = 0 - num[i];    // The sum of rest two should be target.
            int start = i+1;            // Starting from i;
            int end = len-1;            // right most.
            while (start < end) {       // start should on left side of end.
                if (num[start]+num[end]==target) {  // find one triple
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[start]);
                    tmp.push_back(num[end]);
                    result.push_back(tmp);
                    start++; end--;     // shift by one digit.
                    while (start < end && num[start]==num[start-1]) start++;  // keep shifting left. 
                    while (start < end && num[end+1]==num[end])  end--;       // keep shifting right.
                } else 
                if (num[start]+num[end]<target) 
                    start++;            // sum of tripe < 0. need to increase.
                else
                    end--;              // sum of triple > 0, need to decrease.
            }
            
            while (i < len-1 && num[i] == num[i+1]) i++;   
            
        }
        return result;
    }
};
int main() {
	Solution sol;
	vector<int> num;
	num.push_back(-2);
	num.push_back(0);
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
//	num.push_back(-4);
 	vector<vector<int> > result = sol.threeSum(num);
	int i, j;
	for (i = 0; i < result.size(); i++) {
		for (j = 0; j < result[i].size(); j++)
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}

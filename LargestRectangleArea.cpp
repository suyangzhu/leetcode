#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int i, j, k;
        int min;
        int max = 0;
        
        int size = height.size();
        if (size == 0) {
            return 0;
        }
        for (i = 0; i < size; i++) {
            if (i+1 < size && height[i+1]>=height[i])
                continue;
	    min = height[i];
            for (j = i; j >=0; j--) {
                min = min < height[j] ? min:height[j];
                max = max > (i-j+1)*min? max:(i-j+1)*min;
            }
        }
        return max;
    }
};

int main() {
	vector<int> vec;
	vec.push_back(0);
	Solution sol;
	std::cout << sol.largestRectangleArea(vec) << std::endl;
	return 0;
}

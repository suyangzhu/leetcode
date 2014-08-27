#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

class Solution {
public:
     int largestRectangleArea(vector<int> &height) {
        int i, j, k;
        int topIndex;
        int min;
        int max = 0;
        int tmpArea;
        stack<int> indexStack;
        
        int size = height.size();
        if (size == 0) {
            return 0;
        }
        i = 0;
        // If the next one is smaller than previous one. compute the current max area until 
        // reaching the first smaller descendant.
        while (i < size) {
            if (indexStack.empty() || height[indexStack.top()] <= height[i])    
                indexStack.push(i++);
            else {
                topIndex = indexStack.top();
                indexStack.pop();
                tmpArea = height[topIndex]*(indexStack.empty()?i:i-1-indexStack.top());
                max = max > tmpArea? max:tmpArea;
            }
        }
        // compute the rest
        while (!indexStack.empty()) {
            topIndex = indexStack.top();
            indexStack.pop();
            tmpArea = height[topIndex]*(indexStack.empty()?i:i-1-indexStack.top());
            max=max>tmpArea? max:tmpArea;
        }
        return max;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row, col, i, j,k, cnt, tmpRow, tmpArea, maxAreaRec;
        vector<int> heights;
        
        row = matrix.size();
        if (row == 0)
            return 0;
            
        col = matrix[0].size();
        if (col == 0)
            return 0;
        
        maxAreaRec = 0;
        for (i = 0; i < row; i++) {
            heights.clear();
            for (j = 0; j < col; j++) {
                cnt = 0;
                tmpRow = i;
                while(tmpRow >= 0 && matrix[tmpRow][j] == '1') {
                    cnt++;
                    tmpRow--;
                }
                heights.push_back(cnt);
            }
            tmpArea = largestRectangleArea(heights);
            maxAreaRec = maxAreaRec > tmpArea? maxAreaRec: tmpArea;
        }
        return maxAreaRec;
    }
};

int main() {
	Solution sol;
	vector<char> vec1;
	vector<vector<char> >vec2;
	vec1.push_back('1');
	vec2.push_back(vec1);
	std::cout << sol.maximalRectangle(vec2) << std::endl;
	return 0;
}

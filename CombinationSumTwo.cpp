#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
/**
 * DFS:
 */
    void DFS(int idx, int target, vector<int> &num, vector<int> &item, vector<vector<int> > &result) {
        if (idx >= num.size() || num[idx] > target) return;
        if (num[idx] == target) {
            item.push_back(num[idx]);
            if (find(result.begin(), result.end(), item) == result.end()){ 
            	result.push_back(item);
	    }
            item.pop_back();
            return;
        } 
        for (int i = idx+1; i < num.size(); i++) {
            item.push_back(num[idx]);
            DFS(i, target-num[idx], num, item, result);
            item.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> item;
        vector<vector<int> > result;
        int size = num.size();
        for (int i = 0; i < size; i++) {
            if(num[i] > target) break;
            DFS(i, target, num, item, result);
        }
        return result;
    }
};

int main() {
	Solution sol;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(8);
	num.push_back(9);
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	vector<vector<int> > result;
	result = sol.combinationSum2(num, 10) ;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) std::cout << result[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
		
}

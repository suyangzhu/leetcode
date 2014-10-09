#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void DFS(int idx, vector<int> &S, vector<int> &item, vector<vector<int> > &result) {
  
        for (int i = idx; i < S.size(); i++) {
            item.push_back(S[i]);
            result.push_back(item);
        
            if (i < S.size() -1) DFS(i+1, S, item, result);

            item.pop_back();
            while (i < S.size()-1 && S[i] == S[i+1]) i++; 
        }

       
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> item;
        int SSize = S.size();
        if (!SSize) return result;

        sort(S.begin(), S.end());
        result.push_back(item);
        DFS(0, S,  item, result);
        return result;
    }
};

int main() {
	Solution sol;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	vector<vector<int> > result = sol.subsetsWithDup(num);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

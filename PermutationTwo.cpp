#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void DFS(vector<int> &num, vector<bool> &visited, vector<int> &item, vector<vector<int> > &result) {
        if (item.size() == num.size()) {
            if (find(result.begin(), result.end(), item) == result.end()) result.push_back(item);
            return;
        } else {
            int size = num.size();
            for (int i = 0; i < size; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    item.push_back(num[i]);
                    DFS(num, visited, item, result);
                    visited[i] = false;
                    item.pop_back();
                }
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> item;
        int size = num.size();
        vector<bool> visited(size, false);
        DFS(num, visited, item, result);
        return result;
    }
};

int main() {
	vector<int> num;
	num.push_back(-1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	Solution sol;
	vector<vector<int> > result = sol.permuteUnique(num);
	for (int i = 0; i < result.size() ; i++) {
		for (int j = 0; j < result[0].size(); j++) {
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

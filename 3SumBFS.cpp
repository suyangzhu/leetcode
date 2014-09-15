#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >  result;
	int len = num.size();
	if (len < 3) 
		return result;
	sort(num.begin(), num.end());
	queue<vector<int> > indexQueue;
	int i, j;
	for (i = 0; i < len; i++) {
		vector<int> vec(1, i);
		indexQueue.push(vec);
	}
	while (!indexQueue.empty()) {
		vector<int> current = indexQueue.front();
		indexQueue.pop();
		for (j = current.back()+1; j < len; j++) {
			vector<int> next = current;
			next.push_back(j);
			if (next.size() < 3)
				indexQueue.push(next);
			if (next.size() == 3 && 
			    (num[next[0]]+num[next[1]]+num[next[2]]==0))  {
				vector<int> tmp;
				tmp.push_back(num[next[0]]);
				tmp.push_back(num[next[1]]);
				tmp.push_back(num[next[2]]);
				if (find(result.begin(), result.end(), tmp) == result.end())
					result.push_back(tmp);
			}
		}
	}
	return result;
    }
};

int main() {
	Solution sol;
	vector<int> num;
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
//	num.push_back(2);
//	num.push_back(-1);
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

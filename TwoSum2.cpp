#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int Index(vector<int> &numbers, vector<bool> &visited, int n) {  // return the index of element
        int i = 0;
        int len = numbers.size();
        while (i < len) {
            if (numbers[i] == n && !visited[i]) {
                visited[i] = true;
                return i;
            } 
		i++;
        } 
        return -1;
        
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> inputPair;
        vector<int> result;
        int len = numbers.size();
        if (len < 2) 
            return result;
        vector<int> originNumbers = numbers;
        sort(numbers.begin(), numbers.end());
        int i;
        for (i = 0; i < len-1; i++) {
		std::cout << i << std::endl;
        	vector<bool> isVisited(len, false);
		int idx = Index(originNumbers, isVisited, numbers[i]);
            if (find(numbers.begin()+i+1, numbers.end(), target-numbers[i]) != numbers.end()) {
                result.push_back(idx+1);
                result.push_back(Index(originNumbers, isVisited, target-numbers[i])+1);
                return result;
            } 
        }
        
    }
};

int main() {
	Solution sol;
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(75);
	vec.push_back(25);
	vector<int> result = sol.twoSum(vec, 100);
	int i;
	for (i = 0; i < result.size(); i++) 
		std::cout << result[i] << std::endl;
	return 0;	
} 

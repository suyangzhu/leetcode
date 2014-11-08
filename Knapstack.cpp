#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void DFS(int start, vector<int>& item, int& currentSum, vector<int>& value, vector<int>& weight, int target, vector<int>& result, int& maxValue) {
	if(start == value.size()) {
		if (currentSum > maxValue) {
			result = item;
			maxValue = currentSum;
		} 
		return;
	}
	for (int i = start; i < value.size(); i++) {
		if (target >= weight[i]) {
			item.push_back(value[i]);
			currentSum+=value[i];
			if (currentSum > maxValue) {
				result = item;
				maxValue = currentSum;
			}
			DFS(i+1, item, currentSum, value, weight, target-weight[i], result, maxValue);
			currentSum -= value[i];
			item.pop_back();
		}
	}
}

vector<int> KnapStack(vector<int>& value, vector<int>& weight, int target, int& maxValue) {
	vector<int> item;
	vector<int> result;
	int currentSum = 0;
	DFS(0, item, currentSum, value, weight, target, result, maxValue);
	return result;
}

int MaxKnapStack(int target, vector<int>& value, vector<int>& weight, int n) {
	if (n == 0 || target == 0) return 0;
	if (weight[n-1] > target) {
		return MaxKnapStack(target, value, weight, n-1);
	} else {
		int first = value[n-1] + MaxKnapStack(target - weight[n-1], value, weight, n-1);
		int second = MaxKnapStack(target, value, weight, n-1);
		return first > second? first:second;
	}
}

int DPMaxKnapStack(int target, vector<int>& value, vector<int>& weight, int n) {
	int DP[n+1][target+1];
	for (int i = 0; i <=n; i++) {
		for (int w = 0; w <= target; w++) {
			if (i == 0 || w == 0) {
				DP[i][w] = 0;
			} else 
			if (weight[i-1] > w) {
				DP[i][w] = DP[i-1][w];
			} else {
				DP[i][w] = value[i-1] + DP[i-1][w-weight[i-1]] > DP[i-1][w]?
					   value[i-1] + DP[i-1][w-weight[i-1]] : DP[i-1][w];
			}
		}
	}
	return DP[n][target];
}

int main() {
	vector<int> weight;
	vector<int> value;
	weight.push_back(3);
	weight.push_back(2);
	weight.push_back(1);
	value.push_back(12);
	value.push_back(10);
	value.push_back(6);
	int maxValue = -1;
	vector<int> result = KnapStack(value, weight, 4, maxValue);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	std::cout << maxValue << std::endl;
	std::cout << MaxKnapStack(4, value, weight, 3) << std::endl;
	std::cout << DPMaxKnapStack(4, value, weight, 3) << std::endl;
	return 0;
}

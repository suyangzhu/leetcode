#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int max(int first, int second) {
	return first > second?first:second;
}
vector<int> LongestIncreasingSubsequence(const int* A, int n) {
	vector<int> prev(n, -1);
	vector<int> lis(n, 0);
	lis[0] = 1;
	vector<int> result;
	for (int i = 1; i < n; i++) {
		int maxLen = 1;
		for (int k = 0; k < i; k++) {
			if (A[i] > A[k]) {
				if (maxLen < lis[k]+1) {
					maxLen = lis[k] + 1;
					prev[i] = k;
				}
			}	
		}
		lis[i] = maxLen;
	}

	int largest = -1;
	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (largest < lis[i]) {
			largest = lis[i];
			idx = i;
		}
	}
	while (idx != -1) {
		result.push_back(A[idx]);
		idx = prev[idx];
	}
	for (int i = 0; i< n; i++) {
		std::cout << lis[i] << " ";
	}
	std::cout << std::endl;
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	int A[11] = {66, 92, 123, 31, 83, 53, 48, 17, 9, 57, 75};
	for (int i = 0; i < 11; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	vector<int> result = LongestIncreasingSubsequence(A, 11);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;		
}

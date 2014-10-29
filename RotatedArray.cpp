#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
	public:
	int BinarySearch(int A[], int start, int end, int target) {
		if (!(start < end)) return -1;
		while (start < end) {
			int middle = (start + end) / 2;
			if (A[middle] == target) return middle;
			if (A[middle] > A[start]) {
				if (A[middle] > target && target >= A[start]) {
					end = middle;
				} else {
					start = middle + 1;
				}
			} else {
				if (target > A[middle] && A[end-1] >= target) {
					start = middle + 1;
				} else {
					end = middle;
				}
			}
		}
		return -1;
	}
};

int main() {
	Solution sol;
 	int A[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	std::cout << sol.BinarySearch(A, 0, 12, 5) << std::endl;
	return 0;
}

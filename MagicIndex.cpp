#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
class Solution {
	public:
	int BinarySearch(int A[], int start, int end) {
		if (!(start < end)) return -1;
		int middle = (start + end) / 2;
		if (middle == A[middle]) return middle;
		if (middle < A[middle]) return BinarySearch(A, start, middle);
		else return BinarySearch(A, middle+1, end);
	}

	int BinarySearchIterative(int A[], int start, int end) {
		while (start < end) {
			int middle = (start + end) / 2;
			if (middle == A[middle]) return middle;
			if (middle < A[middle]) end = middle;
			else start = middle + 1;
		}
		return -1;
	}

	int BinarySearchMagic(int A[], int start, int end) {
		if (end < start) return -1;
		int middle = (start + end) / 2;
		if (middle == A[middle]) return middle;

		int leftIndex = min(middle - 1, A[middle]);
		int left = BinarySearchMagic(A, start, leftIndex);
		if (left >= 0) return left;

		int rightIndex = max(middle+1, A[middle]);
		int right = BinarySearchMagic(A, rightIndex, end);
		return right;
	}
};

int main() {
	Solution sol;
	int A[10] = {-10, -5, -1, 2, 3, 9, 9, 9, 9, 9};
	std::cout <<sol.BinarySearchMagic(A, 0, 9) <<std::endl;
	return 0;
}

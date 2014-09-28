#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
/**
 * Binary search within two sorted parts seperately. 
 */
    int BinarySearch(int A[], int start, int end, int target) {
        if (!(start < end)) return -1;
        int middle = (start + end)/2;
        if (target < A[middle]) 
            return BinarySearch(A, start, middle, target);
        else 
        if (target > A[middle]) 
            return BinarySearch(A, middle + 1, end, target);
        else 
            return middle;
    }
    int search(int A[], int n, int target) {
        int i;
        for (i = 1; i < n; i++) {
            if (A[i-1] > A[i]) break;
        }
        int idx = BinarySearch(A, 0, i, target);
        return idx != -1? idx:BinarySearch(A, i, n, target);
    }
};

int main() {
	Solution sol;
	int A[2] = {3, 0};
	std::cout << sol.search(A, 2, 0) << std::endl;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> InterSection(int* A, int* B, int n) {
	sort(A, A+n);
	sort(B, B+n);
	vector<int> result;
	int idxA = 0, idxB = 0;
	while (idxA < n && idxB < n) {
		if (A[idxA] == B[idxB]) {
			idxA++;
			idxB++;
		} else 
		if (A[idxA] > B[idxB]) {
			result.push_back(B[idxB]);
			idxB++;
			while (B[idxB-1] == B[idxB]) idxB++;
		} else {
			result.push_back(A[idxA]);
			idxA++;
			while (A[idxA-1] == A[idxA]) idxA++;
		}
	}
	while (idxA < n) {
		result.push_back(A[idxA]);
		idxA++;
	}
	while (idxB < n) {
		result.push_back(B[idxB]);
		idxB++;
	}
	return result;
}

int main() {
	int A[7] = {1, 2, 3, 5, 5, 7, 8};
	int B[7] = {3, 2, 1, 4, 4, 6, 7};
	vector<int> result = InterSection(A, B, 7);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;
		
}

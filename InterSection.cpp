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
			result.push_back(B[idxB++]);
			while (idxB < n && B[idxB-1] == B[idxB]) idxB++;
		} else {
			idxA++;
		}
	}
	while (idxB < n) {
		result.push_back(B[idxB++]);
		while (idxB < n && B[idxB-1] == B[idxB]) idxB++;
	}
	return result;
}

int main() {
	int A[5] = {1, 2, 3, 3, 3};
	int B[5] = {3, 2, 1, 6, 6};
	vector<int> result = InterSection(A, B, 5);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;
		
}

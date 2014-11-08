#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int Rand(int start, int end) {
	return start + rand() % (end-start+1);
}
void Swap(int* A, int first, int second) {
	int tmp = A[first];
	A[first] = A[second];
	A[second] = tmp;
}
void RandomizeArray(int* A, int n) {
	for (int i = 0; i < n; i++) {
		int rnd = Rand(i, n-1);
		Swap(A, i, rnd);
	}
}

void Switch(int* A, int n) {
	RandomizeArray(A, n);
	for (int i = 0; i < n-1; i ++) {
		if (i % 2 == 0) {
			if (A[i] > A[i+1]) Swap(A, i, i+1);
		} else {
			if (A[i] < A[i+1]) Swap(A, i, i+1);
		}
	}
}

void Print(int* A, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int A[7] = {1, 7, 3, 5, 2, 3, 2};
	Switch(A, 7);
	Print(A, 7);
	return 0;
}

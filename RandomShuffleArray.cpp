#include <iostream>
#include <cstdlib>

class Solution {
public:
	Solution() {}
	~Solution() {}
	/** Generate a randome number between start and end */
	int Random(int start, int end) {
		int rnd = std::rand();
		return start + rand() % (end-start + 1);
	}

	int* Shuffle (int array[], int n, int m) {
		int *subarray = new int[m];
		for (int i = 0; i < m; i++) {
			int idx = Random(i, n-1);
			subarray[i] = array[idx];
			array[idx] = array[i];
			array[i] = subarray[i];	// Now the previous array[idx] will not be selected.
		}
		return subarray;
	}
};

int main() {
	Solution sol;
	int array[10] = {1, 2, 3, 4, 5, 6,7, 8, 9, 10};
	int* shifted = sol.Shuffle(array, 10, 5);
	for (int i = 0; i < 5;i++) {
		std::cout << shifted[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
int BinarySearch(int A[], int start, int end, int target) {
	if (!(start < end)) 
		return -1;
 	int middle = (start+end)/2;
	if (A[middle] == target) 
		return middle;
	else
	if (A[middle] < target) 
		return BinarySearch(A, middle+1, end, target);
	else
		return BinarySearch(A, start, middle, target);
}

int main() {
	
	int A[5] = {1, 2, 3, 4, 5};
	while (1){
		int elem;
		std::cin >> elem;
		std::cout << "index of " << elem << " " << BinarySearch(A, 0, 5, elem) << std::endl;
	}
	return 0;
}

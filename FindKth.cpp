#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

double findKth(int a[], int m, int b[], int n, int k) {
	// always assume m < n;
	if (m > n) 
		return findKth(b, n, a, m, k);
	if (m == 0) 
		return b[k-1];
	if (k == 1) 
		return min(a[0],b[0]);
	int pa = min(k/2, m), pb = k-pa;
	if (a[pa-1] < b[pb-1])
		return findKth(a+pa, m-pa, b, n, k-pa);
	if (a[pa-1] > b[pb-1])
		return findKth(a, m, b+pb, n-pb, k-pb);
	else
		return a[pa-1];
}

int findMedian(int a[], int m, int b[], int n) {
	int total = m+n;
	if (total & 0x1)
		return findKth(a, m, b, n, total/2+1);
	else 
		return (findKth(a, m, b, n, total/2) +
			findKth(a, m, b, n, total/2 +1))/2;	
}

int main() {
	int a[4] = {0, 1, 2, 3};
	int b[3] = {10, 11,12};
	std::cout << findMedian(a, 4, b, 3) << std::endl;
	return 0;
}

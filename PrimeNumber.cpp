#include <iostream>
#include <vector> 
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

vector<int> Prime(int n) {
	vector<int> result;
	if (n < 2) return result;
	if (n == 2) {
		result.push_back(n);
		return result;
	}
	if (n == 3) {
		result.push_back(2);
		result.push_back(3);
		return result;
	} 
	result.push_back(2);
	result.push_back(3);
	for (int i = 4; i <=n; i++) {
		if (i % 6 == 1 || i % 6 == 5) {
			int size = result.size();
			int j;
			bool isPrime = false;
			for (j = 0; j < size; j++) {
				int div = result[j];
				if (div > sqrt(i)) {
					isPrime = true;
					break;
				}
				if (i % div == 0) break;
			}
			if (isPrime || j == size) result.push_back(i);
		}
	}
	return result;
}

void Print(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int num;
	cin >> num;
	vector<int> prime = Prime(num);
	Print(prime);
	return 0;
}

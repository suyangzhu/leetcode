#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

bool IsPrimeNumber (int n) { 
	if (n < 2 ) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0) return false;
	}
	return true;
}

int main() {
	while (1) {
	int n;
	cin >> n;
	if (IsPrimeNumber(n)) {
		std::cout << n << " is prime" << std::endl;
	} else {
		std::cout << n << " is not prime" << std::endl;
	}
	}
	return 0;
}

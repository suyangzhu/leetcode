#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int Negate(int a) {
	int neg = 0;
	int next = (a < 0? 1:-1);
	while (a != 0) {
		a += next;
		neg += next;
	}
	return neg;
}

int Minus(int a, int b) {
	return a + Negate(b);
}

int Multiply(int a, int b) {
	int sum = 0;
	int tmpA = (a < 0? Negate(a):a);
	int tmpB = (b < 0? Negate(b):b);
	if (tmpA < tmpB) {
		return Multiply(b, a);
	}
	int cnt = (b < 0? Negate(b) : b);
	for (int i = 0; i < cnt; i++) {
		sum += a;
	}
	if (b < 0) {
		return Negate(sum);
	} else {
		return sum;
	}
}

int Divide(int a, int b) {
	if (b == 0) return -1;
	if (a == 0) return 0;
	int absA = (a < 0 ? Negate(a):a);
	int absB = (b < 0 ? Negate(b):b); 
	int cnt = 0;
	int sum = 0;
	while (sum + absB <= absA) {
		sum += absB;
		cnt++;
	}
	if (a < 0 && b < 0 || a > 0 && b > 0) {
		return cnt;
	} else {
		return Negate(cnt);
	}
}

int main() {
	while (1) {
		int a, b;
		cin >> a;
		cin >> b;
		std::cout << "a+b = " << a+b << std::endl;
		std::cout << "a-b = " << Minus(a, b) << std::endl;
		std::cout << "a*b = " << Multiply(a, b) << std::endl;
		std::cout << "a/b = " << Divide(a, b) << std::endl;
	}
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstddef>
#include <bitset>

class BitSet {
public:
	BitSet (int size) {
		bitset = new int[size >> 5];
	}

	bool Get(int pos) {
		int wordNumber = pos >> 5;
		int bitNumber = pos & 0x1f;
		return (bitset[wordNumber] & (1 << bitNumber)) != 0;
	}

	bool Set(int pos) {
		int wordNumber = pos >>5;
		int bitNumber = pos & 0x1f;
		bitset[wordNumber] |= 1 << bitNumber;
	}
private:
	int *bitset;
};

int main() {
	std::bitset<1000> foo(std::string("01011"));
	std::cout << sizeof(foo) << std::endl;
	int a;
	std::cout << "a : " << sizeof(a) << std::endl;
	return 0;
}

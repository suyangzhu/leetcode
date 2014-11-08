#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
void Compress(char* str) {
	if (!str) return;
	char* ptr1;
	char* ptr2;
	ptr1 = str;
	ptr2 = str;
	while (*ptr1 != '\0') {
		char tmp = *ptr1;
		int cnt = 0;
		while (ptr1 && *ptr1 == tmp) {
			ptr1++;
			cnt++;
		}
		if (cnt > 1) {
			ptr2++;
			*ptr2 = cnt+'0';
			ptr2++;
		} else {
			ptr2++;
		}
	}
	*ptr2 = '\0';

}

string Compress2(string str) {
	int size = str.size();
	string result = "";
	int idx = 0;
	while (idx < size) {
		char start = str[idx];
		int cnt = 0;
		while (idx < size && str[idx] == start) {
			cnt++;
			idx++;
		}
		if (start >= '\0' && start <='9') {
			result.push_back('\\');
			result.push_back(start);
		} else {
			result.push_back(start);
		}
		result.push_back(cnt+'0');
	}
	return result;
}

string Decompress2(string str) {
	int size = str.size();
	int idx = 0;
	string result = "";
	while (idx < size) {
		if (str[idx] == '\\') idx++;
		char start = str[idx];
		int cnt = str[++idx] - '0';
		for (int j = 0; j < cnt; j++) {
			result.push_back(start);
		}
		idx++;
	}	
	return result;
}


int main() {
	char str[20] = "aabbccdeeffffffg"; 
	printf("%s\n", str);
	Compress(str);
	printf("%s\n", str);
	
	string str1 = "aabbccdda1"; 
	if (str1 != Decompress2(Compress2(str1))) {
		std::cout << "ERROR" << std::endl;
	} else {
		std::cout << "DONE" << std::endl;
	}

	std::cout << str1 << std::endl;
	std::cout << Compress2(str1) << std::endl;
	std::cout << Decompress2(Compress2(str1)) << std::endl;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

bool HasAnagramSubstring(const string& src, const string& target) { 
	int srcLen = src.size();
	int targetLen = target.size();
	if (targetLen > srcLen) {
		return false;
	}
	vector<int> srcCnt(256, 0);
	vector<int> targetCnt(256, 0);
	int i;
	for (i = 0; i < targetLen; i++) {
		srcCnt[src[i]]++;
		targetCnt[target[i]]++;
	}
	i = 0;
	while(true) {
		int j;
		for (j = 0; j < targetLen; j++) {
			if (srcCnt[target[j]] != targetCnt[target[j]]) break;
		}
		if (j == targetLen) {
			std::cout << "Y" << std::endl;
			return true;
		}
		if (i+ targetLen > srcLen) break;
		--srcCnt[src[i]];
		++srcCnt[src[i+targetLen]];
		i++;
	}
	return false;
}

int main() {
	string src = "cyazx";
	string target = "xyz";
	if (HasAnagramSubstring(src, target)) {
		std::cout << "True" << std::endl;
	} else {
		std::cout << "False" << std::endl;
	}
	return 0;
}

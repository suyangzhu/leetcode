#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

string LongestCommonString(const string& first, const string& second) {
	int firstSize = first.size();
	int secondSize = second.size();
	int DP[firstSize+1][secondSize+1];
	string DPStr[firstSize+1][secondSize+1];
	for (int i = 0; i <= firstSize; i++) {
		for (int j = 0; j <= secondSize; j++) {
			DP[i][j] = 0;
			DPStr[i][j] = "";
		}
	}
	for (int i = 1; i <= firstSize; i++) {
		for (int j = 1; j <= secondSize; j++) {
			if (first[i-1] == second[j-1]) {
				DP[i][j] = DP[i-1][j-1] + 1;
				DPStr[i][j] = DPStr[i-1][j-1] + first[i-1];
			} else {
				DP[i][j] = 0;
				DPStr[i][j] = "";
			}
		}
	}
	int maxLen = -1;
	string maxStr = "";
	for (int i = 1; i <= firstSize; i++) {
		for (int j = 1; j <= secondSize; j++) {
			if (maxLen < DP[i][j]) {
				maxLen = DP[i][j];
				maxStr = DPStr[i][j];
			}
		}
	}
	std::cout << maxLen << std::endl;;
	return maxStr;
}

int main() {
	string first = "ABCBDAB";
	string second = "XBCDAX";
	std::cout << LongestCommonString(first, second) << std::endl;;
	return 0;
}

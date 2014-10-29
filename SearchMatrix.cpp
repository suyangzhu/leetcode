#include <iostream>
#include <vector>
using namespace std;

class Solution {

	// For this solution, the complexity is O(m * n)
	vector<int> index (vector<vector<int> > mat, int target) {
		int row = 0;
		int col = mat[row].size() - 1;
		while (row < mat.size() && col >= 0) {
			if (mat[row][col] == target) {
				vector<int> result;
				result.push_back(row);
				result.push_back(col);
			} else
			if (mat[row][col] > target) {
				col--;
			} else {
				row++;
			}
		}
		vector<int> result;
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
};

int main() {
	return 0;
}

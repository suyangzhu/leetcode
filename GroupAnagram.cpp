#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	vector<string> GroupAnagram(vector<string>& input) {
		int size = input.size();
		unordered_map<string, vector<string> > hashT;
		vector<string> result;
		for (int i = 0; i < size; i++) {
			string str = input[i];
			sort(str.begin(), str.end());
			if (hashT.count(str)> 0) {
				vector<string> vec;
				vec.push_back(input[i]);
				hashT[str] = vec;
			} else {
				hashT[str].push_back(input[i]);
			}
		}

		for (unordered_map<string, vector<string> >::iterator it = hashT.begin();
		     it != hashT.end(); 
		     it++) {
			result.insert(result.end(), it->second.begin(), it->second.end());
		}
		return result;
	}	
};

int main() {
	return 0;
}

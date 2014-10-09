#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<int> > cntMap;
        vector<string> result;
        int size = strs.size();
        for (int i = 0; i < size; i++) {
            string sortedStr(strs[i]);
            sort(sortedStr.begin(), sortedStr.end());
            if (cntMap.count(sortedStr) > 0) {
		    std::cout << "==="<<strs[i] << std::endl;
                cntMap[sortedStr].push_back(i);
		std::cout << "repeat " << i << std::endl;
            } else {
		    std::cout << "---" << strs[i] << std::endl;
                vector<int> index;
                index.push_back(i);
                cntMap.insert(make_pair(sortedStr, index));
		std::cout << "single " << i << std::endl;
            }
        }
        for (map<string, vector<int> >::iterator it = cntMap.begin();
             it != cntMap.end();
             it++) {
                 if (it->second.size() > 1) {
                     int idxSize = it->second.size();
                     for (int i = 0; i < idxSize; i++) {
                         result.push_back(strs[it->second[i]]);
                     }
                 }
             }
        return result;
    }
};

int main() {
	Solution sol;
	vector<string> arg;
	arg.push_back("");
	arg.push_back("b");
	arg.push_back("");
	vector<string> result = sol.anagrams(arg) ;
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}
}

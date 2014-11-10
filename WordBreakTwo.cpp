#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    void DFS(int index, vector<vector<int> >& package, string& s, string& item, vector<string>& result) {
        if(index == -1) {
            result.push_back(item);
            return;
        } 
        for (int i = 0; i < package[index].size(); i++) {
            int start = package[index][i];
            string str = s.substr(start, index-start+1);
            string origin = item;
            if (item.size()) item = str + " " + item;
            else item = str;
            DFS(start-1, package, s, item, result);
            item = origin;
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int size = s.size();
        vector<int> vec;
        vector<vector<int> > package(size, vec);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j <= i; j++) {
                string str = s.substr(j, i-j+1);
                if (dict.count(str) > 0) {
                    package[i].push_back(j);
                }
            }
        }
        vector<string> result;
        string item;
        DFS(size-1, package, s, item, result);
        return result;
    }
};
int main() {
	Solution sol;
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	string str = "catsanddog";
	vector<string> result = sol.wordBreak(str, dict);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}

	return 0;	
}

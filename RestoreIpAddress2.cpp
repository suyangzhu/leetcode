#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool IsIpAddr(string &s) {
        int size = s.size();
     
        if (size == 1) {    // One digit;
            return true;
        } else 
        if (size == 2) {    // two digit, the first digit cannot be 0 eg 01;
            return !(s[0] == '0');
        } else 
        if (size == 3) {    // three digit, the first digit cannot be 0, eg 011 and <= 255
            if (s[0] == '0') return false;
            
            return stoi(s) <= 255;
        } else 
            return false;
    }
    void DFS(int start, string &s, vector<string> &item,vector<string> &result) {
        if (start == s.size() && item.size() == 4) {
            string ipAddr = item[0]+"."+item[1]+"."+item[2]+"."+item[3];
            result.push_back(ipAddr);
            return;
        } else 
        if (start >= s.size() || item.size() >= 4) {    
            return;
        } else {
            if (start < s.size()) {
                string str = s.substr(start, 1);
                if (IsIpAddr(str)) {
                    item.push_back(str);
                    DFS(start+1, s, item, result);
                    item.pop_back();
                }
            } 
            if (start < s.size() -1) {
                string str = s.substr(start, 2);
                if (IsIpAddr(str)) {
                    item.push_back(str);
                    DFS(start+2, s, item, result);
                    item.pop_back();
                }
                
            } 
            if (start < s.size() -2) {
                string str = s.substr(start, 3);
                if (IsIpAddr(str)) {
                    item.push_back(str);
                    DFS(start+3, s, item, result);
                    item.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> item;
        vector<string> result;
        DFS(0, s, item, result);
        return result;
    }
};
int main() {
	Solution sol;
	vector<string> result = sol.restoreIpAddresses("010010");
	for (auto i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}
	return 0;
}

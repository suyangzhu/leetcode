#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
/**
 * a stack. parse words using '/'
 * if word == '.' do nothing
 * if word == '..', pop the top 
 */ 
    vector<string> StringTokenizer(string &path) {
        int pathLength = path.size();
        vector<string> result;
        if (pathLength == 0) return result;
        int i = 0;
        while (i < pathLength) {
            if (path[i] == '/') {
                while (i<pathLength && path[i] == '/') i++;  // eliminate duplicate '/'
                int start = i;
                while(i < pathLength && path[i] != '/') {
                    i++;
                }
                if (i>start) {
                    string sub = path.substr(start, i-start);
                    result.push_back(sub);
                }
            }
        }
        return result;
    }
    string simplifyPath(string path) {
        vector<string> directory = StringTokenizer(path);
        int directoryCount = directory.size();
        if (directoryCount == 0 ) return "/";
        stack<string> directoryStack;
        int i;
        for (i = 0; i < directoryCount; i++) {
            if (directory[i] == ".") {
                continue;
            } else 
            if (directory[i] == ".." && directoryStack.empty()) {
                continue;
            } else 
            if (directory[i] == "..") {
                directoryStack.pop();
            } else {
                directoryStack.push(directory[i]);
            }
        }
        directoryCount = directoryStack.size();
        if (directoryCount == 0) return "/";
        else 
        if (directoryCount == 1) return "/"+directoryStack.top();
        else {
            string result = "";
            while (!directoryStack.empty()) {
                result = "/" +directoryStack.top()+result;
                directoryStack.pop();
            }
            return result;
        }
    }
};
int main() {
	Solution sol;
	std::cout << sol.simplifyPath("/../a/b/..//") << std::endl;
	return 0;
}




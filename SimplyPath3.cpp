#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
/**
 * - Parsing the strings
 * - if directory name. push into stack.  
 *   if . discard
 *   if .. - stack empty, discard, not empty, discard the top.
 *   
 * - dump stack into a vector, reverse vector.
 * - if vector size is zero, return '/'
 *   1, return /xxx
 *   >=2, return /a/b/c
 */
    vector<string> StringTokenizer(string &path) {
        int pathSize = path.size();
        vector<string> result;
        if (!pathSize) return result;
        int i = 0;
        while (i < pathSize) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            int begin = i;
            while (i < pathSize && path[i] !='/') {
                i++;
            }
            string word = path.substr(begin, i - begin);
            result.push_back(word);
        }
        return result;
    }
    
    string simplifyPath(string path) {
        vector<string> directories = StringTokenizer(path);
        if (directories.size() == 0) return "";
        stack<string> directoryStack;
	std::cout << "  --- " << std::endl;
        for (int i = 0; i < directories.size(); i++) {
            if (directories[i] == ".") continue;
            else 
            if (directories[i] == "..") {
                if (directoryStack.empty()) continue;
                else directoryStack.pop();
            } else {
                directoryStack.push(directories[i]);
            }
        }
	string result = "";
        directories.clear();
        while (!directoryStack.empty()) {
            directories.push_back(directoryStack.top());
            directoryStack.pop();
        }
	std::cout << "  " << std::endl;
        reverse(directories.begin(), directories.end());
        if (directories.empty()) return "/";
        else 
        if (directories.size() == 1) return "/" + directories[0];
        else {
            for (int i = 0; i < directories.size(); i++) {
                result = result + "/" + directories[i];
            }
        }
        return result;
    }
};
int main() {
	Solution sol;
	std::cout << sol.simplifyPath("/.") << std::endl;
	return 0;
}




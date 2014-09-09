#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        int i;
        string result = "";
        vector<string> vecPath;
        stack<string> stackPath;
	// FSM to parse every seg in directory.
        for (i = 0; i < len; i++) {
            if (path[i] == '/') {
                string seg = "";
		// i must increase by 1;
		i++;
                while (i < len && path[i] != '/') {
                    seg = seg + path[i++];
                }
		// i must deduce by 1;
		if (i < len && path[i] == '/') {
			i--;
		}
		if (seg.size())
                	vecPath.push_back(seg);
            }
        }
	
        int size = vecPath.size();
	for (i = 0; i < size; i++) 
		std::cout << vecPath[i] << std::endl;
        for (i = 0; i < size; i++) {
            if (vecPath[i] == ".") {
                continue;
            } else
            if (vecPath[i] == "..") {
                if (stackPath.empty()) 
                    continue;
                else {
                    stackPath.pop();
                }
            } else {
                stackPath.push(vecPath[i]);
            }
        }
	if (stackPath.empty()) {
		result = "/";
		return result;
	}
        while (!stackPath.empty()) {
            result = "/"+ stackPath.top()+result;
            stackPath.pop();
        }
        return result;
    }
};

int main() {
	Solution sol;
	std::cout << sol.simplifyPath("/.") << std::endl;
	return 0;
}




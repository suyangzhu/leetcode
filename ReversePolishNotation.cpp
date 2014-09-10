#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    int evalRPN(vector<string> &tokens) {
        stack<int> opStack;
        int len = tokens.size();
        int i;
        int first, second;
        for (i = 0; i < len; i++) {
            if (tokens[i] == "+") {
                second = opStack.top();
                opStack.pop();
                if (opStack.empty()) { 
                    opStack.push(second);
                }
                else {
                    first = opStack.top();
                    opStack.pop();
                    opStack.push(first + second);
                }
            } else
            if (tokens[i] == "-") {
                second = opStack.top();
                opStack.pop();
                if (opStack.empty()) { 
                    opStack.push(-second);
                }
                else {
                    first = opStack.top();
                    opStack.pop();
                    opStack.push(first - second);
                }
            } else 
            if (tokens[i] == "*") {
                second = opStack.top();
                opStack.pop();
                first = opStack.top();
                opStack.pop();
                opStack.push(first * second);
            } else 
            if (tokens[i] == "/") {
                second = opStack.top();
                opStack.pop();
                first = opStack.top();
                opStack.pop();
                opStack.push(first / second);
            } else {
                opStack.push(stoi(tokens[i]));
            }
        }
        return opStack.top();
    }
};

int main() {
	vector<string> rpn;
	rpn.push_back("2");
	rpn.push_back("12");
	rpn.push_back("5");
	rpn.push_back("/");
	rpn.push_back("+");
	Solution sol;
	std::cout << sol.evalRPN(rpn) << std::endl;

	return 0;
}

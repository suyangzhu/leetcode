#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if (!size) return true;
        stack<char> pStack;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                pStack.push(s[i]);
            } else 
            if (s[i] == ')') {
                if (!pStack.empty() && pStack.top() == '(') {
                    pStack.pop();
                }
                else {
			std::cout << s[i] <<std::endl;
                    return false;
                }
            }else
            if (s[i] == ']') {
                if (!pStack.empty() && pStack.top() == '[') pStack.pop();
                else {
			std::cout << s[i] << std::endl;
			return false;
		}
            }else
            if (s[i] == '}') {
                if (!pStack.empty() && pStack.top() == '{') pStack.pop();
                else {
			std::cout << s[i] << std::endl;
			return false;
		}
            }
        }
        return pStack.empty();
    }
};

int main(){
	Solution sol;
	string s = "()[]";
	if (sol.isValid(s)) std::cout << "is " <<std::endl;
}

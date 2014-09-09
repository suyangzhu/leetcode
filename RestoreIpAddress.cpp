#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // segments cannot be "001", "01", "00"
    // segments must be valid number
    bool validSegment(string str) {
	    if (str.size() < 2)
		    return true;
	    else 
	    if (str[0]=='0')
		    return false;
	    return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int strSize = s.size();
        int i,j, k;
        vector<string> result;
        if (strSize < 4)
            return result;
        
        stack<vector<string> > ipStack;
        
        for (i = 0; i < 3; i++) {
            if (strSize - (i+1)<3)
                break;
            string sub = s.substr(0, i+1);
	    if(!validSegment(sub)) 
		   break; 
            if (stoi(sub) > 255)
                break;
            vector<string> ip;
            ip.push_back(sub);
            ipStack.push(ip);
        }
        while (!ipStack.empty()) {
            vector<string> prevIp = ipStack.top();
            ipStack.pop();
            int prevSize = 0;
            for (i = 0; i < prevIp.size();i++) {
                prevSize += prevIp[i].size();
            }
            
            string currentStr = s.substr(prevSize, strSize-prevSize);
            for (j = 0; j < 3; j++) {
                vector<string> tmp = prevIp;
		// enough digits for remaining segments.
                if ((currentStr.size() - (j+1) < 4-prevIp.size()-1) || 
		     j+1 > currentStr.size()) // j+1 may be out of boundary for the last one.
                    break;

                string sub = currentStr.substr(0, j+1);
		if (!validSegment(sub))
			break;
                if (stoi(sub) > 255)
                    break;
                tmp.push_back(sub);
		// sub.size() == currentStr.size() guarentees last element in string.
		// tmp.size == 4 means 4 ip address now. 
                if(tmp.size() == 4 && 
	           sub.size() == currentStr.size()) { 
                    string ipAddr = tmp[0]+"." + tmp[1]+"."+tmp[2]+"."+tmp[3];
                    result.push_back(ipAddr);
                } else 
                    ipStack.push(tmp);
            }
        }
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

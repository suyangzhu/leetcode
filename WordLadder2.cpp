#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 2;
        queue<pair<string, int> > pathQueue;    // <word, path length>
        pathQueue.push(make_pair(start, 1));    // start word, path len = 1
        int wordLength = start.size();
        int i;
        char replaceChar;
	dict.erase(start);
	if (dict.empty()) return 0;
        while (!pathQueue.empty()) {
            string current = pathQueue.front().first;
            int len = pathQueue.front().second;
            pathQueue.pop();
            for (i = 0; i < wordLength; i++) {
                char originalChar = current[i];
                for (replaceChar = 'a'; replaceChar <= 'z'; replaceChar++) {
                    if (replaceChar != originalChar) {
                        current[i] = replaceChar;
                        if (current == end) {
                            return len+1;
                        } else
                        if (dict.count(current) >0) {
                            pathQueue.push(make_pair(current, len+1));
			    dict.erase(current);
			    if (dict.empty())	break;
                        } else continue;
                    } else 
                        continue;
                }
                current[i] = originalChar;
            }
        }
	return 0;
    }
};

int main() {
	string start = "hit";
	string end = "cog";
	unordered_set<string> vec; 
	vec.insert("hot");
	vec.insert("dot");
	vec.insert("dog");
	vec.insert("lot");
	vec.insert("log");
	Solution sol;
	std::cout << sol.ladderLength(start, end, vec ) << std::endl;
	return 0;
}

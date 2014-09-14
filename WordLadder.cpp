#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        int len = start.size();
        vector<vector<string> > result;
        if (len == 0) return result;
        int i;
        char ch;
        if (start == end) {
            vector<string> vec;
            vec.push_back(start);
            vec.push_back(end);
            result.push_back(vec);
            return result;
        }
	int minLen = 0;
	// unordered_map O(1) when search it is a hash table.
        unordered_map<string, string> backTrackMap;
	unordered_map<string, bool> visited;
	for (unordered_set<string>::iterator it = dict.begin();
	     it != dict.end();
	     it++) {
		visited[*it] = false;
	}
        queue<pair<string, int> > wordQueue;
        wordQueue.push(make_pair(start, 1));
//        dict.erase(start);
//	visited[start] = true;
        while (!wordQueue.empty()) {
            string current = wordQueue.front().first;
	    int curLen = wordQueue.front().second;
            string originWord = current;
            wordQueue.pop();
            int wordSize = current.size();
	    // For each word which is one char away from previous one.
            for (i = 0; i < wordSize; i++) {
                char origin = current[i];
                for (ch = 'a'; ch <= 'z'; ch++) {
                    current[i] = ch;
                    if (current == end) {
			    // ensure that only record the shortest path
			if ( minLen == 0 || 
			   (minLen > 0 &&curLen == minLen)) { 
//				) {
                        vector<string> vec;
                        vec.push_back(current);
			visited[current] = false;
//			dict.erase(current);
//			dict.erase(originWord);
                        while (originWord != start) {
			    vec.push_back(originWord);
			    visited[originWord] = false;
                            originWord = backTrackMap[originWord];
                        }
			
                        vec.push_back(originWord);
			visited[originWord] = false;
			//  end... start to start ... end
			reverse(vec.begin(), vec.end());
                        result.push_back(vec);
			} 
			if (minLen == 0) {
				minLen = curLen;
			}
                    } else
                    if (dict.count(current) > 0 && !visited[current]) {
                        wordQueue.push(make_pair(current, curLen+1));
                        backTrackMap[current] = originWord; // track the origin word
			// since if the path through current cannot reach end, there
			// is no need to keep current in the dict since it will not 
			// be used again.
    //                    dict.erase(current);
			 visited[current] = true;
                    }
                }
		visited[current] = false;
                current[i] = origin;
//		visited[current] = false;
            }
        }
        return result;
    }
};

int main() {
	unordered_set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");

	string start = "red";
	string end = "tax";
	Solution sol;
	vector<vector<string> > result = sol.findLadders(start,end, dict);
	int i, j;
	for (i = 0; i < result.size(); i++) {
		for (j = 0; j < result[i].size(); j++) 
		       std::cout << result[i][j] << " " ;
		std::cout << std::endl;
	}
	return 0;
}


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool duplicate(int a, int b, int c, int d) {
	    unordered_map<int, int> mymap;
	    mymap[a] = 1;
	    if (mymap.find(b) == mymap.end()) 
		    mymap[b] = 2;
	    else 
		    return true;
	    if (mymap.find(c) == mymap.end()) 
		    mymap[c] = 2;
	    else 
		    return true;
	    if (mymap.find(d) == mymap.end()) 
		    mymap[d] = 2;
	    else 
		    return true;
	    return false;
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int i, j;
        int volume = num.size();
        vector<vector<int> > result;
	multimap<int, pair<int, int> > hashTable;
	sort(num.begin(), num.end());
	if (volume == 0)
		return result;
        for (i = 0; i < volume-1; i++) {
		for (j = i+1; j < volume; j++) {
			hashTable.insert (std::make_pair (num[i]+num[j], std::make_pair(i, j)));	
		}
	}		
        for (multimap<int, pair<int, int> >::iterator it = hashTable.begin();
	     it != hashTable.end();
	     it++) {
		int sub = target - it->first;
		for (multimap<int, pair<int, int> >::iterator 
		     it2 = hashTable.equal_range(sub).first;
		     it2 != hashTable.equal_range(sub).second;
		     it2++) {
			if (duplicate(it->second.first, it->second.second, it2->second.first, it2->second.second))
				continue;
			vector<int> item;
			item.push_back(num[it->second.first]);
			item.push_back(num[it->second.second]);
			item.push_back(num[it2->second.first]);
			item.push_back(num[it2->second.second]);
			sort(item.begin(), item.end());
			if (find(result.begin(), result.end(), item) == result.end())
				result.push_back(item);
		}	
	}
	return result;
    }
};

int main() {
	vector<int> num;
	num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);
	int target = 0;
	int i;
	int j;
	Solution sol;
	vector<vector<int> > result = sol.fourSum(num, target);
        for (i = 0; i < result.size(); i++) {
		for (j = 0; j < result[i].size(); j++) 
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
	}	
	std::cout << std::endl;
	return 0;
}

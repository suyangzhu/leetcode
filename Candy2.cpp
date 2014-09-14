#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
// A very naive solution. TLE
class Solution {
public:
    int location(vector<int>& ratings, vector<int>& candies, int target) {
	    int i;
	    int len = ratings.size();
	    for (i = 0; i < len; i++) {
		    if (ratings[i] == target && (candies[i] == 0))
			    return i;
	    }
	    return -1;
    }
    int candy(vector<int> &ratings) {
    	int len = ratings.size();
	int i, sum;
	sum = 0;
        if (len == 0) 
		return 0;
	if (len == 1) 
		return 1;
   	vector<int> candies(len, 0);
	vector<int> sortedRatings =  ratings;
	sort(sortedRatings.begin(), sortedRatings.end());
	for (i = 0; i < len; i++) {
		int index = location(ratings, candies, sortedRatings[i]);
		if (index == 0) {
			candies[index] = ratings[index] <= ratings[index+1]?1:candies[index+1]+1;
		} else 
		if (index == len-1) {
			candies[index] = ratings[index] <= ratings[index-1]?1:candies[index-1]+1;
		} else {
			if (ratings[index] <= ratings[index+1] && ratings[index] <= ratings[index-1])
				candies[index] = 1;
			else 
			if (ratings[index] <= ratings[index+1]) 
				candies[index] = candies[index-1] +1;
			else
			if (ratings[index] <= ratings[index-1])
				candies[index] = candies[index+1] +1;
			else
				candies[index] = candies[index+1]>candies[index-1]? candies[index+1]+1: candies[index-1]+1;
		}
	}
	for (i = 0; i < len; i++) 
		sum+=candies[i];
	return sum;	
    }
};

int main() {
	Solution sol;
	vector<int> ratings;
	ratings.push_back(3);
	ratings.push_back(6);
	ratings.push_back(5);
	ratings.push_back(1);
	ratings.push_back(1);
	ratings.push_back(7);
	std::cout << sol.candy(ratings) << std::endl;
	return 0;
}

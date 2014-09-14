#include <iostream>
#include <vector>
// For this question we need to keep the gradient of
// each element. If the next is larger than the first,
// the first gets one more candy than the previous.
// If the next is equal to the previous, the next gets 1
// candy. If the next is smaller than previous, the next
// child gets 1 less than the previous to keep the gradient.
// However we need to resize the array each time we reach a 
// bottom.
using namespace std;
class Solution {
public:
	void resetVector(vector<int>& vec, vector<int>& ratings, int index) { 
		int k = index;
		int diff = 1-vec[k];
		while (k > 0 && ratings[k-1] > ratings[k]) {
			vec[k] += diff;
			k--;
		}
		// Increase the top only when increase the top.
		// Because the top is reached from the top's previuos 
		// element, it cannot be decrease.
		if (diff > 0) vec[k] += diff;
	}
    	int candy(vector<int> &ratings) {
		int len = ratings.size();
		int i;
		int result = 0;
		if (len == 0)
			return 0;
		if (len == 1)
			return 1;
		vector<int> vec(len, 0);
		vec[0] = 1;
		for (i = 1; i < len; i++) {
			if (ratings[i-1] == ratings[i])
				vec[i] = 1;
			else 
			if (ratings[i-1] < ratings[i]) 
				vec[i] = vec[i-1] + 1;
			else 
				vec[i] = vec[i-1] - 1;
			// Resize vec each time reach a bottom.
			if (i < len-1 && ratings[i-1] > ratings[i] && ratings[i] <= ratings[i+1])
				resetVector(vec, ratings, i);
		}
		if(ratings[len-1] < ratings[len-2])
			resetVector(vec, ratings, len-1);
		for (i = 0; i < len; i++) 
			result += vec[i];
		return result;
    	}
}
;

int main() {
	Solution sol;
	vector<int> ratings;
	ratings.push_back(58);
	ratings.push_back(21);
	ratings.push_back(72);
	ratings.push_back(77);
	ratings.push_back(48);
	ratings.push_back(9);
	ratings.push_back(38);
	ratings.push_back(71);
	ratings.push_back(68);
	ratings.push_back(77);
	sol.candy(ratings);
}

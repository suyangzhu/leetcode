#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
void resetVector(vector<int>& vec, vector<int>& ratings) {
	int len = vec.size();
	int i;
	if (len < 2) 
		return;
	for (i = 0; i < len; i++) {
		if ( i-1 >= 0 &&	
		     vec[i-1] >= vec[i] 
		     && ((i+1 < len && vec[i+1] > vec[i]) ||
			i+1 == len)) {
			int begin;	// begin index for resize
			int end;	// end index for resize
			int k = i-1;
			while (k>= 0 && vec[k] == vec[k+1]+1) {
				k--;
			}
			begin = k+1;
			k = i +1;
			while (k <len && vec[k] == vec[k-1]+1 && ratings[k] != ratings[k-1]) {
				k++;
			}
			end = k - 1;
		        int origin = vec[i];
			if (origin != 1){	
				for (k = begin; k <= end; k++) {
					vec[k] = vec[k] + (1-origin);
				}
			}
			i = end+1;
		}
		     
	}
}
    int candy(vector<int> &ratings) {
	int len = ratings.size();
	int result = 0;
        if (len == 0) 
		return 0;
	if (len == 1) 
		return 1;
	vector<int> CandyCnt(len, 0);
	CandyCnt[0] = 1;
	int i; 
	for (i = 1; i < len; i++) {
		if (ratings[i] > ratings[i-1])
			CandyCnt[i] = CandyCnt[i-1] + 1;
		else 
		if (ratings[i] < ratings[i-1])
			CandyCnt[i] = CandyCnt[i-1] - 1;
		else 
			CandyCnt[i] = 1; 
	}
	for (i = 0; i < len; i++) 
		std::cout << CandyCnt[i] << " ";
	std::cout << std::endl;	
	resetVector(CandyCnt, ratings);
	for (i = 0; i < len; i++) 
		std::cout << CandyCnt[i] << " ";
	std::cout << std::endl;	
	for (i = 0; i < len; i++) 
		result += CandyCnt[i];
	return result;
    }
};

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

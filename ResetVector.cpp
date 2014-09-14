#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void resetVector(vector<int>& vec) {
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
			while (k>= 0 && vec[k] > vec[k+1]) {
				k--;
			}
			begin = k+1;
			k = i +1;
			while (k <len && vec[k] > vec[k-1]) {
				k++;
			}
			end = k - 1;
		        int origin = vec[i];	
			for (k = begin; k <= end; k++) {
				vec[k] = vec[k] + (1-origin);
			}
			i = end+1;
		}
		     
	}
}

int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(-1);
	vec.push_back(-1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(3);
	int i;
	for (i = 0; i < vec.size(); i++) 
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	resetVector(vec);
	for (i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	return 0;
}

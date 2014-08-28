/**
 * [1 3] [2 6] [8 10]
 * [1 6] [8 10] 
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		vector<Interval> sortIntervals(vector<Interval> &intervals) {
			int i;
			int size = intervals.size();
			vector<Interval> result;
			map<int, Interval> index ;
			if (size == 0)
				return result;
			for (i = 0; i < size; i++) {
				index[intervals[i].start] = intervals[i];
			}
			for (std::map<int, Interval>::iterator it = index.begin(); 
			     it != index.end();
			     it++) {
				result.push_back(it->second);
			}
			return result;
			
		}
		vector<Interval> merge(vector<Interval> &intervals) {
		}
};

int main() {
	Interval i0(1, 4);
	Interval i1(5,6 );
	Interval i2(8, 10);
	vector<Interval> vec;
	vec.push_back(i0);
	vec.push_back(i1);
//	vec.push_back(i2);
	Solution sol;
	vector<Interval> result =  sol.merge(vec);
	int i;
	for (i = 0; i < result.size(); i++) {
		std::cout << result[i].start << "	" << result[i].end << std::endl;
	}
	
	return 0;
}

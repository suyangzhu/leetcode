/**
 * [1 3] [2 6] [8 10]
 * [1 6] [8 10] 
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <stack>
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
		// Sort the intervals first. Sort by the start value;
		// Then merge these intervals.
		vector<Interval> sortIntervals(vector<Interval> &intervals) {
			int i;
			int size = intervals.size();
			vector<Interval> result;
			multimap<int, Interval> index ;
			if (size == 0)
				return result;
			for (i = 0; i < size; i++) {
				index.insert(std::pair<int, Interval> (intervals[i].start, intervals[i]));
			}
			for (std::multimap<int, Interval>::iterator it = index.begin(); 
			     it != index.end();
			     it++) {
				result.push_back(it->second);
			}
			return result;
			
		}
		vector<Interval> merge(vector<Interval> &intervals) {
			int i;
			vector<Interval> SortedIntervals = sortIntervals(intervals);
			int size = SortedIntervals.size();
			vector<Interval> result;
			stack<Interval> resultStack;
			if (size <= 1) 
				return SortedIntervals;
		
			int first = 0;
			int last = 0;
			for (i = 0; i < size; i++) {
				if (resultStack.empty()) {
					resultStack.push(SortedIntervals[i]);
				} else { 
					if (resultStack.top().end < SortedIntervals[i].start) {
						resultStack.push(SortedIntervals[i]);
					} else {
						Interval tmp = resultStack.top();
						resultStack.pop();
						tmp.start = tmp.start<SortedIntervals[i].start? 
							    tmp.start:SortedIntervals[i].start;
						tmp.end = tmp.end > SortedIntervals[i].end?
							  tmp.end:SortedIntervals[i].end;
						resultStack.push(tmp);
					}
				}
			}
			while (!resultStack.empty()) {
				result.push_back(resultStack.top());
				resultStack.pop();
			}
			return result;
		}
};

int main() {
	Interval i0(2, 3);
	Interval i1(5,5 );
	Interval i2(2, 2);
	Interval i3 (3, 4);
	Interval i4(3, 4);
	vector<Interval> vec;
	vec.push_back(i0);
	vec.push_back(i1);
	vec.push_back(i2);
	vec.push_back(i3);
	vec.push_back(i4);
	Solution sol;
	vector<Interval> result =  sol.merge(vec);
	int i;
	for (i = 0; i < result.size(); i++) {
		std::cout << result[i].start << "	" << result[i].end << std::endl;
	}
	
	return 0;
}

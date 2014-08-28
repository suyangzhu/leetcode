/**
 * [1 3] [2 6] [8 10]
 * [1 6] [8 10] 
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		int upperBound(vector<Interval> &intervals) {
			int size = intervals.size();
			if (size == 0)
				return 0;
			int i;
			int upper = intervals[0].end;
			for (i = 0; i < size; i++) {
				if (upper < intervals[i].end)
					upper = intervals[i].end;
			}
			return upper;
		} 
		int lowerBound(vector<Interval> &intervals) {
			int size = intervals.size();
			if (size == 0) 
				return 0;
			int i; 
			int lower = intervals[0].start;
			for (i = 0; i < size; i++) {
				if (lower > intervals[i].start)
					lower = intervals[i].start;
			}
			return lower;
		}
		vector<Interval> merge(vector<Interval> &intervals) {
			int size = intervals.size();
			int i, j;
			int upper, lower, range, shift;
			vector<Interval> result;
			if (size == 0)
				return result;
			upper = upperBound(intervals);
			lower = lowerBound(intervals);
			range = upper - lower + 1;
			shift = -lower;

			vector<bool> isOccupied(range, false);
			for (i = 0; i < size; i++) {
				for (j = intervals[i].start + shift; j <= intervals[i].end + shift; j++) {
					isOccupied[j] = true;
				}
			}
			for (i = 0; i < range; i++) {
				if (!isOccupied[i])
					continue;
				int start = i - shift;
				int end = start;
				if (i == range- 1) {
					Interval tmp(start, end);
					result.push_back(tmp);
					break;
				}
				i++;
				while (i < range && isOccupied[i++]) {
					end++;
					
				}
				Interval tmp(start, end);
				result.push_back(tmp);
			}
			return result;
		}
};

int main() {
	Interval i0(3, 6);
	Interval i1(-2, -2);
	Interval i2(8, 10);
	vector<Interval> vec;
	vec.push_back(i0);
	vec.push_back(i1);
	vec.push_back(i2);
	Solution sol;
	vector<Interval> result =  sol.merge(vec);
	int i;
	for (i = 0; i < result.size(); i++) {
		std::cout << result[i].start << "	" << result[i].end << std::endl;
	}
	
	return 0;
}

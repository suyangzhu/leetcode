#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int index(vector<int>& numbers, vector<bool>& visited, int target) {
        int size = numbers.size();
	int i;
        for (i = 0; i < size; i++) {
            if (!visited[i] && numbers[i] == target) {
                visited[i] = true;
                return i+1;
            }
        }
    }
    
    int binarySearch(vector<int>& list, int start, int end, int target) {
        if (start > end)
            return -1;
        int mid = (start + end)/2;
        if(list[mid] == target) 
            return mid;
        else 
        if (list[mid] < target) 
            return binarySearch(list, mid+1, end, target);
        else 
            return binarySearch(list, start, mid-1, target);
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        int first, second, size, i, j;
        int index1;
        int index2;
        vector<int> result;
        size = numbers.size();
        vector<bool> visited(size, false);
        // Build the sorted array;
        vector<int> sortedVec = numbers;
        sort(sortedVec.begin(), sortedVec.end());
        for (i = 0; i < size-1; i++) {
            int tmpTarget = target - sortedVec[i];
            vector<int> tmpArr = sortedVec;
            tmpArr.erase(tmpArr.begin() + i);
	    std::cout << tmpArr[0] << "	" << tmpArr[1] << std::endl;
            int tmpSize = tmpArr.size();
	    std::cout << "tmp target " << tmpTarget << std::endl; 
            int tmpIndex = binarySearch(tmpArr, 0, tmpSize-1, tmpTarget);
            if (tmpIndex != -1) {
                first = sortedVec[i];
                second = tmpArr[tmpIndex];
                break;
            }
        }
	std::cout << "first: " << first << " second  " << second << std::endl;
        index1 = index(numbers, visited, first);
        index2 = index(numbers, visited, second);
        if (index1 > index2) {
            result.push_back(index2);
            result.push_back(index1);
        } else {
            result.push_back(index1);
            result.push_back(index2);
        }
        return result;
    }
};

int main() {
	vector<int> result;
	vector<int> args;
	args.push_back(3);
	args.push_back(2);
	args.push_back(4);
//	args.push_back(15);
	Solution sol;
	result = sol.twoSum(args, 6);
	std::cout << result[0] << "	" << result[1] << std::endl;
	return 0;
}

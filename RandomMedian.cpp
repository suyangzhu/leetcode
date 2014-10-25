#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
	Solution() {}
	~Solution() {}
	int CurrentMedian(int k) {
		if(leftHeap.empty()) {
			leftHeap.push(k);
		} else 
		if (k <= leftHeap.top()) {
			leftHeap.push(k);
			if (leftHeap.size() > rightHeap.size() + 1) {
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
			}
		} else { 
			rightHeap.push(k);
			if (rightHeap.size() > leftHeap.size()) {
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
			}
		}
		return leftHeap.top();
	}	
private:
	std::priority_queue<int, std::vector<int>, std::greater<int> > rightHeap; // smallest at root.
	std::priority_queue<int> leftHeap;	// larget at root.
	
};

int main() {
	Solution sol;
	while (1) {
		int k;
		cin >> k;
		std::cout << "insert " << k << " median is " << sol.CurrentMedian(k) << std::endl;
	}
	return 0;
}

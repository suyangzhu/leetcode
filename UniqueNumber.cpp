#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	Solution() {}
	~Solution() {}
	int RemoveMin() {
		int result = 0;
		if (!minQueue.empty()) {
			result = minQueue.top();
			minQueue.pop();	
		}
		while (1) {
			if (result != minQueue.top()) break;
			minQueue.pop();
		}
		return result;
	}
	int Insert(int n) {
		minQueue.push(3 * n);
		minQueue.push(5 * n);
		minQueue.push(7 * n);
	}

	int FindKth(int k) {
		Insert(1);
		int val = 1;
		for (int i = 0; i < k; i++) {
			val = RemoveMin();
			Insert(val);
		}
		return val;
	}	
private:
	std::priority_queue<int, std::vector<int>, std::greater<int> > minQueue;

};

int main() {
	
	while (1) {
		int k;
		cin >> k;
		Solution sol;
		std::cout << k <<"th element is " << sol.FindKth(k) << std::endl;
	} 
	return 0;
}

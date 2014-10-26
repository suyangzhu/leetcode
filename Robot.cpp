#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void DFS(int &cnt, int x, int y, int m, int n, vector<vector<bool> > &visited) {
	if (x == m-1 && y == n-1) {
		cnt++;
		std::cout << std::endl;
		return;
	} 
	visited[x][y] = true;
	std::cout << "(" << x << "," << y << ")" << "   ";
	if (x + 1 < m && !visited[x+1][y]) {
		DFS(cnt, x+1, y, m, n, visited);
	}
	if (x - 1 >= 0 && !visited[x-1][y]) {
		DFS(cnt, x-1, y, m, n, visited);
	}
	if (y + 1 < n && !visited[x][y+1]) {
		DFS(cnt, x, y+1, m, n, visited);
	}
	if (y - 1 >= 0 && !visited[x][y-1]) {
		DFS(cnt, x, y-1, m, n, visited);
	}
	visited[x][y] = false;
}

int Step(int m, int n) {
	vector<bool> vec(n, false);
	vector<vector<bool> > visited(m, vec);
	int cnt = 0;
	DFS(cnt, 0, 0, m, n, visited);
	std::cout << "m = " << m << " n = " << n << " cnt =  " << cnt << std::endl;
}

int main() {
	int m, n;
	cin >> m;
	cin >> n;
	Step(m, n);
	return 0;
}

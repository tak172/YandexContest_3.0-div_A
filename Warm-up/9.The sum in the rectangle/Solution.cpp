#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int m, n, k, x1, y1, x2, y2;
	cin >> m >> n >> k;
	vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
			v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
		}
	}
	
	while (k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1] << endl;
	}
	
	return 0;
	
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
	long long n, m; cin >> m >> n;
	vector<vector<long long>> d(m + 1, vector<long long>(n, 0));
	for (long long i = 1; i < m + 1; i++) d[i][0] = 1;
	for (long long i = 1; i < m + 1; i++)
		for (long long j = 1; j < n; j++) d[i][j] = d[i][j - 1] + d[i - 1][j] + d[i - 1][j - 1];

	cout << d[m][n - 1];
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string str1, str2; cin >> str1 >> str2;
	int n = (int)str1.size(), m = (int)str2.size();
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < n + 1; i++)	d[i][0] = i;
	for (int i = 0; i < m + 1; i++)	d[0][i] = i;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			d[i][j] = min(d[i][j - 1], d[i - 1][j]) + 1;
			if (str1[i - 1] == str2[j - 1]) d[i][j] = min(d[i][j], d[i - 1][j - 1]);
			else d[i][j] = min(d[i][j], d[i - 1][j - 1] + 1);
		}
	}
	cout << d[n][m];
	return 0;
}
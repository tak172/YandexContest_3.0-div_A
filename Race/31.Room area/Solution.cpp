#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Count = 0;
void Rec(vector<vector<char>>& r, int i, int j);
int main() {
	int n, coord_i, coord_j; cin >> n;
	vector<vector<char>> r(n, vector<char>(n));
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) r[i][j] = str[j];
	}
	cin >> coord_i >> coord_j;
	Rec(r, coord_i - 1, coord_j - 1);
	cout << Count;
	return 0;
}
void Rec(vector<vector<char>>& r, int i, int j) {
	if (r[i][j] == '.') {
		Count++;
		r[i][j] = '*';
		Rec(r, i - 1, j);
		Rec(r, i, j - 1);
		Rec(r, i + 1, j);
		Rec(r, i, j + 1);
	}
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct tower {
	int x;
	int y;
	int color = 0;
};
bool Check(vector<vector<long long>>& dist, long long mid, vector<tower>& data);
int main() {
	int n; cin >> n;
	vector<tower> data(n);
	for (auto& it : data) cin >> it.x >> it.y;
	vector<vector<long long>> dist(n, vector<long long>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = pow(data[i].x - data[j].x, 2) + pow(data[i].y - data[j].y, 2);
	long long R = 10e8, L = 0, mid;
	double ans;
	vector<int> Col(n);
	while (R - L >= 0) {
		for (auto& it : data) it.color = 0;
		mid = (R + L) / 2;
		if (Check(dist, mid, data)) {
			L = mid + 1;
			ans = sqrt(mid) / 2;
			for (int i = 0; i < n; i++) Col[i] = data[i].color;
		}
		else R = mid - 1;
	}
	cout << fixed;
	cout.precision(12);
	cout << ans << endl;
	for (auto& it : Col) cout << it << " ";
	return 0;
}
bool Check(vector<vector<long long>>& dist, long long mid, vector<tower>& data) {
	queue<int> idx;
	data[0].color = 1;
	int count = 1;
	idx.push(0);
	while (count < (int)data.size()) {
		for (int i = 0; i < data.size(); i++){
			if (idx.front() == i) continue;
			if (data[idx.front()].color == data[i].color && data[i].color != 0) if (dist[idx.front()][i] < mid) return false;
			if (data[i].color == 0 && dist[idx.front()][i] < mid) {
				data[i].color = 3 - data[idx.front()].color;
				idx.push(i);
				count++;
			}
		}
		idx.pop();
		if (idx.size() == 0)
			for (int i = 0; i < (int)data.size(); i++)
				if (data[i].color == 0) {
					data[i].color = 1;
					idx.push(i);
					count++;
					break;
				}
	}
	while (!idx.empty()) {
		for (int i = 0; i < data.size(); i++) {
			if (idx.front() == i) continue;
			if (data[idx.front()].color == data[i].color && data[i].color != 0) if (dist[idx.front()][i] < mid) return false;
		}
		idx.pop();
	}
	return true;
}
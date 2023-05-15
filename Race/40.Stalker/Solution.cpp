#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void bfs(vector<vector<int>>& rast, vector<vector<bool>>& used, vector<vector<vector<pair<int, int>>>> d);
int main() {
	int n, k; cin >> n >> k;
	vector<vector<vector<pair<int, int>>>> d(n + 1, vector<vector<pair<int, int>>>(k + 1));
	int count_map, in, to;
	for (int i = 1; i <= k; i++) {
		cin >> count_map;
		for (int j = 0; j < count_map; j++) {
			cin >> in >> to;
			d[in][0].push_back(pair<int, int>(in, i));
			d[to][0].push_back(pair<int, int>(to, i));
			d[in][i].push_back(pair<int, int>(in, 0));
			d[to][i].push_back(pair<int, int>(to, 0));
			d[in][i].push_back(pair<int, int>(to, i));
			d[to][i].push_back(pair<int, int>(in, i));
		}
	}
	d.shrink_to_fit();
	vector<vector<int>> rast(n + 1, vector<int>(k + 1, (int)10e5));
	rast[1][0] = 0;
	vector<vector<bool>> used(n + 1, vector<bool>(k + 1, false));
	bfs(rast, used, d);
	if (rast[n][0] == (int)10e5) cout << -1;
	else cout << rast[n][0];
	return 0;
}
void bfs(vector<vector<int>>& rast, vector<vector<bool>>& used, vector<vector<vector<pair<int, int>>>> d) {
	deque<pair<int, int>> deq;
	pair<int, int> temp(1, 0);
	deq.push_front(temp);
	while (!deq.empty()) {
		temp = deq.front();
		deq.pop_front();
		if (used[temp.first][temp.second]) continue;
		for (int i = 0; i < (int)d[temp.first][temp.second].size(); i++) {
			if (used[d[temp.first][temp.second][i].first][d[temp.first][temp.second][i].second]) continue;
			if (temp.second == 0) {
				if (1 + rast[temp.first][temp.second] < rast[d[temp.first][temp.second][i].first][d[temp.first][temp.second][i].second]) {
					rast[d[temp.first][temp.second][i].first][d[temp.first][temp.second][i].second] = 1 + rast[temp.first][temp.second];
					deq.push_back(d[temp.first][temp.second][i]);
				}
			}
			else
				if (rast[temp.first][temp.second] < rast[d[temp.first][temp.second][i].first][d[temp.first][temp.second][i].second]) {
					rast[d[temp.first][temp.second][i].first][d[temp.first][temp.second][i].second] = rast[temp.first][temp.second];
					deq.push_front(d[temp.first][temp.second][i]);
				}
		}
		used[temp.first][temp.second] = true;
	}
}
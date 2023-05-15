#include <iostream>
#include <vector>
#include<queue>
using namespace std;
struct Poz{
	int x;
	int y;
};
int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> p(n + 2, vector<int>(m + 2, 1)), len(n + 2, vector<int>(m + 2, -1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> p[i][j];
	queue<Poz> q;
	len[1][1] = 0;
	Poz temp; temp.x = 1; temp.y = 1;
	q.push(temp);
	while (true) {
		temp = q.front();
		q.pop();
		if (p[temp.x][temp.y] == 2) {
			cout << len[temp.x][temp.y];
			return 0;
		}
		Poz t(temp);
		while (p[t.x][t.y] != 2 && p[t.x + 1][t.y] != 1) t.x += 1;
		if (len[t.x][t.y] == -1) {
			len[t.x][t.y] = len[temp.x][temp.y] + 1;
			q.push(t);
		}
		t = temp;
		while (p[t.x][t.y] != 2 && p[t.x - 1][t.y] != 1) t.x -= 1;
		if (len[t.x][t.y] == -1) {
			len[t.x][t.y] = len[temp.x][temp.y] + 1;
			q.push(t);
		}
		t = temp;
		while (p[t.x][t.y] != 2 && p[t.x][t.y + 1] != 1) t.y += 1;
		if (len[t.x][t.y] == -1) {
			len[t.x][t.y] = len[temp.x][temp.y] + 1;
			q.push(t);
		}
		t = temp;
		while (p[t.x][t.y] != 2 && p[t.x][t.y - 1] != 1) t.y -= 1;
		if (len[t.x][t.y] == -1) {
			len[t.x][t.y] = len[temp.x][temp.y] + 1;
			q.push(t);
		}
	}
	return 0;
}
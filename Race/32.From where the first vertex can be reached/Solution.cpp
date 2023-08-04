#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool dfs(vector<vector<int>>& r, vector<bool>& visited, vector<bool>& fl, int now);

int main() {
	
	int n, m, idx, val;
	cin >> n >> m;
	
	vector < vector<int>> r(n + 1);
	vector<bool> visitet(n + 1, false);
	vector<bool> fl(n + 1);
	
	for (int i = 0; i < m; i++) {
		cin >> idx >> val;
		r[idx].push_back(val);
	}
	
	for (int i = 1; i <= n; i++) {
		dfs(r, visitet, fl, i);
		for (int j = 0; j < visitet.size(); j++) visitet[i] = false;
	}
	
	set<int> ans;
	ans.insert(1);
	
	for (int i = 0; i < fl.size(); i++)
		if (fl[i]) 
			ans.insert(i);
	
	for (auto& it : ans) 
		cout << it << " ";
	
	return 0;
	
}

bool dfs(vector<vector<int>>& r, vector<bool>& visited, vector<bool>& fl, int now) {
	
	visited[now] = true;
	
	if (now == 1) 
		return true;
	
	for (auto& it : r[now]) {
		if (fl[it]) {
			fl[now] = true;
			continue;
		}
		if (!visited[it])
			fl[now] = fl[now] || dfs(r, visited, fl, it);
	}
	return fl[now];
	
}

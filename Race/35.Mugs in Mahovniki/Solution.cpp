#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<vector<int>> r(n + 1);
	vector<int> c(n + 1, 0), ans;
	set<int> emp;
	int val, to;
	
	for (int i = 1; i < r.size(); i++) {
		cin >> val;
		
		for (int j = 0; j < val; j++) {
			cin >> to;
			r[i].push_back(to);
			c[to]++;
		}
		
	}
	
	for (int i = 1; i < c.size(); i++)
		if (c[i] == 0) 
			emp.insert(i);
	
	while (!emp.empty()) {
		val = *emp.rbegin();
		emp.erase(*emp.rbegin());
		ans.push_back(val);
		
		for (int i = 0; i < r[val].size(); i++) {
			to = r[val][i];
			c[to]--;
			if (c[to] == 0) emp.insert(to);
		}
		
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
	
	return 0;
	
}

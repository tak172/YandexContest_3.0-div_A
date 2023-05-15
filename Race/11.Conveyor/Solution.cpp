#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;
bool Foo(vector<double>& ans);
int main() {
	int n, k; cin >> n;
	while (n--) {
		cin >> k;
		stack<double> temp;
		vector<double> ans;
		double val;
		for (int i = 0; i < k; i++) {
			cin >> val;
			if (temp.empty() || temp.top() >= val) temp.push(val);
			else {
				while (!temp.empty() && temp.top() < val) {
					ans.push_back(temp.top());
					temp.pop();
				}
				temp.push(val);
			}
		}
		while (!temp.empty()) {
			ans.push_back(temp.top());
			temp.pop();
		}
		if (Foo(ans)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

bool Foo(vector<double>& ans) {
	for (int i = 1; i < ans.size(); i++) if (ans[i - 1] > ans[i]) return 0;
	return 1;
}
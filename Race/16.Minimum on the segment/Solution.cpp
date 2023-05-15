#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> b;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) b[a[i]] = i;
	for (int i = 0;; i++){
		while((!b.empty()) && b.begin()->second < i) b.erase(b.find(b.begin()->first));
		cout << b.begin()->first << endl;
		if (i + k < n) b[a[i + k]] = i + k;
		else return 0;
	}
	return 0;
}
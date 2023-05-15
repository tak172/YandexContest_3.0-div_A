#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main() {
	int n, k, val = 0; cin >> n;
	set<int> Di;
	for (int i = 0; i < n; i++) {
		cin >> k;
		Di.insert(k);
	}
	cin >> k;
	vector<int> Col(k);
	map<int, int> mCol;
	for (int i = 0; i < k; i++){
		cin >> Col[i];
		mCol[Col[i]] = 0;
	}
	auto itm = mCol.begin();
	auto its = Di.begin();
	for (; itm != mCol.end(); itm++){
		while (its != Di.end() && *its < itm->first) {
			itm->second++;
			its++;
		}
		itm->second += val;
		val = itm->second;
	}
	for (auto it : Col) cout << mCol[it] << endl;
	return 0;
}
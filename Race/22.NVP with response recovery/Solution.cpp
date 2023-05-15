#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct s{
	int val;
	int count = 1;
	int used = -1;
};
int main() {
	int n; cin >> n;
	vector<s> d(n);
	vector<int> temp;
	for (int i = 0; i < n; i++) cin >> d[i].val;
	for (int i = 1; i < n; i++)
		for (int j = i - 1; j >= 0; j--)
			if (d[j].val < d[i].val) {
				if (d[j].count + 1 > d[i].count) {
					d[i].count = d[j].count + 1;
					d[i].used = j;
				}
			}
	int idx = 0;
	for (int i = 1; i < d.size(); i++) if (d[i].count > d[idx].count) idx = i;
	while (idx != -1) {
		temp.push_back(d[idx].val);
		idx = d[idx].used;
	}
	for (int i = temp.size() - 1; i >= 0; i--) cout << temp[i] << " ";
	return 0;
}
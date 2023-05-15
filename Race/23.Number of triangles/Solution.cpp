#include <iostream>
#include <vector>
using namespace std;
struct tr {
	long long ch = 0;
	long long nch = 0;
	long long honest = 0;
	long long unhonest;
};
int main() {
	int n; cin >> n;
	long long ans = 0;
	if (n == 0) {
		cout << '0';
		return 0;
	}
	vector <tr> d(n);
	d[0].nch = 1;
	d[0].unhonest = n - 1;
	ans += n - 1 + d[0].nch;
	for (int i = 1; i < d.size(); i++) {
		d[i].ch = d[i - 1].ch + 1;
		d[i].nch = d[i - 1].nch + 1;
		if (i % 2 != 0) d[i].honest = d[i - 1].honest + i / 2;
		else d[i].honest = d[i - 1].honest + (i - 1) / 2;
		d[i].unhonest = (n - 1 - i) * d[i].nch;
		ans += d[i].unhonest + d[i].nch + d[i].ch + d[i].honest;
	}
	cout << ans;
	return 0;
}
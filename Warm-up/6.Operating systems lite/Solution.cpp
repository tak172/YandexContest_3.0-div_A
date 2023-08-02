#include <iostream>
#include <vector>
using namespace std;

struct val {
	int l;
	int r;
	bool fl = true;
};

int main() {
	
	int m, n, ans = 0;
	cin >> m >> n;
	vector<val> x(n);
	
	for (int i = 0; i < n; i++) {
		cin >> x[i].l >> x[i].r;
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j <= i-1; j++) {
			if (!(x[i].l > x[j].r || x[i].r < x[j].l))
				x[j].fl = false;
		}
	}

	for (auto &it : x) {
		if (it.fl) ans++;
	}
	
	cout << ans;
	return 0;
	
}

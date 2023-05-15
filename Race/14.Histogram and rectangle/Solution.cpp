#include <iostream>
#include <stack>
using namespace std;
long long max(long long a, long long b);
struct row {
	long long lenght;
	long long count = 1;
};
int main() {
	long long n, idx = 0; cin >> n;
	stack<row> st;
	row val;
	long long ans = 0;
	cin >> val.lenght;
	st.push(val);
	val.count = 1;
	for (int i = 1; i < n; i++){
		cin >> val.lenght;
		val.count = 1;
		if (val.lenght > st.top().lenght) st.push(val);
		else {
			while (!st.empty() && val.lenght < st.top().lenght) {
				idx += st.top().count;
				ans = max(ans, st.top().lenght * idx);
				st.pop();
			}
			if (!st.empty() && st.top().lenght == val.lenght) {
				val.count += st.top().count + idx;
				st.pop();
			}
			else val.count += idx;
			st.push(val);
			idx = 0;
		}
	}
	if (st.empty()) cout << ans;
	else {
		idx = 0;
		while (!st.empty()) {
			idx+= st.top().count;
			ans = max(ans, st.top().lenght * idx);
			st.pop();
		}
		cout << ans;
	}
	return 0;
}
long long max(long long a, long long b) {
	if (a > b) return a;
	return b;
}
#include <iostream>
#include <vector>
using namespace std;

long long min(long long a, long long b) {
	if (a < b) return a;
	return b;
}

int main() {
	
	long long n, ans = 0; 
	cin >> n;
	vector<long long> val(n);
	
	for (auto &it : val) {
		cin >> it;
	}
	
	for (int i = 0; i < (int)val.size() - 1; i++){
		ans += min(val[i], val[i + 1]);
	}
	
	cout << ans;
	return 0;
	
}

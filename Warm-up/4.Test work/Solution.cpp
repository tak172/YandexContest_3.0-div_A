#include<iostream>
using namespace std;
int main() {
	
	long long n, k, var, row, ans;
	cin >> n >> k >> row >> var;
	long long num = row * 2 - var % 2;
	long long a1 = num - k, a2 = num + k;
	
	if (a1 > 0 && a2 <= n) {
		if (abs(row - (a1 + 1) / 2) >= abs(row - (a2 + 1) / 2)) {
			cout << (a2 + 1) / 2 << " ";
			if (a2 % 2)
				cout << 1;
			else
				cout << 2;
			return 0;
		}
		else {
			cout << (a1 + 1) / 2 << " ";
			if (a1 % 2) 
				cout << 1;
			else
				cout << 2;
			return 0;
		}
	}
	else if (a1 > 0) {
		cout << (a1 + 1) / 2 << " ";
		if (a1 % 2) 
			cout << 1;
		else 
			cout << 2;
		return 0;
	}
	else if (a2 <= n) {
		cout << (a2 + 1) / 2 << " ";
		if (a2 % 2)
			cout << 1;
		else 
			cout << 2;
		return 0;
	}
	else cout << -1;
	
	return 0;
	
}

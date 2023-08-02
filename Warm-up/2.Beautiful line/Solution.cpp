#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	int k, ans = 0;
	cin >> k;
	
	string s; 
	cin >> s;
	
	map<char, int>  dic;
	
	for (char i = 'a'; i <= 'z'; i++) {
		dic[i] = 0;
	}
	
	char rm = 'a';
	
	auto L = s.begin(), R = s.begin();

	while (R != s.end()) {
		for (auto it : dic) {
			if (it.second > dic[rm]) {
				rm = it.first;
			}
		}
		
		while (R != s.end() && R-L - dic[rm] <= k) {
			dic[*R]++;
			
			if (dic[*R] >= dic[rm]) {
				rm = *R;
			}
			
			R++;
		}

		if (R - L - dic[rm] <= k && R - L > ans) {
			ans = R - L;
		}
		else if (R - L - dic[rm] > k && R - L - 1 > ans) {
			ans = R - L - 1;
		}

		while (R - L - dic[rm] != k) {
			dic[*L]--;
			
			for (auto it : dic) {
				if (it.second > dic[rm]) {
					rm = it.first;
				}
			}
			
			L++;
		}
	}
	
	cout << ans;
	return 0;
	
}

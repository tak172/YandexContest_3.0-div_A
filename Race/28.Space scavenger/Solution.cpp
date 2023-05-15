#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long Find(char x, vector<char>& dic);
long long Foo(long long& s, vector<char>& dic, string& l, long long i, vector<vector<long long>>& d);

int main() {
	vector<char> dic{ 'N', 'S', 'W', 'E', 'U', 'D' };
	vector<string> l(6);
	for (auto& it : l) getline(cin, it);
	char sim;
	long long n, s; cin >> sim >> n;
	vector<vector<long long>> d(n + 1, vector<long long>(6, 0));
	for (long long i = 1; i < n + 1; i++) {
		for (long long j = 0; j < 6; j++) {
			s = Foo(s, dic, l[j], i, d);
			d[i][j] = s + 1;
		}
	}
	cout << d[n][Find(sim, dic)];
	return 0;
}
long long Foo(long long& s, vector<char>& dic, string& l, long long i, vector<vector<long long>>& d) {
	s = 0;
	for (long long k = 0; k < l.size(); k++) s += d[i - 1][Find(l[k], dic)];
	return s;
}
long long Find(char x, vector<char>& dic) { for (int i = 0; i < dic.size(); i++) if (x == dic[i]) return i; }
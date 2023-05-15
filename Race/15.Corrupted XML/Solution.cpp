#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isValid(string& s);
int main() {	
	string s; getline(cin, s);
	string chars = "</>";
	for (char i = 'a'; i <= 'z'; i++) chars += i;
	for (auto &it : s) {
		char old = it;
		for (auto newC : chars)
			if (newC != old) {
				it = newC;
				if (isValid(s)) {
					cout << s;
					return 0;
				}
			}
		it = old;
	}
	return 0;
}
bool isValid(string& s) {
	if (s[0] != '<' || s.back() != '>') return false;
	stack<string> open;
	int i = 0;
	while (true){
		if (i == (int)s.size()) break;
		if (s[i] != '<') return false;
		i++;
		bool closing = false;
		if (s[i] == '/') {
			closing = true;
			i++;
		}
		if (!('a' <= s[i] && s[i] <= 'z')) return false;
		string tag(1, s[i]);
		i++;
		while ('a' <= s[i] && s[i] <= 'z') {
			tag += s[i];
			i++;
		}
		if (s[i] != '>') return false;
		i++;
		if (!closing) open.push(tag);
		else {
			if (open.empty()) return false;
			if (open.top() != tag) return false;
			open.pop();
		}
	}
	return open.empty();
}
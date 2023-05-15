#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str; getline(cin, str);
	vector<char> ans(str.size()), ans2;
	for (int i = 0; i < (int)ans.size(); i++) ans[i] = str[i];
	stack<char> temp;
	for (int i = 0; i < (int)ans.size(); i++){
		if (ans[i] == '1' || ans[i] == '0') ans2.push_back(ans[i]);
		else {
			if (ans[i] == '!') {
				while (!temp.empty() && temp.top() == '!') {
					ans2.push_back(temp.top());
					temp.pop();
				}
				temp.push(ans[i]);
			}
			if (ans[i] == '&') {
				while (!temp.empty() && (temp.top() == '!' || temp.top() == '&')) {
					ans2.push_back(temp.top());
					temp.pop();
				}
				temp.push(ans[i]);
			}
			if (ans[i] == '^' || ans[i] == '|') {
				while (!temp.empty() && (temp.top() == '!' || temp.top() == '&' || temp.top() == '^' || temp.top() == '|')) {
					ans2.push_back(temp.top());
					temp.pop();
				}
				temp.push(ans[i]);
			}
			if (ans[i] == '(') temp.push(ans[i]);
			if (ans[i] == ')') {
				while ((!temp.empty()) && temp.top() != '(') {
					ans2.push_back(temp.top());
					temp.pop();
				}
				temp.pop();
			}
		}
	}
	while (!temp.empty()) {
		ans2.push_back(temp.top());
		temp.pop();
	}
	stack<int> steck;
	for (int i = 0; i < (int)ans2.size(); i++) {
		if (ans2[i] == '0' || ans2[i] == '1') steck.push(ans2[i] - 48);
		else {
			if (ans2[i] == '!') {
				bool tmp = steck.top();
				steck.pop();
				steck.push(!tmp);
			}
			if (ans2[i] == '&') {
				bool tmp = steck.top();
				steck.pop();
				bool tmp2 = steck.top();
				steck.pop();
				steck.push(tmp && tmp2);
			}
			if (ans2[i] == '|') {
				bool tmp = steck.top();
				steck.pop();
				bool tmp2 = steck.top();
				steck.pop();
				steck.push(tmp || tmp2);
			}
			if (ans2[i] == '^') {
				bool tmp = steck.top();
				steck.pop();
				bool tmp2 = steck.top();
				steck.pop();
				steck.push(tmp ^ tmp2);
			}
		}
	}
	cout << steck.top();
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct T {
	int val;
	int sale;
};

struct ans {
	int sale;
	int otv = 0;
};

int main() {
	
	int n, idx = 0;
	cin >> n;
	string temp;
	vector<T> t(n);
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		t[i].val = int(temp[0] - '0') * 10 * 60 * 60 + int(temp[1] - '0') * 60 * 60 + int(temp[3] - '0') 
			* 60 * 10 + int(temp[4] - '0') * 60 + int(temp[6] - '0') * 10 + int(temp[7] - '0');
		cin >> t[i].sale;
	}
	
	for (int i = 1; i < n; i++) 
		t[i - 1].val = t[i].val - t[i - 1].val;
	
	t[n - 1].val = 64800 - t[n - 1].val;
	vector<ans> bef(32401);
	
	for (int i = 0; i < n; i++) {
		for (int j = idx; j < bef.size() && j < idx + t[i].val; j++)
			bef[j].sale = t[i].sale;
		
		idx += t[i].val;
	}
	vector<ans> before(14401), after(14401);
	
	for (int i = 0; i < before.size(); i++)
		before[i].sale = bef[i].sale;
	
	for (int i = 0; i < after.size(); i++)
		after[i].sale = bef[i + 18000].sale;

	for (int i = 0; i < before.size() - 1; i++) {
		before[i + 1].otv = max(before[i].otv, before[i + 1].otv);
		
		if (i + before[i].sale < before.size()) 
			before[i + before[i].sale].otv = max(before[i].otv + 1, before[i + before[i].sale].otv);
	}
	
	for (int i = 0; i < after.size() - 1; i++) {
		after[i + 1].otv = max(after[i].otv, after[i + 1].otv);
		
		if (i + after[i].sale < after.size())
			after[i + after[i].sale].otv = max(after[i].otv + 1, after[i + after[i].sale].otv);
	}
	
	int answer = 0, temp1 = 0;
	
	for (auto& it : before)
		if (it.otv > answer)
			answer = it.otv;
	
	for (auto& it : after) 
		if (it.otv > temp1)
			temp1 = it.otv;
	
	cout << answer + temp1;
	
	return 0;
	
}

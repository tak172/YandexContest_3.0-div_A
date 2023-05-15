#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	multiset<double> s;
	int n; cin >> n;
	double val, temp;
	for (int i = 0; i < n; i++) {
		cin >> val;
		s.insert(val);
	}
	val = 0;
	while (s.size() != 1) {
		temp = *s.begin();
		s.erase(s.begin());
		temp += *s.begin();
		s.erase(s.begin());
		val += temp * 0.05;
		s.insert(temp);
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << val;
	return 0;
}
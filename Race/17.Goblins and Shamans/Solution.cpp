#include <iostream>
#include <list>
using namespace std;
int main() {
	int n, num; cin >> n;
	list<int> f, s;
	char act;
	while (n--) {
		cin >> act;
		if (s.size() > f.size()) {
			while (s.size() > f.size()) {
				f.push_back(s.front());
				s.pop_front();
			}
		}
		if (s.size() < f.size()) {
			while (s.size() + 1 < f.size()) {
				s.push_front(f.back());
				f.pop_back();
			}
		}
		if (act == '+') {
			cin >> num;
			s.push_back(num);
			continue;
		}
		if (act == '*') {
			cin >> num;
			s.push_front(num);
			continue;
		}
		if (act == '-') {
			if (f.size() == 0) f.push_front(s.front());
			cout << f.front() << endl;
			f.pop_front();
		}
	}
	return 0;
}
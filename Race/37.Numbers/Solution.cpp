#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int>way;

void bfs(int a, deque<int>& d, int b, vector<int>& used);

void Ans(int b);

int main() {
	
	deque<int> d;
	int a; int b;
	cin >> a >> b;
	
	vector<int> used(10000, 0);
	way = vector<int>(10000, -1);
	
	bfs(a, d, b, used);
	Ans(b);
	
	return 0;
	
}

void Ans(int b) {
	
	if (b == -1)
		return;
	
	Ans(way[b]);
	cout << b << endl;
	
}

void bfs(int a, deque<int>& d, int b, vector<int> & used) {
	
	int temp, foo;
	d.push_front(a);
	used[a] = 1;
	
	while (!d.empty()) {
		temp = d.front();
		foo = temp;
		d.pop_front();
		if (temp == b) 
			return;
		
		if (temp / 1000 != 9) {
			foo = temp + 1000;
			if (!used[foo]) {
				used[foo] = 1;
				way[foo] = temp;
				d.push_back(foo);
			}
		}
		
		foo = temp;
		
		if (temp % 10 != 1) {
			foo = temp - 1;
			if (!used[foo]) {
				used[foo] = 1;
				way[foo] = temp;
				d.push_back(foo);
			}
		}
		
		foo = (temp % 1000) * 10 + temp / 1000;
		
		if (!used[foo]) {
			used[foo] = 1;
			way[foo] = temp;
			d.push_back(foo);
		}
		
		foo = (temp % 10) * 1000 + temp / 10;
		
		if (!used[foo]) {
			used[foo] = 1;
			way[foo] = temp;
			d.push_back(foo);
		}
		
	}
}

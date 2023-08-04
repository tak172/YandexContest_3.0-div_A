#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	
	int n; 
	cin >> n;
	
	vector<int> p(101);
	
	for (int i = 0; i < p.size(); i++)
		p[i] = pow(i, 3);
	
	vector<int> a(n+1, (int)10e6);
	a[0] = 0;
	a[1] = 1;
	
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; p[j] <= i; j++) {
			if (p[j] <= i)
				a[i] = min(1 + a[i - p[j]], a[i]);
			else
				break;
		}
	}
	
	cout << a[n];
	
	return 0;
	
}

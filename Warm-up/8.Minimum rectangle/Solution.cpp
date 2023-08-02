#include <iostream>
#include <vector>
using namespace std;
const int INF = 10e10;
int main() {
	
	struct toch {
		int x;
		int y;
	};
	
	int k; 
	cin >> k;
	vector<toch> val(k);
	toch max, min;
	max.x = 0; max.y = 0; min.x = INF; min.y = INF;
	
	for (auto& it : val) {
		cin >> it.x >> it.y;
		if (max.x < it.x) max.x = it.x;
		if (max.y < it.y) max.y = it.y;
		if (min.x > it.x) min.x = it.x;
		if (min.y > it.y) min.y = it.y;
	}
	
	cout << min.x << " " << min.y << " " << max.x << " " << max.y;
	return 0;
	
}

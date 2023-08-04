#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Poz{
	int x;
	int y;
};

int main() {
	
	string temp;
	cin >> temp;
	vector <vector<Poz>> d1(1);
	vector <vector<Poz>> d2(1);
	
	Poz help; help.x = temp[0] - 'a' + 1; help.y = temp[1] - '0';
	d1[0].push_back(help);
	
	cin >> temp;
	help.x = temp[0] - 'a' + 1; help.y = temp[1] - '0';
	d2[0].push_back(help);
	int idx = 0;
	
	while (idx != d1.size()) {
		if (idx > 5) {
			cout << -1;
			return 0;
		}
		
		for (int i = 0; i < d1[idx].size(); i++) {
			for (int j = 0; j < d2[idx].size(); j++)
				if (d1[idx][i].x == d2[idx][j].x && d1[idx][i].y == d2[idx][j].y) {
					cout << idx;
					return 0;
				}
		}
		
		d1.push_back(vector<Poz>());
		d2.push_back(vector<Poz>());
		
		for (auto& it : d1[idx]) {
			
			if (it.x - 2 > 0 && it.y + 1 <= 8) {
				help.x = it.x - 2; help.y = it.y + 1;
				d1[idx + 1].push_back(help);
			}
			
			if (it.x - 2 > 0 && it.y - 1 > 0) {
				help.x = it.x - 2; help.y = it.y - 1;
				d1[idx + 1].push_back(help);
			}
			
			if (it.x + 1 <= 8 && it.y + 2 <= 8) {
				help.x = it.x + 1; help.y = it.y + 2;
				d1[idx + 1].push_back(help);
			}
			
			if (it.x - 1 > 0 && it.y + 2 <= 8) {
				help.x = it.x - 1; help.y = it.y + 2;
				d1[idx + 1].push_back(help);
			}
			
			if (it.x + 2 <= 8 && it.y + 1 <= 8) {
				help.x = it.x + 2; help.y = it.y + 1;
				d1[idx + 1].push_back(help);
			}
			
			if (it.x + 2 <= 8 && it.y - 1 > 0) {
				help.x = it.x + 2; help.y = it.y - 1;
				d1[idx + 1].push_back(help);
			}
			
			if (it.x + 1 <= 8 && it.y - 2 > 0) {
				help.x = it.x + 1; help.y = it.y - 2;
				d1[idx + 1].push_back(help);
			}
			
			if (it.x - 1 > 0 && it.y - 2 > 0) {
				help.x = it.x - 1; help.y = it.y - 2;
				d1[idx + 1].push_back(help);
			}
			
		}
		
		for (auto& it : d2[idx]) {
			
			if (it.x - 2 > 0 && it.y + 1 <= 8) {
				help.x = it.x - 2; help.y = it.y + 1;
				d2[idx + 1].push_back(help);
			}
			
			if (it.x - 2 > 0 && it.y - 1 > 0) {
				help.x = it.x - 2; help.y = it.y - 1;
				d2[idx + 1].push_back(help);
			}
			
			if (it.x + 1 <= 8 && it.y + 2 <= 8) {
				help.x = it.x + 1; help.y = it.y + 2;
				d2[idx + 1].push_back(help);
			}
			
			if (it.x - 1 > 0 && it.y + 2 <= 8) {
				help.x =it.x - 1; help.y =it.y + 2;
				d2[idx + 1].push_back(help);
			}
			
			if (it.x + 2 <= 8 && it.y + 1 <= 8) {
				help.x =it.x + 2; help.y = it.y + 1;
				d2[idx + 1].push_back(help);
			}
			
			if (it.x + 2 <= 8 && it.y - 1 > 0) {
				help.x = it.x + 2; help.y = it.y - 1;
				d2[idx + 1].push_back(help);
			}
			
			if (it.x + 1 <= 8 && it.y - 2 > 0) {
				help.x = it.x + 1; help.y = it.y - 2;
				d2[idx + 1].push_back(help);
			}
			
			if (it.x - 1 > 0 && it.y - 2 > 0) {
				help.x = it.x - 1; help.y = it.y - 2;
				d2[idx + 1].push_back(help);
			}
			
		}
		
		idx++;
	}
	
	return 0;
	
}

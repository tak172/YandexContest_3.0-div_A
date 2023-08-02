#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
	
	vector<int> sim(94, 0);
	string str, ans, text;
	
	fstream file("input.txt");
	
	while(!file.eof()) { 
		getline(file, text);
		str += text;
	}
	
	int max = 0;
	for (int i = 0; i < str.size(); i++) if ((int)str[i] >= 33 && (int)str[i] <= 126) {
		
		sim[(int)str[i] - 33]++;
		
		if (max < sim[(int)str[i] - 33]) {
			max = sim[(int)str[i] - 33];
		}
		
	}
	for (int i = 0; i < sim.size(); i++) {
		if (sim[i]) {
			ans += char(i + 33);
		}
	}
	
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < sim.size(); j++) {
			if (sim[j]) if (sim[j] == max - i) {
				cout << '#';
				sim[j]--;
			}
			else cout << " ";
		}
		cout << endl;
	}
	
	cout << ans;
	return 0;
	
}

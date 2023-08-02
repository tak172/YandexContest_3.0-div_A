#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	
	vector<long long> sim(26, 0);
	string str;
	
	getline(cin, str);
	
	for (long long i = 0; i < (long long)str.size(); i++) {
		sim[(int)str[i] - 97] += (i + 1) * ((long long)str.size() - i);
	}
	
	for (int i = 0; i < (int)sim.size(); i++) {
		if (sim[i]) {
			cout << char(i + 97) << ": " << sim[i] << endl;
		}
	}
	
	return 0;
	
}

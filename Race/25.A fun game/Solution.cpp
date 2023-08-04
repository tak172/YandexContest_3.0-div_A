#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    
    int n, a, b;
    cin >> n >> a >> b;
    
    int maximum = max(a, b);
    int minimum = min(a, b);
    
    vector<int> d(n + 1);
    d[2] = maximum;
    d[3] = maximum + minimum;
    
    for (int i = 4; i < n + 1; i++) {
        if (i % 2 == 1) {
            
            d[i] = (i - 2) * minimum + maximum;
            int tmp1 = i / 2, tmp2 = i / 2 + 1;
            int temp;
            
            while (tmp1 >= 2) {
                temp = max(maximum + d[tmp1], minimum + d[tmp2]);
                d[i] = min(d[i], temp);
                tmp1--;
                tmp2++;
            }
            
        }
        else {
            
            d[i] = min(maximum + d[i / 2], (i - 2) * minimum + maximum);
            int tmp1 = i / 2 - 1, tmp2 = i / 2 + 1;
            int temp;
            
            while (tmp1 >= 2) {
                temp = max(maximum + d[tmp1], minimum + d[tmp2]);
                d[i] = min(d[i], temp);
                tmp1--;
                tmp2++;
            }
        }
    }
    
    cout << d[n];
    
    return 0;
    
}

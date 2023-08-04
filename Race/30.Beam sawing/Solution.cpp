#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
  
  int l, n;
  cin >> l >> n;
  
  vector<int>a(n + 2);
  vector<vector<long long>> d = vector < vector<long long>>(n+1, vector<long long>(n + 2, 0));
  
  a[0] = 0;
  a[n + 1] = l;
  
  for (int i = 1; i < n + 1; i++)
    cin >> a[i];
  
  for (int i = 2; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1 - i; j++) {
      int k = 1;
      d[j][i] = d[j][k] + d[j + k][i - k] + (a[j + i] - a[j]);
      
      while (k <= i - 1) {
        d[j][i] = min(d[j][i], d[j][k] + d[j + k][i - k] + (a[j + i] - a[j]));
        k++;
      }
      
    }
  }
  
  cout << d[0][n + 1];
  
  return 0;
  
}

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<functional>
using namespace std;
int main(void) {
  int k, n, l, r;
  cin >> k >> n;
  multiset<pair<int, int>> my_set;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    if (my_set.empty()) {
      pair<int, int> t = make_pair(r, 0);
      my_set.insert(t);
      a.push_back(1);
    }
    else {
      if (l <= my_set.begin()->first && my_set.size() == k) {
        cout << 0 << ' ' << i + 1 << endl;
        return 0;
      }
      if (l <= my_set.begin()->first) {
        pair<int, int> t = make_pair(r, my_set.size());
        a.push_back(my_set.size() + 1);
        my_set.emplace(t);
      }
      else {
        set<pair<int, int>>::iterator it = my_set.begin();
        set<pair<int, int>>::iterator now = my_set.begin();
        pair<int, int> t;
        int minimum = it->second;
        while (it != my_set.end()) {
          if (l > it->first) {
            if (it->second < minimum) {
              minimum = it->second;
              now = it;
            }
            it++;
          }
          else break;
        }
        my_set.erase(now);
        t = make_pair(r, minimum);
        my_set.emplace(t);
        a.push_back(minimum + 1);
      }
    }
  }
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }
  return 0;
}
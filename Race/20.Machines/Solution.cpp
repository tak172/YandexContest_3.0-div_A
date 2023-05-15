#include<iostream>
#include <set>
#include <list>
#include<vector>
#include<fstream>
#include<map>
#define INF 500001
using namespace std;
struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }

        return l.first < r.first;
    }
};
int main() {
    int n, k, p, ans = 0;
    cin >> n >> k >> p;
    vector<int> d(p);
    vector<list<int>> x(n + 1);
    for (int i = 0; i < p; i++) {
        cin >> d[i];
        x[d[i]].push_back(i);
    }
    set<int> floor;
    set<pair<int, int>, comp> my_map;
    int i = 0;
    for (; floor.size() != k; i++) {
        x[d[i]].pop_front();
        if (x[d[i]].size() == 0) {
            pair<int, int> t = make_pair(d[i], INF);
            my_map.insert(t);
        }
        else {
            pair<int, int> t = make_pair(d[i], *x[d[i]].begin());
            my_map.insert(t);
        }
        floor.insert(d[i]);
    }
    ans += k;
    for (; i < p; i++) {
        if (floor.find(d[i]) != floor.end()) {
            x[d[i]].pop_front();
            if (x[d[i]].size() == 0) {
                pair<int, int> t = make_pair(d[i], INF);
                my_map.insert(t);
            }
            else {
                pair<int, int> t = make_pair(d[i], *x[d[i]].begin());
                my_map.insert(t);
            }
        }
        else {
            floor.erase(my_map.rbegin()->first);
            my_map.erase(--my_map.end());
            floor.insert(d[i]);
            x[d[i]].pop_front();
            if (x[d[i]].size() == 0) {
                pair<int, int> t = make_pair(d[i], INF);
                my_map.insert(t);
            }
            else {
                pair<int, int> t = make_pair(d[i], *x[d[i]].begin());
                my_map.insert(t);
            }
            ans++;
        }
    }
    cout << ans;
    return 0;
}
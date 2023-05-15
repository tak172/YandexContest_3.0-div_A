#include<iostream>
#include<vector>
#include<map>
#include <fstream>
using namespace std;
void Rec(map<int, int>& my_map, vector<vector<int>>& d, vector<vector<int>>& used, int i, int j);
int main(void) {
    ifstream f("input.txt");
    int n, m, answer = 0; f >> n >> m;
    vector<vector<int>> d = vector<vector<int>>(n, vector<int>(m)), used(n, vector<int>(m, 0));
    map<int, int> my_map;
    for (int i = 0; i < 10001; i++) my_map[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            f >> d[i][j];
            my_map[d[i][j]]++;
        }
    for (int i = 0; i < 10001; i++)
        while (my_map[i] != 0)
            for (int t = 0; t < n; t++)
                for (int j = 0; j < m; j++)
                    if (d[t][j] == i && used[t][j] != 1) {
                        answer++;
                        my_map[i]--;
                        used[t][j] = 1;
                        Rec(my_map, d, used, t, j);
                    }
    cout << answer;
    return 0;
}
void Rec(map<int, int>& my_map, vector<vector<int>>& d, vector<vector<int>>& used, int i, int j) {
    if (i + 1 < d.size() && d[i + 1][j] >= d[i][j] && used[i + 1][j] == 0) {
        used[i + 1][j] = 1;
        my_map[d[i + 1][j]]--;
        Rec(my_map, d, used, i + 1, j);
    }
    if (i - 1 >= 0 && d[i - 1][j] >= d[i][j] && used[i - 1][j] == 0) {
        used[i - 1][j] = 1;
        my_map[d[i - 1][j]]--;
        Rec(my_map, d, used, i - 1, j);
    }
    if (j + 1 < d[0].size() && d[i][j + 1] >= d[i][j] && used[i][j + 1] == 0) {
        used[i][j + 1] = 1;
        my_map[d[i][j + 1]]--;
        Rec(my_map, d, used, i, j + 1);
    }
    if (j - 1 >= 0 && d[i][j - 1] >= d[i][j] && used[i][j - 1] == 0) {
        used[i][j - 1] = 1;
        my_map[d[i][j - 1]]--;
        Rec(my_map, d, used, i, j - 1);
    }
}
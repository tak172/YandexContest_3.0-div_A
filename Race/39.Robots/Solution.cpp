#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
struct hon {
  int honest = -1;
  int unhonest = -1;
};
void dfs(vector<int>& used, vector<vector<int>>& d, int idx);
void bfs(vector<vector<int>>& d, vector<hon>& gr, int idx);
int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> used(n + 1, -1);
  vector<vector<int>>d = vector<vector<int>>(n + 1, vector<int>(0));
  for (int i = 0; i < k; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    d[tmp1].push_back(tmp2);
    d[tmp2].push_back(tmp1);
  }
  int m;
  cin >> m;
  vector<int> N(m);
  for (int i = 0; i < m; i++) {
    cin >> N[i];
  }
  dfs(used, d, N[0]);
  for (int i = 1; i < n + 1; i++) {
    if (used[i] == -1) {
      for (int j = 0; j < m; j++) {
        if (N[j] == i) {
          cout << -1;
          return 0;
        }
      }
    }
  }

  vector<vector<hon>> gr = vector<vector<hon>>(n + 1, vector<hon>(n + 1));
  for (int i = 0; i < m; i++) {
    bfs(d, gr[N[i]], N[i]);
  }
  int unHonanswer = 1000000;
  int Honanswer = 1000000;
  for (int j = 1; j < n + 1; j++) {
    int key = 0;
    int max1 = -1;
    for (int i = 0; i < m; i++) {
      if (gr[N[i]][j].unhonest == -1) {
        key = 1;
        break;
      }
      else {
        max1 = max(max1, gr[N[i]][j].unhonest);
      }  
    }
    if (key == 0) unHonanswer = min(unHonanswer, max1);
  }
  for (int j = 1; j < n + 1; j++) {
    int key = 0;
    int max1 = -1;
    for (int i = 0; i < m; i++) {
      if (gr[N[i]][j].honest == -1) {
        key = 1;
        break;
      }
      else {
        max1 = max(max1, gr[N[i]][j].honest);
      }
    }
    if (key == 0) Honanswer = min(Honanswer, max1);
  }
  vector<int> maxi(0);
  for (int j = 1; j < n + 1; j++) {
    for (int i = 0; i < d[j].size(); i++) {
      int Max = -10000;
      int key = 0;
      for (int f = 0; f < m; f++) {
        int key1 = 0;
        int key2 = 0;
        int Min1 = -1;
        int Min2 = -1;
        int Min = -1;
        if (max(gr[N[f]][j].honest, gr[N[f]][d[j][i]].honest) == -1) key1 = 1;
        else if (gr[N[f]][j].honest == -1) Min1 = gr[N[f]][d[j][i]].honest;
        else if (gr[N[f]][d[j][i]].honest == -1) Min1 = gr[N[f]][j].honest;
        else Min1 = min(gr[N[f]][j].honest, gr[N[f]][d[j][i]].honest);
        if (max(gr[N[f]][j].unhonest, gr[N[f]][d[j][i]].unhonest) == -1) key2 = 1;
        else if (gr[N[f]][j].unhonest == -1) Min2 = gr[N[f]][d[j][i]].unhonest;
        else if (gr[N[f]][d[j][i]].unhonest == -1) Min2 = gr[N[f]][j].unhonest;
        else Min2 = min(gr[N[f]][j].unhonest, gr[N[f]][d[j][i]].unhonest);
        if (key1 == 0 && key2 == 0) Min = min(Min1, Min2);
        if (key1 == 0 && key2 != 0) Min = Min1;
        if (key1 != 0 && key2 == 0) Min = Min2;
        if (Min == -1) {
          key = 1;
          break;
        }
        Max = max(Min, Max);
      }
      if (key == 1) continue;
      maxi.push_back(Max);
    }
  }

  double answer = (double)min(Honanswer, unHonanswer);
  int minii = maxi[0];
  for (int i = 0; i < maxi.size(); i++) {
    minii = min(minii, maxi[i]);
  }
  cout << min(answer, (double)minii + 0.5);
  return 0;
}

void dfs(vector<int>& used, vector<vector<int>>& d, int idx) {
  used[idx] = 1;
  for (int i = 0; i < (int)d[idx].size(); i++) {
    if (used[d[idx][i]] == -1) {
      dfs(used, d, d[idx][i]);
    }
  }
}

void bfs(vector<vector<int>>& d,vector<hon>& gr, int idx) {
  gr[idx].honest = 0;
  vector<queue<int>> q(d.size() + 1);
  int i = 0;
  q[i].push(idx);
  while (!q[i].empty()) {
    while (!q[i].empty()) {
      int t = q[i].front();
      q[i].pop();
      for (int j = 0; j< (int)d[t].size(); j++) {
        if (gr[d[t][j]].honest == -1 && gr[d[t][j]].unhonest == -1) {
          if (i % 2 == 1) {
            gr[d[t][j]].honest = i + 1;
            q[i + 1].push(d[t][j]);
          }
          else {
            gr[d[t][j]].unhonest = i + 1;
            q[i + 1].push(d[t][j]);
          }
          continue;
        }
        if (gr[d[t][j]].honest == -1 && gr[d[t][j]].unhonest != -1) {
          if (i % 2 == 1) {
            gr[d[t][j]].honest = i + 1;
            q[i + 1].push(d[t][j]);
          }
          continue;
        }
        if (gr[d[t][j]].honest != -1 && gr[d[t][j]].unhonest == -1) {
          if (i % 2 == 0) {
            gr[d[t][j]].unhonest = i + 1;
            q[i + 1].push(d[t][j]);
          }
          continue;
        }
      }
    }
    i++;
  }
}
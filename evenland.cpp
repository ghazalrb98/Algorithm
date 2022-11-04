#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int MAXN = 1e5 + 3;
const int mod = 1000000009;

int n, m;
pair<int, int> e[MAXN];
vector<int> adjs[MAXN];
bool vis[MAXN];
num ans = 1, pow_2[MAXN];

num nodes, edges;

void dfs(int u) {
  nodes++, edges += adjs[u].size();
  vis[u] = 1;
  for (int i = 0; i < adjs[u].size(); i++) {
    pair<int, int> p = e[adjs[u][i]];
    int v = p.first;
    if (v == u) {
      v = p.second;
    }
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  cin >> n >> m;

  pow_2[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    pow_2[i] = (2 * pow_2[i - 1]) % mod;
  }

  for (int i = 0; i < m; i++) {
    cin >> e[i].first >> e[i].second;
    e[i].first--, e[i].second--;
  }

  for (int i = 0; i < m; i++) {
    adjs[e[i].first].push_back(i), adjs[e[i].second].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      nodes = edges = 0;
      dfs(i);
      ans = (ans * pow_2[(edges / 2) - nodes + 1]) % mod;
    }
  }

  cout << ans << endl;
}
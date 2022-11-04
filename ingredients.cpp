#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int MAXN = 1e6 + 3, MAXB = 1e4 + 3, MAXP = 1e4 + 3;

num budget, n;
string dish_names[MAXN], dish_base_names[MAXN], ingredient;
num dish_costs[MAXN], dish_prestiges[MAXN];
map<string, int> pizza_ids;
int pizza_cnt = 0;
vector<int> recipes[MAXP];
pair<num, num> cumulative[MAXP];

// Standard Knapsack
num weights[MAXP], profits[MAXP], dp[MAXB];

pair<num, num> cdp(string pizza) {
  if (pizza_ids.find(pizza) == pizza_ids.end()) {
    return make_pair(0LL, 0LL);
  }

  int pizza_id = pizza_ids[pizza];

  if (cumulative[pizza_id] != make_pair(-1LL, -1LL)) {
    return cumulative[pizza_id];
  }

  vector<int>& pizza_recipes = recipes[pizza_id];
  num cost = LLONG_MAX, prestige = LLONG_MIN;
  for (int i = 0; i < pizza_recipes.size(); i++) {
    pair<num, num> p = cdp(dish_base_names[pizza_recipes[i]]);
    p.first += dish_costs[pizza_recipes[i]], p.second += dish_prestiges[pizza_recipes[i]];
    if (cost > p.first) {
      cost = p.first, prestige = p.second;
    } else if (cost == p.first) {
      if (prestige < p.second) {
        prestige = p.second;
      }
    }
  }

  return cumulative[pizza_id] = make_pair(cost, prestige);
} 

int main() {
  cin >> budget >> n;

  for (int i = 0; i < n; i++) {
    cin >> dish_names[i] >> dish_base_names[i] >> ingredient >> dish_costs[i] >> dish_prestiges[i];

    if (pizza_ids.find(dish_names[i]) == pizza_ids.end()) {
      pizza_ids[dish_names[i]] = (pizza_cnt++);
    }

    recipes[pizza_ids[dish_names[i]]].push_back(i);
  }

  for (int i = 0; i < pizza_cnt; i++) {
    cumulative[i] = make_pair(-1LL, -1LL);
  }

  for (map<string, int>::iterator pizza = pizza_ids.begin(); pizza != pizza_ids.end(); pizza++) {
    pair<num, num> p = cdp(pizza->first);
    weights[pizza->second] = p.first, profits[pizza->second] = p.second;
  }

  for (int i = 0; i <= budget; i++) {
    dp[i] = -1;
  }

  dp[0] = 0;
  for (int i = 0; i < pizza_cnt; i++) {
    for (int b = budget; b > 0; b--) {
      if (b - weights[i] >= 0 && dp[b-weights[i]] != -1) {
        dp[b] = max(dp[b], dp[b-weights[i]] + profits[i]);
      }
    }
  }

  num ans_cost = LLONG_MAX, ans_prestige = LLONG_MIN;
  for (int b = 0; b <= budget; b++) {
    if (ans_prestige < dp[b]) {
      ans_cost = b;
      ans_prestige = dp[b];
    }
  }

  cout << ans_prestige << endl;
  cout << ans_cost << endl;
}
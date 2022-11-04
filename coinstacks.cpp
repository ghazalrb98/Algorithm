#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > ans;
priority_queue<pair<int, int> > coins;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    pair<int, int> x;
    cin >> x.first;
    
    if (x.first) {
      coins.push(make_pair(x.first, i + 1));
    }
  }

  while (coins.size() >= 2) {
    pair<int, int> coin1 = coins.top();
    coins.pop();
    pair<int, int> coin2 = coins.top();
    coins.pop();

    ans.push_back(make_pair(coin1.second, coin2.second));
    if (coin1.first > 1) {
      coin1.first--;
      coins.push(make_pair(coin1.first, coin1.second));
    }
    if (coin2.first > 1) {
      coin2.first--;
      coins.push(make_pair(coin2.first, coin2.second));
    }
  }

  if (coins.size() == 0) {
    cout << "yes" << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  } else {
    cout << "no" << endl;
  }
}
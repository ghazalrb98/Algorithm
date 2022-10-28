#include <bits/stdc++.h>
using namespace std;

int main() {
  int g, t, n, sum=0, w[103];
  cin >> g >> t >> n;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    
  }

  for (int i = 0; i < n; i++) {
    if (sum > 0.9 * (g - t)) {
      break;
    }
    sum += w[i];
  }

  cout << 0.9 * (g - t) - sum << endl;
}
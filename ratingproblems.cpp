#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  double sum=0;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  cout << fixed << setprecision(4) << ((n - k) * (-3) + sum) / n << " " << ((n - k) * 3 + sum) / n << endl;
}
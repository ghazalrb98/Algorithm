#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  float sum = 0;
  cin >> n;
  while(n--) {
    float q, y;
    cin >> q >> y;
    sum += q * y;
  }

  cout << fixed << setprecision(3) << sum << endl;
}
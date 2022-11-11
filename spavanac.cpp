#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, m, clk;
  cin >> h >> m;
  if (h == 0) {
    h = 24;
  }
  clk = h * 60 + m - 45;
  cout << clk / 60 << " " << clk % 60 << endl;
}
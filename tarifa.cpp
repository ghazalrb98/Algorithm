#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n, sum=0;
  cin >> x >> n;
  while(n--) {
    int p;
    cin >> p;
    sum += (x - p);
  }

  cout << sum + x << endl;
}
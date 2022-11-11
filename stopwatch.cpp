#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2) {
    while(n--) {
      int x;
      cin >> x;
    }

    cout << "still running" << endl;
  } else {
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
      int startt, stopp;
      cin >> startt >> stopp;
      sum += (stopp - startt);
    }

    cout << sum << endl;
  }
}
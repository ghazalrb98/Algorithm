#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while(n--) {
    int x;
    cin >> x;
    cout << x;
    if (x % 2) {
      cout << " is odd" << endl;
    } else {
      cout << " is even" << endl;
    }
  }
}
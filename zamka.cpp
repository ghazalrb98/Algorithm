#include <bits/stdc++.h>
using namespace std;

int getDigitsSum(int x) {
  int sum = 0;
  while(x) {
    sum += (x % 10);
    x /= 10;
  }

  return sum;
}

int main() {
  int l, d, x, lastNum;
  bool isFirstFound = false;
  cin >> l >> d >> x;

  for (int i = l; i <= d; i++) {
    if (getDigitsSum(i) == x) {
      if (!isFirstFound) {
        isFirstFound = true;
        cout << i << endl;
      }
      lastNum = i;
    }
  }

  cout << lastNum << endl;
}
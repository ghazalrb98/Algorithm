#include <bits/stdc++.h>
using namespace std;

int main() {
  for (int i = 1; i <= 10; i++) {
    cout << i << " ";
    
    if (i % 3 == 0) {
      cout << endl;
      continue;
    }

    cout << " hi" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  float w, h;
  cin >> n >> w >> h;
  float max_length = sqrt(w * w + h * h);
  while(n--) {
    int l;
    cin >> l;
    if (l <= max_length) {
      cout << "DA" << endl;
    } else {
      cout << "NE" << endl;
    }
  }
}
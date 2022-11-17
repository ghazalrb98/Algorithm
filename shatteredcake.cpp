#include <bits/stdc++.h>
using namespace std;

#define num long long int

int W, n, w, l;
num area=0;

int main() {
  cin >> W >> n;
  while(n--) {
    cin >> w >> l;
    area += w * l;
  }

  cout << area / W << endl;
}
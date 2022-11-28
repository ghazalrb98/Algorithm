#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, X=0;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    int p = (s[s.size() - 1]) - '0';
    s.pop_back();
    X += pow(stoi(s), p);
  }

  cout << X << endl;
}
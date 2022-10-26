#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, ids;
  getline(cin, s);
  cin >> ids;
  for (int i = 0; i < ids.size(); i += 3) {
    int indx = stoi(ids.substr(i, 3));
    cout << s[indx-1];
  }
  cout << endl;
}
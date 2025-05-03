#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
  i64 x;
  char ch;
  cin >> x >> ch;
  if(ch == '*') cout << 1 << " " << x;
  else if(ch == '+') cout << 1 << " " << x - 1;
  else if(ch == '-') cout << x + 1 << " " << 1;
}

int main() {
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

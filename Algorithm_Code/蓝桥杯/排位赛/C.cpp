#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> v(4,vector<int>(4,0));
  for(int i = 0; i < n; i++) {
    if(s[i] == 'b') v[0][i % 4]++;
    else if(s[i] == 'l') v[1][i % 4]++;
    else if(s[i] == 'u') v[2][i % 4]++;
    else if(s[i] == 'e') v[3][i % 4]++;
  } 
  int  ans = 0;
  for(int i = 0; i < n - 3; i++) {
    if(v[0][i % 4] > 0 && v[1][(i + 1) % 4] > 0 && v[2][(i + 2) % 4] > 0 && v[3][(i + 3) % 4] > 0) {
      v[0][i % 4]--;
      v[1][(i + 1) % 4]--;
      v[2][(i + 2) % 4]--;
      v[3][(i + 3) % 4]--;
      ans++;
      i += 3;
    }
  }
  cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    //cin >> T;
    while(T--) solve();
    
    return 0;
}
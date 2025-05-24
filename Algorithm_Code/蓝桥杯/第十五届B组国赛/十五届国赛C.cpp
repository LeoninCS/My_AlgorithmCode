#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
  int n, m;
  cin >> n >> m;
  string s,c;
  cin >> s >> c;
  vector<int> cnt(26,0);
  for(int i = 0; i < c.size(); i++) {
    int idx = c[i] - 'a';
    cnt[idx]++;
  }
  //for(int i = 0; i < 26; i++) cout << cnt[i];
  for(int i = 0; i < s.size(); i++) {
    for(int j = 0; j < 26; j++) {
        int idx = s[i] - 'a';
		if(idx > j) {
            for(int k = 0; k < cnt[j]; k++) cout << char(j + 'a');
            cnt[j] = 0;
        }
    }
    cout << s[i];
  }
  for(int j = 0; j < 26; j++) {
        for(int k = 0; k < cnt[j]; k++) cout << char(j + 'a');
        cnt[j] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}

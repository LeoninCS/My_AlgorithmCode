#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
   int n, m; 
   cin >> n >> m;
   vector<vector<i64>> gra(n + 1, vector<i64>(n + 1, INF));
    for(int i = 0; i <= n; i++) {
         gra[i][i] = 0;
    }
   for(int i = 0; i < m; i++) {
    i64 a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    gra[a][b] = min(gra[a][b], c * 2);
    gra[b][a] = min(gra[b][a], c * 2);
  } 
  i64 k, t;
  cin >> k >> t;
  for(int i = 0; i < k; i++) {
    int d;
    cin >> d;
    d--;
    gra[d][n] = gra[n][d] = t;
  }
  //floyd
  for(int k = 0; k <= n; k++) {
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= n; j++) {
        gra[i][j] = min(gra[i][j], gra[i][k] + gra[k][j]);
      }
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int x;
    cin >> x;
    if(x == 1) {
        i64 a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        gra[a][b] = min(gra[a][b], c * 2);
        gra[b][a] = min(gra[b][a], c * 2);
        for(int i = 0; i <= n; i++) {
          for(int j = 0; j <= n; j++) {
            gra[i][j] = min({gra[i][j],gra[i][a] + gra[a][b] + gra[b][j], gra[i][b] + gra[b][a] + gra[a][j]});
          }
        }
    } else if(x == 2) {
        int d;
        cin >> d;
        d--;
        gra[d][n] = gra[n][d] = t;
        for(int i = 0; i <= n; i++) {
          for(int j = 0; j <= n; j++) {
            gra[i][j] = min({gra[i][j], gra[i][d] + gra[d][n] + gra[n][j],gra[j][d] + gra[d][n] + gra[n][i]});
          }
        }
    } else {
      i64 ans = 0;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          if(gra[i][j] < INF) {
            ans += gra[i][j];
          }
        }
      }
      cout << ans / 2 << "\n";
    }
  }
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
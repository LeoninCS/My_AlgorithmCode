#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
   i64 n, k;
   i64 l, r;
   cin >> n >> l >> r >> k;
   if(n % 2 == 1) cout << l << "\n";
   else {
        if(n == 2) {
            cout << -1 << "\n";
            return;
        }
        int cnt1 = log2(l);
        int cnt2 = log2(r);
        if(cnt1 == cnt2) {
            cout << -1 << "\n";
        } else {
            if(k < n - 1) cout << l << "\n";
            else cout << (1LL << (cnt1 + 1)) << "\n";
        }
   }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}
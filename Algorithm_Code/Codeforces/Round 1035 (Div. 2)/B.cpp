#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    i64 n;
    cin >> n;
    i64 px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<i64> a(n);
    i64 sum = 0;
    i64 mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    i64 d = (px - qx) * (px - qx) + (py - qy) * (py - qy);
    i64 mxlen = sum;
    i64 milen = 0;
    if(mx < sum - mx) {
        milen = 0; 
    } else {
        milen = mx - (sum - mx);
    }
    if(d >= milen * milen && d <= mxlen * mxlen) cout << "Yes\n";
    else cout << "No\n";
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
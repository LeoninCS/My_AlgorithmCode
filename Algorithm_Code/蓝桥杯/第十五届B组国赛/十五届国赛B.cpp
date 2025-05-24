#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b;
    b.push_back(a[0]);
    for(int i = 0; i < n - 1; i++) {
        b.push_back(a[i + 1] - a[i]);
    }

    int l = 1, r = a[n - 1];
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int cnt = 0;
        for(int i = 0; i < b.size(); i++) {
            cnt += max(0, b[i] - 1) / mid;
        }

        if(cnt <= m + 1) r = mid - 1;
  		 else l = mid + 1;
    }

    cout << l;
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

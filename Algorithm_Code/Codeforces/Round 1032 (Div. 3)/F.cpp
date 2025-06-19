#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    i64 n, s, x;
    cin >> n >> s >> x;
    vector<i64> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<i64> pre(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    auto get = [&](i64 x) ->i64 {
        map<i64,int> mp;
        mp[0]++;
        i64 res = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > x) {
                mp.clear();
            }
            if(mp.count(pre[i + 1] - s)) {
                res += mp[pre[i + 1] - s];
            }
            mp[pre[i + 1]]++;
        }
        return res;
    };

    i64 ans = get(x) - get(x - 1);
    cout << ans << "\n";
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
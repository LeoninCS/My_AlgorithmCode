#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k;
    cin >> n >> k;
    vector<i64> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    multiset<i64> se;
    int st = n - n / (k + 1) * (k + 1);
    for(int i = 0; i <= st; i++) {
        se.insert(d[i]);
    }
    i64 ans = 0;
    ans += *se.rbegin();
    se.extract(*se.rbegin());
    for(int i = st + 1; i < n - k; i += (k + 1)) {
        for(int j = i; j < i + (k + 1); j++) {
            se.insert(d[j]);
        }
        ans += *se.rbegin();
        se.extract(*se.rbegin());
    }
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
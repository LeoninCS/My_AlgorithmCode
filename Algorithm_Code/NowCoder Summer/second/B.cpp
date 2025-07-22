#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<i64> a(n);
    for(i64 i = 0; i < n; i++) cin >> a[i];
    vector<i64> cnt(64, 0);
    for(i64 i = 0; i < n; i++) {
        for(i64 j = 0; j < 64; j++) {
            if(a[i] & (1LL << j)) cnt[j]++;
        }
    }
    for(i64 i = 0; i < 64; i++) cout << cnt[i] << " ";
    for(i64 i = 0; i < n; i++) {
        for(i64 j = 63; j >= 0; j--) {
            if(a[i] & (1LL << j)) {
                if(cnt[j] != 1) {
                    cout << "NO\n";
                    return;
                }
                break;
            }
        }
    }
    cout << "YES\n";
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
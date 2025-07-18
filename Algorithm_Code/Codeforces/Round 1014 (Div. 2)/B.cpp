#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if(s1[i] == '0') cnt1++;
            if(s2[i] == '0') cnt2++;
        } else {
            if(s1[i] == '0') cnt2++;
            if(s2[i] == '0') cnt1++;
        }
    }
    cnt1 = min(cnt1, (n + 1) / 2);
    cnt2 = min(cnt2, n / 2);
    if(cnt1 + cnt2 >= n) cout << "YES\n";
    else cout << "NO\n";
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
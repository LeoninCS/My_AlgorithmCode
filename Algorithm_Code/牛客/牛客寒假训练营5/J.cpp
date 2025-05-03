#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	i64 ans = 0;
	int v = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			v += 10;
			ans += v;
		} else if(s[i] == '1') {
			v = max(0, v - 5);
			ans += v;
		} else {
			i64 tem = max(0, v - 10);
			ans += tem;
		}
	}	
	cout << ans;
}

int main() {
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

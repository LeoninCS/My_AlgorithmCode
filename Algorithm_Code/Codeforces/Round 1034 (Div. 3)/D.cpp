#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            cnt++;
        }
    }
    if(cnt <= k || n < 2 * k) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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
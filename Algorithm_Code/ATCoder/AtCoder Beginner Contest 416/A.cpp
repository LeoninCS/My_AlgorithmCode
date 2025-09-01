#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    for(int i = l - 1; i < r; i++) {
        if(s[i] != 'o') {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
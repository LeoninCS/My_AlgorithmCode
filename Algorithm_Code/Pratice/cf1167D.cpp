#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            cout << cnt1 % 2;
            cnt1++;
        } else {
            cout << cnt2 % 2;
            cnt2++;
        }
    }
    cout << "\n";
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
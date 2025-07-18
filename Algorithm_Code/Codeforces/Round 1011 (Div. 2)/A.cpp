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
    for(int i = 0; i < k; i++) {
        if(i >= n) break;
        int idx = i, cur = 100;
        for(int j = i; j < n; j++) {
            int asc = s[j] - 'a';
            if(asc <= cur) {
                cur = asc;
                idx = j;
            }
        }
        swap(s[i], s[idx]);
        if(s[i] == s[idx]) k++;
    }
    string t = s;
    reverse(t.begin(), t.end());
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) continue;
        if(s[i] < t[i]) {
            cout << "YES\n";
            return;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "NO\n";
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
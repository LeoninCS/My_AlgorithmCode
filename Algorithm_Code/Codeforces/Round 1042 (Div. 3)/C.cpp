#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int s;
        cin >> s;
        a.push_back(s % k);
        a.push_back(k - s % k);
    }
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b.push_back(t % k);
        b.push_back(k - t % k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            cout << "NO\n";
            return;
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
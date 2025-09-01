#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if(a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }
    for(int i = n - 2; i >= 0; i--) {
        //cout << (a[i] ^ a[i + 1]) << " " << (a[i] ^ b[i + 1]) << " " << b[i] << "\n";
        if((a[i] ^ a[i + 1]) == b[i] || (a[i] ^ b[i + 1]) == b[i] || a[i] == b[i]) continue;
        cout << "NO\n";
        return;
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
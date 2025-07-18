#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) cnt++;
    }
    if(cnt == 0) {
        cout << 1 << "\n";
        cout << 1 << " " << n << "\n";
    } else {
        if(a[0] == 0) {
            if(cnt == 1 || a[1] == 0 && cnt == 2) {
                cout << 2 << "\n";
                cout << 1 << " " << 2 << "\n";
                cout << 1 << " " << n - 1 << "\n";
            } else {
                cout << 3 << "\n";
                cout << 1 << " " << 2 << "\n";
                cout << 2 << " " << n - 1 << "\n";
                cout << 1 << " " << 2 << "\n";
            }
        } else {
            cout << 2 << "\n";
            cout << 2 << " " << n  << "\n";
            cout << 1 << " " << 2 << "\n";
        }
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
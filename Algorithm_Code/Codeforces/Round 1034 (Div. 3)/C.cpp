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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> mi(n);
    mi[0] = a[0];
    for(int i = 1; i < n; i++) {
        mi[i] = min(a[i], mi[i - 1]);
    }
    vector<int> mx(n);
    mx[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        mx[i] = max(a[i], mx[i + 1]);
    }
    cout << "1";
    for(int i = 1; i < n - 1; i++) {
        if(a[i] < mi[i - 1] || a[i] > mx[i + 1]) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << "1\n";
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
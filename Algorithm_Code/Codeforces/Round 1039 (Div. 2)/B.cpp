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
    int l = 0, r = n - 1;
    int x = 0;
    while(l <= r) {
        if(x % 2 == 0) {
            if(a[l] > a[r]) {
                cout << "L";
                l++;
            } else {
                cout << "R";
                r--;
            }
        } else {
            if(a[l] < a[r]) {
                cout << "L";
                l++;
            } else {
                cout << "R";
                r--;
            }
        }
        x++;
    }
    cout << "\n";
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
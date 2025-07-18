#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto check = [&](int m) -> bool {
        int cnt = 0;
        set<int> se;
        for(int i = 0; i < n; i++) {
            if(a[i] < m) se.insert(a[i]);
            if(se.size() == m) {
                cnt++;
                se.clear();
            }
        }
        return cnt < k;
    };
    int l = 0, r = n; 
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r << "\n";
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
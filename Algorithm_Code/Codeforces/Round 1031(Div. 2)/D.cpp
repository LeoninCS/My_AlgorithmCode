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
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int l = 0, r = n;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int mul = n - mid;
        int mi = 1e9;
        for(int i = 0; i <= mul; i++) mi = min(mi,b[i]);
        int cnt = 0;
        for(int i = 0; i < mid; i++) {
            if(a[i] > mi) cnt++;
        }
        int add = 0;
        for(int i = mid; i < n; i++) {
            if(a[i] > mi) {
                add = 1;
                break;
            }
        }
        cnt += add;
        if(cnt >= mid) l = mid + 1;
        else r = mid - 1;
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
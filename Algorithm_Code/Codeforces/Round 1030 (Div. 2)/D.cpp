#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k;
    cin >> n >> k;
    vector<i64> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int q;
    cin >> q;
    vector<i64> a(q);
    for(int i = 0; i < q; i++) {
        cin >> a[i];
    }
    i64 mx = p[n - 1];
    for(int i = 0; i < q; i++) {
        i64 cur = a[i];
        map<i64,int> mp; 
        int idx = lower_bound(p.begin(), p.end(), cur) - p.begin();
        i64 t = 0;
        bool found = true;
        int cnt = 1;
        while(idx >= 0 && idx < n) {
             t += abs(p[idx] - cur);
             //cout << t << "-" << p[idx] << "-" << cur << " ";
             if(mp[p[idx]] > 2) {
                found = false;
                break;
             }
             
            if(t >= d[idx] && (t - d[idx]) % k == 0) {
                mp[p[idx]]++;
                cnt++;
                if(cnt % 2 == 0) {
                    cur = p[idx] - 1;
                    t++;
                    idx--;
                } else {
                    cur = p[idx] + 1;
                    t++;
                    idx++;
                }
            } else {
                if(cnt % 2 == 0) {
                    cur = p[idx] - 1;
                    t++;
                    idx--;
                } else {
                    cur = p[idx] + 1;
                    t++;
                    idx++;
                }
            }
        }
        if(found || idx < 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
const i64 mod = 1e9 + 7;

void solve()
{
    int n, L;
    cin >> n >> L;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    function<bool(double)> check = [&](double mid) -> bool {
        vector<double> pre(n + 1, 0.0);
        for(int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (a[i] - mid);
        }
        
        double mi = pre[0]; 
        int t = 0;  
        
        for(int k = L; k <= n; k++) {
            if(pre[k] >= mi) {
                return true;
            }
            t++;
            mi = min(mi, pre[t]);
        }
        return false;
    };
    
    double l = *min_element(a.begin(), a.end());
    double r = *max_element(a.begin(), a.end());
    
    for(int iter = 0; iter < 100; iter++) {
        double mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;  
        } else {
            r = mid;  
        }
    }
    
    cout << fixed << setprecision(10) << l << "\n";
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

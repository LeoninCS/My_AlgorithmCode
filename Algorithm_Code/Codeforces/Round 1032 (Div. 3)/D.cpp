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
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] <= a[j + 1]) continue;
            swap(a[j],a[j + 1]);
            ans.push_back({1, j + 1});
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(b[j] <= b[j + 1]) continue;
            swap(b[j],b[j + 1]);
            ans.push_back({2, j + 1});
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) ans.push_back({3, i + 1}); 
    }
    int k = ans.size();
    cout << k << "\n";
    for(int i = 0; i < k; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
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
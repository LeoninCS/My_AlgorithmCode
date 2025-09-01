#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    function<bool(int)> check = [&](int mid) ->bool {
        set<int> sel;
        
    };


    int l = 0, r = 200000;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    cout << l << "\n";
    
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
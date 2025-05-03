#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n = 0;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> lb;
    for(int i = 0 ; i <= 31; i++) {
        int add = pow(2, i) - 1;
        lb.push_back(add);
    }
    vector<int> aa(n + 1, 0);
    int idx = upper_bound(lb.begin(), lb.end(), n) - lb.begin();
    idx--;
    //cout << lb[idx];
    for(int i = n; i >= 1; i--) {
    	if(!aa[i]) {
    		aa[i] = 2 * lb[idx] - i + 1;
			aa[2 * lb[idx] - i + 1] = i;	
		}
        if( i == lb[idx]) idx--;
    }
    for(int i = 0 ; i < n; i++) cout << aa[a[i]] << " ";
    
    
    
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}
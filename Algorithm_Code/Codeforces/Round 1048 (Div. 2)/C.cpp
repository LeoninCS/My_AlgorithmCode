#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;

void solve()
{
	i64 k, x;
    cin >> k >> x;
    i64 cur = pow(2, k);
    if(cur == x) {
        cout << 0 << "\n\n";
        return;
    }
    vector<int> v(k + 1, 0);
    for(int i = 0; i < k + 1; i++) {
        if(x & (1LL << i)) v[i] = 1;
    }
    reverse(v.begin(),v.end());
    i64 oo = 0;
    vector<int> ans;
    while(1) {
        //check
        while(v[0] == 0) {
            for(int i = 0; i < k; i++) {
                v[i] = v[i + 1];
            }
            v[k] = 0;
            if(oo % 2 == 0) ans.push_back(1);
            else ans.push_back(2);
        }
        bool ok = true;
        for(int i = 1; i < k + 1; i++) {
            if(v[i] == 1 && v[i - 1] != 1) ok = false;     
        }
        if(ok) break;
        //change
        int idx = 0;
        for(int i = 0; i < k + 1; i++) {
            if(v[i] == 1) idx = i;     
        }
        for(int i = 0; i < k + 1; i++) {
            if(i < idx - 1) v[i] = 1 - v[i + 1];
            else if(i == idx - 1) v[i] = 1;
            else v[i] = 0;
        }
        if(oo % 2 == 0) ans.push_back(2);
        else ans.push_back(1);
        oo++;
    }
    for(int i = 1; i < k + 1; i++) {
        if(v[i] == 1) {
            if(oo % 2 == 0) ans.push_back(2);
            else  ans.push_back(1);
        }
    }
    int n = ans.size();
    cout << n << "\n";
    for(int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
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
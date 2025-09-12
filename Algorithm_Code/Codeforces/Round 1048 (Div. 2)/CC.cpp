#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;

void check(vector<int> ans, i64 k, i64 x) 
{
    reverse(ans.begin(), ans.end());
    i64 a = pow(2, k), b = pow(2, k);
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == 1) {
            if(a & 1) {
                cout << "NO" << " " << k << " " << x << "\n";
                return;
            }
            a /= 2;
            b += a;
        } else {
            if(b & 1) {
                cout << "NO" << " " << k << " " << x << "\n";
                return;
            }
            b /= 2;
            a += b;
        }
    }
    if(a != x) {
        cout << "NO" << " " << k << " " << x << "\n";
        return;
    }
}


void solve(i64 k, i64 x) 
{
        i64 cur = pow(2, k);
    if(cur == x) {
        //cout << 0 << "\n\n";
        return;
    }
    vector<int> v(k + 1, 0);
    for(int i = 0; i < k + 1; i++) {
        if(x & (1 << i)) v[i] = 1;
    }
    reverse(v.begin(),v.end());
    int oo = 0;
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
    //cout << n << "\n";
    for(int i = n - 1; i >= 0; i--) {
        //cout << ans[i] << " ";
    }
    //cout << "\n"; 
    check(ans, k, x);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	for(int i = 1; i < 10; i++) {
        for(int j = 1; j < pow(2, i + 1); j += 1) {
            solve(i, j);
        }
    }
	
	return 0;
}
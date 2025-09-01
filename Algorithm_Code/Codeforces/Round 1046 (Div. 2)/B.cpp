#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p(n);
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            p[i] = cnt;
            cnt++;
        }  
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            p[i] = cnt;
            cnt++;
        }
    }
    int num = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == '1') num++;
    }
    if(num == k) {
        cout << "NO\n";
        return;
    }
    for(int i = k; i < n; i++) {
        if(s[i] == '1') num++;
        if(s[i - k] == '1') num--;
        if(num == k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
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
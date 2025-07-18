#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<i64> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(s[i] == '0') {
            a[i] = -1e13;
            cnt++;
        }
    }
    vector<i64> mxf(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(mxf[i - 1] > 0) {
            mxf[i] = mxf[i - 1] + a[i - 1];
            if(mxf[i] > k) {
                cout << "No\n";
                return;
            } 
        } else {
            mxf[i] = a[i - 1];
            if(mxf[i] > k) {
                cout << "No\n";
                return;
            }
        }
    }
    vector<i64> mxe(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
    if(mxe[i + 1] > 0) {
            mxe[i] = mxe[i + 1] + a[i]; 
            if(mxe[i] > k) {
                cout << "No\n";
                return;
            }
        } else {
            mxe[i] = a[i];
            if(mxe[i] > k) {
                cout << "No\n";
                return;
            }
        }
    }
    
    if(cnt == 0) {
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(mxf[i + 1] == k || mxe[i] == k) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout << "Yes\n";
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            continue;
        }
        a[i] = k - max(mxf[i], 0LL) - max(mxe[i + 1], 0LL);
        break;
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
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
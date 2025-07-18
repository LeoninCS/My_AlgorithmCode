#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pre0(n + 1, 0);
    vector<int> pre1(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pre0[i + 1] = pre0[i];
        pre1[i + 1] = pre1[i];
        if(a[i] <= k) pre0[i + 1]++;
        else pre1[i + 1]++;
    }   
    // 前向处理
    int idx0 = n, idx1 = n;
    for(int i = 1; i <= n; i++) {
        if(pre0[i] > 0 && pre0[i] == pre1[i]) {
            idx0 = i;
            break;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(pre0[i] == pre1[i] + 1) {
            idx1 = i;
            break;
        }
    }
    bool ans = false;
    for(int i = n - 1; i > idx0; i--) {
        if(pre0[n] - pre0[i] >= pre1[n] - pre1[i] || pre0[i] - pre0[idx0] >= pre1[i] - pre1[idx0]) ans = true;
    }
    for(int i = n - 1; i > idx1; i--) {
        if(pre0[n] - pre0[i] >= pre1[n] - pre1[i] || pre0[i] - pre0[idx1] >= pre1[i] - pre1[idx1]) ans = true;
    }
    // 后向处理
    int rev_idx0 = 0, rev_idx1 = 0;
    for(int i = n - 1; i >= 0; i--) {
        int zeros = pre0[n] - pre0[i];
        int ones = pre1[n] - pre1[i];
        if(zeros > 0 && zeros == ones) {
            rev_idx0 = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        int zeros = pre0[n] - pre0[i];
        int ones = pre1[n] - pre1[i];
        if(zeros == ones + 1) {
            rev_idx1 = i;
            break;
        }
    }
    for(int i = 1; i < rev_idx0; i++) {
        if(pre0[i] >= pre1[i] || (pre0[rev_idx0] - pre0[i] >= pre1[rev_idx0] - pre1[i])) ans = true;
    }
    for(int i = 1; i < rev_idx1; i++) {
        if(pre0[i] >= pre1[i] || (pre0[rev_idx1] - pre0[i] >= pre1[rev_idx1] - pre1[i])) ans = true;
    }
    
    cout << (ans ? "YES" : "NO") << "\n";
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
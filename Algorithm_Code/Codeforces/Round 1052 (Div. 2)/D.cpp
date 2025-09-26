#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int cal(int x) {
    if (x == 0) return 0;
    int res = 0;
    while (x > 0) {
        res++;
        x /= 2;
    }
    return res;
}

void solve(){
    int l,r;
    cin>> l >> r;
    int n = r - l + 1;
    vector<int> ans(n, -1);
    for(int i = r; i >= 0; i--) {
        if(ans[i] != -1) continue;
        int j = pow(2,cal(i)) - i - 1;
        ans[i] = j;
        ans[j] = i;
    }
    i64 sum = 0;
    for(int i = l; i <= r; i++) {
        sum += (ans[i] | i);
    }
    cout << sum << '\n';
    for(int i = l; i <= r; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

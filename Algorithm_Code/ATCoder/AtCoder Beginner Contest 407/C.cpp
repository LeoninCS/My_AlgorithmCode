#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = s[n - 1] - '0' + 1;
    int cnt = s[n - 1] - '0';
    for(int i = n - 2; i >= 0; i--) {
        int val = s[i] - '0';
        int end = cnt % 10;
        if(val >= end)  {
            ans += val - end + 1;
            cnt += val - end;
        }
        else  {
            ans += 10 - end + val + 1;
            cnt += 10 - end + val;
        }
    } 
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

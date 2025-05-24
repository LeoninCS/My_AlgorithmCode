#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int dif = 1e9;
    while(true) {
        int diff = abs(ans * b - a);
        if(diff >= dif) break;
        dif = diff;
        ans++; 
    }
    cout << ans - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

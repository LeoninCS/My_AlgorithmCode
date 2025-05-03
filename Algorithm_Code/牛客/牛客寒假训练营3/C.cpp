#include <bits/stdc++.h>
using namespace std;

int f[1000000][26], cnt[1000000];
int idx;

void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int tem = s[i] - 'a'; 
        if (!f[p][tem]) f[p][tem] = ++idx;
        p = f[p][tem];
    }
    cnt[p]++;
}

int count() {
    int nodeCount = 0;
    for (int i = 0; i <= idx; i++) {
        for (int j = 0; j < 26; j++) {
            if (f[i][j]) {
                nodeCount++;
            }
        }
    }
    return nodeCount;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        insert(s);
        mx = max(mx, (int)s.size());
    }
    int a, b;
    cin >> a >> b;
    int ans = count() * 2 - mx;
    cout << ans << endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}

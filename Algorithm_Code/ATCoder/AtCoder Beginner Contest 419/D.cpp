#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 500005;
int bit[MAXN];
int N;

int lowbit(int x) {
    return x & -x;
}

void add(int k, int v) {
    for (; k <= N; k += lowbit(k)) {
        bit[k] += v;
    }
}

int query(int k) {
    int sum = 0;
    for (; k > 0; k -= lowbit(k)) {
        sum += bit[k];
    }
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    N = n;
    string s, t;
    cin >> s >> t;
    
    memset(bit, 0, sizeof(bit));
    
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        add(l, 1);
        add(r + 1, -1);
    }
    
    for(int i = 0; i < n; i++) {
        int flip = query(i + 1);
        cout << (flip % 2 ? t[i] : s[i]);
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int MAX_NODES = N * 24;
int rt[N];
int ls[MAX_NODES], rs[MAX_NODES]; 
int sm[MAX_NODES];
int tot;
int a[N];
vector<int> vls;
//主席树模板
int get_rank(int x) {
    return lower_bound(vls.begin(), vls.end(), x) - vls.begin() + 1;
}

int update(int pre, int l, int r, int x) {
    int p = ++tot;
    ls[p] = ls[pre];
    rs[p] = rs[pre];
    sm[p] = sm[pre] + 1;

    if (l == r) {
        return p;
    }
    int mid = l + (r - l) / 2;
    if (x <= mid) {
        ls[p] = update(ls[pre], l, mid, x);
    } else {
        rs[p] = update(rs[pre], mid + 1, r, x);
    }
    return p;
}

void query(int u, int v, int l, int r, int k, vector<int>& ans) {
    int cnt = sm[u] - sm[v];
    if (cnt <= k) {
        return;
    }
    if (l == r) {
        ans.push_back(vls[l - 1]);
        return;
    }
    int mid = l + (r - l) / 2;
    query(ls[u], ls[v], l, mid, k, ans);
    query(rs[u], rs[v], mid + 1, r, k, ans);
}

void solve() {
    vls.clear();
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vls.push_back(a[i]);
    }
    sort(vls.begin(), vls.end());
    vls.erase(unique(vls.begin(), vls.end()), vls.end());
    int m = vls.size();
    tot = 0;
    rt[0] = 0;
    ls[0] = rs[0] = sm[0] = 0;
        for (int i = 1; i <= n; i++) {
        if(m > 0) rt[i] = update(rt[i - 1], 1, m, get_rank(a[i]));
        else rt[i] = rt[i-1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int k = (r - l + 1) / 3;

        vector<int> ans;
        if (m > 0) {
            query(rt[r], rt[l - 1], 1, m, k, ans);
        }

        if (ans.empty()) {
            cout << -1 << "\n";
        } else {
            sort(ans.begin(), ans.end());
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j] << (j == ans.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}

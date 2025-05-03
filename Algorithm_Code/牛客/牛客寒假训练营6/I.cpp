#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 1e5 + 10;
const int MAXM = MAXN * 20;

struct Node {
    int l, r, sum;
} tree[MAXM];
int idx = 0;
int roots[MAXN];

int update(int pre, int l, int r, int pos) {
    int now = ++idx;
    tree[now] = tree[pre];
    tree[now].sum++;
    if (l == r) {
        return now;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        tree[now].l = update(tree[pre].l, l, mid, pos);
    } else {
        tree[now].r = update(tree[pre].r, mid + 1, r, pos);
    }
    return now;
}

int query(int u, int v, int l, int r, int ql, int qr) {
    if (ql > qr) return 0;
    if (ql <= l && r <= qr) {
        return tree[v].sum - tree[u].sum;
    }
    int mid = (l + r) >> 1;
    int res = 0;
    if (ql <= mid) {
        res += query(tree[u].l, tree[v].l, l, mid, ql, qr);
    }
    if (qr > mid) {
        res += query(tree[u].r, tree[v].r, mid + 1, r, ql, qr);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> temp(p.begin() + 1, p.end());
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    int sz = temp.size();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(temp.begin(), temp.end(), p[i]) - temp.begin() + 1;
    }

    idx = 0;
    roots[0] = 0;
    for (int i = 1; i <= n; ++i) {
        roots[i] = update(roots[i - 1], 1, sz, a[i]);
    }

    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        int x = p[c];
        int k = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
        int cnt = query(roots[l - 1], roots[r], 1, sz, 1, k - 1);
        cout << cnt + l << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int total_g = 0;
    vector<vector<int>> gsum(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int add = (v[i][j] == 'g') ? 1 : 0;
            total_g += add;
            gsum[i + 1][j + 1] = gsum[i + 1][j] + gsum[i][j + 1] - gsum[i][j] + add;
        }
    }

    int min_cover = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#' || v[i][j] == 'g') continue;

            int u = max(0, i - k + 1);
            int d = min(n - 1, i + k - 1);
            int l = max(0, j - k + 1);
            int r = min(m - 1, j + k - 1);

            int cnt = gsum[d + 1][r + 1] - gsum[d + 1][l] - gsum[u][r + 1] + gsum[u][l];

            min_cover = min(min_cover, cnt);
        }
    }

    if (min_cover == INT_MAX) min_cover = 0;
    cout << total_g - min_cover << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}

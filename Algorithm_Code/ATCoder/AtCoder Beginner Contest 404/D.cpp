#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<i64> c(n + 1);
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            a[x].push_back(i);
        }
    }

    i64 ans = INF;
    vector<int> cnt(m, 0);

    function<void(int, i64)> dfs = [&](int idx, i64 sum) {
        if (idx > n) {
            if (*min_element(cnt.begin(), cnt.end()) >= 2) {
                ans = min(ans, sum);
            }
            return;
        }

        // 选0次
        dfs(idx + 1, sum);

        // 选1次
        for (int u : a[idx]) cnt[u - 1]++;
        dfs(idx + 1, sum + c[idx]);
        for (int u : a[idx]) cnt[u - 1]--; // 回溯

        // 选2次
        for (int u : a[idx]) cnt[u - 1] += 2;
        dfs(idx + 1, sum + 2 * c[idx]);
        for (int u : a[idx]) cnt[u - 1] -= 2; // 回溯
    };

    dfs(1, 0);
    cout << ans << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}
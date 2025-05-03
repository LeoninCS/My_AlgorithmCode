#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int n, m;

int cal(string s1, string s2) {
    s1 = s1 + s1; // 将s1变成环形字符串，即加上自己一份
    s2 = s2 + s2;
    vector<vector<int>> f(2 * m + 1, vector<int>(2 * m + 1, 0));

    // 计算两个字符串的最大公共子串
    for (int i = 1; i <= 2 * m; i++) {
        for (int j = 1; j <= 2 * m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }

    // 计算最大的公共子串长度
    int max_length = 0;
    for (int i = 1; i <= 2 * m; i++) {
        for (int j = 1; j <=  2 * m; j++) {
            max_length = max(max_length, f[i][j]);
        }
    }

    return min(max_length,m);
}

struct st {
    int x, y, z;
};

int find(vector<int>& pa, int node) {
    if (pa[node] != node) {
        pa[node] = find(pa, pa[node]);  // 路径压缩
    }
    return pa[node];
}

void solve() {
    cin >> n >> m;
    vector<string> ss(n);
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
    }

    vector<st> ans;
    vector<int> pa(n);
    iota(pa.begin(), pa.end(), 0);  // 初始化并查集

    // 计算每对字符串之间的最大公共子串
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = cal(ss[i], ss[j]);
            ans.push_back({i, j, cnt});
        }
    }

    // 按照边权降序排列
    sort(ans.begin(), ans.end(), [&](const st& a, const st& b) {
        return a.z > b.z;
    });

    int res = 0;
    int cnt = 0;

    // 使用并查集来构建最大生成树
    for (auto& st1 : ans) {
        int fa1 = find(pa, st1.x);
        int fa2 = find(pa, st1.y);

        // 如果这两个节点不在同一集合，则合并
        if (fa1 != fa2) {
            pa[fa2] = fa1;  // 合并操作
            res += st1.z;   // 加入边的权重
            cnt++;

            // 如果已经选了n-1条边，说明生成树已构建完成
            if (cnt == n - 1) break;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

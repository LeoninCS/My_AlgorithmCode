#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

// 计算数字的位数（最高有效位位置）
inline int h(int x) {
    return x == 0 ? 0 : 32 - __builtin_clz(x);
}

// 获取数字x的第k位（从1开始计数）
inline int gbit(i64 x, int k) {
    return ((x >> (k - 1)) & 1);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // 特殊情况处理：a和b都为0
    if (a == 0 && b == 0) {
        cout << (c > 0 ? "-1\n" : "0\n");
        return;
    }
    
    vector<int> ans;
    
    // 确保a的最高位不低于b
    if (h(a) > h(b)) {
        ans.push_back(4);
        b ^= a;
    }
    if (h(a) < h(b)) {
        ans.push_back(3);
        a ^= b;
    }
    
    // 处理a的最高位高于c的情况
    if (h(a) > h(c)) {
        while (h(b) > h(c)) {
            if (h(b) == h(a)) {
                ans.push_back(3);
                a ^= b;
            }
            ans.push_back(2);
            b >>= 1;
        }
    }
    
    // 再次确保a和b的最高位一致
    if (h(a) < h(b)) {
        ans.push_back(3);
        a ^= b;
    }
    
    // 将a左移直到与c的最高位一致
    while (h(a) < h(c)) {
        if (gbit(c, h(c) - h(a) + h(b)) != gbit(a, h(b))) {
            ans.push_back(3);
            a ^= b;
        }
        ans.push_back(1);
        a <<= 1;
    }
    
    // 处理b的剩余位
    while (h(b) > 0) {
        if (gbit(c, h(b)) != gbit(a, h(b))) {
            ans.push_back(3);
            a ^= b;
        }
        ans.push_back(2);
        b >>= 1;
    }
    
    // 最后一步操作
    ans.push_back(4);
    b ^= a;
    
    // 输出结果
    cout << ans.size() << '\n';
    for (int u : ans) {
        cout << u << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}

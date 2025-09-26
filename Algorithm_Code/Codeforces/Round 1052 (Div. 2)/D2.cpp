#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int l, r;
    std::cin >> l >> r;
    
    int n = r - l + 1;
    
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), l);
    
    int L = 0, R = n;
    for (int i = 29; i >= 0; i--) {
        int x = L;
        while (x < R && (~a[x] >> i & 1)) {
            x++;
        }
        
        if (x - L < R - x) {
            int m = 2 * x - L;
            std::reverse(a.begin() + L, a.begin() + m);
            L = m;
        } else {
            int m = 2 * x - R;
            std::reverse(a.begin() + m, a.begin() + R);
            R = m;
        }
    }
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] | (l + i);
    }
    
    std::cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

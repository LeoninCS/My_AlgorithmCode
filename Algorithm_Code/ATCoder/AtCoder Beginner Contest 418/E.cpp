#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve() {
    i64 n;
    cin >> n;

    vector<pair<i64, i64>> v(n);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    unordered_map<i64, unordered_map<i64, unordered_map<i64, vector<i64>>>> mp;
    for (i64 i = 0; i < n; i++) {
        for (i64 j = i + 1; j < n; j++) {
            i64 xa = v[i].first, ya = v[i].second;
            i64 xb = v[j].first, yb = v[j].second;

            i64 d2 = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);

            i64 a = yb - ya, b = xa - xb, c = xb * ya - xa * yb;

            if (a < 0 || (a == 0 && b < 0) || (a == 0 && b == 0 && c < 0)) {
                a = -a, b = -b, c = -c;
            }

            i64 g = __gcd(__gcd(abs(a), abs(b)), abs(c));
            a /= g, b /= g, c /= g;

            mp[a][b][c].push_back(d2);
        }
    }

    i64 ans1 = 0, ans2 = 0;

    for (auto& pa : mp) {
        for (auto& pb : pa.second) {
            i64 sm = 0;
            unordered_map<i64, i64> cnt;

            for (auto& pc : pb.second) {
                ans1 += pc.second.size() * sm;
                sm += pc.second.size();

                unordered_map<i64, i64> tmp;
                for (i64 d2 : pc.second) {
                    tmp[d2]++;
                }

                for (auto& p : tmp) {
                    ans2 += p.second * cnt[p.first];
                    cnt[p.first] += p.second;
                }
            }
        }
    }

    assert(ans2 % 2 == 0);
    cout << "Total trapezoids: " << ans1 - ans2 / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    i64 T = 1;
    while (T--) solve();

    return 0;
}

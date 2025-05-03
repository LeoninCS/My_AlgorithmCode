#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<set<pair<int, int>>> se(n + 1);
    vector<int> ans(n);


    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        se[x].insert({y, i}); 
    }


    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    for (int i = 1; i <= n; ++i) {
        for (auto& pa : se[i]) {
            pq.push(pa);
        }

        if (pq.empty() || i > pq.top().first) {
            cout << -1 << endl;
            return;
        }

        auto pa = pq.top();
        pq.pop();
        ans[pa.second] = i;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
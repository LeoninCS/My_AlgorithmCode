#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> l; 
    vector<int> r; 
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (b == 1) l.push_back(a);
        else r.push_back(a);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    double left = 0, right = 1e9;
    double result = -1;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = left + (right - left) / 2;
        int sum = 0;

        for (int i = 0; i < r.size(); ++i) {
            int idx = lower_bound(l.begin(), l.end(), r[i] - 2 * mid) - l.begin();
            sum += l.size() - idx;
            if (sum >= k) break;
        }

        if (sum >= k) {
            result = mid; 
            right = mid; 
        } else {
            left = mid;
        }
    }

    if (result == -1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        int cnt = 0;
        int l_idx = 0, r_idx = 0;
        double final_result = 0;

        for (int i = 0; i < r.size(); ++i) {
            int idx = lower_bound(l.begin(), l.end(), r[i] - 2 * result) - l.begin();
            int current = l.size() - idx;
            if (cnt + current >= k) {
                r_idx = r[i];
                l_idx = l[idx + (k - cnt - 1)];
                final_result = (r_idx - l_idx) / 2.0;
                break;
            }
            cnt += current;
        }

        cout << fixed << setprecision(6) << final_result << endl;
    }
}

int main() {
    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}
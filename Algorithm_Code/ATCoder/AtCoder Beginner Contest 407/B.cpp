#include <bits/stdc++.h>
using namespace std;

void solve() {
    int X, Y;
    cin >> X >> Y;

    int total = 0, valid = 0;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            total++;
            if (i + j >= X || abs(i - j) >= Y) {
                valid++;
            }
        }
    }

    cout << fixed << setprecision(12) << (double)valid / total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

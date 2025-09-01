#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Point {
    i64 val1, val2, x, y;
};
i64 xx = -1, yy = 3;

i64 cal(string s, vector<Point> &a) {
    if(s == "R") {
        xx += 1e9;
    } else if(s == "L") {
        xx -= 1e9;
    } else if(s == "U") {
        yy += 1e9;
    } else {
        yy -= 1e9;
    }
    i64 mi = 1e18;
    for(auto &p : a) {
        i64 d = abs(xx - p.x) + abs(yy - p.y);
        mi = min(mi, d);
    }
    cout << mi << endl;
    return mi;
}

void solve() {
    i64 k = 1e9;
    int n;
    cin >> n;
    vector<Point> a(n); 
    for (int i = 0; i < n; i++) {
        i64 x, y;
        cin >> x >> y;
        a[i].val1 = x + y;
        a[i].val2 = x - y;
        a[i].x = x;
        a[i].y = y;
    }
    i64 d;
    cout << "? R " << k <<endl;
    //d = cal("R", a);
    cin >> d;
    cout << "? R " << k <<endl;
    //d = cal("R", a);
    cin >> d;
    cout << "? U " << k <<endl;
    //d = cal("U", a);
    cin >> d;
    cout << "? U " << k <<endl;
    //d = cal("U", a);
    cin >> d;
    sort(a.begin(), a.end(), [](const Point &p1, const Point &p2) {
        return p1.val1 > p2.val1;
    });
    i64 v1 = a[0].val1, d1 = d;
    cout << "? D " << k <<endl;
    //d = cal("D", a);
    cin >> d;
    cout << "? D " << k <<endl;
    //d = cal("D", a);
    cin >> d;
    cout << "? D " << k <<endl;
    //d = cal("D", a);
    cin >> d;
    cout << "? D " << k <<endl;
    //d = cal("D", a);
    cin >> d;
    sort(a.begin(), a.end(), [](const Point &p1, const Point &p2) {
        return p1.val2 > p2.val2;
    });
    i64 v2 = a[0].val2, d2 = d;
    //cout << d1 << " " << d2 << "\n";
    i64 x = (d1 + v1 + d2 + v2 - 8 * k) / 2;
    i64 y = (d1 + v1 - d2 - v2) / 2;
    cout << "! " << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
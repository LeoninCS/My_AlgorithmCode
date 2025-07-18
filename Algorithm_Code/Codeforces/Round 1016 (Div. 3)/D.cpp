#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

i64 qpow(i64 base, i64 exp) {
    i64 res = 1;
    while(exp > 0) {
        if(exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}


pair<i64,i64> cal(i64 a, i64 n)
{
    a--;
    vector<i64> v;
    for (int i = 0; i < n; ++i) {
        i64 digit = a % 4; 
        v.push_back(digit + 1);
        a /= 4;
    }
    i64 x = 0, y = 0;
    for(int i = v.size() - 1; i >= 0; i--) {
        x *= 2;
        y *= 2;
        if(v[i] == 1) {
            x += 0;
            y += 0;
        } else if(v[i] == 4) {
            x += 0;
            y += 1;
        } else if(v[i] == 3) {
            x += 1;
            y += 0;
        } else if(v[i] == 2) {
            x += 1;
            y += 1;
        }
    }
    return {x + 1, y + 1};
}

void solve()
{
    i64 n, q;
    cin >> n >> q;
    while(q--) {
        string s;
        cin >> s;
        if(s == "->") {
            i64 a, b;
            cin >> a >> b;
            vector<i64> v;

            for (int i = 0; i < n; ++i) {
                int x_bit, y_bit;
                if(a % 2 == 1) x_bit = 1; else x_bit = 2;
                if(b % 2 == 1) y_bit = 1; else y_bit = 2;

                i64 add;
                if(x_bit == 1 && y_bit == 1) add = 1;
                else if(x_bit == 1 && y_bit == 2) add = 4; 
                else if(x_bit == 2 && y_bit == 1) add = 3; 
                else if(x_bit == 2 && y_bit == 2) add = 2; 
                v.push_back(add);
                a = (a + 1) / 2;
                b = (b + 1) / 2;
            }
            
            i64 ans = 0;
            for (int i = v.size() - 1; i >= 0; --i) {
                ans *= 4;
                ans += (v[i] - 1);
            }

            cout << ans + 1 << "\n"; 

        } else {
            i64 a;
            cin >> a;
            pair<i64,i64> pa = cal(a, n);
            cout << pa.first << " " << pa.second << "\n";
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}

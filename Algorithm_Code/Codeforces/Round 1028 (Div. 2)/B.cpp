#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 998244353;

int qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return (int)res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    
    int max_a = -1, max_b = -1;
    int max_index_a = -1, max_index_b = -1;
    
    for(int i = 0; i < n; i++) {
        if(a[i] > max_a) {
            max_a = a[i];
            max_index_a = i;
        }
        if(b[i] > max_b) {
            max_b = b[i];
            max_index_b = i;
        }

        i64 res = 0;
        if(max_a > max_b) {
            if (i >= max_index_a)
                res = (qmi(2, a[max_index_a]) + qmi(2, b[i - max_index_a])) % mod;
        } else if(max_b > max_a) {
            if (i >= max_index_b)
                res = (qmi(2, b[max_index_b]) + qmi(2, a[i - max_index_b])) % mod;
        } else {
            if (i >= max_index_a && i >= max_index_b) {
                if(b[i - max_index_a] > a[i - max_index_b])
                    res = (qmi(2, a[max_index_a]) + qmi(2, b[i - max_index_a])) % mod;
                else
                    res = (qmi(2, b[max_index_b]) + qmi(2, a[i - max_index_b])) % mod;
            }
        }

        cout << res << " \n"[i == n - 1];
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}
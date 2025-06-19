#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, q;
    cin >> n >> q;
    vector<int> x(q);
    for(int i = 0; i < q; i++) {
        cin >> x[i];
    }
    vector<int> a(n + 1, 0);
    a[0] = 100000;
    for(int i = 0; i < q; i++) {
        if(x[i] > 0) {
            cout << x[i] << " ";
            a[x[i]]++;
        }
        else {
            int mi = 10000;
            int idx;
            for(int j = 1 ; j <= n; j++) {
                if(a[j] < mi) {
                    mi = a[j];
                    idx = j;
                }
            }
            cout << idx << " ";
            a[idx]++;
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}
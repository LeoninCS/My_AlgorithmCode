#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mi = -1;
    int idx = -1;
    set<int> se;
    for(int i = 0; i < n; i++) {
        if(a[i] < mi) {
            mi = a[i];
            idx = i;
        } 
        se.insert(a[i]);
    }
    if(se.size() == 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for(int i = 0; i < n; i++) {
            if(i == idx) {
                cout << 1 << " ";
            } else {
                cout << 2 << " ";
            }
        }
        cout << "\n";
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
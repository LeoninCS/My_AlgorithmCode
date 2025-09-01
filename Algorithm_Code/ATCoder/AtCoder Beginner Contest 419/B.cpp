#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            cin >> b;
            pq.push(b);
        } else {
            int ans = pq.top();
            pq.pop();
            cout << ans  << "\n";
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
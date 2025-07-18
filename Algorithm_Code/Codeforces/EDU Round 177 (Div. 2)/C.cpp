#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    set<int> se;
    for(int i = 1; i <= n; i++) se.insert(i);

    for(int i = 1; i <= n; i++) {
        queue<int> q;
        if(se.count(d[i])) q.push(d[i]);
        while(!q.empty()) {
            int tp = q.front();
            q.pop();
            se.erase(tp);
            if(se.count(p[tp])) q.push(p[tp]); 
        }        
        cout << n - se.size() << " ";
    }
    cout << "\n";
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
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
set<int> se{2,3,7,8};
set<int> see{}

void solve()
{
	int n;
    cin >> n;
    int cnt = 0;
    vector<int> ans;
    for(int i = 2; i <= n; i++) {
        int mo = i % 10;
        //int moo = i % 100;
        if(se.count(mo)) {
            //cout << i << " ";
            ans.push_back(i);
            cnt++;
            if(cnt == n / 2) {
                cout << "\n";
                break;
            }
        };
    }
    for(int x:ans) for(int y:ans) for(int z:ans) 
    {int cc = x * y * z; if((int)sqrt(cc) * (int)sqrt(cc) == cc) cout << x << " " << y << " " << z << "\n";}
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
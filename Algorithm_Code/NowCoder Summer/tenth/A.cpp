#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve(int n, int m)
{
	//int n, m;
    //cin >> n >> m;
    set<int> se;
    if(__gcd(n, m) != 1) {
        //cout << "NO\n";
        //cout << endl;
        return;
    }
    vector<vector<int>> ans(n, vector<int>(m));
    int mid = (m - 1) / 2;
    vector<int> idxm(m);
    vector<int> idxn(n);
    for(int i = 1; i <= m; i++) {
        if(i % 2 == 0) idxm[mid + i / 2] = i;
        else idxm[mid - i / 2] = i;
    }
    mid = (n - 1) / 2;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) idxn[mid + i / 2] = i;
        else idxn[mid - i / 2] = i;
    }
    //cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[i][j] = (idxn[i] - 1) * m + idxm[(m / 2 * (idxn[i] - 1) + j) % m];
            //cout << ans[i][j] << " ";
        }
        //cout << "\n";
    }
    unordered_map<int,pair<int,int>> ump;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ump[ans[i][j]] = {i, j};
        }
    }
    for(int i = 2; i <= n * m; i++) {
        int x = ump[i].first - ump[i - 1].first;
        int y = ump[i].second - ump[i - 1].second;
        if(n - (x + n) % n != (i - 1) % n && (x + n) % n != (i - 1) % n && (y + m) % m != (i - 1) % m && m - (y + m) % m != (i - 1) % m) cout << i << "fuck\n";
    }
    //cout << endl;
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) {
        for(int i = 1; i < 5; i+=1) {
            for(int j = 1; j < 10000; j+=1000) {
                solve(i, j);
            }
        }
    } 
	
	return 0;
}
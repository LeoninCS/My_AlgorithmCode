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
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int mx = n;
    for(int i = 0; i < n; i++) {
        if(!mp.count(i)) {
            mx = i;
            break;
        }
    }
    vector<int> v;
    int cnt = 0;
    for(auto & it : mp) {
        if(it.first > mx) {
            cnt += it.second;
            continue;
        }
        v.push_back(it.second);
    }
    int d = n - v.size();
    sort(v.begin(), v.end());
    for(int i = 0; i <= n; i++) {
        if(i > d) {
            cout << n - i + 1 << " ";
            continue;
        } 
        int idx = upper_bound(v.begin(), v.end(), i) - v.begin();
        cout << idx + 1 << " ";
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
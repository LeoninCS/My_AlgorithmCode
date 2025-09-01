#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

struct DSU {
    std::vector<int> f, siz, num;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        num.assign(n, 0);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        num[x] += num[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }

};

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    DSU dsu(2 * n + 1);

    vector<int> ans;
    
    for(int i = 0; i < n; i++) {
        if(dsu.merge(a[i], b[i])) {
            int aa = dsu.find(a[i]);
            if(dsu.siz[aa] == dsu.num[aa]) dsu.num[aa]--;
            else ans.push_back(i + 1);             
        }
    }
    cout << ans.size() << "\n";
    for(int x: ans) cout << x << " ";
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
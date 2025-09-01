#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    
    int n;
    cin >> n;
	vector<pair<int,int>> tree(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> tree[i].first >> tree[i].second;
    }
    function<int(int)> dfs = [&](int root)-> int {
        if(root == 0) return 0; 
        int l = tree[root].first;
        int r = tree[root].second;
        int llh = dfs(tree[l].first);
        int lrh = dfs(tree[l].second);
        int lh = max(llh, lrh) + 1;
        int rlh = dfs(tree[r].first);
        int rrh = dfs(tree[r].second);
        int rh = max(lrh, rrh) + 1;
        if(lh > rh) swap(tree[root].first, tree[root].second);
        return max(lh,rh);
    };
    dfs(1);
    int ans = 1e9;
    function<void()> cal = [&](){
        int add = 0;
        int sub = 0;
        queue<int> q;
        q.push(1);
        while(q.size()) {
            int k = q.size();
            for(int i = 0; i < k; i++) {
                int root = q.front();
                q.pop();
                sub++;
            }
            

        }
    };
    cal();
    vector<int> 
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
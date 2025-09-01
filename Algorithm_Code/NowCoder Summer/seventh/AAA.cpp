#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

vector<int> vis(10, 0);

vector<int> ans;

void dfs(int cur) {
    {
        bool flag = true;
        for(int x: ans) {
            for(int y: ans) {
                for(int z:ans) {
                    if(x * y * z % 10 == 0 ||
                    x * y * z % 10 == 1 ||
                    x * y * z % 10 == 4 ||
                    x * y * z % 10 == 5 ||
                    x * y * z % 10 == 6 ||
                    x * y * z % 10 == 9 ) flag = false;
                }
            }
        }
        if(flag) {
            for(int x: ans) cout << x << " ";
            cout << "\n";
        }
        
    }
    for(int i = cur;  i < 10 ; i++) {
        if(vis[i]) continue;
        ans.push_back(i);
        vis[i] = 1;
        dfs(i + 1);
        vis[i] = 0;
        ans.pop_back();
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	dfs(0);
	
}
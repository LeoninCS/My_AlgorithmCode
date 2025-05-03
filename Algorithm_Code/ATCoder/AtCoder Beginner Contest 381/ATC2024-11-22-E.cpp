#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
int pre[100005][2];
vector<int> v;
int ans;

int cal(int L, int R) {
    ans = 0;
	int l = 0, r = v.size() - 1;
    while(l <= r) {
    	int mid = (r - l) / 2 + l;
    	if(v[mid] < L) l = mid + 1;
		else if(v[mid] > R) r = mid - 1;
		else {
			int c1 = pre[v[mid]][0] - pre[L - 1][0];
			int c2 = pre[R][1] - pre[v[mid] - 1][1];
			ans = max(ans, min(c1, c2) * 2 + 1);
			if(c1 <= c2) l = mid + 1;
			else  r = mid - 1;
		} 
	}
	return ans;
}

void solve() {
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) {
        pre[i][0] = pre[i - 1][0];
        pre[i][1] = pre[i - 1][1];
        if(s[i - 1] == '1') pre[i][0]++;
        if(s[i - 1] == '2') pre[i][1]++;
        if(s[i - 1] == '/') v.push_back(i);
    } 

    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << cal(l, r) << '\n';
    }
}

int main() {
    solve();
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int ans = 0;
    bool low = false, big = false;
    for(int i = 0; i < n; i++) {
        int mul = s2[i] - s1[i];  
        if(mul > 1) {
            break;
        } else if(mul == 1) {
            int cnt1 = 0,cnt2 = 0;
            for(int j = i + 1; j < n; j++) {
                if(s1[j] != '9') break;
                cnt1++;
            }
            for(int j = i + 1; j < n; j++) {
                if(s2[j] != '0') break;
                cnt2++;
            }
            ans += (min(cnt1, cnt2) + 1);
            break;
        } else {
            ans += 2;
        }
        
    }
    cout << ans << "\n";
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
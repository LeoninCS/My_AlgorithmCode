#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
   int n,q;
   cin >> n >> q;
   vector<int> a(n + 1, 0);//鸽子----位置
   vector<int> b(n + 1, 0);//位置----笼子
   vector<int> c(n + 1, 0);//笼子----位置
   for(int i = 1; i <= n; i++) {
   		a[i] = i;
   		b[i] = i;
   		c[i] = i;
   }
   for(int i = 1; i <= q; i++) {
   	int z,x,y;
   	cin >> z;
   	if(z == 3) {
   			cin >> x;
			cout << b[a[x]] << endl;
	} else if(z == 2){
			cin >> x >> y;
			swap(b[c[x]],b[c[y]]);
			swap(c[x],c[y]);			
	} else {
		cin >> x >> y;
		a[x] = c[y];
	}
   }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    //cin >> T;
    while (T--) solve();
}

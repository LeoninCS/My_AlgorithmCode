#include<iostream>
#include<vector>
using namespace std;


vector<int> ans;
bool vis[100000005]; 

int main()
{
	int n,k;
	cin >> n >> k;
	for(int i=2;i<=n;i++) {
		if(!vis[i]) {
			ans.push_back(i);
		}
		for(int j=0;j<ans.size();j++) {
			if(i*ans[j]>n) break;
			vis[i*ans[j]] = true;
			if(i%ans[j]==0) break;
		}
	}
	while(k--) {
		int t = 0;
		cin >> t;
		cout << ans[t-1] << endl;
	}
	return 0;
}

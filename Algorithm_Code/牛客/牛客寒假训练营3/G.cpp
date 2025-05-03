#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	for(int i = 1; i < n; i++) {
		v.push_back(n%i);
	}
	sort(v.begin(),v.end());
	for(auto a:v) cout << a << " ";
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> add(vector<int> &a,vector<int> &b)
{
	if(a.size()<b.size()) return add(b,a);
	vector<int> c;
	int t = 0;
	for(int i=0;i<a.size();i++) {
		t += a[i];
		if(i<b.size()) t+= b[i];
		c.push_back(t%10);
		t/=10;
	}
	if(t) c.push_back(t);
	return c;
}

int main()
{
	string a,b;
	cin >> a >> b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	vector<int> av(a.size());
	vector<int> bv(b.size());
	for(int i = 0; i<a.size();i++) {
		av[i] = a[i]-'0';
	}
	for(int i = 0;i<b.size();i++) {
		bv[i] = b[i]- '0';
	}
	vector<int> cv = add(av,bv);
	for(int i=cv.size()-1;i>=0;i--) cout << cv[i];
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int> &v,int l,int r)
{
	if(l >= r) return;
	int i= l-1, j = r+1,x = v[l+(r-l)/2];
	while(i<j) {
		do i++;while(v[i]<x);
		do j--;while(v[j]>x);
		if(i<j) swap(v[i],v[j]);
	}  
	quicksort(v,l,j),quicksort(v,j+1,r);
}
 

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	quicksort(v,0,v.size()-1);
	for(int a:v) cout << a << " ";
	return 0;
}

#include<iostream> 
#include<vector>
using namespace std;

vector<int> arr = {0,1,2,3,4,5,6,7,8,9};

int lower_bound(int x)
{
	int l =0,r = arr.size();
	while(l<=r) {
		int mid = l+(r-l)/2;
		if(x<=arr[mid]) r = mid-1;
		else l = mid+1; 
	}
	return l;
}

int main()
{
	int x = 0;
	cin >> x;
	int idx = lower_bound(x);
	cout << idx;	
	return 0;
 } 

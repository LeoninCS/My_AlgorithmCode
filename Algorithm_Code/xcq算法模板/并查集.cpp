#include<bits/stdc++.h>
using namespace std;

int pa[10010];
int find (int x) 
{
	if(pa[x] != x) pa[x] = find(pa[x]);
	return pa[x];
}

void merge(int x,int y)
{
	x = find(x),y=find(y);
	pa[y] = x;
}

int main()
{
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int M=1e9+7;
	
 
 
int main()
{
	int n,price;
	cin>>n>>price;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;++i)cin>>v[i].first;
	for(int i=0;i<n;++i)cin>>v[i].second;
 
 
	vector<int> dp(price+1,0);
	for(int i=price;i>=0;--i)
	{
		if(v[0].first<=i)dp[i]=v[0].second;
	}
 
	for(int j=1;j<n;++j)
	{
		for(int i=price;i>=0;--i)
		{
			if(i>=v[j].first)dp[i]=max(dp[i],dp[i-v[j].first]+v[j].second);
		}
 
	}
	cout<<dp[price]<<"\n";
 
 
}
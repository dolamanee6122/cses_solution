// Created by ...
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'

#define vll vector< ll >
#define M 200005
#define MD 1000000007
#define pb push_back
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define fo(i,a,b) for(int i = a; i<= b; ++i)
#define pii pair<ll,ll> 
#define vec(a) vector<a >
#define all(a) a.begin(),a.end()
#define se second
#define fi first
#define inf 0xffffffff
#define inchar getchar_unlocked
#define outchar(x) putchar_unlocked(x)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
using ll = long long;
ll md=MD;

ll exp(ll a,ll b){ll r=1ll;while(b>0){if(b&1){r=r*(a%md);r=(r+md)%md;}b>>=1;a=(a%md)*(a%md);a=(a+md)%md;}return (r+md)%md;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll Min(ll a,ll b){if(a<b)return a; return b;}
ll Max(ll a,ll b){if(a>b)return a; return b;}
int tree[2*M],a[M],n,b;

int query(int l,int r){
	int sum=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)sum+=tree[l++];
		if(r&1)sum+=tree[--r];
	}
	return sum;
}

void update(int p){
	for(tree[p+=n]=0,p>>=1;p>0;p>>=1)tree[p]=tree[p<<1]+tree[p<<1|1];
}
int32_t main() {
    IOS;

        cin>>n;
        rep(i,0,n-1)tree[i+n]=1;
        for(int i=n-1;i>0;--i)tree[i]=tree[i<<1]+tree[i<<1|1];
        rep(i,0,n-1)cin>>a[i];
    	rep(i,0,n-1){
    		cin>>b;
    		int low=0,high=n-1,mid,ans=high;
    		while(low<=high){
    			mid=(low+high)>>1;
    			int x=query(0,mid+1);
    			if(x<b)low=mid+1;
    			else if(x>b)high=mid-1;
    			else{
    				if(tree[mid+n]==1){
    					ans=mid;
    					break;
    				}
    				high=mid-1;
    			}
    		}
    		cout<<a[ans]<<" ";
    		update(ans);
    	}

        cout<<'\n';
    return 0;
}
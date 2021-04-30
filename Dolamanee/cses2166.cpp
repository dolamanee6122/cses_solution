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

struct node{
	bool dummy;
	int sum,psum;
	node(){
		dummy=true;
	}
	node(int s,int p){
		dummy=false;
		sum=s;
		psum=p;
	}
};

node tree[2*M];
int n,q,k,u,a,b;
node combine(node a,node b){
	if(a.dummy)return b;
	if(b.dummy)return a;
	node ans=a;
	ans.sum = a.sum+b.sum;
	ans.psum = Max(ans.psum,a.sum+b.psum);
	return ans;
}
void update(int p,int val){
	for(tree[p+=n].sum=val,tree[p].psum=val,p>>=1;p>0;p>>=1)tree[p]=combine(tree[p<<1],tree[p<<1|1]);
}

node query(int l,int r){
	node left,right;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)left=combine(left,tree[l++]);
		if(r&1)right=combine(tree[--r],right);
	}
	return combine(left,right);
}
int32_t main() {
    IOS;

        cin>>n>>q;
        rep(i,0,n-1)cin>>a,tree[i+n]=node(a,a);
        for(int i=n-1;i>0;--i)tree[i]=combine(tree[i<<1],tree[i<<1|1]);

        /*rep(i,1,n-1)cout<<"("<<tree[i].psum<<","<<tree[i].sum<<") ";
    	cout<<endl;*/
        rep(i,0,q-1){
        	cin>>k>>a>>b;
        	if(k==1){
        		update(a-1,b);
        	}
        	else{
        		cout<<Max(0,query(a-1,b).psum)<<endl;
        	}
        }

    return 0;
}
// Created by ...
#include <bits/stdc++.h>

#define vll vector< ll >
#define M 200005
#define MD 1000000007
#define pb push_back
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define per(i,a,b) for(ll i = a; i >= b; --i)
#define pii pair<ll,ll> 
#define vec(a) vector<a >
#define all(a) (a).begin(),(a).end()
#define EACH(x, a) for (auto x:a)
#define se second
#define fi first
#define inf 0xffffffff
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
using ll = long long;
ll md=MD;

ll exp(ll a,ll b){ll r=1ll;while(b>0){if(b&1){r=r*(a%md);r=(r+md)%md;}b>>=1;a=(a%md)*(a%md);a=(a+md)%md;}return (r+md)%md;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
template<class T> T Min(T a,T b){if(a<b)return a; return b;}
template<class T> T Max(T a,T b){if(a>b)return a; return b;}

struct Node{
	int sum,psum,ssum,maxsum;
	bool dummy;
	Node(){dummy=true;}
	Node(int s,int ps,int ss,int ms){
		sum=s; psum=ps; ssum=ss; maxsum=ms;
		dummy=false;
	}
};
string to_string(Node a){
	cout<<"("<<a.sum<<","<<a.psum<<","<<a.ssum<<","<<a.maxsum<<")\n";
}
Node tree[2*M];
int n,q,a,k,x;
Node combine(Node a, Node b){
	if(a.dummy)return b;
	if(b.dummy)return a;
	Node ans;
	ans.dummy=false;
	//sum
	ans.sum=a.sum+b.sum;

	//psum
	ans.psum = Max(a.psum,a.sum+b.psum);

	//ssum
	ans.ssum = Max(b.ssum,b.sum+a.ssum);

	//maxsum
	ans.maxsum=Max(a.maxsum,b.maxsum);
	ans.maxsum=Max(ans.maxsum,Max(ans.psum,ans.ssum));
	ans.maxsum=Max(ans.maxsum,Max(ans.sum,a.ssum+b.psum));

	return ans;
}

void update(int p,int x){
	for(tree[p+=n]=Node(x,x,x,x),p>>=1;p>0;p>>=1)tree[p]=combine(tree[p<<1],tree[p<<1|1]);
}

Node query(int l,int r){
	Node left,right;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)left=combine(left,tree[l++]);
		if(r&1)right=combine(tree[--r],right);
	}
	return combine(left,right);
}
int32_t main() {
    IOS;

        cin>>n>>q;
        rep(i,0,n-1){
        	cin>>a;
        	tree[i+n]=Node(a,a,a,a);
        }
        per(i,n-1,1)tree[i]=combine(tree[i<<1],tree[i<<1|1]);
        //rep(i,1,n-1)to_string(tree[i]);
        while(q--){
        	cin>>k>>x;
        	update(k-1,x);
        	cout<<Max(query(0,n).maxsum,0LL)<<endl;
        	//rep(i,1,n-1)to_string(tree[i]);
        	//cout<<endl;
        }
    return 0;
}
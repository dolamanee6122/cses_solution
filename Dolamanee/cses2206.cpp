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

int t[2][2*M],n,q,k,x;

void update(int i,int p,int val){
	for(t[i][p+=n]=val,p>>=1;p>0;p>>=1)t[i][p]=Min(t[i][p<<1],t[i][p<<1|1]);
}

int query(int i,int l,int r){
	int ans=2e9;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)ans=Min(ans,t[i][l++]);
		if(r&1)ans=Min(ans,t[i][--r]);
	}
	return ans;
}
int32_t main() {
    IOS;

        cin>>n>>q;
        rep(i,0,n-1){
        	cin>>x;
        	t[0][i+n]=x-i;
        	t[1][i+n]=x+i;
        }
        for(int i=n-1;i>0;--i)
        	rep(j,0,1)t[j][i]=Min(t[j][i<<1],t[j][i<<1|1]);
        
        while(q--){
        	cin>>k;
        	if(k==1){
        		cin>>k>>x;
        		--k;
        		update(0,k,x-k);
        		update(1,k,x+k);
        	}
        	else{
        		cin>>k;
        		--k;
        		cout<<Min(query(0,0,k)+k,query(1,k,n)-k)<<endl;
        	}
        }
    return 0;
}
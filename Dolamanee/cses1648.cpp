// Created by ...
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'

#define vll vector< ll >
#define M 100000
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
const int mx=2e5+5;
int t[2*mx],n,q,a,b,c;

void update(int x,int h){
	for(t[x+=n]=h,x>>=1;x>0;x>>=1)t[x]=t[x<<1]+t[x<<1|1];
}
int query(int a,int b){
	int ans=0;
	for(a+=n,b+=n;a<b;a>>=1,b>>=1){
		if(a&1)ans+=t[a++];
		if(b&1)ans+=t[--b];
	}
	return ans;
}
int32_t main() {
    IOS;

        cin>>n>>q;
        rep(i,0,n-1)cin>>t[i+n];
        for(int i=n-1;i>0;--i)t[i]=t[i<<1]+t[i<<1|1];
        while(q--){
        	cin>>c>>a>>b;
        	if(c==1)update(a-1,b);
        	else cout<<query(a-1,b)<<endl;
        }

    return 0;
}
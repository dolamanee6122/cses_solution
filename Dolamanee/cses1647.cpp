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
const int h=20,mx=2e5+5;
#define log Log
int st[mx][h],log[mx];
int32_t main() {
    IOS;

    	log[1]=0;
    	rep(i,2,mx-1)log[i]=log[i/2]+1;
        ll n,q;
        cin>>n>>q;
        vll v(n);
        rep(i,0,n-1) cin>>v[i];
        rep(i,0,n-1)st[i][0]=v[i];
        for(int j=1;j<=18;++j){
        	for(int i=0;i+(1<<j)<=n;++i){
        		st[i][j]=Min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        	}
        }
        while(q--){
        	int a,b;
        	cin>>a>>b;
        	--a;--b;
        	int j=log[b-a+1];
        	int ans=Min(st[a][j],st[b-(1<<j)+1][j]);
        	cout<<ans<<endl;
        }
    return 0;
}
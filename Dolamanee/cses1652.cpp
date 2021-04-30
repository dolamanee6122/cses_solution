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
bool check(int x){
	int y=x,rev=0;
	while(y){
		rev=(rev*10+y%10);
		y/=10;
	}
	return rev==x;
}
int32_t main() {
    IOS;

        /*int n,q,x1,x2,y1,y2;char c;
        cin>>n>>q;
        int a[n][n];
        rep(i,0,n-1)rep(j,0,n-1){
        	cin>>c;
        	if(c=='*')a[i][j]=1;
        	else a[i][j]=0;
        }	
        rep(i,0,n-1)rep(j,0,n-1){
        	if(i-1>=0)a[i][j]+=a[i-1][j];
        	if(j-1>=0)a[i][j]+=a[i][j-1];
        	if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
        }
        while(q--){
        	cin>>x1>>y1>>x2>>y2;
        	--x1;--x2;--y1;--y2;
        	int ans=a[x2][y2];
        	if(x1-1>=0)ans-=a[x1-1][y2];
        	if(y1-1>=0)ans-=a[x2][y1-1];
        	if(x1-1>=0 && y1-1>=0)ans+=a[x1-1][y1-1];
        	cout<<ans<<endl;
        }*/
    	int a[20][20],ans=0;
    	rep(i,0,19)rep(j,0,19)cin>>a[i][j];
    	rep(i,3,16)rep(j,3,16){
    		int val=1;
    		rep(k,0,3)val*=a[i][j+k];
    		ans=max(ans,val);

    		val=1;
    		rep(k,0,3)val*=a[i][j-k];
    		ans=max(ans,val);

    		val=1;
    		rep(k,0,3)val*=a[i+k][j];
    		ans=max(ans,val);

    		val=1;
    		rep(k,0,3)val*=a[i-k][j];
    		ans=max(ans,val);

    		val=1;
    		rep(k,0,3)val*=a[i+k][j+k];
    		ans=max(ans,val);

    		val=1;
    		rep(k,0,3)val*=a[i+k][j-k];
    		ans=max(ans,val);

    		val=1;
    		rep(k,0,3)val*=a[i-k][j+k];
    		ans=max(ans,val);

    		val=1;
    		rep(k,0,3)val*=a[i-k][j-k];
    		ans=max(ans,val);
    	}
    	db1(ans);
    return 0;
}
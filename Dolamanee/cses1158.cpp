// Created by ...
#include <bits/stdc++.h>

#define vll vector< ll >
#define M 100000
#define MD 1000000007
#define pb push_back
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define per(i,a,b) for(ll i = a; i >= b; --i)
#define pii pair<ll,ll> 
#define vec(a) vector<a >
#define all(a) (a).begin(),(a).end()
#define EACH(x, a) for (auto& x:a)
#define se second
#define fi first
#define inf 0xffffffff
//#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
using ll = int;
ll md=MD;

ll exp(ll a,ll b){ll r=1ll;while(b>0){if(b&1){r=r*(a%md);r=(r+md)%md;}b>>=1;a=(a%md)*(a%md);a=(a+md)%md;}return (r+md)%md;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
template<class T> T Min(T a,T b){if(a<b)return a; return b;}
template<class T> T Max(T a,T b){if(a>b)return a; return b;}

int n,x,h[1005],s[1005];

int32_t main() {
    IOS;
        cin>>n>>x;
        vec(vll) dp(n+1,vll(x+1,0));
        rep(i,0,n-1)cin>>h[i];
        rep(i,0,n-1)cin>>s[i];
        rep(i,1,n){
            rep(j,0,x){
                dp[i][j]=dp[i-1][j];
                if(j-h[i-1]>=0)dp[i][j]=Max(dp[i][j],s[i-1]+dp[i-1][j-h[i-1]]);
            }
        }
        cout<<dp[n][x];


        cout<<'\n';
    return 0;
}
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
const int Mx = 1e5+5;
int dp[Mx][101],a[Mx],n,m;

void apply(int i,int j){
    dp[i][j]=dp[i-1][j];
    if(j-1>=1)dp[i][j]+=dp[i-1][j-1];
    if(j+1<=m)dp[i][j]+=dp[i-1][j+1];
    dp[i][j]%=md;
}
int32_t main() {
    IOS;

        cin>>n>>m;
        rep(i,0,n-1)cin>>a[i];

        if(a[0]==0)rep(i,1,m)dp[0][i]=1;
        else dp[0][a[0]]=1;

        rep(i,1,n-1){
            if(a[i]==0)rep(j,1,m)apply(i,j);     
            else apply(i,a[i]);
        }
        int ans=0;
        if(a[n-1]==0)rep(i,1,m)ans=(ans+dp[n-1][i])%md;
        else ans=dp[n-1][a[n-1]];

        cout<<ans;
        cout<<'\n';
    return 0;
}
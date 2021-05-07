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
int dp[505][505];

int solve(int l,int b){
    if(l==b)return 0;
    if(dp[l][b]!=-1)return dp[l][b];
    int ans=1e9;

    rep(i,1,l-1)ans=Min(ans,1+solve(i,b)+solve(l-i,b));
    rep(i,1,b-1)ans=Min(ans,1+solve(l,i)+solve(l,b-i));
    return dp[l][b]=ans;
}
int a,b;
int32_t main() {
    IOS;
        memset(dp,-1,sizeof(dp));
        cin>>a>>b;
        cout<<solve(a,b);
        cout<<'\n';
    return 0;
}
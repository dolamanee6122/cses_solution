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
const int Mx=1e6+5;
int dp[Mx],n;

vll getdigit(int x){
    set<int> ans;
    while(x){
        if(x%10)ans.insert(x%10);
        x/=10;
    }
    vll ret(all(ans));
    return ret;
}
int solve(int x){
    if(x<=0)return 0;
    if(x<10)return 1;
    if(dp[x]!=-1)return dp[x];
    vll v = getdigit(x);
    int ans=1e9;
    EACH(d,v)ans=Min(ans,1+solve(x-d));
    return dp[x]=ans;
}
int32_t main() {
    IOS;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        cout<<solve(n);



        cout<<'\n';
    return 0;
}
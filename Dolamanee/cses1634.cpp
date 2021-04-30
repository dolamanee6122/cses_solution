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
int dp[Mx],n,x,c[100];

int32_t main() {
    IOS;
        cin>>n>>x;
        rep(i,0,n-1)cin>>c[i];
        rep(i,1,x)dp[i]=1e9;
        sort(c,c+n);
        rep(i,0,n-1)dp[c[i]]=1;
        dp[0]=0;
        rep(i,1,x){
            rep(j,0,n-1)if(i-c[j]<0)break;
            else dp[i]=Min(dp[i],1+dp[i-c[j]]);
        }
        if(dp[x]>=1e9)cout<<"-1";
        else cout<<dp[x];



        cout<<'\n';
    return 0;
}
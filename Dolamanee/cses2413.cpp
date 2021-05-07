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
int dp[Mx][8];
int n,t;
vll tran[8];
int solve(int i,int mask){
    if(mask==1 || mask==4)return 0;
    if(i<=0)return (mask==5 || mask==7);
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=0;
    EACH(x,tran[mask])ans=(ans+solve(i-1,x))%md;  
    return dp[i][mask]=ans;

}
int32_t main() {
    IOS;
        memset(dp,-1,sizeof(dp));
        tran[0]={0,5};
        tran[2]=tran[3]=tran[6]={2,3,6,7};
        tran[5]=tran[7]={0,2,3,5,6,7};

        cin>>t;
        while(t--){
            cin>>n;
            cout<<solve(n,5)<<endl;
        }
    return 0;
}
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
        
string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vector<bool> v) {
    string res;
    for(bool x:v)
        res+=char('0'+x);
    return res;
}
template<size_t S> string to_string(bitset<S> b) {
    string res;
    for(auto x:b)
        res+=char('0'+x);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int dp[5005][5005],n,m;
string s,t;

int solve(int i,int j){
    if(i<0 || j<0)return Max(i+1,j+1);
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=1+Min(solve(i-1,j),solve(i,j-1));
    ans=Min(ans,(s[i]!=t[j])+solve(i-1,j-1));
    return dp[i][j]=ans;
}
int32_t main() {
    IOS;
        memset(dp,-1,sizeof(dp));
        cin>>s>>t;
        n=s.size(); m=t.size();
        cout<<solve(n-1,m-1);


        cout<<'\n';
    return 0;
}
// Created by ...
#include <bits/stdc++.h>

#define vll vector< ll >
#define M 200005
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

int bit[M],n,q,v[M],a,b,ans[M];
vec(pii) qi[M];
map<int,int> mp;

void update(int i,int val){
	for(;i<=n;i+=i&-i)
		bit[i]+=val;
}

int query(int i){
	int ans=0;
	for(;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

int32_t main() {
    IOS;

        cin>>n>>q;
        rep(i,0,n-1)cin>>v[i];
        rep(i,0,q-1){
        	cin>>a>>b;
        	qi[b].pb({a,i});
        }
        rep(i,0,n-1){
        	if(mp.find(v[i])!=mp.end())update(mp[v[i]],-1);
        	mp[v[i]]=i+1;
        	update(i+1,1);
        	int r=query(i+1);
        	EACH(x,qi[i+1]){
        		ans[x.se]=r-query(x.fi-1);
        	}
        }
        rep(i,0,q-1)cout<<ans[i]<<"\n";
    return 0;
}
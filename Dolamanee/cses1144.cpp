// Created by ...
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'

#define vll vector< ll >
#define M 200005
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
int tree[6*M],n,q,a[M],b[M][3],cnt=0;
set<int> st;
void update(int p,int val){
    for(tree[p+=cnt]+=val,p>>=1;p>0;p>>=1)tree[p]=tree[p<<1]+tree[p<<1|1];
}

int query(int l,int r){
    int ans=0;
    for(l+=cnt,r+=cnt;l<r;l>>=1,r>>=1){
        if(l&1)ans+=tree[l++];
        if(r&1)ans+=tree[--r];
    }
    return ans;
}

int findId(int x,vll& v){
    return lower_bound(all(v),x)-v.begin();
}
int32_t main() {
    IOS;
        char c;
        int u,v;
        cin>>n>>q;
        rep(i,0,n-1)cin>>a[i],st.insert(a[i]);
        rep(i,0,q-1){
            cin>>c>>b[i][1]>>b[i][2];
            if(c=='!')b[i][0]=0,st.insert(b[i][2]); //update = 0
            else b[i][0]=1,st.insert(b[i][1]),st.insert(b[i][2]); //query = 1
        }
        
        vll vq(st.begin(),st.end());
        sort(vq.begin(),vq.end());
        cnt=st.size();
        rep(i,0,n-1)tree[cnt+findId(a[i],vq)]++;
        for(int i=cnt-1;i>0;--i)tree[i]=tree[i<<1]+tree[i<<1|1];
        rep(i,0,q-1){
            u=b[i][1];
            v=b[i][2];
            if(b[i][0]==0){
                --u;
                int x=findId(a[u],vq);
                update(x,-1);
                a[u]=v;
                x=findId(v,vq);
                update(x,1);
            }
            else{
                u=findId(u,vq); v=findId(v,vq);
                cout<<query(u,v+1)<<"\n";
            }
            
        }
    return 0;
}
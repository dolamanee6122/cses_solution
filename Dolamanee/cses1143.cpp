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
int tree[4*M],a[M],n,m;

void build(int id,int tl,int tr){
    if(tl==tr){
        tree[id]=a[tl];
        return;
    }
    else{
        int tm=(tl+tr)>>1;
        build(id<<1,tl,tm);
        build(id<<1|1,tm+1,tr);
        tree[id]=Max(tree[id<<1],tree[id<<1|1]);
    }
}

void update(int id,int tl,int tr,int pos,int val){
    if(tl==tr){
        tree[id]+=val;
    }
    else{
        int tm=(tl+tr)>>1;
        if(pos<=tm)update(id<<1,tl,tm,pos,val);
        else update(id<<1|1,tm+1,tr,pos,val);

        tree[id]=Max(tree[id<<1],tree[id<<1|1]);
    }
}

int query(int id,int tl,int tr,int val){
    if(tl==tr)return tl;
    int tm=(tl+tr)>>1;

    if(tree[id<<1]>=val)return query(id<<1,tl,tm,val);
    return query(id<<1|1,tm+1,tr,val);
}
int32_t main() {
    IOS;
        cin>>n>>m;

        rep(i,0,n-1)cin>>a[i];

        build(1,0,n-1);
        int r;
        rep(i,0,m-1){
            cin>>r;

            if(tree[1]<r)cout<<"0 ";
            else{
                int id=query(1,0,n-1,r);
                cout<<id+1<<" ";
                update(1,0,n-1,id,-r);
            }
        }

    return 0;
}
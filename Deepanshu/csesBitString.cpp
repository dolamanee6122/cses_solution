#include<bits/stdc++.h>
#include <sstream>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define fo(i,a,b) for(int i = a; i<= b; ++i)
#define ull unsigned long long int
#define ll long long
#define all(a) a.begin(),a.end()
using namespace std;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
ll MD=1000000007;
ll md=MD;
const ll INF=1e18L+5;
ll exp(ll a,ll b){ll r=1ll;while(b>0){if(b&1){r=r*(a%md);r=(r+md)%md;}b/=2;a=(a%md)*(a%md);a=(a+md)%md;}return (r+md)%md;}//put b as bmod(md-1) if md is prime}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll pow_2(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }

    return res;
}
bool isPrime(ll a)
{
    for(ll i=3; (i*i)<=a; i+=2)
    {
        if( (a%i)==0 )
            return false;
    }
    if( ( a!=2 ) && ( (a%2)==0 ) )
        return false;
    if( a==1 )
        return false;

    return true;
}
string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string s="";
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            //cout << "1";
            s=s+"1";
        else
            //cout << "0";
            s=s+"0";
    }
    return s;
}
int decimalToBinary(int N)
{

    // To store the binary number
    ull B_Number = 0;
    int cnt = 0;
    while (N != 0) {
        int rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;

        // Count used to store exponent value
        cnt++;
    }

    return B_Number;
}
string toString(ull num)
{
    std::string number;
    std::stringstream strstream;
    strstream << num;
    strstream >> number;
    return number;
}
const double PI = acos(-1);
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll ans=exp(2,n);
    cout<<ans<<endl;
return 0;}



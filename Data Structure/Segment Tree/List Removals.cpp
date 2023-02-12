//https://cses.fi/problemset/task/1749


#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;

#define pii pair<long long int,long long int>
#define intmax  INT_MAX
#define endl        "\n"
#define READ(x)     freopen(x,"r",stdin)
#define WRITE(x)    freopen(x,"w",stdout)
#define sl(x) scanf("%lld", &x)
#define pl(x) printf("%lld", x)
#define BOOST       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fraction() cout.unsetf(ios::floatfield);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);
// for(auto i:v)
#define mem(a,b)            memset(a,b,sizeof(a))
#define pb                  push_back
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a*b)/(gcd(a,b)))
#define pow(a, b)           (ll)(pow(a,b)+1e-9)
#define vsorti(v)           sort(v.begin(),v.end())
#define vsortd(v)           sort(v.begin(), v.end(), greater<ll>());
#define asorti(a,n)         sort(a+1,a+1+n);
#define asortd(a,n)         sort(a+1,a+1+n, greater<ll>());


#define fo(n)               for(int i=1;i<=n;i++)
#define fo1(n)              for(int i=0;i<n;i++)
#define fov(v)              for(ll i=0;i<v.size();i++)
#define fos(s)              for(int i=0;i<s.size();i++)


using namespace std;


////////////////CODE/////////////////////////////////

const int N=200000+10;
struct Node{
    ll cost, prop;
}tree[N*4];
ll n,q;
ll hoise=0;
ll a[N];
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node].cost=1;
        return;
    }
    ll mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node].cost=tree[node*2].cost+tree[node*2+1].cost;
}

void update(ll node,ll l, ll r,ll i,ll j,ll value)
{
    if(l>j or r<i) return;
    if(l>=i and r<=j)
    {
        tree[node].cost=value;
        return;
    }

    ll mid=(l+r)/2;
    update(node*2,l,mid,i,j,value);
    update(node*2+1,mid+1,r,i,j,value);
    tree[node].cost=tree[node*2].cost+tree[node*2+1].cost;
}

ll query(ll node,ll l,ll r,ll deci)
{
    if(l==r)
    {
        return l;
    }

    ll mid=(l+r)/2;

    if(tree[node*2].cost>=deci)
    {
        return query(node*2,l,mid,deci);
    }
    else
    {
        return query(node*2+1,mid+1,r,deci-tree[node*2].cost);
    }
    
}
void solve()
{
        cin>>n;
        ll x,y,deci,value;
        fo(n)
        {
            cin>>a[i];
        }
        init(1,1,n);
        fo(n)
        {
          cin>>deci;
          x=query(1,1,n,deci);
          cout<<a[x]<<" ";
          update(1,1,n,x,x,0);
        }
}



int main()
{

        //BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
        solve();

        return 0;
}
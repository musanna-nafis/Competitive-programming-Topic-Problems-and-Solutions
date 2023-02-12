//https://cses.fi/problemset/task/1651


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
ll  val[N];
ll n,q;
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node].cost=val[l];
        tree[node].prop=0;
        return;
    }
    ll mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node].cost=tree[node*2].cost+tree[node*2+1].cost;
    tree[node].prop=0;
}


void update(ll node,ll l, ll r,ll i,ll j,ll value)
{
    if(l>j or r<i) return;
    if(l>=i and r<=j)
    {
        tree[node].prop+=value;
        tree[node].cost+=(r-l+1)*value;
        return;
    }

    ll mid=(l+r)/2;
    update(node*2,l,mid,i,j,value);
    update(node*2+1,mid+1,r,i,j,value);
    tree[node].cost=tree[node*2].cost+tree[node*2+1].cost+((r-l)*tree[node].prop);
}

ll query(ll node,ll l,ll r,ll i,ll carry)
{
    if(l==r)
    {
        return tree[node].cost+carry;
    }

    ll mid=(l+r)/2;
    if(i<=mid)
    {
        return query(node*2,l,mid,i,carry+tree[node].prop);
    }
    else
    {
        return query(node*2+1,mid+1,r,i,carry+tree[node].prop);
    }
}
void solve()
{
        cin>>n;
        cin>>q;
        ll x,y,deci,value;
        fo(n)
        {
            cin>>val[i];
        }
        init(1,1,n);
        while(q--)
        {
          cin>>deci;
          if(deci==1)
          {
            cin>>x>>y>>value;
            update(1,1,n,x,y,value);
          }
          else
          {
            cin>>x;
            cout<<query(1,1,n,x,0)<<endl;
          }
        }

}



int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
        solve();

        return 0;
}
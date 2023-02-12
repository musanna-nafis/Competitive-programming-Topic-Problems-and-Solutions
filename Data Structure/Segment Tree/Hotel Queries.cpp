//https://cses.fi/problemset/task/1143


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
#define fo1(n)              for(int i=0;i<=n;i++)
#define fov(v)              for(ll i=0;i<v.size();i++)
#define fos(s)              for(int i=0;i<s.size();i++)


using namespace std;


////////////////CODE/////////////////////////////////

const int N=300000+10;
ll tree[N*4],val[N];
ll n,q;
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node]=val[l];
        return;
    }
    ll mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

ll query(ll node,ll l,ll r,ll value)
{
    
    if(l==r)
    {
        if(val[l]>=value) return l;
        else return 0;
    }
    
    if(tree[node]<value) return 0;
    ll mid=(l+r)/2;
    if(tree[node*2]>=value)
    {
        ll x=query(node*2,l,mid,value);
        return x;
    }
    else
    {
        ll x=query(node*2+1,mid+1,r,value);
        return x;
    }
}

void update(ll node,ll l,ll r,ll posi,ll value)
{
    if(l==r)
    {
        tree[node]-=value;
        return;
    }

    ll mid=(l+r)/2;
    if(posi<=mid)
    {
        update(node*2,l,mid,posi,value);
    }
    else
    {
        update(node*2+1,mid+1,r,posi,value);
    }

    tree[node]=max(tree[2*node],tree[2*node+1]);
}



void solve()
{
        cin>>n>>q;
        ll x,y,deci;
        fo(n)
        {
            cin>>val[i];
        }
        init(1,1,n);
        while(q--)
        {
          cin>>x;
          y=query(1,1,n,x);
          if(y!=0)
          {
            update(1,1,n,y,x);
          }
          cout<<y<<" ";
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
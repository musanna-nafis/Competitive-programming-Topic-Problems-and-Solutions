// https://toph.co/p/dengue-affected-areas


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

const int N=200000;
vector<ll>tree[N*4];
ll n,q;
ll a[N];
ll res1=-1,res2=-1;
ll findlow(vector<ll>v,ll val)
{
    ll m1=-1,mid,first=0,last=v.size()-1;

    while(first<=last)
    {
        mid=first+(last-first)/2;
        if(v[mid]<=val)
        {
            first=mid+1;
            m1=mid;
        }
        else
        {
            last=mid-1;
        }
    }
    return m1;
}
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node].pb(a[l]);
        return;
    }
    ll mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    ll i=0,j=0;
    while(i<tree[node*2].size() and j<tree[node*2+1].size())
    {
        if(tree[node*2][i]<=tree[node*2+1][j])
        {
            tree[node].pb(tree[node*2][i]);
            i++;
        }
        else
        {
            tree[node].pb(tree[node*2+1][j]);
            j++;
        }
    }

    while(i<tree[node*2].size())
    {
        tree[node].pb(tree[node*2][i]);
        i++;
    }
    while(j<tree[node*2+1].size())
    {
        tree[node].pb(tree[node*2+1][j]);
        j++;
    }

    return;
}


ll query(ll node,ll l,ll r,ll i,ll j,ll x,ll y)
{

    if(l>j or r<i) return 0;
    if(l>=i and r<=j)
    {

      if(tree[node][0]>y or x>tree[node][(tree[node].size()-1)])
      {
        return 0;
      }
      else
      {
          ll idx=upper_bound(tree[node].begin(),tree[node].end(),x-1)-tree[node].begin();
          ll idx2=findlow(tree[node],y);
          if(tree[node][idx2]<x or tree[node][idx]>y)
          {
            return 0;
          }
          res1=max(res1,tree[node][idx2]);
          res2=min(res2,tree[node][idx]);
          return (idx2-idx)+1;
      }
    }
    ll mid=(l+r)/2;
    ll xx=query(node*2,l,mid,i,j,x,y);
    ll yy=query(node*2+1,mid+1,r,i,j,x,y);
    return xx+yy;
}
void solve()
{
        cin>>n>>q;
        fo(n)
        {
           cin>>a[i];
        }
        init(1,1,n);
        ll i,j,x,y;
        while(q--)
        {
          res1=-1,res2=10000000000;
          cin>>i>>j>>x>>y;
          cout<<query(1,1,n,i,j,x,y)<<" ";
          if(res2==10000000000)
          {
            cout<<-1<<" ";
          }
          else
          {
            cout<<res2<<" ";
          }
          cout<<res1<<endl;
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
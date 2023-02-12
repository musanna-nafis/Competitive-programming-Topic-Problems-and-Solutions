// https://lightoj.com/problem/diablo

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
//ll a[N];
vector<ll>v;
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node].cost=l;
        tree[node].prop=0;
        return;
    }
    ll mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node].cost=max(tree[node*2].cost,tree[node*2+1].cost);
    tree[node].prop=0;
}

void update(ll node,ll l, ll r,ll i,ll j,ll value)
{

    if(tree[node].prop!=0)
    {
        tree[node].cost-=(tree[node].prop);
        if(l!=r)
        {
            tree[node*2].prop+=tree[node].prop;
            tree[node*2+1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }


    if(l>j or r<i) return;
    if(l>=i and r<=j)
    {
        tree[node].cost-=value;
        if(l!=r)
        {
            tree[node*2].prop+=value;
            tree[node*2+1].prop+=value;
        }
        return;
    }

    ll mid=(l+r)/2;
    update(node*2,l,mid,i,j,value);
    update(node*2+1,mid+1,r,i,j,value);
    tree[node].cost=max(tree[node*2].cost,tree[node*2+1].cost);
}

ll query(ll node,ll l,ll r,ll deci)
{
    if(hoise!=0) return 0;
    if(tree[node].cost<deci) return 0;
    if(tree[node].prop!=0)
    {
        tree[node].cost-=(tree[node].prop);
        if(l!=r)
        {
            tree[node*2].prop+=tree[node].prop;
            tree[node*2+1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    if(tree[node].cost<deci) return 0;
    if(l==r) 
    {
       if(tree[node].cost==deci)
       {
         hoise=1;
         return l;
       }
       else
       {
         return 0;
       }       
    }

    ll mid=(l+r)/2;
    ll xx=query(node*2,l,mid,deci);
    ll yy=query(node*2+1,mid+1,r,deci);
    return xx+yy;
}
void solve(int cas)
{
        cout<<"Case "<<cas<<": "<<endl;
        v.clear();
        cin>>n;
        cin>>q;
        ll cou=n;
        ll range=n+q+10;
        ll x,y,deci,value;
        char cc;
        fo(n)
        {
            cin>>x;
            v.pb(x);
        }
        init(1,1,range);
        fo(q)
        {
          cin>>cc;
          if(cc=='a')
          {
            cin>>deci;
            v.pb(deci);
            cou++;
          }
          else
          {
            cin>>deci;
            if(deci>range or deci>cou)
            {
              cout<<"none"<<endl;
              continue;
            }
            hoise=0;
            x=query(1,1,range,deci);
            cout<<v[x-1]<<endl;
            update(1,1,range,x,range,1);
            cou--;
            
          }
        }
}



int main()
{

    BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
    int tt;
    cin>>tt;
    fo(tt)
    {
       solve(i);
    }

        return 0;
}
// https://codeforces.com/problemset/problem/1234/D


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

const int N=100000+10;
struct Node{
    ll cost;
    ll val[27];
}tree[N*4];
ll n,q;
ll a[27]={0};
string s;
map<char,ll>mp;
void assign()
{
    char aa='a';
    fo(26)
    {
        mp[aa]=i;
        aa=aa+1;
    }
}
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        ll x=mp[s[l]];
        fo(26)
        {
            if(i==x)
            {
                tree[node].val[i]=1;
            }
            else
            {
                tree[node].val[i]=0;
            }
        }
        return;
    }

    ll mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    fo(26)
    {
       tree[node].val[i]=tree[node*2].val[i]+tree[node*2+1].val[i];
    }
}

void update(ll node,ll l, ll r,ll i,ll j,char value)
{

    if(l>j or r<i) return;
    if(l>=i and r<=j)
    {
        ll x=mp[value];
        fo(26)
        {
            if(i==x)
            {
                tree[node].val[i]=1;
            }
            else
            {
                tree[node].val[i]=0;
            }
        }
        return;
    }

    ll mid=(l+r)/2;
    update(node*2,l,mid,i,j,value);
    update(node*2+1,mid+1,r,i,j,value);
    fo(26)
    {
       tree[node].val[i]=tree[node*2].val[i]+tree[node*2+1].val[i];
    }
    
}

void query(ll node,ll l,ll r,ll i, ll j)
{
    
   if(l>j or r<i) return;
   if(l>=i and r<=j)
   {
        fo(26)
        {
            if(a[i]>0) continue;
            if(tree[node].val[i]>0)
            {
                a[i]=1;
            }
            else
            {
                a[i]=0;
            }
        }
        return;
   }

   ll mid=(l+r)>>1;
   query(node*2,l,mid,i,j);
   query(node*2+1,mid+1,r,i,j);
}
void solve()
{
        cin>>s;
        n=s.size()-1;
        cin>>q;
        init(1,0,n);
        char kk;
        ll posi,x,y,deci;
        while(q--)
        {
           cin>>deci;
           if(deci==1)
           {
             cin>>posi>>kk;
             update(1,0,n,posi-1,posi-1,kk);
             
           }
           else
           {
               cin>>x>>y;
               fo(26)
               {
                 a[i]=0;
               }
               query(1,0,n,x-1,y-1);
               ll co=0;
               fo(26)
               {
                 if(a[i]>0) co++;
               }
               cout<<co<<endl;

           }
        }
}



int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
        assign();
        solve();

        return 0;
}
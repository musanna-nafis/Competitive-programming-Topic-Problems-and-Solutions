// https://lightoj.com/problem/one-way-roads

#include<bits/stdc++.h>
typedef long long int   ll;
typedef long double     ld;

#define pii pair<ll,ll>
#define intmax  INT_MAX
#define endl        "\n"
#define Endl        "\n"
#define yes         cout<<"YES"<<endl;
#define no          cout<<"NO"<<endl;
#define READ(x)     freopen(x,"r",stdin)
#define WRITE(x)    freopen(x,"w",stdout)
#define sl(x) scanf("%lld", &x)
#define pl(x) printf("%lld", x)
#define BOOST       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fraction() cout.unsetf(ios::floatfield);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);
// for(auto i:v)
#define ff first
#define ss second
#define mem(a,b)            memset(a,b,sizeof(a))
#define pb                  push_back
#define in                  insert
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a*b)/(gcd(a,b)))
#define pow(a, b)           (ll)(pow(a,b)+1e-9)
#define vsorti(v)           sort(v.begin(),v.end())
#define vsortd(v)           sort(v.begin(), v.end(), greater<ll>());
#define asorti(a,n)         sort(a+1,a+1+n);
#define asortd(a,n)         sort(a+1,a+1+n, greater<ll>());


#define fo(i,aa,n)          for(ll i=aa;i<=n;i++)
#define foo(i,aa,bb)        for(ll i=aa;i>=bb;i--)
#define fov(v)              for(int i=0;i<v.size();i++)
#define fos(s)              for(int i=0;i<s.size();i++)

//Graph direction array[4]
//int dx[]={0,0,-1,1};
//int dy[]={1,-1,0,0};

//Graph direction array[8]
//dx[]={0,0,1,-1,-1,1,1,-1};
//dy[]={1,-1,0,0,-1,-1,1,1};

using namespace std;

/*

bool cmp ( pii A , pii B)
{
   return A.first < B.first;

}
struct structure_name
{

  int u,v,w;
  structure_name(int _u,int _v,int _w)
  {
    u=_u;
    v=_v;
    w=_w;

  }
};
*/
////////////////CODE////////////////////////////////////////////////////////////////////////////////////

const int N=105;
bool visited[N];
vector<ll>adj[N];
ll lagbe1=0,lagbe2=0,n;
map<pii,ll>mp;
void clear()
{
   mp.clear();
   lagbe1=0,lagbe2=0;
   fo(i,1,n)
   {
      visited[i]=false;
      adj[i].clear();
   }
}

void dfs1(ll node,ll parent)
{
   visited[node]=true;
   ll xx=adj[node][0];
   if(node==1)
   {
        if(visited[xx]==false)
        {
            lagbe1+=mp[{node,xx}];
            dfs1(xx,node);
        }
   }
   else
   {
        if(xx==parent)
        {
            xx=adj[node][1];
        }
        if(visited[xx]==false)
        {
            lagbe1+=mp[{node,xx}];
            dfs1(xx,node);
        }
        else if(visited[xx]==true and xx==1)
        {
            lagbe1+=mp[{node,xx}];
        }
   }

}
void dfs2(ll node,ll parent )
{
   visited[node]=true;
   ll xx=adj[node][1];
   if(node==1)
   {
        if(visited[xx]==false)
        {
            lagbe2+=mp[{node,xx}];
            dfs2(xx,node);
        }
   }
   else
   {
        if(xx==parent)
        {
            xx=adj[node][0];
        }
        if(visited[xx]==false)
        {
            lagbe2+=mp[{node,xx}];
            dfs2(xx,node);
        }

        if(xx==1)
        {
            lagbe2+=mp[{node,xx}];
        }
   }
}

void solve(int cas)
{
    ll m,x,y,z,sum=0,total=0,c=0,k;
    string s,t;
    cin>>n;
    clear();
    fo(i,1,n)
    {
        cin>>x>>y>>z;
        mp[{y,x}]=z;
        mp[{x,y}]=0;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(1,1);
    mem(visited,false);
    dfs2(1,1);
    cout<<"Case "<<cas<<": ";
    cout<<min(lagbe1,lagbe2)<<endl;
}


int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
        int ttt;
        cin>>ttt;
        fo(i,1,ttt)
        {
           solve(i);
        }

        return 0;
}


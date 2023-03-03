// https://lightoj.com/problem/min-max-roads

#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;

#define pii pair<long long int,long long int>
#define pii1 pair<char,long long int>
#define intmax  INT_MAX
#define endl        "\n"
#define Endl        "\n"
#define yes         cout<<"YES";
#define no          cout<<"NO";
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


#define fo(i,aa,n)          for(int i=aa;i<=n;i++)
#define foo(i,aa,bb)        for(int i=aa;i>=bb;i--)
#define fo1(n)              for(int i=0;i<n;i++)
#define fov(v)              for(int i=0;i<v.size();i++)
#define fos(s)              for(int i=0;i<s.size();i++)


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
///////////////////////////////////////////////////////////////////CODE///////////////////////////////////////////////////////////////////////////////

struct Edge{
    int v,w;
};
const int N=2e5;
const int lg=log2(N+2);
int T[N][lg+2],Tmin[N][lg+2],Tmax[N][lg+2];
int n;
vector<Edge>adj[N];
int level[N];

void dfs(int node)
{
    for(auto xx:adj[node])
    {
       if(T[xx.v][0]==-1 and xx.v!=1)
       {
         T[xx.v][0]=node;
         Tmin[xx.v][0]=xx.w;
         Tmax[xx.v][0]=xx.w;
         level[xx.v]=level[node]+1;
         dfs(xx.v);
       }
    }
}
void build()
{
    memset(T,-1,sizeof(T));
    memset(Tmax,-1,sizeof(Tmax));
    memset(Tmin,intmax,sizeof(T));
    level[1]=0;
    dfs(1);
    int lg1=log2(n+2);
    fo(j,1,lg1)
    {
        fo(i,1,n)
        {
            int xx=T[i][j-1];
            if(xx!=-1)
            {
                T[i][j]=T[xx][j-1];
                Tmax[i][j]=max(Tmax[xx][j-1],Tmax[i][j-1]); 
                Tmin[i][j]=min(Tmin[xx][j-1],Tmin[i][j-1]); 
            }
        }
    }
}
pii lca(int u, int v)
{
    pii a;

    int maxi=-1;
    int mini=intmax;
    if(level[u]<level[v]) swap(u,v);
    int lg1=log2(level[u]+2);
    for(int i=lg1;i>=0;i--)
    {
       if(T[u][i]!=-1 and (level[u]-(1<<i))>=level[v])
       {
         maxi=max(maxi,Tmax[u][i]);
         mini=min(mini,Tmin[u][i]);
         u=T[u][i];
       }
    }

    if(u==v)
    {
        a.first=maxi;
        a.second=mini;
        return a;
    }

    lg1=log2(n+2);
    for(int i=lg1;i>=0;i--)
    {
        if(T[u][i]!=-1 and T[u][i]!=T[v][i])
        {
            maxi=max(maxi,Tmax[u][i]);
            mini=min(mini,Tmin[u][i]);
            maxi=max(maxi,Tmax[v][i]);
            mini=min(mini,Tmin[v][i]);
            u=T[u][i];
            v=T[v][i];
        }
    }

   maxi=max(maxi,Tmax[u][0]);
   mini=min(mini,Tmin[u][0]);
   maxi=max(maxi,Tmax[v][0]);
   mini=min(mini,Tmin[v][0]);

   a.first=maxi;
   a.second=mini;
   return a;
}
void clear()
{
    fo(i,1,N-4)
    {
        adj[i].clear();
        level[i]=-1;
    }
}
void solve(int cas)
{
    int m,x,q,y,z;
    cin>>n;
    fo(j,1,n-1)
    {
       cin>>x>>y>>z;
       adj[x].pb({y,z});
       adj[y].pb({x,z});
    }
    build();
    cin>>q;
    cout<<"Case "<<cas<<":"<<endl;
    while(q--)
    {
      cin>>x>>y;
      pii b=lca(x,y);
      cout<<b.second<<" "<<b.first<<endl;
    }

}


int main()
{


        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
      
         int tt;
         cin>>tt;
         fo(i,1,tt)
         {
           clear();
           solve(i);
         }

        return 0;
}

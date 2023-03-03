/*
   https://www.spoj.com/problems/LCA/
*/
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

const int N=2e3;
const int lg=log2(N+2);
int T[N][lg+2];
int n;
vector<int>adj[N];
int level[N];
void dfs(int node)
{
    for(auto xx:adj[node])
    {
       if(T[xx][0]==-1 and xx!=1)
       {
         T[xx][0]=node;
         level[xx]=level[node]+1;
         dfs(xx);
       }
    }
}
void build()
{
    memset(T,-1,sizeof(T));
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
            }
        }
    }
}
int lca(int u, int v)
{
    if(u<v) swap(u,v);
    int lg1=log2(level[u]+2);
    for(int i=lg1;i>=0;i--)
    {
       if(T[u][i]!=-1 and (level[u]-(1<<i))>=level[v])
       {
         u=T[u][i];
       }
    }

    if(u==v) return u;

    lg1=log2(n+2);
    for(int i=lg1;i>=0;i--)
    {
        if(T[u][i]!=-1 and T[u][i]!=T[v][i])
        {
            u=T[u][i];
            v=T[v][i];
        }
    }

    return T[u][0];
}
void solve(int cas)
{
    cin>>n;
    int m,x,q,y;
    fo(i,1,n)
    {
      cin>>m;
      fo(j,1,m)
      {
        cin>>x;
        adj[i].pb(x);
        adj[x].pb(i);
      }
    }

    build();
    cin>>q;
    cout<<"Case "<<cas<<":"<<endl;
    while(q--)
    {
      cin>>x>>y;
      cout<<lca(x,y)<<endl;
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
           solve(i);
         }

        return 0;
}
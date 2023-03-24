// https://lightoj.com/problem/greatest-parent


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


////////////////////////////////////////////////////////Code//////////////////////////////////

const int N=1e5+100;
const int lg=log2(N);
ll T[N][lg+4];
vector<ll>adj[N];
ll val[N];
ll n;
void clear()
{
	memset(T,-1,sizeof(T));
	for(int i=1;i<=N-10;i++)
	{
		val[i]=0;
		adj[i].clear();
	}
}
void dfs(ll node)
{
	for(auto xx:adj[node])
	{
		if(T[xx][0]==-1 and xx!=1)
		{
			T[xx][0]=node;
			dfs(xx);
		}
	}
}

void build()
{
	ll lg1=log2(n+2)+2;
	for(int j=1;j<=lg1;j++)
	{
		for(int i=1;i<=n;i++)
		{
			ll xx=T[i][j-1];
			if(xx!=-1)
			{
				T[i][j]=T[xx][j-1];
			}
		}
	}
}

ll query(ll nodenum,ll cost)
{
	for(int i=lg;i>=0;i--)
	{
		if(T[nodenum][i]!=-1 and val[T[nodenum][i]]>=cost)
		{
			nodenum=T[nodenum][i];
		}
	}

	return nodenum;
}

void solve(int cas)
{
   cout<<"Case "<<cas<<":"<<endl;
   ll q,parent,cost,nodenum;
   cin>>n>>q;
   val[1]=1;
   for(int i=2;i<=n;i++)
   {
     cin>>parent>>cost;
     parent++;
     adj[parent].pb(i);
     adj[i].pb(parent);
     val[i]=cost;
   }
   dfs(1);
   build();
   for(int i=1;i<=q;i++)
   {
   	  cin>>nodenum>>cost;
   	  nodenum++;
   	  ll ans=query(nodenum,cost);
   	  cout<<ans-1<<endl;
   }

}
int main()
{
	BOOST;
	ll test;
	cin>>test;
	for(int i=1;i<=test;i++)
	{
		clear();
		solve(i);
	}
}


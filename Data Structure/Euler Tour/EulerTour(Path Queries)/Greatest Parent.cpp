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
bool visited[N];
vector<ll>adj[N];
ll in[N],out[N],val[N],arr[N*2],tree[N*8];
ll tim=1;
ll n;
ll nodenum;
map<ll,ll>mp;
bool hoise=false;
void clear()
{
	mp.clear();
	for(int i=1;i<=N-50;i++)

	{
		adj[i].clear();
		out[i]=-1;
		in[i]=-1;
		val[i]=0;
		visited[i]=0;

	}
}
void dfs(ll node)
{
	visited[node]=1;
	in[node]=tim++;
	mp[tim-1]=node;
	for(auto xx:adj[node])
	{
		if(visited[xx]==0)
		{
			dfs(xx);
		}
	}

	out[node]=tim++;
	mp[tim-1]=node;
}
void build(ll node,ll l,ll r)
{
	if(l==r)
	{
		tree[node]=arr[l];
		return;
	}

	ll mid=(l+r)>>1;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}

ll query(ll node,ll l,ll r,ll i,ll j,ll val)
{
	if(hoise==true) return 0;
	if(l==r)
	{
		ll xx=mp[l];
		if(out[xx]<=in[nodenum+1])
		{
			return 0;
		}
		else
		{
			if(tree[node]>=val)
			{
				hoise=true;
				return mp[l];
			}
			else
			{
				return 0;
			}
		}
	}

	if(r<i or l>j) return 0;
	if(tree[node]<val) return 0;

	ll mid=(l+r)>>1;
	ll res=query(node*2,l,mid,i,j,val)+query(node*2+1,mid+1,r,i,j,val);
	return res;
}
void addval()
{
	val[1]=1;
	for(int i=1;i<=n;i++)
	{
       arr[in[i]]=val[i];
       arr[out[i]]=val[i]*-1;
	}
}
void solve(int cas)
{
   cout<<"Case "<<cas<<":"<<endl;
   ll q,parent,cost;
   cin>>n>>q;
   for(int i=2;i<=n;i++)
   {
     cin>>parent>>cost;
     adj[parent+1].pb(i);
     adj[i].pb(parent+1);
     val[i]=cost;
   }
   tim=1;
   dfs(1);
   addval();
   build(1,1,2*n);
   for(int i=1;i<=q;i++)
   {
   	  cin>>nodenum>>cost;
   	  hoise=false;
   	  ll ans=query(1,1,2*n,in[1],in[nodenum+1],cost);
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


//https://cses.fi/problemset/task/1193/
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
const int N=1e3+10;
char a[N][N];
bool visited[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int r,c;
map<pii,pii>mp;
void bfs(int xx,int yy)
{
    queue<pii>q;
    q.push({xx,yy});
    visited[xx][yy]=true;
    while(!q.empty())
    {
        int x=q.front().ff;
        int y=q.front().ss;
        q.pop();
        fo(i,0,3)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=1 and newx<=r and newy>=1 and newy<=c and visited[newx][newy]==false and a[newx][newy]!='#')
            {
                mp[{newx,newy}]={x,y};
                visited[newx][newy]=true;
                q.push({newx,newy});
            }
        }
 
    }
}
 
void solve()
{
    ll n,m,x,y,z,sum=0,total=0,k,x1,y1;
    string s,t;
    cin>>r>>c;
    fo(i,1,r)
    {
        fo(j,1,c)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
            {
                x=i,y=j;
            }
            else if(a[i][j]=='B')
            {
                x1=i,y1=j;
            }
        }
    }
    mp[{x,y}]={x,y};
    bfs(x,y);
    if(visited[x1][y1]==false)
    {
       no;
       return;
    }
    yes;
    int currx=x1;
    int curry=y1;
    vector<char>v;
    while(1)
    {
        x1=mp[{currx,curry}].ff;
        y1=mp[{currx,curry}].ss;
        if(x1==currx and y1==curry)
        {
            break;
        }
        if(x1+1==currx)
        {
            v.pb('D');
        }
        else if(x1-1==currx)
        {
            v.pb('U');
        }
        else if(y1+1==curry)
        {
            v.pb('R');
        }
        else if(y1-1==curry)
        {
            v.pb('L');
        }
        currx=x1;
        curry=y1;
    }
    cout<<v.size()<<endl;
    reverse(v.begin(),v.end());
    fov(v)
    {
        cout<<v[i];
    }
 
}
 
 
int main()
{
 
        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
        int ttt=1;
        //cin>>ttt;
        fo(i,1,ttt)
        {
           solve();
        }
 
        return 0;
}
// https://lightoj.com/problem/power-puff-girls
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
const int N=22;
char a[N][N];
bool visited[N][N];
int timer[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
ll r,c,first=-1,second=-1,third=-1;
void bfs(int x1,int y1)
{
    queue<pii>q;
    q.push({x1,y1});
    visited[x1][y1]=true;
    timer[x1][y1]=0;
    while(!q.empty())
    {
        int x=q.front().ff;
        int y=q.front().ss;
        q.pop();
        fo(i,0,3)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=1 and newx<=r and newy>=1 and newy<=c and visited[newx][newy]==false and a[newx][newy]!='#' and a[newx][newy]!='m')
            {
                q.push({newx,newy});
                timer[newx][newy]=timer[x][y]+1;
                visited[newx][newy]=true;
            }
        }
    }
}
void solve(int cas)
{
    int n,m,x,y,z,x1,y1,z1,homex,homey;
    string s,t;
    cin>>r>>c;
    fo(i,1,r)
    {
        fo(j,1,c)
        {
            cin>>a[i][j];
            if(a[i][j]=='a')
            {
               x=i,x1=j;
            }
            else if(a[i][j]=='b')
            {
                y=i,y1=j;
            }
            else if(a[i][j]=='c')
            {
                z=i,z1=j;
            }
            else if(a[i][j]=='h')
            {
                homex=i;
                homey=j;
            }
        }
    }
    mem(visited,false);
    mem(timer,-1);
    bfs(x,x1);
    first=timer[homex][homey];


    mem(visited,false);
    mem(timer,-1);
    bfs(y,y1);
    second=timer[homex][homey];

    mem(visited,false);
    mem(timer,-1);
    bfs(z,z1);
    third=timer[homex][homey];

    ll ans=max(first,max(second,third));
    cout<<"Case "<<cas<<": ";
    if(first==-1 or second==-1 or third==-1)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
   
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


//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
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
int a[N][N];
bool visited[N][N];
int level[N][N];
int r,c;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void clear()
{
    fo(i,1,r)
    {
        fo(j,1,c)
        {
            visited[i][j]=false;
            a[i][j]=0;
            level[i][j]=-1;
        }
    }
}

void bfs(int x,int y)
{
    queue<pii>q;
    q.push({x,y});
    visited[x][y]=true;
    level[x][y]=0;
    while(!q.empty())
    {
        int xx=q.front().ff;
        int yy=q.front().ss;
        q.pop();
        fo(i,0,3)
        {
            int newx=xx+dx[i];
            int newy=yy+dy[i];
            if(newx>=1 and newx<=r and newy>=1 and newy<=c and visited[newx][newy]==false and a[newx][newy]==0)
            {
                level[newx][newy]=level[xx][yy]+1;
                q.push({newx,newy});
                visited[newx][newy]=true;
            }
        }
    }
}

void solve()
{
    int n,m,x,y,z,sum=0,total=0,c=0,k;
    string s,t;
    cin>>n;
    fo(i,1,n)
    {
        cin>>x>>y;
        fo(j,1,y)
        {
            cin>>z;
            a[x+1][z+1]=1;
        }
    }
    int startx,starty,destix,destiy;
    cin>>startx>>starty>>destix>>destiy;
    bfs(startx+1,starty+1);
    cout<<level[destix+1][destiy+1]<<endl;
}


int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
        //int ttt;
        //cin>>ttt;
        //fo(i,1,ttt)
        while(cin>>r>>c)
        {
           if(r==0 and c==0)
           {
             break;
           }
           solve();
           clear();
        }

        return 0;
}


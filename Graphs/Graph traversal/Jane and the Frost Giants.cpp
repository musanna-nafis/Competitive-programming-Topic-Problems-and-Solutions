//https://lightoj.com/problem/jane-and-the-frost-giants

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
const int N=205;
char a[N][N];
bool visited[N][N];
bool visited1[N][N];
int timer[N][N],timer1[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int r,c,curr=0;
queue<pii>q;
void clear()
{
    fo(i,1,r+1)
    {
        fo(j,1,c+1)
        {
            visited[i][j]=false;
            visited1[i][j]=false;
            timer[i][j]=-1;
            timer1[i][j]=-1;
        }
    }
}

void bfsforfire()
{
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
                q.push({newx,newy});
                visited[newx][newy]=true;
                timer[newx][newy]=timer[x][y]+1;
            }
        }

    }
}
void bfs(int xx,int yy)
{
    queue<pii>qq;
    qq.push({xx,yy});
    timer1[xx][yy]=1;
    visited1[xx][yy]=true;
    while(!qq.empty())
    {
        int x=qq.front().ff;
        int y=qq.front().ss;
        qq.pop();
        fo(i,0,3)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=1 and newx<=r and newy>=1 and newy<=c and visited1[newx][newy]==false and a[newx][newy]!='#')
            {
                if(visited[newx][newy]==false or (visited[newx][newy]==true and timer[newx][newy]>timer1[x][y]+1))
                {
                    qq.push({newx,newy});
                    visited1[newx][newy]=true;
                    timer1[newx][newy]=timer1[x][y]+1;
                }
            }
        }

    }

}

void solve(int cas)
{
    int x,y,total=1e9;
    string s,t;
    cin>>r>>c;
    clear();
    fo(i,1,r)
    {
        fo(j,1,c)
        {
            cin>>a[i][j];
            if(a[i][j]=='F')
            {
                q.push({i,j});
                timer[i][j]=1;
                visited[i][j]=true;
            }
            if(a[i][j]=='J')
            {
                x=i;
                y=j;
            }
        }
    }
    bfsforfire();
    bfs(x,y);
    fo(i,1,r)
    {
        fo(j,1,c)
        {
            if(i==1 or i==r or j==1 or j==c)
            {
                if(visited1[i][j]==true)
                {
                    total=min(total,timer1[i][j]);
                }
            }
        }
    }
    cout<<"Case "<<cas<<": ";
    if(total==1e9)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        cout<<total;
    }


    cout<<endl;
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


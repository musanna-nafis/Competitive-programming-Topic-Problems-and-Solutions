//https://lightoj.com/problem/gathering-food
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
const int N=15;
char a[N][N];
bool visited[N][N];
int timer[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n;
char curr;
void clear()
{
   fo(i,1,n+1)
   {
     fo(j,1,n+1)
     {
        visited[i][j]=false;
        timer[i][j]=-1;
     }
   }
}
void bfs(int xx,int yy)
{
    queue<pii>q;
    q.push({xx,yy});
    visited[xx][yy]=true;
    timer[xx][yy]=0;
    while(!q.empty())
    {
        int x=q.front().ff;
        int y=q.front().ss;
        q.pop();
        fo(i,0,3)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            char okk=curr+1;
            if(newx>=1 and newx<=n and newy>=1 and newy<=n and visited[newx][newy]==false and a[newx][newy]!='#' and (a[newx][newy]=='.' or a[newx][newy]<=okk))
            {
               visited[newx][newy]=true;
               timer[newx][newy]=timer[x][y]+1;
               q.push({newx,newy});
            }
        } 
    }
}

void solve(int cas)
{
    int m,x,y,z,sum=0,total=0,c=0,k,z1;
    string s,t;
    cin>>n;
    map<char,pii>mp;
    fo(i,1,n)
    {
        fo(j,1,n)
        {
            cin>>a[i][j];
            if(a[i][j]!='.' and a[i][j]!='#')
            {
                c++;
                mp[a[i][j]]={i,j};
            }
        }
    }
    cout<<"Case "<<cas<<": ";
    char aa='A';
    fo(i,1,c-1)
    {
        x=mp[aa].ff;
        y=mp[aa].ss;
        curr=aa;
        bfs(x,y);
        z=mp[curr+1].ff;
        z1=mp[curr+1].ss;
        if(visited[z][z1]==true)
        {
            total+=timer[z][z1];
        }
        else
        {
            cout<<"Impossible"<<endl;
            clear();
            return;
        }
        clear();
        aa=aa+1;
    }

    cout<<total<<endl;
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


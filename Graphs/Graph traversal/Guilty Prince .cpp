/// https://lightoj.com/problem/guilty-prince

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
const int N=23;
bool visited[N][N];
char a[N][N];
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll c=0,w,h;
void clear()
{
   c=0;
   fo(i,1,N-1)
   {
     fo(j,1,N-1)
     {
        visited[i][j]=false;
     }
   }
}
void dfs(ll x,ll y)
{
    visited[x][y]=true;
    c++;
    fo(i,0,3)
    {
        ll newx=x+dx[i];
        ll newy=y+dy[i];
        if(newx>=1 and newx<=w and newy>=1 and newy<=h and a[newx][newy]=='.' and visited[newx][newy]==false)
        {
            dfs(newx,newy);
        }
    }
}

void solve(int cas)
{
    ll n,m,x,y,z,sum=0,total=0,k;
    string s,t;
    cin>>h>>w;
    fo(i,1,w)
    {
        fo(j,1,h)
        {
            cin>>a[i][j];
            if(a[i][j]=='@')
            {
                x=i,y=j;
            }
        }
    }
    dfs(x,y);

    

    cout<<"Case "<<cas<<": "<<c<<endl;
    
    
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
           clear();
        }

        return 0;
}


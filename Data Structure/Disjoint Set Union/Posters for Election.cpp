
// https://lightoj.com/problem/posters-for-election


#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;

#define pii pair<long long int,long long int>
#define pii1 pair<char,long long int>
#define intmax  INT_MAX
#define endl        "\n"
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


#define fo(n)               for(int i=1;i<=n;i++)
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
//////////////////////////////////////////////////////////////////CODE/////////////////////////////////////////////////////////////////////////////////


const int N = 1e6;
int parent[N];
void init()
{
    fo(N-3)
    {
       parent[i]=i;
    }
}

ll find(ll v)
{
    if(v>N) return v;
    if(parent[v]==v) return v;

    return  parent[v]=find(parent[v]);
}

void Union(ll u, ll v)
{
    u=find(u);
    v=find(v);
    parent[u]=v;
}

void solve(int cas)
{
    cout<<"Case "<<cas<<": ";
    int n,a,b,x,y,tota=0;
    cin>>n;
    int suru=(2*n)+10;
    vector<pair<int,int>>v;
    map<int,int>mp;
    fo(n)
    {
        cin>>a>>b;
        v.pb({a,b});
    }
    int j,c;
    reverse(v.begin(),v.end());
    fov(v)
    {
        x=v[i].first;
        y=v[i].second;
        c=0;
        j=x;
        while(j<=y)
        {
            if(j>y) break;

            if(parent[j]!=j)
            {
                j=mp[j]+1;
            }
            else{
                mp[j]=max(mp[j],y);
                parent[j]=suru;
                c++;
                j++;
            }

        }
        mp[x]=max(mp[x],y);
         if(c!=0)
        {
            suru++;
            tota++;
        }
    }

    cout<<tota<<endl;


}


int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
       int tt;
       cin>>tt;
       fo(tt)
       {
           init();
           solve(i);
       }

        return 0;
}

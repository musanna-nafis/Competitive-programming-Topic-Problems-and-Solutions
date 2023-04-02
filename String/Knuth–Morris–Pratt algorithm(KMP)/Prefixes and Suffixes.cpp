// https://codeforces.com/problemset/problem/432/D

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


#define fo(i,aa,n)          for(ll i=aa;i<=n;i++)
#define foo(i,aa,bb)        for(ll i=aa;i>=bb;i--)
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
const int N=2e5+12;
int failure[N],cou[N];
int n;
string s;
void findFailureFun()
{
    failure[1]=0;
    for(int i=2;i<=n;i++)
    {
        int j=failure[i-1];
        while(true)
        {
            if(s[j]==s[i-1])
            {
                failure[i]=j+1;
                break;
            }

            if(j==0)
            {
               failure[i]=0;
               break; 
            }
            else
            {
                j=failure[j];
            }
        }
    }
}

void solve()
{

    cin>>s;
    int mainlength=s.size();
    string t=s;
    s=t+'#';
    s=s+t;
    n=s.size();
    findFailureFun();
    vector<int>v;
    int x=failure[n];
    while(x!=0)
    {
        v.pb(x);
        x=failure[x];
    }
    sort(v.begin(),v.end());
    for(int i=mainlength+2;i<=n;i++)
    {
        cou[failure[i]]++;
    }
    for(int i=mainlength;i>=1;i--)
    {
        cou[failure[i]]+=cou[i];

    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" "<<cou[v[i]]<<endl;
    }


    //cout<<endl;

    

}


int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
         int tt=1;
         //cin>>tt;
         fo(i,1,tt)
         {
           solve();
         }

        return 0;
}
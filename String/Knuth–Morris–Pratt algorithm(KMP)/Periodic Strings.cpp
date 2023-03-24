// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=396



#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;

#define pii pair<long long int,long long int>
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
#define fov(v)              for(int i=0;i<v.size();i++)
#define fos(s)              for(int i=0;i<s.size();i++)


using namespace std;


////////////////CODE/////////////////////////////////
const int N=100;
int failure[N+12];
string s;
int n;
void buildFailureFun()
{
    failure[0]=0;
    failure[1]=0;
    for(int i=2;i<=n;i++)
    {
        int j=failure[i-1];
        while(1)
        {
            if(s[j]==s[i-1])
            {
                failure[i]=j+1;
                break;
            }
            else
            {
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
}

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>s;
        n=s.size();
        buildFailureFun();
        int ans=n-failure[n];
        if(n%(ans))
        {
            printf("%d\n", n);
        }
        else 
        {
            printf("%d\n", ans);
        }
        if(T)
        {
            puts("");
        }

    }
}


int main()
{

        //BOOST;
       //READ("in.txt");
       //WRITE("out.txt");


        solve();

        return 0;
}


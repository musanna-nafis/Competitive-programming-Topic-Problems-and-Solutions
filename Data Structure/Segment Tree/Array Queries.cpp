//https://lightoj.com/problem/array-queries


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
// for(auto i:v)
#define MAX_LIMIT 1000000
#define mem(a,b)        memset(a,b,sizeof(a))
#define pb              push_back
#define gcd(a, b)       __gcd(a, b)
#define vsorti(v)         sort(v.begin(),v.end())
#define vsortd(v)         sort(v.begin(), v.end(), greater<int>());
using namespace std;

ll a[100002];
ll tree[300006+1];
void init(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node] = a[b];
        return;
    }
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left] , tree[Right]);
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (i > e || j < b)
        return 10000002;
    if (b >= i && e <= j)
        return tree[node];
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return min(p1,p2);
}
/*

ll my1=-1,my2=-1;

void mybinary(ll last,ll total)
{
    ll first=1;
      while(last>=first)
      {

           ll mid=(first)+((last-first)/ 2);

           ll op=(mid*(mid-1));
           if(op<total)
           {
              // my1=mid;
               first=mid+1;
           }
           else if(op>=total)
           {

               last=mid-1;
               my1=mid;
           }


       }
}



*/





int main()
{

BOOST;
       //READ("in.txt");
       //WRITE("out.txt");

       ll q,c=0;
       cin>>q;
       while(q--)
       {
           c++;
           ll d,n,i,sum=0,j,total=0,x,k,y,z,m;
           cin>>n>>m;
           for(i=1;i<=n;i++)
           {
               cin>>a[i];
           }
           init(1,1,n);
            cout<<"Case "<<c<<":"<<" "<<endl;
           for(i=1;i<=m;i++)
           {
               cin>>x>>y;
              cout<<query(1,1,n,x,y)<<endl;


           }






       }

    return 0;
}

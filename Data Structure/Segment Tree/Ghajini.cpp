// https://lightoj.com/problem/ghajini


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

ll a[100009];
ll tree[300009];
ll tree1[300009];
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
    tree[node] = max(tree[Left] , tree[Right]);
}
void bnit(ll node, ll b, ll e)
{
    if (b == e) {
        tree1[node] = a[b];
        return;
    }
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    bnit(Left, b, mid);
    bnit(Right, mid + 1, e);
    tree1[node] = min(tree1[Left] , tree1[Right]);
}
ll maxquery(ll node, ll b, ll e, ll i, ll j)
{
    if (i > e || j < b)
        return -1;
    if (b >= i && e <= j)
        return tree[node];
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    ll p1 = maxquery(Left, b, mid, i, j);
    ll p2 = maxquery(Right, mid + 1, e, i, j);
    return max(p1,p2);
}
ll minquery(ll node, ll b, ll e, ll i, ll j)
{
    if (i > e || j < b)
        return 1000000000;
    if (b >= i && e <= j)
        return tree1[node];
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    ll p1 = minquery(Left, b, mid, i, j);
    ll p2 = minquery(Right, mid + 1, e, i, j);
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
           ll d,n,i,sum=0,j,total=-1,x,k,y,z,m;
           cin>>n>>d;
           for(i=1;i<=n;i++)
           {
               cin>>a[i];
           }
           init(1,1,n);
           bnit(1,1,n);
           x=(n-d)+1;
           cout<<"Case "<<c<<":"<<" ";


           for(i=1;i<=x;i++)
           {

              y=maxquery(1,1,n,i,i+d-1);
              z=minquery(1,1,n,i,i+d-1);
              total=max(total,y-z);


           }


           cout<<total<<endl;



       }

    return 0;
}

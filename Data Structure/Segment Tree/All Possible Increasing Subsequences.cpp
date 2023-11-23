//https://lightoj.com/problem/all-possible-inc-subseq
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=2e5;
const int mod=1e9+7;
ll tree[N*4];
vector<pair<ll,ll>>arr;
ll n;
bool cmp(pair<ll,ll> aa,pair<ll,ll>bb)
{
    if(aa.first!=bb.first) return aa.first<bb.first;
    return aa.second>bb.second;
}
void update(ll node,ll l,ll r,ll i,ll val)
{
    if(l==r and i==l)
    {
        tree[node]=val;
        return;
    }
    ll mid=(l+r)/2;
    if(i>=l and i<=mid)
    {
        update(node*2,l,mid,i,val);
    }
    if(i>=mid+1 and i<=r)
    {
        update(node*2+1,mid+1,r,i,val);
    }
    tree[node]=((tree[node*2]%mod)+(tree[node*2+1]%mod))%mod;
}
ll query(ll node,ll l,ll r,ll i,ll j)
{
    if(r<i or l>j) return 0;
    if(l>=i and r<=j) return tree[node]%mod;
    ll mid=(l+r)/2;
    ll xx=query(node*2,l,mid,i,j);
    ll yy=query(node*2+1,mid+1,r,i,j);
    return ((xx%mod)+(yy%mod))%mod;
}
void solve(int caseno)
{
   
    cin>>n;
    ll x;
    arr.clear();
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      arr.push_back({x,i});
    }
    sort(arr.begin(),arr.end(),cmp);
    memset(tree,0,sizeof(tree));
    for(int i=0;i<n;i++)
    {
        x=arr[i].second;
        if(x!=1)
        {
           ll cou=query(1,1,n,1,x-1);
           update(1,1,n,x,cou+1);
        }
        else
        {
            update(1,1,n,x,1);
        }
    }

    cout<<"Case "<<caseno<<": ";
    cout<<query(1,1,n,1,n)<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ttt;
    cin>>ttt;
    for(int i=1;i<=ttt;i++)
    {
        solve(i);
    }

    return 0;
}
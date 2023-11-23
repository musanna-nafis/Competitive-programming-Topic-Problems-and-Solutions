//https://lightoj.com/problem/histogram

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N=3e4+10;
ll tree[3*N];
ll a[N];
ll n;
ll idx=-1;
void init(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
ll query(int node,int l,int r,int i,int j)
{
    if(l>=i and r<=j)
    {
        return tree[node];
    }
    if(r<i or l>j)
    {
       return 1e12;
    }
    int mid=(l+r)/2;
    ll xx=query(node*2,l,mid,i,j);
    ll yy=query(node*2+1,mid+1,r,i,j);
    return min(xx,yy);
}
void query1(int node,int l,int r,int i, int j,ll val)
{
    if(idx!=-1) return;
    if(r<i or l>j)
    {
        return;
    }
    if(l==r)
    {
        if(tree[node]==val)
        {
            idx=l;
        }
        return;
    }
    int mid=(l+r)/2;
    ll ans=n+100;
    if(tree[node*2]<=val)
    {
        query1(node*2,l,mid,i,j,val);
    }
    if(tree[node*2+1]<=val)
    {
        query1(node*2+1,mid+1,r,i,j,val);
    }
}
ll find(int l,int r)
{
    if(l==r)
    {
        return a[l];
    }
    ll mini=query(1,1,n,l,r);
    ll ans=((r-l)+1)*mini;
    idx=-1;
    query1(1,1,n,l,r,mini);
    ll aaa=idx;
    if(aaa==l)
    {
      ans=max(ans,find(aaa+1,r));
    }
    else if(aaa==r)
    {
      ans=max(ans,find(l,aaa-1));
    }
    else
    {
      ans=max(ans,find(l,aaa-1));
      ans=max(ans,find(aaa+1,r));
    }
    return ans;
}
void solve(int caseno)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    init(1,1,n);
    cout<<"Case "<<caseno<<": ";
    cout<<find(1,n)<<"\n";
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
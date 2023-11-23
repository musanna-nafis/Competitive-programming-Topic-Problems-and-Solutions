//https://lightoj.com/problem/lucky-number

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=2e6+10;
ll ans[100009];
ll tree[N*4];
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        if(l%2) tree[node]=1;
        return;
    }
    ll mid=(l+r)>>1;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void update(ll node,ll l,ll r,ll val)
{
    if(l==r)
    {
        tree[node]=0;
        return;
    }
    ll mid=(l+r)>>1;
    if(tree[node*2]>=val) update(node*2,l,mid,val);
    else update(node*2+1,mid+1,r,val-tree[node*2]);
    tree[node]=tree[node*2]+tree[node*2+1];
}
ll query(ll node,ll l,ll r,ll val)
{
    if(l==r)
    {
        return l;
    }
    ll mid=(l+r)>>1;
    if(tree[node*2]>=val) return query(node*2,l,mid,val);
    else return query(node*2+1,mid+1,r,val-tree[node*2]);
}
void generate()
{
    init(1,1,2e6);
    ans[1]=1;
    for(int i=2;i<=1e5;i++)
    {
        ll idx=query(1,1,2e6,i);
        ans[i]=idx;
        ll c=0;
        for(int j=idx;j<=2e6;j+=idx)
        {
            update(1,1,2e6,j-c++);
        }
    }
}
void solve(int caseno)
{
    ll idx;
    cin>>idx;
    cout<<"Case "<<caseno<<": "<<ans[idx]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    generate();
    for(int i=1;i<=test;i++)
    {
        solve(i);
    }
    return 0;
}
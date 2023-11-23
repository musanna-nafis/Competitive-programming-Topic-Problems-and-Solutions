//https://lightoj.com/problem/points-in-segments-ii

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=5e4+100;
struct Node
{
   int cost,prop;
}tree[N*4];
int arr[N],arra[N],brr[N],crr[N];
int n,q;
void update(int node,int l,int r,int i,int j)
{
    if(tree[node].prop!=0)
    {
        tree[node].cost+=tree[node].prop;
        if(l!=r)
        {
            tree[node*2].prop+=tree[node].prop;
            tree[node*2+1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    if(r<i or l>j) return;
    if(l>=i and r<=j)
    {
        tree[node].cost+=1;
        if(l!=r)
        {
            tree[node*2].prop+=1;
            tree[node*2+1].prop+=1;
        }
        return;
    }
    int mid=(l+r)>>1;
    update(node*2,l,mid,i,j);
    update(node*2+1,mid+1,r,i,j);
    tree[node].cost=tree[node*2].cost+tree[node*2+1].cost;
}
ll query(int node,int l,int r,int i)
{
    if(tree[node].prop!=0)
    {
        tree[node].cost+=tree[node].prop;
        if(l!=r)
        {
            tree[node*2].prop+=tree[node].prop;
            tree[node*2+1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    if(i<l or i>r) return 0;
    if(l==r and i==l) return tree[node].cost;
    int mid=(l+r)>>1;
    int xx=query(node*2,l,mid,i);
    int yy=query(node*2+1,mid+1,r,i);
    return xx+yy;

}
void solve(int caseno)
{
    memset(tree,0,sizeof(tree));
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i]>>crr[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>arr[i];
        arra[i]=arr[i];
    }
    sort(arr+1,arr+1+q);
    int l,r,first,mid,x,y,last;
    for(int i=1;i<=n;i++)
    {
       first=1;
       last=q;
       l=q+1;
       r=-1;
       while(first<=last)
       {
          mid=first+(last-first)/2;
          if(arr[mid]>=brr[i])
          {
            l=mid;
            last=mid-1;
          }
          else
          {
            first=mid+1;
          }
       }
       first=1;
       last=q;
       while(first<=last)
       {
          mid=first+(last-first)/2;
          if(arr[mid]<=crr[i])
          {
             r=mid;
             first=mid+1;
          }
          else
          {
            last=mid-1;
          }

       }

       if(l<=r and l<=q)
       {
          update(1,1,q,l,r);
       }
    }
    cout<<"Case "<<caseno<<":\n";

    for(int i=1;i<=q;i++)
    {
        x=-1;
        first=1;
        last=q;
        while(first<=last)
        {
            mid=first+(last-first)/2;
            if(arr[mid]==arra[i])
            {
              x=mid;
              break;
            }
            else if(arr[mid]<arra[i])
            {
                first=mid+1;
            }
            else
            {
                last=mid-1;
            }
        }
        cout<<query(1,1,q,x)<<"\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        solve(i);
    }
    return 0;
}
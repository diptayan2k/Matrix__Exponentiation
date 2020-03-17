#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizof(arr))
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll neginf=-100000000000000000;
ll mod=1000000007;
ll temp[2][2]={{2,2},{1,0}};
ll mat[2][2]={{2,2},{1,0}};
ll x[2][2]={{2,2},{1,0}};

void multiply(ll a[2][2], ll b[2][2])
{
    temp[0][0]=((a[0][0]%mod*b[0][0]%mod)%mod+(a[0][1]%mod*b[1][0]%mod)%mod)%mod;
    temp[0][1]=((a[0][0]%mod*b[0][1]%mod)%mod+(a[0][1]%mod*b[1][1]%mod)%mod)%mod;
    temp[1][0]=((a[1][0]%mod*b[0][0]%mod)%mod+(a[1][1]%mod*b[1][0]%mod)%mod)%mod;
    temp[1][1]=((a[1][0]%mod*b[0][1]%mod)%mod+(a[1][1]%mod*b[1][1]%mod)%mod)%mod;

    f(i,0,1) f(j,0,1) a[i][j]=temp[i][j]%mod;
}


void power(ll a[2][2], ll n)
{
    if (n==1)
        return;

    power(a, n/2);
    multiply(a, a);

    if (n%2 != 0)
        multiply(a, mat);
}


void solve(ll t)
{
     f(i,0,1)
     {
         f(j,0,1)
         {
             temp[i][j]=mat[i][j];
             x[i][j]=mat[i][j];
         }
     }
    ll n;
    cin>>n;
    power(x,n-1);
    cout<<(x[0][0]%mod*2+x[0][1]%mod)%mod<<endl;

}

int main()
{
    ll t=1;

    cin>>t;
    f(i,1,t)
    {
        solve(i);
    }

}

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =3e5+1;
ll n,m;
ll big_mod(ll x,ll y,ll mod)
{
    ll ans=1;
    while(y)
    {
        if((y&1))
        {
            ans*=x;
            ans%=mod;
        }
        x*=x;
        x%=mod;
        y>>=1;
    }return ans;
}
vector<ll>fact(N),inv(N);
ll nCr(ll x,ll y)
{
    if(x<y){swap(x,y);}
    ll ans=fact[x];
    ans*=inv[y];
    ans%=M;
    ans*=inv[x-y];
    ans%=M;
    return ans;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    for(i=1;i<N;i++)
    {
        j=(j*i)%M;
        fact[i]=j;
        inv[i]=big_mod(j,M-2,M);
    }
    fact[0]=inv[0]=1;
    
    while(tc--)
    {
        //Erase the 58 to 66th line and start coding.
        cout<<"This is the pascals triangle"<<endl;
        for(i=0;i<=20;i++)
        {
            for(j=0;j<=i;j++)
            {
                cout<<nCr(i,j)<<" ";
            }cout<<endl;
        }
    }
}


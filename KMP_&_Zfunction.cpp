#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//uniform_int_distribution<int> random(1, 1000000);
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e16
const ll M =1e9+7;
const ll N =4e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<int>prefix_function(string &s)
{
    int i,j,k,n= s.size();
    vector<int>pi(n);
    for(i=1;i<n;i++)
    {
        j=pi[i-1];
        while(j && s[i]!=s[j])
        {
            j=pi[j-1];
        }
        if(s[i]==s[j]){j++;}
        pi[i]=j;
    }
    return pi;
}
vector<ll> z_function(string s)
{
    ll sz=s.size();
    vector<ll>z(sz);
    ll l=0,r=0,i;
    for(i=1;i<sz;i++)
    {
        if(i<r){z[i]=min(r-i,z[i-l]);}
        while(i+z[i]<sz && s[z[i]]==s[i+z[i]]){z[i]++;}
        if(i+z[i]>r)
        {
            l=i;
            r=i+z[i];
        }
    }return z;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        string s;cin>>s;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl '\n'
const ll N = 1e6+1;
ll n,m,id=0;
vector<ll>g[N],rg[N],vis(N),in_scc(N),answer(N,-1);
stack<ll>stk;
/*
>>Kosaraju's alogorithm's first part
>>Pushes nodes into stack according to dfs leaving(completion) order
*/
void dfs(ll cur)
{
    vis[cur]=1;
    for(auto chi:g[cur])
    {
        if(vis[chi]){continue;}
        dfs(chi);
    }stk.push(cur);
}
/*
>>Kosaraju's algorithm second(final) part
>>Runs dfs on reversed graph and stores all node on this single sccZ
*/
void scc_detector(ll cur, vector<ll>&v)
{
    in_scc[cur]=id;
    v.pb(cur);
    for(auto chi:rg[cur])
    {
        if(in_scc[chi]){continue;}
        scc_detector(chi,v);
    }
}
/*
>>Returns the value position of -1 for 1 and 1 for -1
*/
ll rev(ll x)
{
    if(x>m){x-=m;}
    else{x+=m;}
    return x;
}
int32_t main()
{
    fast
    ll i,j=1,k,p,q,tc=1,cs=0;
    //cin>>tc;
    while(tc--)
    {
       cin>>n>>m;
       j=n;
       //Building the implication graph. And reverse implication graph
       while(j--)
       {
           char a,b;ll x,y;
           cin>>a>>x>>b>>y;
           if(a=='-'){x+=m;}
           if(b=='-'){y+=m;}
           g[rev(x)].pb(y);
           rg[y].pb(rev(x));
           g[rev(y)].pb(x);
           rg[x].pb(rev(y));
       }
       //Kosaraju
       for(i=1;i<=2*m;i++)
       {
           if(!vis[i]){dfs(i);}
       }
       ll impossible=0;
       while(stk.size())
       {
           ll t=stk.top();
           stk.pop();
           if(in_scc[t]){continue;}
           id++; //id tracks the number of scc
           vector<ll>v;
           scc_detector(t,v);
       }//Kosaraju ends
       for(i=1;i<=2*m;i++)
       {
           if(in_scc[i]==in_scc[i+m]){impossible=1;break;}
           else if(in_scc[i]<in_scc[i+m]){answer[i]=0;}
           else{answer[i]=1;}
       }if(impossible){cout<<"IMPOSSIBLE"<<endl;continue;}
       for(i=1;i<=m;i++)
       {
           cout<<(answer[i]==1?"+ ":"- ");
       }cout<<endl;
    }
}
//https://cses.fi/problemset/task/1684

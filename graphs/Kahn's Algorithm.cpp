  //Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second
#define P pair<ll,ll>
#define PP pair<pair<ll,ll>,ll>
#define V vector<ll>
#define VP vector<pair<ll,ll>>
#define VS vector<string>
#define VV vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll,vector<ll>,greater<ll>>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    FAST;
   
    ll n, m;   cin>>n>>m;

    vector<vector<ll>> v(n);

    V indeg(n,0);

    FOR(i,0,m)
    {
        ll a,b; cin>>a>>b;
        indeg[b]++;
        v[a].pb(b);
    }

    queue<ll> q;
    V vis(n,0);

    FOR(i,0,n)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            vis[i]=1;
        }
    }

    ll count=0;

    while(!q.empty())
    {
        ll t=q.front();
        q.pop();

        count++;

        for(ll i=0;i<v[t].size();i++)
        {
            ll val=v[t][i];
            if(!vis[val] && indeg[val]>0)
            {
                indeg[val]--;
                if(indeg[val]==0)
                {
                    q.push(val);
                    vis[val]=1;
                }
            }

        }

    }

    if(count==n)
        cout<<"Possible";
    else
        cout<<"Not Possible";      
    return 0;
}

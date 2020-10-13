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
    
    ll n;   cin>>n;

    VP v(n+1);

    FOR(i,1,n+1)
    {
        ll num; cin>>num;
        v[i]={num,i};
    }

    sort(v.begin()+1,v.end());

    ll ans=0;

    V vis(n+1,0);

    FOR(i,1,n+1)
    {
        if(vis[i] || v[i].S==i)
            continue;

        ll j=i,count=0;

        while(!vis[j])
        {
            vis[j]=1;
            j=v[j].S;
            count++;
        }

        ans+=(count-1);
    }

    cout<<ans;
    
    return 0;
}

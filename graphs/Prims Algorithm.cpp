//Chochu Singh
//Prims Algorithm
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
#define VV vector<vector<ll>> 
#define pb push_back
#define pf push_front

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,m;	cin>>n>>m;
	vector<vector<P>> v(n+1);
	
	for(ll i=0;i<m;i++)
	{
		ll a,b,c; cin>>a>>b>>c;
		v[a].pb({b,c});
		v[b].pb({a,c});
	}
	
	V vis(n+1,0);
	
	priority_queue<P,vector<P>,greater<P>> q;
	
	q.push({0,1});

	ll ans=0;
	
	while(!q.empty())
	{
	    P p=q.top();
	    q.pop();
	    
	    ll x=p.S;
	    if(vis[x])
	        continue;
	        
	    vis[x]=1;
	    
	    ans+=p.F;
	    
	    for(ll i=0;i<v[x].size();i++)
	    {
	        P p1=v[x][i];
	        ll node=p1.F;
	        if(vis[node]==0)
	            q.push({p1.S,p1.F});
	    }
	    
	}
	
	cout<<ans;
	
	
	return 0;
}

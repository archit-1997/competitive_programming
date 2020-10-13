/*Bajtek is learning to skate on ice. He's a beginner, so his only mode of transportation is pushing off from a snow drift to the north, east, south or west and sliding until he lands in another snow drift. He has noticed that in this way it's impossible to get from some snow drifts to some other by any sequence of moves. He now wants to heap up some additional snow drifts, so that he can get from any snow drift to any other one. He asked you to find the minimal number of snow drifts that need to be created.

We assume that Bajtek can only heap up snow drifts at integer coordinates.
Input

The first line of input contains a single integer n (1 ≤ n ≤ 100) — the number of snow drifts. Each of the following n lines contains two integers xi and yi (1 ≤ xi, yi ≤ 1000) — the coordinates of the i-th snow drift.

Note that the north direction coinсides with the direction of Oy axis, so the east direction coinсides with the direction of the Ox axis. All snow drift's locations are distinct.
Output

Output the minimal number of snow drifts that need to be created in order for Bajtek to be able to reach any snow drift from any other one.
Examples
Input
Copy

2
2 1
1 2

Output
Copy

1

Input
Copy

2
2 1
4 1

Output
Copy

0
*/

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

void dfs(ll s,VP &v,V &vis,ll &n)
{
    vis[s]=1;
    
    FOR(i,1,n+1)
    {
        if(!vis[i])
        {
            ll x=v[i].F,y=v[i].S;
            
            if(v[s].F == x || v[s].S==y)
                dfs(i,v,vis,n);
        }
    }
}

int main()
{
	FAST;
	
	ll n;	cin>>n;
	VP v(n+1);
	
	FOR(i,1,n+1)
	{
		ll a,b; cin>>a>>b;
		v[i]={a,b};
	}
	
	V vis(n+1,0);
	
	ll ans=0;
	
	FOR(i,1,n+1)
	{
	    if(!vis[i])
	    {
	        dfs(i,v,vis,n);
	        ans++;
	    }
	}
	
	cout<<ans-1<<endl;
	
	return 0;
}

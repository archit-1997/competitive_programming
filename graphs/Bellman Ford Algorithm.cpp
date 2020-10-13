//Chochu Singh
//Bellman Ford Algorithm
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
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll,vector<ll>,greater<ll>>

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,m; cin>>n>>m;
	
	VV v(m);
	
	for(ll i=0;i<m;i++)
	{
	    ll a,b,c;   cin>>a>>b>>c;
	    v[i].pb(a); //From
        v[i].pb(b); //To
        v[i].pb(c); //Weight        
	}
	
	V dis(n+1,INT_MAX);
	
	dis[1]=0;
	
	//Run the outer loop n-1 times
	
	for(ll i=1;i<=n-1;i++)
	{
	    ll j=0;
	    while(j<m)
	    {
	            if(dis[v[j][0]] + v[j][2] < dis[v[j][1]])
	            {
	                dis[v[j][1]] = dis[v[j][0]] + v[j][2];
	            }
	       
	       j++;
	    }
	}
	
	for(ll i=2;i<=n;i++)
	    cout<<dis[i]<<" ";
	
	return 0;
}

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

ll root(V &par,ll i)
{
    while(par[i]!=i)
    {
        par[i]=par[par[i]];
        i=par[i];
    }
    
    return i;
}

ll find(V &par,ll a,ll b)
{
    if(root(par,a)==root(par,b))
        return 1;
    return 0;
}

void Union(V &par,ll a,ll b)
{
    ll r1=root(par,a);
    ll r2=root(par,b);
    par[r1]=r2;
}

int main()
{
	FAST;
	
	ll n;	cin>>n;
	
	V par(n);
	
	FOR(i,0,n)
	    par[i]=i;
	
	ll m;   cin>>m;
	
	FOR(i,0,m)
	{
	    ll a,b; cin>>a>>b;
	    if(find(par,a,b))
	    {
	        cout<<"Cycle present";
	        return 0;
	    }
	    else
	        Union(par,a,b);
	}
	
	cout<<"Cycle not present";
	
	return 0;
}

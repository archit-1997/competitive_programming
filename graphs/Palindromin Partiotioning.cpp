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
	
	ll t;   cin>>t;
	
	while(t--)
	{
	
	    string s;   cin>>s;
	    
	    ll n=s.size();
	    
	    vector<vector<ll>> dp(n,vector<ll> (n,0));
	    
	    vector<vector<ll>> pal(n,vector<ll> (n,0));
	    
	    for(ll i=0;i<n;i++)
	        pal[i][i]=1;
	    
	    for(ll i=2;i<=n;i++)
	    {
	        for(ll j=0;j<n-i+1;j++)
	        {
	            string str;
	            ll start=j,end=i+j-1;
	            for(ll k=j;k<j+i;k++)
	                str=str+s[k];
	           
	            if(i==2)
	                pal[start][end]=(s[start]==s[end]);
	            else
	                pal[start][end]=(s[start]==s[end])&&(pal[start+1][end-1]);
	            
	            if(pal[start][end])
	                dp[start][end]=0;
	            else
	            {
	                ll ans=INT_MAX;
	                for(ll k=start;k<end;k++)
	                {
	                    ll val=1+dp[j][k]+dp[k+1][end];
	                    ans=min(ans,val);
	                }
	                dp[start][end]=ans;
	            }
	        }
	    }
	    cout<<dp[0][n-1]<<endl;
	    
	
    }
    
    return 0;    
    
}

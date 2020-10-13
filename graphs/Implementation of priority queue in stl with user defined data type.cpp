//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second
#define p pair<pair<ll,ll>,ll>

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,t;	cin>>n>>t;
	priority_queue<p,vector<p>,greater<p>> pq;
	
	for(ll i=0;i<n;i++)
	{
	    ll a,b; cin>>a>>b;
	    pq.push({{a,b},i+1});
	}
	
	//Printing the queue
	
	while(!pq.empty())
	{
	    p front=pq.top();
	    pq.pop();
	    cout<<front.F.F<<" "<<front.F.S<<" "<<front.S<<endl;
	}
	
	while(!pq.empty())
	{
	    p front=pq.top();
	    pq.pop();
	    ll at=front.F.F;
	    ll interval=front.F.S;
	    ll index=front.S;
	    if(at<t)
	    {
	        at+=interval;
	        pq.push({{at,interval},index});
	    }
	    else
	    {
	        cout<<index;
	        return 0;
	    }
	}
	
	
	return 0;
}

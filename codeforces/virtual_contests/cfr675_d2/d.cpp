/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Round 675 Div 2
 * @Problem     : Returning Home
 */
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>

using namespace std;
using namespace __gnu_pbds;
 
#define ll		long long int
#define ld		long double
#define line	cout<<"-------------"<<endl;
#define F		first
#define S		second
#define P		pair<ll,ll>
#define V		vector<ll>
#define VP  	vector<pair<ll,ll>>
#define VS  	vector<string>
#define VV  	vector<vector<ll>>
#define pb  	push_back
#define pf  	push_front
#define PQ  	priority_queue<ll>
#define PQ_G   	priority_queue<ll,vector<ll>,greater<ll>>
#define mod 	1000000007
#define inf 	1e18

#define ps(x,y) 		fixed<<setprecision(y)<<x
#define w(tt)    		ll tt; cin>>tt; while(tt--)
#define FOR(i,a,b) 		for(ll i=a;i<b;i++)
#define ma(arr,n,type)  type *arr=new type[n]
#define pbds tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>


void init()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

ll dist(map<P,ll> &hash,P p){
    ll x=p.F, y=p.S;
    ll ans=INT_MAX;
    for(auto it=hash.begin();it!=hash.end();it++){
        P val=it->F;
        ll num=abs(val.F-x)+abs(val.S-y);
        ans=min(ans,num);
    }
    return ans;
    
}

int main()
{
	
	init();

    ll n,m;cin>>n>>m;
    ll xi,yi,xf,yf;
    cin>>xi>>yi>>xf>>yf;
    map<P,ll> hash;
    FOR(i,0,m){
        ll a,b;cin>>a>>b;
        P p={a,b};
        hash[p]=1;
    }

    P pi={xi,yi},pf={xf,yf};
    //if both are at wormhole positions
    if(hash[pi] && hash[pf])
        cout<<0;
    else if(hash[pi]){
        //only the initial position is at the wormhole
        //find the nearest wormhole from the final position
        ll ans=dist(hash,pf);
        cout<<ans;
    }
    else if(hash[pf]){
        //only the final position is at the wormhole
        //find the nearest wormhole from the inital position
        ll ans=dist(hash,pi);
        cout<<ans;
    }
    else{
        //neither of them are at wormhole
        //find the nearest wormhole from the inital and the final position
        ll v1=dist(hash,pi),v2=dist(hash,pf);
        cout<<(v1+v2);
    }

	return 0;
}


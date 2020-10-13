
//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997
//DSA learning series : Lowest Sum


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
#define PP		pair<pair<ll,ll>,ll>
#define V		vector<ll>
#define VP  	vector<pair<ll,ll>>
#define VS  	vector<string>
#define VV  	vector<vector<ll>>
#define VVP   	vector<vector<pair<ll,ll>>>
#define pb  	push_back
#define pf  	push_front
#define PQ  	priority_queue<ll>
#define PQ_G   	priority_queue<P,vector<P>,greater<P>>
#define line    cout<<"-------------"<<endl;
#define mod 	1000000007
#define inf 	1e18

#define setbits(x)		__builtin_popcount(x)
#define zerobits(x) 	__builtin_ctzll(x)
#define ps(x,y) 		fixed<<setprecision(y)<<x
#define w(x)    		ll x; cin>>x; while(x--)
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

int main()
{
	
	init();

	ll t;cin>>t;
	while(t--){
        ll n,q;cin>>n>>q;
        V a(n),b(n);

        FOR(i,0,n)
            cin>>a[i];
        FOR(i,0,n)
            cin>>b[i];

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        PQ_G pq;
        //Insert the first pair of smallest elements
        FOR(i,0,n)
            pq.push(make_pair(a[0]+b[i],0));
        ll count=0;
        V ans;
        while(!pq.empty() && count<1e6){
            P p=pq.top();
            pq.pop();
            ans.pb(p.F);
            if(p.S+1<n){
                pq.push({a[p.S+1]+p.F-a[p.S],p.S+1});
                count++;
            }
        }

        while(q--){
            ll k;cin>>k;
            cout<<ans[k-1]<<endl; 
        }

	}

	return 0;
}


//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997
 
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
#define PQ_G   	priority_queue<ll,vector<ll>,greater<ll>>
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
        ll n;cin>>n;
        ll flag=0;
        V v(n);
        ll g;
        FOR(i,0,n){
            cin>>v[i];
            if(i==0)
                g==v[i];
            else
                g=__gcd(g,v[i]);
            if(i>1 && v[i]<v[i-1])
                flag=1;
        }

    //if everything is fine
    if(g>1 && flag==0)
        cout<<0;
    else {
        //something is wrong with the sequence
        ll ans=0;
        if(v[0]%2==1){
            v[0]++;
            ans++;
        }
        FOR(i,1,n){
            //increase this number if this is less than the previous number and add the differene to the answer
            ll rep=v[i];
            if(rep<v[i-1])
                rep=v[i-1];
            //if not less, then check whether this is odd or not
            if(rep%2==1)
                rep++;
            ans+=(rep-v[i]);
            
        }
        cout<<ans;
    }
    cout<<"\n";
    }

	
	return 0;
}


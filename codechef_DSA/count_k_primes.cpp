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
#define len     1e5+2
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
    
    //first create the prime factors array
    V pf(len,0);
    FOR(i,2,len){
        if(pf[i]!=0)
            continue;
        pf[i]=i;
        for(ll j=i*i;j<len;j+=i)
            pf[j]=i;
    }

    //create the magic array a
    V a(len,0);
    FOR(i,2,len){
        ll x=i;
        map<ll,ll> hash;
        while(x!=1){
            hash[pf[x]]++;
            x/=pf[x];
        }
        a[i]=hash.size();
    }

   //create a 2D array for exploiting the condition that k <=5 and then prepopulate the array
   VV prefix(len, V (6,0));

    FOR(i,2,len){
        FOR(k,1,6){
            prefix[i][k]=prefix[i-1][k]+(a[i]==k);
        }
    }

    ll t;cin>>t;
    while(t--){
        ll a,b,k;cin>>a>>b>>k;
        ll val=prefix[b][k]-prefix[a-1][k];
        cout<<val<<"\n";
    }

    return 0;
}

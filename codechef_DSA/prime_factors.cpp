//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997
//This program prints the prime factors of the numbers from 1 to n

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
	
}

int main()
{
	
	init();
    
    ll n;cin>>n;
    V pf(n+1,0);
    for(ll i=2;i<=n;i++){
        if(pf[i]!=0)
            continue;
        pf[i]=i;
        for(ll j=i*i;j<=n;j+=i)
            pf[j]=i;
    }
    
    VVP ans(n+1);
    
    FOR(i,2,n+1){
        ll x=i;
        map<ll,ll> hash;
        while(x!=1){
            hash[pf[x]]++;
            x/=pf[x];
        }
        for(auto it=hash.begin();it!=hash.end();it++)
            ans[i].pb({it->F,it->S});
    }
    
    FOR(i,2,n+1){
        cout<<i<<" --> ";
        FOR(j,0,ans[i].size()){
            cout<<" {"<<ans[i][j].F<<","<<ans[i][j].S<<"} ,";
        }
        cout<<"\n";
    }

    return 0;
}


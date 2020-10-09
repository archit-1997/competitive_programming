/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Educational Round 95
 * @Problem     : Buying torches
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

ll _ceil(ll a, ll b){
    return (a+b-1)/b;
}

int main()
{
	
	init();
    
    //to craft k torches, he needs to have k sticks and k coals 
    //initially he has 1 stick and 0 coal
    //so h needs to generate k coals
    //no of stick required = ky
    //now we already had one stick at the start of the game
    //now he needs to have k sticks as well, so no of sticks additionally required = k-1
    //so total no of sticks is ky+k-1
    //in one iteration, you get additionally (x-1) sticks
    //total number of iterations is (ky+k-1)/(x-1)
    //answer should be the ceil of this value
    w(tt){
        ll x,y,k;cin>>x>>y>>k;
        ll val=_ceil(k*y + k-1,x-1);
        cout<<val+k<<"\n";
    }
    
	return 0;
}


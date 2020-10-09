/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codefroces Roung 671 Div 2
 * @Problem     : Stairs
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

int main()
{
	
	init();

	//lets first precompute upto 1e18
	
	V store(32,0);
	store[1]=1;

	FOR(i,2,32){
        ll v1=(2*store[i-1]);
        ll expo=2*(i-1);
        ll v2=pow(2,expo);
        ll sum=v1+v2;
        store[i]=sum;
	}

	FOR(i,2,32)
	    store[i]+=store[i-1];

    w(tt){
        ll n;cin>>n;
        ll i=1;
        for(;i<32;i++){
            if(store[i]>n)
                break;
        }
        cout<<i-1<<"\n";

    }	
	
	return 0;
}


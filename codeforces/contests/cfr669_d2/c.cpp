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

ll ask(ll x, ll y) {
    cout << "? " << x << ' ' << y << endl;
    ll z;
    cin >> z;
    return z;
}

int main()
{
	
	init();

    ll n;cin>>n;
    V ans(n+1,0);
    //now you can give 2*n queries
    ll big_index=1,v1,v2;
    FOR(i,2,n+1){
       v1=ask(i,big_index);
       v2=ask(big_index,i);

       if(v1>v2){
            //this means that i has the smaller value
            ans[i]=v1;
            //no change in the value f big_index
       }
       else{
            //this means that big_index has the smaller value
            ans[big_index]=v2;
            big_index=i;
       }
    }

    //now we know that the last remaining element at big_index is n
    ans[big_index]=n;

    cout<<"! ";
    FOR(i,1,n+1)
        cout<<ans[i]<<" ";
    cout<<"\n";
	
	return 0;
}


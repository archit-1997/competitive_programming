/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Round 675 Div 2
 * @Problem     : Nice Matrix
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

ll calc(V &num){
    ll n=num.size();
    sort(num.begin(),num.end());
    ll ans=0;
    FOR(i,0,n)
        ans+=abs(num[i]-num[n/2]);
    return ans;
}

int main(){
	
	init();

	w(tt){
        ll n,m;cin>>n>>m;
        VV v(n,V (m,0));
        FOR(i,0,n)
            FOR(j,0,m)
                cin>>v[i][j];

        ll u=0,d=n-1,l,r,ans=0;

        while(u<=d){
            l=0,r=m-1;
            while(l<=r){
                V num;
                num.pb(v[u][l]);
                if(u!=d)
                    num.pb(v[d][l]);
                if(l!=r)
                    num.pb(v[u][r]);
                if(l!=r && u!=d)
                    num.pb(v[d][r]);
                ans+=calc(num);
                l++,r--;
            }
            u++,d--;
        }

        cout<<ans<<"\n";
          

    }
	
	return 0;
}


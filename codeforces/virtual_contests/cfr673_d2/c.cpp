/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Round 673 Div 2
 * @Problem     : K - Amazing numbers
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

	w(tt){
        ll n;cin>>n;
        VV pos(n);
        FOR(i,0,n){
            ll num;cin>>num;
            num--;
            //decreased the value of the element by 1, will increase while assigning them back to the array
            pos[num].pb(i);
        }

        ll k=n;
        V ans(n+1,-1);
        
        //here we are already starting from the min element that is 
        FOR(i,0,n){
            if(pos[i].empty())
                continue;
                
            ll dist=INT_MIN,prev=-1;
            //if the current value of n does not have any occurrence in the array, then go to the next iteration
            V val=pos[i];
            FOR(j,0,val.size()){
                dist=max(dist,val[j]-prev);
                prev=val[j];
            }
            dist=max(dist,n-prev);
            //now for all windows whose size>=k, this i will be the answer(actually i+1)
            while(dist<=k && k>=1){
                ans[k]=i+1;
                k--;
            }
        }

        FOR(i,1,n+1)
            cout<<ans[i]<<" ";
        cout<<"\n";
	}
	
	return 0;
}


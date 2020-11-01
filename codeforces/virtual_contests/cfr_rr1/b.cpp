/**
 * @author      : archit1997
 * created  	: Tuesday Oct 27, 2020 08:12:30 IST
 * problem    	: Belted Rooms
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
#define FL(i,a,b) 		for(ll i=a;i<b;i++)
#define RFL(i,a,b)		for(ll i=a;i>=b;i--)
#define mp(a,b)			make_pair({a,b})
#define ma(arr,n,type)  type *arr=new type[n]
#define pbds tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>


void solve(){
    
    w(tt){

    ll n;cin>>n;
    string s;cin>>s;

    ll cl=0,acl=0;
    FL(i,0,n){
            if(s[i]=='>')
                cl=1;
            if(s[i]=='<')
                acl=1;
    }

    //flag =0, means we can go one complete round
    if(cl && acl){
        //check whether there are off paths on any one side of the node
        ll ans=0;
            FL(i,0,n-1){
                if(s[i]=='-' || s[i+1]=='-')
                    ans++;
            }
            //check for the extremeties
            if(s[0]=='-' || s[n-1]=='-')
                ans++;
        cout<<ans;
    }
    else
        cout<<n;
    cout<<"\n";
    }

}

int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	
	if(freopen("input.txt","r",stdin)==0)
		cerr<<"wo input file";
		
	if(freopen("output.txt","w",stdout)==0)
		cerr<<"No output file";

	solve();	
	
	return 0;
}


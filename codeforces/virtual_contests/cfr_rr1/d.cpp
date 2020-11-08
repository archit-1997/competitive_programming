/**
 * @author      : archit1997
 * created  	: Sunday Nov 08, 2020 07:27:25 IST
 * problem    	: Bouncing Boomerangs
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

int solve(){

	ll n;cin>>n;
	V v(n+1);

	FL(i,1,n+1)
	    cin>>v[i];

    V ones, twos, threes, twomatch(1e5+1,0),threematch(1e5+1,0),col(1e5+1,0);
    ll currow=1,curcol=1;

    RFL(i,n,1){
        if(v[i]==1)
            ones.pb(i);
        else if(v[i]==2){
            //a two can only be paired up with one
            if(ones.size()==0){
                cout<< -1;
                return 0;
            }
            else{
                twomatch[i]=ones.back();
                ones.pop_back();
            }
            twos.pb(i);
        }
        else if(v[i]==3){
            //3 can be paired up with either 1,2 or 3
            //but we need preference in the order 3,2,1
            if(threes.size()>0)
                threematch[i]=threes.back();
            else if(twos.size()>0)
                threematch[i]=twos.back();
            else if(ones.size()>0){
                threematch[i]=ones.back();
                ones.pop_back();
            }
            else{
                cout<< -1;
                return 0;
            }

            //you need to push in the current position also 
            threes.pb(i);
        }
    }

    
    //now you can start filling the array
    VP targets;

    FL(i,1,n+1){
        if(col[i]==1 || v[i]==0)
            continue;

        curcol=i;
        while(curcol!=0){
            //fill in this current column
            col[curcol]=1;
            if(v[curcol]==1){
                targets.pb(make_pair(currow,curcol));
                //terminate from the loop
                curcol=0;
                //go to the next row because you have 1 in this row
                currow++;
            }
            else if(v[curcol]==2){
                targets.pb(make_pair(currow,curcol));
                curcol=twomatch[curcol];
            }
            else if(v[curcol]=3){
                targets.pb(make_pair(currow,curcol));
                curcol=threematch[curcol];
                targets.pb(make_pair(currow,curcol));
                currow++;
            }
        }
    }
    
    cout<<targets.size()<<"\n";
    for(auto it : targets)
        cout<<it.F<<" "<<it.S<<"\n";

    return 1;


}

int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	
	if(freopen("input.txt","r",stdin)==0)
		cerr<<"No input file";
		
	if(freopen("output.txt","w",stdout)==0)
		cerr<<"No output file";

	solve();	
	
	return 0;
}


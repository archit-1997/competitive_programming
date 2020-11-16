/**
 * @author      : archit1997
 * created  	: Monday Nov 16, 2020 11:14:46 IST
 * problem    	: Putting bricks in the wall
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

    
    w(tt){
        ll n;cin>>n;
        VP ans;
        ll count=0;
        vector<vector<char>> v(n, vector<char> (n));

        FL(i,0,n){
            FL(j,0,n){
                char ch;cin>>ch;
                v[i][j]=ch;
            }
        }

        //check if the top two are only 0
        if(v[0][1]=='0' && v[1][0]=='0'){
            //now we can change the bottom two to 1
            if(v[n-1][n-2]=='0'){
                count++;
                ans.pb(make_pair(n,n-1));
            }
            if(v[n-2][n-1]=='0'){
                count++;
                ans.pb(make_pair(n-1,n));
            }
        }
        //check if the top two are 1
        else if(v[0][1]=='1' && v[1][0]=='1'){
            if(v[n-1][n-2]=='1'){
                count++;
                ans.pb(make_pair(n,n-1));
            }
            if(v[n-2][n-1]=='1'){
                count++;
                ans.pb(make_pair(n-1,n));
            }
        }
        else{
            //this means that the top two are different
            //now check if the bottom two are same or not
            if(v[n-1][n-2]!=v[n-2][n-1]){
                //now both the pairs are different
                char val=v[n-1][n-2];
                count++;
                ans.pb(make_pair(n,n-1));
                if(v[0][1]==val){
                    count++;
                    ans.pb(make_pair(2,1));
                }
                else if(v[1][0]==val){
                    count++;
                 ans.pb(make_pair(1,2));
                }
            }
            else{
                //bottom two are same
                //take the value of one of the bottom cell
                char val=v[n-1][n-2];
                //now change the values from the top cells
                if(v[0][1]==val){
                    count++;
                    ans.pb(make_pair(1,2));
                }
                else if(v[1][0]==val){
                    count++;
                    ans.pb(make_pair(2,1));
                }
            }
        }
        cout<<count<<"\n";
        FL(i,0,count){
            cout<<ans[i].F<<" "<<ans[i].S<<"\n";
        }
    }
	
	return 0;
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


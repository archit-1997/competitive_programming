/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		:
 * @Problem     : 
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
        ll rh=0,bh=0;
        ll n,num;cin>>n;
        string s;cin>>s;
        ll len=s.size();
        FOR(i,1,len+1){
            num=s[i-1]-'0';
            if(i%2==1){
                //this is raze's section
                if(num%2==1)
                  rh=1;
            }
            else{
                //this is breach's section
                if(num%2==0)
                    bh=1;
            }
        }
        //if the number is odd, then check raze's hash
        if(n%2==1){
            if(rh==1)
                cout<<1<<"\n";
            else
                cout<<2<<"\n";
        }
        else{
            if(bh==1)
                cout<<2<<"\n";
            else
                cout<<1<<"\n";
        }
    } 

	return 0;
}


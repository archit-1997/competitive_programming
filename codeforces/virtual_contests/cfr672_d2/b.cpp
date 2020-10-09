/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Round 672 Div 2
 * @Problem     : Rock and Lever
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

V dec2bin(ll n){
    V res;
    while(n!=0){
        res.pb(n%2);
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
	
	init();

    w(tt){
        ll n;cin>>n;
        V v(n);
        FOR(i,0,n)
            cin>>v[i];
        //stores the pos of the highest 1 bit in the binary of the given number
        map<ll,ll> hash;
        FOR(i,0,n){
            if(v[i]==0){
                continue;
            }
            V bin=dec2bin(v[i]);
            ll val=0;
            FOR(j,0,bin.size()){
                if(bin[j]==1){
                    val=j;
                    break;
                }
            }
            ll num=bin.size()-val;
            hash[num]++;
        }
        ll ans=0;
        for(auto it=hash.begin();it!=hash.end();it++){
            ll a=it->S;
            ll sum=(a*(a-1))/2;
            ans+=sum;
        }
        cout<<ans<<"\n";
    }	
	
	return 0;
}


/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Round 668 Div 2
 * @Problem     : Balanced Bitstring
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
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        ll flag=0;
        FOR(i,0,k){
            char ch=' ';
            if(s[i]!='?')
                ch=s[i];
            for(ll j=i+k;j<n;j+=k){
                if(s[j]!='?'){
                    if(ch==' ')
                        ch=s[j];
                    else if(s[j]!=ch){
                        flag=1;
                        //cout<<i<<" "<<j<<"\n";
                        break;
                    }
                }
            }
            if(flag)
                break;
            //update s[i] if it was initially ?
            if(s[i]=='?' && ch!=' ')
                s[i]=ch;
        }
        //count and check the decided number of zeros and ones
        ll c0=0,c1=0;
        FOR(i,0,k){
            if(s[i]=='0')
                c0++;
            else if(s[i]=='1')
                c1++;
        }
        if(flag || (c1>(k/2)) || (c0>(k/2)))
            cout<<"NO";
        else
            cout<<"YES";
        cout<<"\n";
    }
	return 0;
}


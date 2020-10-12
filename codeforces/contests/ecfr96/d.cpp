
/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Educational Codeforces Round 96
 * @Problem     : String Deletion 
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
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
}

int main()
{
	
	init();

    w(tt){
        ll n;cin>>n;
        string s;cin>>s;
        V v;
        ll count=1;
        FOR(i,1,n){
            if(s[i]==s[i-1])
                count++;
            else{
                v.pb(count);
                count=1;
            }
        }
        v.pb(count);
        

        //now we need to operate on this vector v
        ll ans=0;
        while(1){
            if(v.size()==0)
                break;
            if(v.size()==1){
                ans++;
                break;
            }
            //if the first character is greater than 1, then operate on it and then proceed
            if(v[0]>1){
                ans++;
                v.erase(v.begin());
            }
            else{
                //find if there is any number greater than 1 on the right side
                ll len=v.size(),flag=0,index=-1;
                FOR(i,1,len){
                    if(v[i]>1){
                        index=i;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    //we have a greater element on the right side
                    if(len%2==1)
                        len++;
                    ans+=(len/2);
                    break;
                }
                else{
                    v[index]--;
                    v.erase(v.begin());
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }	
	
	return 0;
}


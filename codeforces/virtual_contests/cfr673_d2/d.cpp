/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Round 673 Div 2
 * @Problem     : Make them equal
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

void operate(VV &ans,V &v, ll i,ll j,ll x){
    v[i]-=(i*x);
    v[j]+=(i*x);
    V tmp={i,j,x};
    ans.pb(tmp);
}

int main()
{
	
	init();

    w(tt){
        ll n;cin>>n;
        VV ans;
        V v(n+1);
        ll sum=0;
        FOR(i,1,n+1){
            cin>>v[i];
            sum+=v[i];
        }

        if(sum%n)
            cout<<-1<<"\n";
        else{
            //start from 2 and make all of them equal to sum/n
            FOR(i,2,n+1){
                if(v[i]%i)
                    operate(ans,v,1,i,i-(v[i]%i));
                operate(ans,v,i,1,v[i]/i);
            }
        

            FOR(i,2,n+1)
                operate(ans,v,1,i,sum/n);

            cout<<ans.size()<<"\n";
            FOR(i,0,ans.size()){
                V tmp=ans[i];
                FOR(j,0,tmp.size())
                    cout<<tmp[j]<<" ";
                cout<<"\n";
            }
        }
    }	
	
	return 0;
}


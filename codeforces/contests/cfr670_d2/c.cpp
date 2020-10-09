/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: cfr670_d2
 * @Problem     : Link cut centroids
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

//dfs for finding the size of each subtree
void dfs(VV &v, V &sz,V &cent,V &par, ll x, ll prev){
    par[x]=prev;
    ll n=v.size();
    n--;
    sz[x]=1;
    bool isCent=true;
    FOR(i,0,v[x].size()){
        ll cur=v[x][i];
        //recursively do the dfs
        if(cur!=prev){
            dfs(v,sz,cent,par,cur,x);
            sz[x]+=sz[cur];
            if(sz[cur]>(n/2))
                isCent=false;
        }
    }
    if(n-sz[x]>(n/2))
        isCent=false;
    if(isCent)
        cent.pb(x);
}

void ldfs(VV &v,ll &leaf,ll x, ll prev){
    if(v[x].size()==1){
        leaf=x;
        return;
    }

    FOR(i,0,v[x].size()){
        if(v[x][i]!=prev)
            ldfs(v,leaf,v[x][i],x);
    }
}


int main()
{
	
	init();

	w(tt){
        ll n;cin>>n;
        VV v(n+1);
        FOR(i,0,n-1){
            ll a,b;cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
	//cout<<v.size()<<"\n";
    
    //denoted the size of each subtree of a node
    V sz(n+1,0),par(n+1,0);
    FOR(i,1,n+1)
        par[i]=i;
    V cent;
    
    //sending the current node and the prev node
    dfs(v,sz,cent,par,1,-1);
    
    if(cent.size()==1){
        cout<<1<<" "<<v[1][0]<<"\n";
        cout<<1<<" "<<v[1][0]<<"\n";
    } 
    else{
            ll x=cent[0],y=cent[1];
            if(par[y]!=x)
                swap(x,y);

            //pick a leaf node from the subtree of y
            //now the parent of y is x
            ll leaf;
            ldfs(v,leaf,y,x);

            //now just print the answer
            cout<<leaf<<" "<<par[leaf]<<"\n";
            cout<<x<<" "<<leaf<<"\n";


        }
    }

	return 0;
}


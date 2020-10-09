//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997
//Codechef DSA : Love of gift (ASHIGIFT)
//Category : Binary search on answer

//See how you can assign id's while sorting so that you can easily differentiate
//between two different kinds of elements in the same list

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
#define PP		pair<pair<ll,ll>,ll>
#define V		vector<ll>
#define VP  	vector<pair<ll,ll>>
#define VS  	vector<string>
#define VV  	vector<vector<ll>>
#define VVP   	vector<vector<pair<ll,ll>>>
#define pb  	push_back
#define pf  	push_front
#define PQ  	priority_queue<ll>
#define PQ_G   	priority_queue<ll,vector<ll>,greater<ll>>
#define line    cout<<"-------------"<<endl;
#define mod 	1000000007
#define inf 	1e18

#define setbits(x)		__builtin_popcount(x)
#define zerobits(x) 	__builtin_ctzll(x)
#define ps(x,y) 		fixed<<setprecision(y)<<x
#define w(x)    		ll x; cin>>x; while(x--)
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

//Now defining the function f(x) which gives us the number of people that reach byteland when
//the inital nubmer of people starting from byteland is x
ll f(ll x, vector<pair<ll,P>> &v){  //here x is the number of men
    ll cur=0;   //This is the final number of people that will reach byteland
    while(v[cur].S.F!=(-20)){
        if(v[cur].S.F==-10){
            //if this is a dish
            x-=v[cur].S.S;
        }
        else if(x>=v[cur].S.F)
            x+=v[cur].S.S;

        cur++;
    }

    return x;
}

//Defining a custom lower bound function
ll lb(ll k, ll l, ll h,vector<pair<ll,P>> &v){
    ll ans=l;
    while(l<=h){
        ll m=l+(h-l)/2;
        if(f(m,v)>=k){
            ans=m;
            h=m-1;
        }
        else
            l=m+1;
    }
    return ans;
}

int main()
{
	
	init();

    ll t;cin>>t;
    while(t--){
        ll X;cin>>X;    //The distance of byteland from chefs town
        ll b;cin>>b;    //Number of dishes
        //Now defining a structure that will contain the required information
        vector<pair<ll,P>> v;
        while(b--){
        //now you have pairs of numbers from xi yi
        ll x,y;cin>>x>>y;
        //{position,{id,number of people}}
        //defining the id for dishes to be -10
        v.pb({x,{-10,y}});
        }
        ll C;cin>>C;    //Number of tribals
        if(C==0){
            ll ans=0;
            FOR(i,0,v.size())
                ans+=v[i].S.S;
            cout<<ans+1<<endl;
        }
        else{
            
        while(C--){
        ll p,q,r;cin>>p>>q>>r;
        //p->position
        //q->requirement
        //r->new members that will be added
        v.pb({p,{q,r}});
        }
        //now push the last element that indicates that we have finally reached the answer
        //-20 is the id for byteland and -50 is just a random value
        v.pb({X,{-20,-50}});
        sort(v.begin(),v.end());
        //Applying lower bound on the function 
        cout<<lb(1,1,inf,v)<<"\n";
        }
    }
	
	return 0;
}


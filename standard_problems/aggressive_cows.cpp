//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997

//SPOJ : Aggressive Cows AGGRCOW

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
#define pbds tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

bool check(V &v, ll gap, ll c) {
	ll n = v.size();

	ll count = 1, last = v[0];

	FOR(i, 1, n) {
		if (v[i] - last >= gap) {
			if (++count == c)
				return true;
			last = v[i];
		}
	}
	return false;
}

int main()
{

	init();

	w(x) {
		ll n, c;	cin >> n >> c;

		V v(n);

		FOR(i, 0, n)
		cin >> v[i];

		sort(v.begin(), v.end());

		//initailly we will store the max gap that is possible
		ll l = 0, h = v[n - 1];
		ll ans = 0;
		while (l <= h) {
			ll m = (l + h) / 2;
			//if the value of m is a suitable gap

			//now we will check whether we can fill all the cows with the given gap
			bool res = check(v, m, c);

			//if we are able to fill the cows in the sheds
			if (res) {
				ans = m;
				l = m + 1;
			}
			else
				h = m - 1;

		}

		cout << ans << "\n";
	}

	return 0;
}
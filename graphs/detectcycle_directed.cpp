//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997

#include <bits/stdc++.h>
using namespace std;

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

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

bool cycle(VV &v, V &vis, ll x, V &rec) {
	//check if the current node has already been visited or not
	if (!vis[x]) {
		vis[x] = 1;
		rec[x] = 1;

		FOR(i, 0, v[x].size()) {
			ll num = v[x][i];

			//if this node is not visited, the dfs on this node and check cycle
			if (!vis[num] && cycle(v, vis, num, rec))
				return true;

			//check if this is present in the recursion stack or not
			if (rec[num])
				return true;
		}
	}

	//after the dfs is done, now make sure you remove the item from the stack
	rec[x] = 0;

	//if you have reached here, that means no cycle is found in this iteration, so return false

	return false;
}

int main()
{

	init();

	ll n, m;	cin >> n >> m;

	VV v(n + 1);

	FOR(i, 0, m) {
		ll a, b;	cin >> a >> b;
		v[a].pb(b);
	}

	V vis(n + 1, 0), rec(n + 1, 0);

	FOR(i, 1, n + 1) {
		if (cycle(v, vis, i, rec)) {
			cout << "Cycle present in the graph";
			return 0;
		}
	}

	cout << "No cycle present in the graph";

	return 0;
}
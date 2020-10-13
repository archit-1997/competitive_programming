//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997

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
//here we are using an ordered set of pairs
#define pbds tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>

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

	int t;   cin >> t;

	while (t--) {
		int n, k; cin >> n >> k;

		int v[n];

		FOR(i, 0, n)
		cin >> v[i];

		int ans = 0;
		//now iterate over all possible subarrays
		for (int i = 0; i < n; i++) {
			int hash[2001];
			for (int j = 0; j < 2001; j++)
				hash[j] = 0;
			pbds st;
			for (int j = i; j < n; j++) {
				//This is the correct way to insert duplicates in a set
				//by storing the element along with its frequency
				st.insert(v[j]);
				hash[v[j]]++;
				int m = ceil(((double)k) / (j - i + 1));
				int pos = ceil((double)k / m);
				pos--;
				auto it = st.find_by_order(pos);
				int val = (*it);
				//finding f which is the frequency of x in S(the subarray)
				int f = hash[val];
				if (hash[f] > 0)
					ans++;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
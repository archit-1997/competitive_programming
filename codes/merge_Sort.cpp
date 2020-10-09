//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997

//Merge Sort

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

//this function will merge two sorted arrays
void merge(V &a, V &b, V &ans) {
	ll la = 0, lb = 0;
	while (la < a.size() && lb < b.size()) {
		if (a[la] < b[lb])
			ans.pb(a[la++]);
		else
			ans.pb(b[lb++]);
	}

	while (la < a.size())
		ans.pb(a[la++]);
	while (lb < b.size())
		ans.pb(b[lb++]);

}

void mergeSort(V &v, ll l, ll h) {
	if (l == h) {
		//You can just return as it is already sorted
		return;
	}
	ll m = l + (h - l) / 2;
	mergeSort(v, l, m);
	mergeSort(v, m + 1, h);
	//Now we need to merge both of these
	V a, b, ans;
	FOR(i, l, m + 1)
	a.pb(v[i]);
	FOR(i, m + 1, h + 1)
	b.pb(v[i]);
	merge(a, b, ans);
	FOR(i, 0, ans.size())
	v[l + i] = ans[i];
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{

	init();

	ll n;	cin >> n;

	V v(n);

	FOR(i, 0, n)
	cin >> v[i];

	mergeSort(v, 0, n - 1);

	FOR(i, 0, n)
	cout << v[i] << " ";

	return 0;
}
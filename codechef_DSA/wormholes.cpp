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
//#define w(x)    		ll x; cin>>x; while(x--)
#define FOR(i,a,b) 		for(ll i=a;i<b;i++)
#define ma(arr,n,type)  type *arr=new type[n]

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

bool compare(const P &a, const P &b) {
	if (a.F == b.F)
		return a.S < b.S;
	return a.F < b.F;

}

int main()
{

	init();

	ll n, x, y;	cin >> n >> x >> y;

	VP interval(n, {0, 0});

	FOR(i, 0, n)
	{
		ll a, b;	cin >> a >> b;
		interval[i] = {a, b};
	}

	V v(x, 0), w(y, 0);

	FOR(i, 0, x)
	cin >> v[i];

	FOR(i, 0, y)
	cin >> w[i];

	sort(interval.begin(), interval.end(), compare);
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	ll ans = INT_MAX;

	FOR(i, 0, n) {
		ll high = upper_bound(v.begin(), v.end(), interval[i].F) - v.begin();
		high--;
		ll low = lower_bound(w.begin(), w.end(), interval[i].S) - w.begin();
		if (high >= 0 && low < y)
			ans = min(ans, w[low] - v[high] + 1);
	}

	cout << ans << endl;

	return 0;
}
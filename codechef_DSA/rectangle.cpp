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

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

bool compare(const P &a, const P &b) {
	if (a.F == b.F)
		return a.S < b.S;
	else
		return a.F < b.F;
}

int main()
{

	init();

	ll n;	cin >> n;

	VP points;

	//first lets push the dummy points
	points.pb({0, 0});
	points.pb({1e5, 0});

	for ( ll i = 0; i <= 1e5; i++)
		points.pb({i, 500});

	FOR(i, 0, n) {
		ll a, b;	cin >> a >> b;
		points.pb({a, b});
	}

	sort(points.begin(), points.end(), compare);

	ll len = points.size();

	V x(len, -1), y(len, -1);

	FOR(i, 0, len) {
		x[i] = points[i].F;
		y[i] = points[i].S;
	}

	V right(len, -1), left(len, -1);

	//Now create an array which contains next smaller element on the right side
	stack<P> st;
	st.push({y[0], 0});

	FOR(i, 1, len) {
		if (y[i] < st.top().F) {
			while (!st.empty() && y[i] < st.top().F) {
				P p = st.top();
				st.pop();
				ll val = p.F, index = p.S;
				right[index] = i;
			}
			st.push({y[i], i});
		}
		st.push({y[i], i});
	}

	//empty the stack
	while (!st.empty())
		st.pop();

	//Now create an array which contains next smaller element on the left side
	st.push({y[0], 0});

	FOR(i, 1, len) {
		if (st.top().F < y[i]) {
			left[i] = st.top().S;
			st.push({y[i], i});
		}
		else if (st.top().F >= y[i]) {
			while (!st.empty() && st.top().F >= y[i])
				st.pop();
			if (!st.empty())
				left[i] = st.top().S;
			st.push({y[i], i});
		}
	}

	//Now begin calculating the result
	ll ans = INT_MIN;
	FOR(i, 0, len) {
		//find the right element
		ll xright, xleft;
		if (right[i] == -1)
			xright = 1e5;
		else
			xright = x[right[i]];
		//find the left element
		if (left[i] == -1)
			xleft = 0;
		else
			xleft = x[left[i]];

		ll diff = xright - xleft;
		ll val = y[i] * diff;
		ans = max(ans, val);
	}

	cout << ans << endl;

	return 0;
}
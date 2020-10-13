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

int main()
{

	init();

	ll n, k;	cin >> n >> k;
	V v(n, 0);
	V pos(n, -1);

	FOR(i, 0, n)
	cin >> v[i];

	stack<P> st;

	st.push({v[0], 0});

	FOR(i, 1, n) {
		if (v[i] < st.top().F) {
			//do while the condition is satisfied or the stack does not get empty
			while (!st.empty() && v[i] < st.top().F) {
				P p = st.top();
				st.pop();
				ll val = p.F, index = p.S;
				pos[index] = i;
			}
			st.push({v[i], i});
		}
		st.push({v[i], i});
	}

	ll ans = 1;
	FOR(i, 0, n)
	{
		if (pos[i] != -1)
		{
			ll val = (pos[i] - i + 1) % mod;
			ans = ans * val;
			ans = ans % mod;
		}
	}

	cout << ans << endl;

	return 0;
}
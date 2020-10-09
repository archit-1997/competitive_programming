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

	w(x) {
		ll n, m, k;	cin >> n >> m >> k;
		set<P> s;
		map<ll, ll> hash_x, hash_y;

		FOR(i, 0, k) {
			ll a, b;	cin >> a >> b;
			hash_x[a] = 1, hash_y[b] = 1;
			s.insert({a, b});
		}

		ll ans = k * 4;

		for (auto it = s.begin(); it != s.end(); it++) {
			P p = *it;
			ll a = p.F, b = p.S;

			ll sub = 0;

			//x y+1
			if (s.find({a, b + 1}) != s.end())
				sub++;
			//x y-1
			if (s.find({a, b - 1}) != s.end())
				sub++;
			//x+1 y
			if (s.find({a + 1, b}) != s.end())
				sub++;
			//x-1 y
			if (s.find({a - 1, b}) != s.end())
				sub++;

			ans -= sub;

		}

		cout << ans << endl;
	}

	return 0;
}
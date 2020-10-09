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
		ll k, d0, d1;	cin >> k >> d0 >> d1;
		ll s = (d0 + d1);
		ll c = (2 * s) % 10 + (4 * s) % 10 + (8 * s) % 10 + (6 * s) % 10;

		ll num_cycles = (k - 3) / 4;
		ll total = 0;

		if (k == 2)
			total = s;
		else {
			total = s + (s % 10) + (num_cycles * c);
			ll rem = (k - 3) - (num_cycles * 4);
			ll p = 2;
			for (ll i = 1; i <= rem; i++) {
				total += (p * s) % 10;
				p = (p * 2) % 10;
			}
		}

		if (total % 3 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
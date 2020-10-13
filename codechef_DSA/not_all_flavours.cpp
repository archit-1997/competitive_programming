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
		ll n, k;	cin >> n >> k;

		V v(n, 0);

		FOR(i, 0, n)
		cin >> v[i];

		map<ll, ll> hash;
		ll count = 1, ans = 1;

		if (n == 1) {
			cout << n << endl;
			continue;
		}

		ll l = 0, r = 0;
		hash[v[0]] = 1;

		while (1) {
			r++;
			//put the terminating condition over here
			if (r == n)
				break;

			hash[v[r]]++;
			if (hash[v[r]] == 1)
				count++;

			//if this has reached the value which is not permissible
			if (count == k) {
				while (1) {
					hash[v[l]]--;
					if (hash[v[l]] == 0)
						count--;
					l++;
					if (count < k || l == r)
						break;
				}
			}

			//if everything is alright, then update the result
			ans = max(ans, r - l + 1);


		}
		cout << ans << endl;
	}

	return 0;
}
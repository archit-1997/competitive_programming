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

ll ga, gb, ra, rb;

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

ll check() {
	//check if a has won the game or not
	if (ga > (gb + rb))
		return 1;
	//check if b has won the game
	if (gb > (ga + ra))
		return 0;
	return -1;
}

int main()
{

	init();

	w(x) {
		ll n;	cin >> n;
		string s;	cin >> s;
		V a(n, 0), b(n, 0);
		FOR(i, 0, (2 * n)) {
			if (i % 2 == 0)
				a[i / 2] = s[i] - '0';
			else
				b[i / 2] = s[i] - '0';
		}
		ll ans = 0, res = -1;
		ga = 0, gb = 0, ra = n, rb = n;
		FOR(i, 0, n) {
			if (a[i])
				ga++;
			ra--;
			//check if someone has already won the game
			res = check();
			if (res != -1) {
				ans = (2 * i) + 1;
				break;
			}

			if (b[i])
				gb++;
			rb--;
			//check if someone has already won the game
			res = check();
			if (res != -1)
			{
				ans = 2 * (i + 1);
				break;
			}
		}
		if (ans)
			cout << ans << endl;
		else
			cout << 2 * n << endl;
	}

	return 0;
}
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

	ll n, m;	cin >> n >> m;

	map<string, string> hash;
	//chef -> country
	FOR(i, 0, n)
	{
		string a, b;	cin >> a >> b;
		hash[a] = b;
	}

	map<string, ll> chef, country;

	FOR(i, 0, m) {
		//this is the name of the chef
		string name;	cin >> name;
		chef[name]++;
		country[hash[name]]++;
	}

	string ans_chef = "";
	ll count = 0;

	//This will find out the name of the chef who has won the game
	for (auto it = chef.begin(); it != chef.end(); it++) {
		if (it->S > count) {
			ans_chef = it->F;
			count = it->S;
		}
		else if (it->S == count) {
			string name = it->F;
			if (name < ans_chef)
				name = ans_chef;
		}
	}

	//Now we have to find out the name of the country which has the max no of votes for chefs
	string ans_country = "";
	count = 0;

	for (auto it = country.begin(); it != country.end(); it++) {
		if (it->S > count) {
			ans_country = it->F;
			count = it->S;
		}
		else if (it->S == count) {
			string name = it->F;
			if (name < ans_country)
				name = ans_country;
		}
	}

	cout << ans_country << endl << ans_chef << endl;

	return 0;
}
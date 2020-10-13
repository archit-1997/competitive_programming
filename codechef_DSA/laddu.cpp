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
		ll n;	cin >> n;
		ll laddu = 0;
		string nation;	cin >> nation;
		string empty;
		getline(cin, empty);
		while (n--) {
			string s;	getline(cin, s);
			//contest won or hosted
			if (s[0] == 'C') {
				//here check for won or hosted
				ll len = s.size();
				if (s[len - 1] == 'D')
					laddu += 50;
				else {
					//contest won
					size_t index = s.find(' ');
					string val = s.substr(index + 1);
					ll amt = stoi(val);
					laddu += 300;
					if (amt <= 20)
						laddu += (20 - amt);
				}
			}
			//top contributor
			else if (s[0] == 'T') {
				laddu += 300;
			}
			//bug finder
			else {
				size_t index = s.find(' ');
				string val = s.substr(index + 1);
				ll amt = stoi(val);
				laddu += amt;
			}
		}

		if (nation == "INDIAN")
			cout << (laddu / 200) << endl;
		else
			cout << (laddu / 400) << endl;
	}

	return 0;
}
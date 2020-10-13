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

void remove(set<ll> &st, ll num) {
	auto it = st.find(num);
	if (it != st.end())
		st.erase(it);
}

int main()
{

	init();

	ll n, q;	cin >> n >> q;
	V v(n + 1, 0), s(n + 1, 0);

	FOR(i, 1, n + 1)
	cin >> v[i];

	s[1] = 1;

	FOR(i, 1, n) {
		if (v[i + 1] % v[i] == 0)
			s[i + 1] = s[i];
		else
			s[i + 1] = s[i] + 1;
	}

	//now insert the indexes at which the elements are changing
	set<ll> st;
	st.insert(1);
	ll val = s[1];

	FOR(i, 2, n + 1) {
		if (s[i] != val) {
			st.insert(i);
			val = s[i];
		}
	}

	//This prints the elements of the set
	// for (auto it = st.begin(); it != st.end(); it++)
	// 	cout << *it << " ";

	while (q--) {
		ll type, index, val, f_i, f_i1;	cin >> type;

		switch (type) {
		case 1:
			cin >> index >> val;
			v[index] = val;
			st.insert(index);
			st.insert(index + 1);
			//check for the condition of i and i-1
			f_i = 0, f_i1 = 0;
			if (index != 1 && v[index] % v[index - 1] == 0)
				f_i = 1;
			if (v[index + 1] % v[index] == 0)
				f_i1 = 1;
			if (f_i)
				remove(st, index);
			if (f_i1)
				remove(st, index + 1);
			break;
		case 2:
			cin >> index;
			auto it = st.upper_bound(index);
			it--;
			cout << *it << endl;
		}
	}

	return 0;
}
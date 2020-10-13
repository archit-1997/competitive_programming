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

	ll n;	cin >> n;

	V bracket(n, 0);

	FOR(i, 0, n)
	cin >> bracket[i];

	V v(n, 0);

	//array with 1 and -1
	FOR(i, 0, n) {
		if (bracket[i] == 2)
			v[i] = -1;
		else
			v[i] = bracket[i];
	}

	//array with prefix sum
	FOR(i, 1, n)
	v[i] += v[i - 1];

	//this stores the position of the maximum depth
	ll max = INT_MIN, max_index = -1;
	FOR(i, 0, n)
	{
		if (v[i] > max) {
			max = v[i];
			max_index = i + 1;
		}
	}

	cout << max << " " << max_index << " ";

	//to find the maximum number of symbols between a pair of matched parenthesis
	ll i = 0;
	ll len = INT_MIN, start = 0, begin = 0;
	ll index = 0;
	while (1) {
		while (v[index] != 0) {
			index++;
		}

		//if this contains the new max num of matched parenthesis
		ll size = index - begin + 1;
		if (size > len) {
			len = size;
			start = begin + 1;
		}
		index++;
		if (index >= n)
			break;
		begin = index;
	}

	cout << len << " " << start << endl;

	return 0;
}
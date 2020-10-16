//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997
//DSU : weighted union + path compression

//Note : Here I have not made use of the find function, use only when needed

//INPUT FORMAT
// 10 This is the number of nodes
//now entering the union operation step by step
// 2 1
// 4 3
// 8 4
// 9 3
// 6 5
// -1 -1


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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

void print(V &par, ll n) {
	FOR(i, 0, n)
	cout << par[i] << " ";
	cout << endl;

	line;
}

ll root(V &par, ll x) {
	while (par[x] != x)
	{
		par[x] = par[par[x]];
		x = par[x];
	}

	return x;
}

void Union(V &par, V &size, ll a, ll b) {
	ll ra = root(par, a);
	ll rb = root(par, b);

	if (size[ra] <= size[rb]) {
		//now merge a in b
		par[ra] = par[rb];
		size[rb] += size[ra];
	}
	else {
		//now merge b in a
		par[rb] = par[ra];
		size[ra] += size[rb];
	}

}

int main()
{

	init();

	ll n;	cin >> n;

	//Assumption is taken that the nodes are numbered are form 0 to n-1

	V par(n), size(n, 1);

	FOR(i, 0, n)
	par[i] = i;

	while (1) {
		ll a, b;	cin >> a >> b;

		if (a == -1 && b == -1) {
			cout << "End of input";
			return 0;
		}

		//check if the root of the two numbers are different or not
		if (root(par, a) != root(par, b))
			Union(par, size, a, b);

		//now print the new parent array
		print(par, n);

	}

	return 0;
}

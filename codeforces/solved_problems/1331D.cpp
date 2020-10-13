/*The only line of the input contains a 7-digit hexadecimal number. The first "digit" of the number is letter A, the rest of the "digits" are decimal digits 0-9.

Output
Output a single integer.

Examples
inputCopy
A278832
outputCopy
0
inputCopy
A089956
outputCopy
0
inputCopy
A089957
outputCopy
1
inputCopy
A144045
outputCopy
1*/

//Archit Singh
#include <bits/stdc++.h>
using namespace std;

#define 	ll 				long long int
#define 	ld 				long double
#define 	line 			cout<<"-------------"<<endl;
#define 	f 				first
#define 	s 				second
#define 	mp(a,b) 		make_pair(a,b)
#define 	p 				pair<ll,ll>
#define 	pp 				pair<pair<ll,ll>,ll>
#define 	v 				vector<ll>
#define 	vp 				vector<pair<ll,ll>>
#define 	vs 				vector<string>
#define 	vv 				vector<vector<ll>>
#define 	vvp 			vector<vector<pair<ll,ll>>>
#define 	pb 				push_back
#define 	pf 				push_front
#define 	pqb				priority_queue<ll>
#define 	pqs 			priority_queue<ll,V,greater<ll>>
#define 	FOR(i,a,b) 		for(ll i=a;i<=b;i++)
#define 	setbits(x)		__builtin_popocount(x)
#define 	zrobits(x)		__builtin_ctzll(x)
#define 	mod				1000000007
#define 	inf				1e18
#define 	ps(x,y)			fixed<<setprecision(y)<<x
#define 	ma(arr,n,type)	type *arr=new type[n]
#define 	w(x)			ll x; cin>>x; while(x--)

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{

	init();

	string S;	cin >> S;

	reverse(S.begin(), S.end());

	ll ans = 0;

	FOR(i, 0, 5)
	{
		ll val = S[i] - '0';
		//cout << val << endl;
		ans += (pow(16, i) * val);
	}

	ans += pow(16, 6) * 10;

	cout << ans % 2 << endl;

	return 0;
}
